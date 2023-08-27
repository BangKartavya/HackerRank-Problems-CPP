#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'biggerIsGreater' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING w as parameter.
 */

string biggerIsGreater(string w) {

    int flag = -1;
    
    for(int i =w.size()-1;i>=1;i--) {
        if(w[i]> w[i-1]) {
            flag = i-1;
            break;
        }
    }
    if(flag <0) {
        return "no answer";
    }
    
    int min = flag;
    
    for(int i=w.size()-1;i>flag;i--) {
        if(w[i] > w[flag]) {
            min = i;
            break;
        }
    }
    if (min == flag) {
        return "no answer";
    }
    
    char temp = w[flag];
    w[flag] = w[min];
    w[min] = temp;
    
    string result = "";
    
    for(int i =0;i<=flag;i++) {
        result+=w[i];
    }
    
    vector<char> to_sort;
    
    for(int i =flag+1;i<w.size();i++) {
        to_sort.push_back(w[i]);
    }
    
    sort(to_sort.begin(),to_sort.end());
    
    for(int i = 0;i<to_sort.size();i++) {
        result+=to_sort[i];
    }
    
    return result;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string T_temp;
    getline(cin, T_temp);

    int T = stoi(ltrim(rtrim(T_temp)));

    for (int T_itr = 0; T_itr < T; T_itr++) {
        string w;
        getline(cin, w);

        string result = biggerIsGreater(w);

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
