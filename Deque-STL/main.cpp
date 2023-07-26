#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  int n;
  cin >> n;

  vector<int> nums;

  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    nums.push_back(a);
  }
  int q;
  cin >> q;

  for (int j = 0; j < q; j++) {
    int search;
    cin >> search;
    bool found = binary_search(nums.begin(), nums.end(), search);
    vector<int>::iterator itr = lower_bound(nums.begin(), nums.end(), search);
    int pos = itr - nums.begin();
    if (found) {
      cout << "Yes " << pos + 1 << endl;
    } else {
      cout << "No " << pos + 1 << endl;
    }
  }

  return 0;
}
