#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'getTotalX' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER_ARRAY a
 *  2. INTEGER_ARRAY b
 */

int gcd(int a,int b) {
    if(b==0) return a;
    return gcd(b,a%b);
}

int lcm(int a,int b) {
    return a*b/gcd(a,b);
}

int main() {
    int n, m, e, l = 1, g = 0;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> e;
        l = lcm(l, e);
    }
    for(int i = 0; i < m; i++){
        cin >> e;
        g = gcd(g, e);
    }
    int res = 0;
    for(int c = l; c <= g; c+=l)if(g % c == 0) res ++;
    cout << res;
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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
