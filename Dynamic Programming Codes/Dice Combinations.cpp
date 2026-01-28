/*
Your task is to count the number of ways to construct sum n by throwing a dice one or more times. Each throw produces an
outcome between 1 and  6.
For example, if n=3, there are 4 ways:

1+1+1
1+2
2+1
3

Input
The only input line has an integer n.
Output
Print the number of ways modulo 10^9+7.
Constraints

1 \le n \le 10^6

Example
Input:
3

Output:
4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int M = 1e9+7;
vector<int> coins = {1,2,3,4,5,6};

ll solve(ll n){
    ll value[n+1];
    value[0] = 1;

    for(int x=1 ; x<=n ; x++){
        value[x] = 0;
        for(auto c:coins){
            if(x-c >= 0)
                value[x] = (value[x] + value[x-c])%M; 
        }
    }
    return value[n];
}

int main(){
    ll n;
    scanf("%lld", &n);
    printf("%lld", solve(n));
}

//top down Solution

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int M = 1e9+7;
ll n;
vector<ll> dp;
 
ll solve(ll sum){
    if(sum == n) return 1;
    if(sum > n) return 0;
    if(dp[sum] != -1) return dp[sum];
 
    ll ways = 0;
    for(int i=1 ; i<=6 ; i++){
        ways = (ways + solve(sum+i))%M;
    }
    dp[sum] = ways;
    return ways;
}
 
int main(){
    scanf("%lld", &n);
    dp.assign(n+1,-1);
    printf("%lld", solve(0));
}
*/