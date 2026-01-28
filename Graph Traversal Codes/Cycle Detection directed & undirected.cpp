#include <bits/stdc++.h> //directed graphs only
using namespace std;
typedef long long ll;
const int N = 5;
vector<int> adj[N+1];
bool visited[N+1];
set<int> current_path;

bool dfs(int s){
    if(current_path.find(s) != current_path.end()) return true;
    if(visited[s]) return false;

    visited[s] = true;
    current_path.insert(s);
    for(auto u:adj[s]){
        if(dfs(s))
            return true;     
    }
    current_path.erase(s);
    return false;
}

bool is_cylic(){
    for(int s=1 ; s<=N ; s++){
        if(!visited[s] && dfs(s))
            return true;
    }
    return false;
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

    adj[4].push_back(1);
    adj[5].push_back(2);
    adj[5].push_back(3);
    
    cout<<is_cylic();
    return 0;
}

//undirected graphs cycle detection :
/*
#include <bits/stdc++.h>
using namespace std;

const int N = 5;
vector<int> adj[N+1];
bool visited[N+1];

bool dfs(int v, int parent){
    visited[v] = true;

    for(auto u : adj[v]){
        if(!visited[u]){
            if(dfs(u, v)) return true;
        } else if(u != parent){
            // visited and not parent => cycle
            return true;
        }
    }
    return false;
}

bool is_cyclic(){
    for(int v=1; v<=N; v++){
        if(!visited[v]){
            if(dfs(v, -1)) return true;
        }
    }
    return false;
}

int main(){
    adj[1].push_back(2);
    adj[1].push_back(4);
    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(5);
    adj[4].push_back(1);
    adj[5].push_back(2);
    adj[5].push_back(3);

    cout << is_cyclic();
}

*/
