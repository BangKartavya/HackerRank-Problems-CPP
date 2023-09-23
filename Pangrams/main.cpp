#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'pangrams' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string pangrams(string s) {

    string p = "";

    for(int i =0;i<s.size();i++) {
        p+=(char) tolower(s[i]);
    }

    string unique = "abcdefghijklmnopqrstuvwxyz";
    
    set<char> sup(p.begin(),p.end());
    
    for(int i =0;i<26;i++) {
        set<char>::iterator it = find(sup.begin(),sup.end(),unique[i]);
        
        if(it==sup.end()) return "not pangram";
    }
    return "pangram";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = pangrams(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
