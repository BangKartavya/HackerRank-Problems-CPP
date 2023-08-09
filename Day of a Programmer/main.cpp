#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'dayOfProgrammer' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts INTEGER year as parameter.
 */

string dayOfProgrammer(int year) {
    // int n = 28;
    // if(year%4 == 0 && year%400==0) {
    //     n = 29;
    // }
    // int days[12] = {31,n,31,30,31,30,31,31,30,31,30,31};
    
    // int passed=0;
    
    // int sum = 0;
    
    // for(int i=0;i<12;i++) {
    //     if (sum+days[i] >=256) {
    //         break;
    //     }
    //     sum += days[i];
    //     passed++;
        
    // }
    // if(passed<10) {
    //     string date = 
    // }
    
    if(year==1918) {

        string date = "26.09."+to_string(year);
        return date;
    }
    
    if(year<1918) {
        if(year%4==0) {
            string date = "12.09."+to_string(year);
            return date;
        }
        else{
            string date = "13.09."+to_string(year);
            return date;
        }
    }
    
    if(year%400 == 0 ||  (year%100!=0 && year%4==0)) {
        string date = "12.09."+to_string(year);
        return date;
    }
    else{
        string date = "13.09."+to_string(year);
        return date;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

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
