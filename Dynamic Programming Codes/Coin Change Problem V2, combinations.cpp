#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> coins = {1,3,4};
const int n = 5;
const int Size = 3; //same as coins size
int cnt=0;


int solve(int k, int sum){ //combinations
    cnt++;
    if(sum == n) return 1;
    if(sum > n) return 0;
    if(k==coins.size()) return 0;
    
    return solve(k,sum+coins[k]) + solve(k+1,sum);
}

int main(){
    printf("%d\n", solve(0,0));
    printf("%d", cnt);
}

//with memorization
/* 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> coins = {1,3,4};
const int n = 5;
const int Size = 3; //same as coins size
int cnt=0;
int dp[Size][n];

int solve(int k, int sum){ //combinations
    cnt++;
    if(sum == n) return 1;
    if(sum > n) return 0;
    if(k==coins.size()) return 0;
    if(dp[k][sum] != -1) return dp[k][sum];
    
    dp[k][sum] = solve(k,sum+coins[k]) + solve(k+1,sum);
    return dp[k][sum];
}

int main(){
    memset(dp,-1,sizeof(dp));
    printf("%d\n", solve(0,0));
    printf("%d", cnt);
}
*/


//bottom up Solution

/*
#include <bits/stdc++.h> 
using namespace std;
typedef long long ll; 
vector<int> coins = {1,3,4};


int solve(int n){ //Combinations
    vector<int> value(n+1,0);
    value[0] = 1;

    for(auto c:coins){
        for(int x=c ; x<=n ; x++){
            value[x] += value[x-c];
        }
    }
    
    return value[n];
}

int main(){
    int n = 5;
    printf("%d\n", solve(n));
}
*/