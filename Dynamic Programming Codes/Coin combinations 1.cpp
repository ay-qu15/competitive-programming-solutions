/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number
of distinct ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 8 ways:

2+2+5
2+5+2
5+2+2
3+3+3
2+2+2+3
2+2+3+2
2+3+2+2
3+2+2+2

Input
The first input line has two integers n and x: the number of coins and the desired sum of money.
The second line has n distinct integers c_1,c_2,\dots,c_n: the value of each coin.
Output
Print one integer: the number of ways modulo 10^9+7.
Constraints

1 \le n \le 100
1 \le x \le 10^6
1 \le c_i \le 10^6

Example
Input:
3 9
2 3 5

Output:
8
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+7; 
int n,x;
vector<int> coins;
vector<int> dp;

int solve(int sum){
    if(sum == x) return 1;
    if(sum > x) return 0;
    if(dp[sum] != -1) return dp[sum];

    int ways = 0;
    for(int i=0 ; i<coins.size() ; i++){
        ways = (ways + solve(sum + coins[i]))%M;
    }
    dp[sum] = ways;
    return ways;
}

int main(){
    scanf("%d %d", &n, &x);
    coins.resize(n);
    for(int i=0 ; i<n ; i++) scanf("%d", &coins[i]);

    dp.assign(x+1,-1);
    printf("%d", solve(0));
}

