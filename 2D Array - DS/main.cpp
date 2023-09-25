#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'hourglassSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY arr as parameter.
 */

int sumOfUpperNeighbours(int core_y,int core_x,vector<vector<int>> arr) {
    int sum = 0;
    
    int leftmostCoor = core_x-1;
    int rightmostCoor = core_x+1;
    int uppermostCoor = core_y-1;
    
    sum+=arr[uppermostCoor][leftmostCoor];
    sum+=arr[uppermostCoor][core_x];
    sum+=arr[uppermostCoor][rightmostCoor];
    
    return sum;
}

int sumOfLowerNeighbours(int core_y,int core_x,vector<vector<int>> arr) {
    int sum = 0;
    
    int leftmostCoor = core_x-1;
    int rightmostCoor = core_x+1;
    int LowermostCoor = core_y+1;
    
    sum+=arr[LowermostCoor][leftmostCoor];
    sum+=arr[LowermostCoor][core_x];
    sum+=arr[LowermostCoor][rightmostCoor];
    
    return sum;
}

int hourglassSum(vector<vector<int>> arr) {

    set<int> hourglass_sum;

    for(int i =1;i<5;i++) {
        int sum = 0;
        
        for(int j =1;j<5;j++) {
           sum+=arr[i][j];
           sum+=sumOfUpperNeighbours(i, j, arr); 
           sum+=sumOfLowerNeighbours(i, j, arr); 
           hourglass_sum.insert(sum);
           sum=0;
        }
    }
    
    return *hourglass_sum.rbegin();

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> arr(6);

    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < 6; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = hourglassSum(arr);

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
