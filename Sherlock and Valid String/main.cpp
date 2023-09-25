#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'isValid' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {

    vector<int> alpha(26,0);
    
    for(int i =0;i<s.length();i++) {
        int c = s[i]-'a';
        alpha[c]++;
    }
    
    bool oneTimeRemove = false;
    
    int prev = alpha[0];
    
    for(int i = 1;i<alpha.size();i++) {
        if(alpha[i]!=0) {
            if(alpha[i]!=prev && !oneTimeRemove) {
                oneTimeRemove= true;
                continue;
            }
            else if(alpha[i]!=prev && oneTimeRemove) {
                return "NO";
            }
            prev = alpha[i];
        }
    }
    return "YES";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = isValid(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
