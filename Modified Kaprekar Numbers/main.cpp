#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'kaprekarNumbers' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER p
 *  2. INTEGER q
 */

int getSum(long a){
    long sq = a * a;
    int digit = (int)log10(a) + 1;
    int result = sq % (int)pow(10, digit);
    int rest = (int)log10(sq) + 1 - digit;
    if(rest > 0) result += stoi(to_string(sq).substr(0, rest));
    return result;
}

void kaprekarNumbers(int p, int q) {
    bool valid_range = false;
    for(int i = p; i <= q; i++){
        int s = getSum(i);
        if(s == i){
           cout << i << " ";
           valid_range = true; 
        }  
    }
    if(!valid_range) cout << "INVALID RANGE";
}
int main()
{
    string p_temp;
    getline(cin, p_temp);

    int p = stoi(ltrim(rtrim(p_temp)));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    kaprekarNumbers(p, q);

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
