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

  sort(nums.begin(), nums.end());

  for (int j = 0; j < n; j++) {
    cout << nums[j] << " ";
  }
  cout << endl;
  return 0;
}
