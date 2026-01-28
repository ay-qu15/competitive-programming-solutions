/*
A factory has n machines which can be used to make products. Your goal is to make a total of t products.
For each machine, you know the number of seconds it needs to make a single product. The machines can work simultaneously, and you can freely decide their schedule.
What is the shortest time needed to make t products?
Input
The first input line has two integers n and t: the number of machines and products.
The next line has n integers k_1,k_2,\dots,k_n: the time needed to make a product using each machine.
Output
Print one integer: the minimum time needed to make t products.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le t \le 10^9
1 \le k_i \le 10^9

Example
Input:
3 7
3 2 5

Output:
8

Explanation: Machine 1 makes two products, machine 2 makes four products and machine 3 makes one product.
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll; //n: #of machines,,, t: #of products.
int n;
ll t;
vector<ll> pt;
 
ll min_time(){
    ll lo = 0, hi = *min_element(pt.begin(), pt.end()) * t;
    while(lo<hi){
        ll mid = (lo+hi)/2;
        ll prod = 0;
        for(ll p:pt){
            prod += mid/p;
            if(prod >= t) break;
        }
        if(prod >= t) hi = mid;
        else lo = mid+1;
    }
    return lo;
}
 
int main(){
    scanf("%d %lld", &n, &t);
    pt.resize(n);
    for(int i=0 ; i<n ; i++) scanf("%lld", &pt[i]);
    printf("%lld", min_time());
}


