#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5;
vector<int> adj[N+1];
bool visited[N+1];

void dfs(int s){
    visited[s] = true;
    printf("%d ", s);
    for(auto u:adj[s]){
        if(!visited[u])
            dfs(u);
    }
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(3);

    adj[3].push_back(2);
    adj[3].push_back(5);

    adj[5].push_back(2);
    adj[5].push_back(3);
    dfs(1);
}

