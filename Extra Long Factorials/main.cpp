#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void extraLongFactorials(int n) {
 
    int value[500];
    int size;
    
    value[0] = 1;
    size = 1;
    
    for(int i =2;i<=n;i++) {
        int carry = 0;
        for(int j =0;j<size;j++) {
            int val = value[j]*i +carry;
            value[j] = val%10;
            carry = val/10;
        }
        while(carry) {
            value[size] = carry%10;
            carry /=10;
            size++;
        }
    }
    for(int i = size-1;i>=0;i--) {
        cout << value[i];
    }
    
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
