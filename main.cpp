#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
#include <cstring> 

int main(){
    string n = "name";
    string s ="sabrina";
    string ans = n +" " + s + " ";
    string hey;
    
    stringstream streamData(ans);
    getline(streamData, hey, ' ');
    cout << hey  << endl; 
    getline(streamData, hey, ' ');
    cout << hey  << endl; 
    cout << s.compare(0,7,"sabrina")  << endl;
}