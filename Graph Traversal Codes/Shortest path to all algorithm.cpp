#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5;
vector<int> adj[N+1];

void bfs(int s) {
    bool visited[N+1] = {false};
    int distance[N+1];
    memset(distance, 0, sizeof(distance));
    queue<int> q;

    visited[s] = true;
    distance[s] = 0;
    q.push(s);

    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto u : adj[x]){
            if(visited[u]) continue;
            visited[u] = true;
            distance[u] = distance[x] + 1;
            q.push(u);
        }
    }

    // --- PLACE YOUR PRINT STATEMENTS HERE ---
    cout << "Distances from node " << s << ":" << endl;
    for(int i = 1; i <= N; i++){
        if(visited[i]) {
            cout << "Node " << i << ": " << distance[i] << endl;
        } else {
            cout << "Node " << i << ": Unreachable" << endl;
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

