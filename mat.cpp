#include <vector>
#include <iostream>
#include "mat.hpp"


/**
 * The Idea of this implementation was taken from -- https://codegolf.stackexchange.com/questions/241219/mat-printing-matrix .
 * The idea is to take 2 matrix, left and right.
 * in the left matrix at each level (inner frames) we put the value of the level by its depth
 * where the values matches the collum length.
 * the right matrix will be upside mirrored to the left (like odd functions).
 * for example - at the size (3, 3) we will get left --> ("0,0,0")  right -->  ("2,1,0")
 *                                                       ("0,1,1")             ("1,1,0")
 *                                                       ("0,1,2")             ("0,0,0")
 * at this point we will build new matrix and put on each cell the minimum value between each matrix (lef/right).
 *
 * at the example above ^ --> ("0,0,0")
                              ("0,1,0")
                              ("0,0,0")
 * note : at bigger size matrix we will have values bigger that '1', so we always module each cell by 2, to get binary values.
 *
 * last step: each value will be replaced at the matching symbol in the input parameters.
 *
 * mat(3,3,'@', '-') --> ("@@@")
                         ("@-@")
                         ("@@@")
 *
 *  Exceptions -> bad inputs: negative, zero or even size of 'carpet' will throw exception.
 *                bad symbols: every char that <= 32 in the ascii table.
 * */


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

        /* checking input exceptions */
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

        /* make the left and right matrix */
        std::vector<std::vector<int>> l_mat(row);
        std::vector<std::vector<int>> r_mat(row);
        for (int i = 0; i < row; ++i) {
            l_mat[i] = std::vector<int>(col);
            r_mat[i] = std::vector<int>(col);
        }


        /* sets the values for each matrix */
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

        /* add the output to string.
         * taking minimum value, calculate module % 2 and choosing the matching symbol at once to avoid making third matrix
         * */
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


