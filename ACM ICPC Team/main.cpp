#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'acmTeam' function below.
 *
 * The function is expected to return an INTEGER_ARRAY.
 * The function accepts STRING_ARRAY topic as parameter.
 */

vector<int> acmTeam(vector<string> topic) {

    vector<int> answer;
    vector<int> subs;
    // vector<int> teams[topic.size()];
    int teams = 1;

    for(int i=0;i<(int)topic.size();i++) {
        for(int j =i+1;j<(int)topic.size();j++) {
            int teamSub = 0;
            for(int p1=0;p1<topic[i].size();p1++){
                
                if(topic[i][p1]=='1') {
                    teamSub++;
                }
                
                if(topic[i][p1]=='0') {
                    if(topic[j][p1] == '1') {
                        teamSub++;
                    }
                    else {
                        continue;
                    }
                    
                }
            }
            
            subs.push_back(teamSub);
        }
    }
    
    sort(subs.begin(),subs.end(),greater<int>());
    
    const int max = subs[0];
    
    for(int i =1;i<subs.size();i++) {
        if(subs[i] == max) {
            teams++;
        }
        else {
            break;
        }
    }
    
    answer.push_back(subs[0]);
    answer.push_back(teams);
    
    return answer;
    
    
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<string> topic(n);

    for (int i = 0; i < n; i++) {
        string topic_item;
        getline(cin, topic_item);

        topic[i] = topic_item;
    }

    vector<int> result = acmTeam(topic);

    for (size_t i = 0; i < result.size(); i++) {
        fout << result[i];

        if (i != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
