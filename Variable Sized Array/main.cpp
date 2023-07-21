#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n;
    int q;
    
    cin >> n >> q;
    
    int **a = new int*[n];
    vector<vector<int>> nums(n);
    
    for (int i = 0; i < n; ++i) {
        int k;
        cin >> k;
        nums[i] = vector<int>(k);
        a[i] = new int[k];
        for (int j = 0; j < k; ++j) {
            cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << a[l][r] << endl;
    }
    
    return 0;
}
