#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  /* Enter your code here. Read input from STDIN. Print output to STDOUT */
  map<string, int> marks;

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    int x = 0; // y marks, x is the query type
    int y = 0;
    string z; // z student name

    cin >> x >> z;

    if (x == 1) {
      cin >> y;
      map<string, int>::iterator itr = marks.find(z);
      if (itr != marks.end()) {
        int mark = marks[z] + y;
        marks.erase(z);
        marks.insert(make_pair(z, mark));
      } else {
        marks.insert(make_pair(z, y));
      }
    } else if (x == 2) {
      marks.erase(z);
    } else if (x == 3) {
      map<string, int>::iterator itr = marks.find(z);

      if (itr != marks.end()) {
        cout << marks[z] << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }

  return 0;
}
