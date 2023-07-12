#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    int n;
    cin >> n;
    int *arr = new int[n];
    
    
    for(int i =0; i < n; i++){
        int a;
        cin >> a;
        
        arr[i] = a;
    }
    
    int j = n-1;
    
    while (j >=0){
        cout << arr[j] << " ";
        j--;
    }
    
    
    return 0;
}