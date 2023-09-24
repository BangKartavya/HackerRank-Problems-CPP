#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'minimumNumber' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. STRING password
 */

int minimumNumber(int n, string password) {
    // Return the minimum number of characters to make the password strong
    
    string numbers = "0123456789";
    string lower_case = "abcdefghijklmnopqrstuvwxyz";
    string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string special_characters = "!@#$%^&*()-+";
    
    int numC = 0;
    int lowC = 0;
    int uppC = 0;
    int speC = 0;
    
    for(int i=0;i<n;i++) {
        auto it = find(numbers.begin(),numbers.end(),password[i]);
        
        if(it!=numbers.end()) {
            numC++;
        }
        it= find(lower_case.begin(),lower_case.end(),password[i]);
        
        if(it!=lower_case.end()) {
            lowC++;
        }
        it= find(upper_case.begin(),upper_case.end(),password[i]);
        
        if(it!=upper_case.end()) {
            uppC++;
        }
        it= find(special_characters.begin(),special_characters.end(),password[i]);
        
        if(it!=special_characters.end()) {
            speC++;
        }
        
    }
    int count =0;
    
    if(numC==0) {
        count++;
    }
    if(lowC==0) {
        count++;
    }
    if(uppC==0) {
        count++;
    }
    if(speC==0) {
        count++;
    }
    
    if(n<6 && n+count<6) {
        count+=6-n-count;
    }
    
    return count;
    
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string password;
    getline(cin, password);

    int answer = minimumNumber(n, password);

    fout << answer << "\n";

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
