#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'makingAnagrams' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

int makingAnagrams(string s1, string s2) {

    map<char,int> mp;
    int c = 0;
    
    for(int i = 0;i<s1.size();i++) {
        mp[s1[i]]++;
    }
    for(int i =0;i<s2.size();i++) {
        mp[s2[i]]--;
    }
    
    for(auto x: mp) {
        c+=abs(x.second);
    }
    return c;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = makingAnagrams(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
