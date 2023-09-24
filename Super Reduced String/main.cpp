#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {

    string res = "";
    stack<char> st;
    
    for(int i =0;i<s.length();i++) {
        if(st.size()==0) st.push(s[i]);
        else if(st.top()==s[i]) st.pop();
        else st.push(s[i]);
    }
    
    while(st.size()!=0) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(),res.end());
    
    if(res.size()==0) return "Empty String";
    return res;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
