#include <iostream>
#include <iomanip> 
using namespace std;

int main() {
	int T; cin >> T;
	cout << setiosflags(ios::uppercase);
	cout << setw(0xf) << internal;
	while(T--) {
		double A; cin >> A;
		double B; cin >> B;
		double C; cin >> C;
        cout << nouppercase;
        cout  << left << hex << showbase << static_cast<long long>(A) << endl;
        cout << dec;
        cout << showpos << setw(15) << setfill('_') << right << fixed << setprecision(2) << B << endl;
        cout << uppercase;
        cout << noshowpos << setprecision(9) << scientific << C << endl; 
		/* Enter your code here */

	}
	return 0;

}