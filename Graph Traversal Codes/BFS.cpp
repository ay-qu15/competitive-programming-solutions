#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5;
vector<int> adj[N+1];

void bfs(int s){
    bool visited[N+1] = {false};
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        printf("%d ", x);
        for(auto u:adj[x]){
            if(visited[u]) continue;
            visited[u] = true;
            q.push(u);
        }
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
    bfs(1);
}

