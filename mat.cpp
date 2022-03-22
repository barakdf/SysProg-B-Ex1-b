#include <vector>
#include <iostream>
#include "mat.hpp"

namespace ariel {
    int max(int col, int row) {
        if (col > row) {
            return col;
        }
        return row;
    }
    int min(int a, int b) {
        if (a > b) {
            return b;
        }
        return a;
    }

    std::string mat(int col, int row, char s1, char s2) {
        if(row % 2 == 0 || col % 2 == 0) {
            throw std::invalid_argument("Mat size is always odd");
        }
        if (row <= 0 || col <= 0) {
            throw std::invalid_argument("Mat should be positive");
        }
        const int invalid_symbol = 32;
        if ((int) s1 <= invalid_symbol || (int) s2 <= invalid_symbol) {
            throw std::invalid_argument("Invalid symbols");
        }
        std::vector<std::vector<int>> l_mat(row);
        std::vector<std::vector<int>> r_mat(row);
        for (int i = 0; i < row; ++i) {
            l_mat[i] = std::vector<int>(col);
            r_mat[i] = std::vector<int>(col);
        }

        for (int i = 0; i < max(col, row); ++i) {
            if (i < row) {
                for (int j = i; j < col; ++j) {
                    l_mat[i][j] = i;
                    r_mat[row - 1 - i][col - 1 - j] = i;
                }
            }
            if (i < col) {
                for (int j = i; j < row; ++j) {
                    l_mat[j][i] = i;
                    r_mat[row - 1 - j][col - 1 - i] = i;
                }
            }

        }

        std::string ans;

        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                int bin = min(l_mat[i][j], r_mat[i][j]) % 2;
                if (bin == 0) {
                    ans += s1;
                } else {
                    ans += s2;
                }
            }
            ans += '\n';
        }
        return ans;
    }
}


