/*
Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two
or more other cities, and finally returns to the starting city. Every intermediate city on the route has to be distinct.
Input
The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
Every road is between two different cities, and there is at most one road between any two cities.
Output
First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print
any valid solution.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 6
1 3
1 2
5 3
1 5
2 4
4 5

Output:
4
3 5 1 3
*/

#include <bits/stdc++.h>
using namespace std; // n: #of cities,,,, m: #of roads
int n,m;
vector<int>* adj;
vector<int> current_path;
bool* visited;
int* parentNode;
 
bool dfs(int s, int parent) {
    visited[s] = true;
    parentNode[s] = parent;
 
    for(auto u: adj[s]) {
        if(!visited[u]) {
            if(dfs(u, s))
                return true;
        } 
        else if(u != parent) {
            // Found a cycle, reconstruct it
            current_path.push_back(u);
            int cur = s;
            while(cur != u) {
                current_path.push_back(cur);
                cur = parentNode[cur];
            }
            current_path.push_back(u); // close the cycle
            reverse(current_path.begin(), current_path.end());
            return true;
        }
    }
    return false;
}
 
bool is_cyclic(){
    for(int s=1 ; s<=n ; s++){
        if(!visited[s] && dfs(s,-1))
            return true;
    }
    return false;
}
 
int main(){
    scanf("%d %d", &n, &m);
    adj = new vector<int>[n+1];
    visited = new bool[n+1]();
    parentNode = new int[n+1]();
 
    for(int i=0 ; i<m ; i++){
        int x,y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
 
    if(!is_cyclic()){
        printf("IMPOSSIBLE");
    }
    else{
        printf("%d\n", current_path.size());
        for(auto u: current_path) printf("%d ", u);
    }
}
