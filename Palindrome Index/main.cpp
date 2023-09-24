#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'palindromeIndex' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING s as parameter.
 */

bool isPal(string s1) {
    string s2 = s1;
    reverse(s1.begin(),s1.end());
    
    
    if(s1==s2) return true;
    return false;
}

int palindromeIndex(string input) {

    int s,e;
    
    for(s=0,e=input.size()-1;s<e;s++,e--) {
        if(input[s]!=input[e]) break;
        
    }
    if(s>=e) return -1;
    string s1=input, s2 = input;
    
    s1.erase(s1.begin()+s);
    if(isPal(s1)) return s;
    s2.erase(s2.begin()+e);
    if(isPal(s2)) return e;
    return -1;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s;
        getline(cin, s);

        int result = palindromeIndex(s);

        fout << result << "\n";
    }

    fout.close();

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
