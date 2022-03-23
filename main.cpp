#include <iostream>
#include "mat.hpp"
using namespace ariel;
using namespace std;

int main() {
    /* the only +$ I will get.... */
    cout << mat(33, 17, '$', '+') << endl;

    /* My algorithm will remind me to smile */
    string smiley;
    string left = ariel::mat(7,7,'.' ,'@');
    string right = ariel::mat(7,7, '.', '@');

    int blocks = 8;

    for (int i = 8; i < left.length() + right.length() - blocks*8; i+=blocks) {
        smiley += left.substr(i, blocks - 1);
        smiley += right.substr(i, blocks - 1);

        smiley += '\n';
    }
    smiley.at(33) = 'X';
    smiley.at(40) = 'X';

    smiley += "\n \\__________/ ";
    cout << smiley << endl;
}