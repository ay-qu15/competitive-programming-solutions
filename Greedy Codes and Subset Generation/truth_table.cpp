#include <iostream>
using namespace std;

void count(int k, int n, int a[]){
    if(k==n){
        for(int i=0; i<n; i++)
            cout << a[i] << " ";
        cout << endl;    
        return;
    }
    a[k] = 0; 
    count(k+1, n, a);
    a[k] = 1; 
    count(k+1, n, a);
}


int main()
{
    int n = 3;   // chnage n to any value you want
    int a[n];
    count(0, n, a); 
    return 0;
}