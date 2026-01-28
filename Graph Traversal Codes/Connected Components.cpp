#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5;
vector<int> adj[N+1];
bool visited[N+1];
int id[N+1];
int cnt=0;

void dfs(int s){
    visited[s] = true;
    id[s] = cnt;
    for(auto u:adj[s]){
        if(!visited[u])
            dfs(u);
    }
}

void cc(){
    for(int s=1 ; s<=N ; s++){
        if(!visited[s]){
            dfs(s);
            cnt++;
        }
    }
}

int main(){
    // Your existing graph building
    adj[1].push_back(2);
    adj[1].push_back(4);

    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(3);

    adj[3].push_back(2);
    adj[3].push_back(5);

    adj[5].push_back(2);
    adj[5].push_back(3);

    // Run the connected components logic
    cc();

    // PRINT THE IDS HERE
    cout << "Node IDs (Connected Components):" << endl;
    for(int i = 1; i <= N; i++){
        cout << "Node " << i << " has Component ID: " << id[i] << endl;
    }

    return 0;
}


