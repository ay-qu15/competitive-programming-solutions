/*
Given an array of n integers, your task is to find the maximum sum of values in a contiguous, nonempty subarray.
Input
The first input line has an integer n: the size of the array.
The second line has n integers x_1,x_2,\dots,x_n: the array values.
Output
Print one integer: the maximum subarray sum.
Constraints

1 \le n \le 2 \cdot 10^5
-10^9 \le x_i \le 10^9

Example
Input:
8
-1 3 -2 5 3 -5 2 2

Output:
9
*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll solve(int n, vector<ll>& vec){
    ll current = vec[0];
    ll max_sum = vec[0];
    for (int i = 1; i < n; i++) {
        current = max(vec[i], current + vec[i]);
        max_sum = max(max_sum, current);
    }
    return max_sum;
}
 
int main() {
    int n;
    scanf("%d", &n);
 
    vector<ll> vec(n);
    for(int i=0 ; i<n ; i++) scanf("%lld", &vec[i]);
 
    printf("%lld", solve(n, vec));
    return 0;
}