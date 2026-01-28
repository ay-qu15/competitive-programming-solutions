/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to produce a sum of money x
using the available coins in such a way that the number of coins is minimal.
For example, if the coins are \{1,5,7\} and the desired sum is 11, an optimal solution is 5+5+1 which requires 3 coins.
Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the minimum number of coins. If it is not possible to produce the desired sum, print -1.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 11
1 5 7

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
int n,x;
vector<int> coins;
vector<int> dp;
const int INF = 1e9;

int solve(int sum){
    if(sum == 0) return 0;
    if(sum < 0) return INF;
    if(dp[sum] != -1) return dp[sum];

    int best = INF;
    for(int c : coins){
        best = min(best, 1 + solve(sum - c));
    }

    return dp[sum] = best;
}

int main(){
    scanf("%d %d", &n, &x);
    coins.resize(n);
    for(int i=0 ; i<n ; i++) scanf("%d", &coins[i]);

    dp.assign(x+1,-1);
    int ans = solve(x);
    printf("%d", ans >= INF ? -1 : ans);
}

