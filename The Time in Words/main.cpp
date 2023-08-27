#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'timeInWords' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. INTEGER h
 *  2. INTEGER m
 */

string timeInWords(int h, int m) {

    vector<string> ones = {
        "",
        "one ",
        "two ",
        "three ",
        "four ",
        "five ",
        "six ",
        "seven ",
        "eight ",
        "nine ",
        "ten ",
        "eleven ",
        "twelve ",
        "thirteen ",
        "fourteen ",
        "fifteen ",
        "sixteen ",
        "seventeen ",
        "eighteen ",
        "nineteen ",
    };
    
    vector<string> tens = {
        "",
        "",
        "twenty ",
        "thirty ",
        "forty ",
        "fifty ",
    };

    string time = "";
    
    if(m==0) {
        time = ones[h] + "o' clock";
    }
    
    if(m>=1 && m<=30) {
        
        if(m == 15) {
            time = "quarter past " + ones[h];
        }
        else if(m==30) {
            time = "half past "+ ones[h];
        }
        
        else if(m>19) {
            time = tens[m/10] + ones[m%10] + "minutes past " + ones[h]; 
        }
        else if (m==1) {
            time  = ones[m] + "minute past " + ones[h];
        }
        else {
            time  = ones[m] + "minutes past " + ones[h];
        }
    }
    else if(m>30) {
        
        if((60-m) == 15) {
            time = "quarter to " +ones[h+1];
        }
        
        else if(60-m > 19) {
            time = tens[(60-m)/10] + ones[(60-m)%10] + "minutes to " + ones[h+1];
        }
        else if(m==1) {
            time = ones[60-m] + "minute to " + ones[h+1];
        }
        else {
            time = ones[60-m] + "minutes to " + ones[h+1];
            
        }
    }
    
    fprintf(stderr,"%d %d",h,m);
    
    return time;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string h_temp;
    getline(cin, h_temp);

    int h = stoi(ltrim(rtrim(h_temp)));

    string m_temp;
    getline(cin, m_temp);

    int m = stoi(ltrim(rtrim(m_temp)));

    string result = timeInWords(h, m);

    fout << result << "\n";

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
