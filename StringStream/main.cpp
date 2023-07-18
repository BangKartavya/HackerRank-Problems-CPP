#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	// Complete this function
    vector<int> ints;
    
    stringstream ss(str);
    char ch;
    int a;
    
    while(!ss.eof()){
        ss >> a >> ch;
        ints.push_back(a);
    }
    
    return ints;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
