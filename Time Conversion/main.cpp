#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    char lastSecond = s[s.size()-2];
    string hour = (s.substr(0,2));
    int h = stoi(hour);
    string minute = (s.substr(3,5));
    if (lastSecond=='P') {
        if(hour != "12") {
            h+=12;
        }
        string time = to_string(h)+":"+(minute);
        return time;
            
        
    }
    else {
        if (hour =="12") {
            string time = "00:"+(minute);
            return time;
        }
        string time = hour+":"+minute;
        return time;
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
