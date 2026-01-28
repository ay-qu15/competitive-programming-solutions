#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
map<int,int> dp;
ll cnt=0;

ll fibo(int n){
    int value[n+1];
    value[0] = 0;
    value[1] = 1;
    for(int x=2 ; x<=n ; x++){
        value[x] = value[x-1] + value[x-2];
    }
    return value[n];
}

int main(){
    printf("%d", fibo(2000));
}


//top down Solutions
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
map<int,int> dp;
ll cnt=0;
ll fibo(int n){
    cnt++;
    if(n==0) return 0;
    if(n==1) return 1;
    if(dp.find(n) != dp.end()) return dp[n];
    dp[n] = fibo(n-1) + fibo(n-2);
    return dp[n];
}
int main(){
   printf("%lld\n", fibo(2000)); //any number
   printf("%lld", cnt);
}
*/