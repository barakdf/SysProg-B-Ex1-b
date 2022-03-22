//
// Created by barak on 22/03/2022.
//

#include <iostream>
#include "mat.hpp"

using namespace std;

int main() {
    string show;

    string left = ariel::mat(7,7,'.' ,'@');
    string right = ariel::mat(7,7, '.', '@');

    int blocks = 8;

    for (int i = 8; i < left.length() + right.length() - blocks*8; i+=blocks) {
        show += left.substr(i,blocks - 1);
        show += right.substr(i, blocks - 1);

        show += '\n';
    }
    show.at(33) = 'X';
    show.at(40) = 'X';

    show += "\n \\__________/ ";
    cout << show << endl;
}