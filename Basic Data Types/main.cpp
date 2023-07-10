#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main() {
    // Complete the code.
    
    int a;
    long b;
    char c;
    float d;
    double e;
    
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    
    cout << a <<endl;
    cout << b << endl;
    cout << c <<endl;
    
    cout << setprecision(3) << fixed << d << endl;
    
    cout << setprecision(9) << fixed << e << endl;
    
    return 0;
}