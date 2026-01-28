/*
Consider a money system consisting of n coins. Each coin has a positive integer value. Your task is to calculate the number of distinct ordered ways you can produce a money sum x using the available coins.
For example, if the coins are \{2,3,5\} and the desired sum is 9, there are 3 ways:

2+2+5
3+3+3
2+2+2+3

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
3
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M = 1e9+7; 
int n,x;
vector<int> coins;

ll solve(int n){
    vector<int> value(n+1,0);
    value[0] = 1;

    for(auto c:coins){
        for(int x=c ; x<=n ; x++){
            value[x] = (value[x] + value[x-c])%M;
        }
    }
    
    return value[n];
}

int main(){
    scanf("%d %d", &n, &x);
    coins.resize(n);
    for(int i=0 ; i<n ; i++) scanf("%d", &coins[i]);
    printf("%lld", solve(x));
}

