#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5;
vector<int> adj[N+1];
bool visited[N+1];
char color[N+1];

bool dfs(int s, char c){
    visited[s] = true;
    color[s] = c;
    cout << s << " " << c << endl;
    c = c == 'R' ? 'B':'R';
    for(auto u:adj[s]){
        if(!visited[u]){
            if(!dfs(u,c))
                return false;
        }
        else if(color[u] == color[s])
            return false;
    }
    return true;
}

bool is_bipartite(){
    for(int s=1 ; s<=N ; s++){
        if(!visited[s] && !dfs(s,'B'))
            return false;
    }
    return true;
}

int main(){
    // Your existing graph building
    adj[1].push_back(2); 
    adj[1].push_back(4);

    adj[2].push_back(1); 
    adj[2].push_back(5); 
    adj[2].push_back(3);

    adj[3].push_back(2); // Removed edge to 5 to make it bipartite

    adj[4].push_back(1);
    adj[5].push_back(2);

    is_bipartite();
    
    return 0;
}


