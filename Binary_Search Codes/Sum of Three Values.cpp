/*
You are given an array of n integers, and your task is to find three values (at distinct positions) whose sum is x.
Input
The first input line has two integers n and x: the array size and the target sum.
The second line has n integers a_1,a_2,\dots,a_n: the array values.
Output
Print three integers: the positions of the values. If there are several solutions, you may print any of them. If there are no solutions, print IMPOSSIBLE.
Constraints

1 \le n \le 5000
1 \le x,a_i \le 10^9

Example
Input:
4 8
2 7 5 1

Output:
1 3 4
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,int>> v;
int n;
ll x;
 
void solve(){
    sort(v.begin(), v.end());
    for(int i=0 ; i<n ; i++){
        ll target = x - v[i].first;
        int l = i+1, r = n-1;
        while(l < r){
            ll sum = v[l].first + v[r].first;
            if(sum == target){
                printf("%d %d %d", v[i].second, v[l].second, v[r].second);
                return;
            }
            else if(sum < target) l++;
            else r--;
        }
    }   
    printf("IMPOSSIBLE");
}
int main() {
    
    scanf("%d %lld", &n, &x);
    v.resize(n);
    for(int i=0 ; i< n ;i++) {
        scanf("%lld", &v[i].first);
        v[i].second = i+1;
    }
    solve();
}
