#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> coins = {1,3,4};
int n = 5;

int solve(int sum){ //permutations
    if(sum == n) return 1;
    if(sum > n) return 0;
    
    int ways = 0;
    for(int i=0 ; i<coins.size() ; i++){
        ways += solve(sum + coins[i]);
    }
    return ways;
}

int main(){
    printf("%d", solve(0));
}

//with memorization
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> coins = {1,3,4};
const int n = 5;
int cnt=0;
map<int,int> dp;

int solve(int sum){ //permutations
    cnt++;
    if(sum == n) return 1;
    if(sum > n) return 0;
    if(dp.find(sum) != dp.end()) return dp[sum];

    int ways = 0;
    for(int c:coins){
        ways += solve(sum+c);
    }
    dp[sum] = ways;
    return ways;
}

int main(){
    printf("%d\n", solve(0));
    printf("%d", cnt);
}
*/

//bottom up Solution

/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<int> coins = {1,3,4};


int solve(int n){ //permutations
    int value[n+1];
    value[0] = 1;

    for(int x=1 ; x<=n ; x++){
        value[x] = 0;
        for(auto c:coins){
            if(x-c >= 0)
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
