//Nash Steed _ Apr 28 _ "puzzle8.h" _ ucq8hz

#ifndef PUZZLE8_H
#define PUZZLE8_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class puzzleeight {
public:
    int BFSearch(vector<string> v, int m);
    bool isSolvable(string s);
    vector<string> generateNeighbors(string s);
    string puzzleToString(char p[3][3]);
    vector<char> stringToVector(string s);
    string vectorToString(vector<char> v);
private:
};


#endif