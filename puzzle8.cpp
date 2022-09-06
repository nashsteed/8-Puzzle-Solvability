//Nash Steed _ ucq8hz _ Apr 28 2022 _ "puzzle8.cpp"
#include <iostream>
#include "puzzle8.h"
#include <vector>
#include <string>
#include <iostream>
// file I/O
#include <fstream>
#include <unordered_map>
// cstdlib is where exit() lives
#include <cstdlib> 
using namespace std;
 unordered_map<string,int> checked;

int BFSearch(vector<string> v, int m);
bool isSolvable(string s);
vector<string> generateNeighbors(string s);
vector<char> stringToVector(string s);
string vectorToString(vector<char> v);

/**
 * @brief solves puzzle and prints the minimum numbers of moves
 * @author Nash Steed
 * @date April 28 2022
 * This finds the shortest number of moves to solve the puzzle
 *
 * 
 */

int main(int argc, char** argv) {
   
   cout << "Enter puzzle" << endl;
   string s;
   char g;
   for (int i=0;i<9;i++){
    cin >> g;
    s+=g;
   }
   if(!(isSolvable(s))){
    cout<< "IMPOSSIBLE" << endl;
    exit(-1);
   }
   vector<string> v2 = generateNeighbors(s);
   for(int i=0;i<v2.size();i++){
    //cout<< v2[i] << endl;
   }
   cout << "Solving puzzle" << endl;
   vector<string> v;
   v.push_back(s);
   int moves = BFSearch(v,1);
   cout << moves << endl;
   return 0;
}
/**
 * @brief do breadth first search
 *
 * This finds the shortest number of moves to solve the puzzle
 *
 * @return int
 * @param v size vector of strings to search on
 * @param m number of moves
 */
int BFSearch(vector<string> v, int m){
    vector<string> v2;
    for(int i=0;i<v.size();i++){
        checked[v[i]]=1;
    }
    for(int i=0;i<v.size();i++){
        vector<string> dum = generateNeighbors(v[i]);
        for(int j=0;j<dum.size();j++){
            if(checked.find(dum[j])==checked.end()){
                v2.push_back(dum[j]);
            }
        }
    }
    for(int n=0; n<v2.size(); n++){
        if(v2[n]=="123456780"){
            return m;
        }
    }
    return BFSearch(v2,m+1);
}
/**
 * @brief checks if puzzle is possible
 *
 *
 * @return bool
 * @param s string of puzzle
 */
bool isSolvable(string s){
    int inv = 0;
    for(int i = 0; i<9; i++){
       for(int j = i+1; j<9; j++) {
            if(!(s.at(i)=='0'||(s.at(j)=='0'))){
            if(s.at(i)>s.at(j)){
                inv++;
            }
        }
       }
    }
    if (inv%2==0){
        return true;
    }
    else{
        return false;
    }
}
/**
 * @brief generates neighbors of puzzle
 *
 * takes in string and returns neighbors
 *
 * @return vector<string>
 * @param s string puzzle
 */
vector<string> generateNeighbors(string s){
    int zero = 0;
    vector<string> v;
    string add ="";
    for(int i=0;i<9;i++){
        if(s.at(i)=='0'){
            zero = i;
        }
    }
    if(!(zero==2 || zero==5 || zero==8)){
        vector<char> r = stringToVector(s);
        r[zero]=r[zero+1];
        r[zero+1]='0';
        add = vectorToString(r);
        v.push_back(add);
    }
    if(!(zero==0 || zero==3 || zero==6)){
        vector<char> r1 = stringToVector(s);
        r1[zero]=r1[zero-1];
        r1[zero-1]='0';
        add = vectorToString(r1);
        v.push_back(add);
    }
    if(!(zero==6 || zero==7 || zero==8)){
        vector<char> r2 = stringToVector(s);
        r2[zero]=r2[zero+3];
        r2[zero+3]='0';
        add = vectorToString(r2);
        v.push_back(add);
    }
    if(!(zero==0 || zero==1 || zero==2)){
        vector<char> r3 = stringToVector(s);
        r3[zero]=r3[zero-3];
        r3[zero-3]='0';
        add = vectorToString(r3);
        v.push_back(add);
    }
    return v;
}
/**
 * @brief converts string to vector
 *
 *
 * @return vector<char>
 * @param s string puzzle
 */
vector<char> stringToVector(string s){
    vector<char> v;
    for(int i=0; i<9;i++){
        v.push_back(s.at(i));
    }
    return v;
}
/**
 * @brief converts vector to string
 *
 *
 * @return string
 * @param v vector of chars
 */
string vectorToString(vector<char> v){
    string s = "";
    for(int i=0;i<9;i++){
        s+=v[i];
    }
    return s;
}
