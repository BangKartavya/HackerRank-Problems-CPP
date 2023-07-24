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

  int x;
  cin >> x;

  nums.erase(nums.begin() + x - 1);

  int y, z;
  cin >> y >> z;

  nums.erase(nums.begin() + y - 1, nums.begin() + z - 1);

  cout << nums.size() << endl;

  int remain = n - ((z - y) + 1);
  for (int j = 0; j < remain; j++) {
    cout << nums[j] << " ";
  }
  cout << endl;

  return 0;
}
