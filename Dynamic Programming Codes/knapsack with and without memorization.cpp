#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> v = {100,70,50,10};
vector<int> w = {10,4,6,12};
const int s = 20;
const int n = 4;
int dp[n][s];
int cnt=0;

int solve(int k, int remW){
    cnt++;
    if(k==n || remW <= 0) return 0;
    if(dp[k][remW] != -1) return dp[k][remW];

    int ans=0;
    if(w[k] > remW) ans = solve(k+1,remW);
    else{
        ans = max(v[k]+solve(k+1,remW-w[k]), solve(k+1,remW));
    }
    dp[k][remW] = ans;
    return ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    printf("%d\n", solve(0,s));
    printf("%d", cnt);
}

//without memorization
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> v = {100,70,50,10};
vector<int> w = {10,4,6,12};
const int s = 20;
const int n = 4;
int cnt=0;

int solve(int k, int remW){
    cnt++;
    if(k==n || remW <= 0) return 0;
    if(w[k] > remW) return solve(k+1,remW);
    else{
        return max(v[k]+solve(k+1,remW-w[k]), solve(k+1,remW));
    }
}
int main(){
    printf("%d\n", solve(0,s));
    printf("%d", cnt);
}
*/


