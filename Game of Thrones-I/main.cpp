#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'gameOfThrones' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string gameOfThrones(string s) {

    map<char,int> mp;
    
    int odd_counter = 0;
    
    for(int i =0;i<s.size();i++) {
        mp[s[i]]++;
    }
    
    for(auto x:mp) {
        if(x.second%2==1) {
            odd_counter++;
        }
    }
    
    if(s.size()%2==1 && odd_counter==1 || odd_counter==0) {
        return "YES";
    }
    return "NO";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = gameOfThrones(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
