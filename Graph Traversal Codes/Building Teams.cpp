/*
There are n pupils in Uolevi's class, and m friendships between them. Your task is to divide the pupils into two teams in such a 
way that no two pupils in a team are friends. You can freely choose the sizes of the teams.
Input
The first input line has two integers n and m: the number of pupils and friendships. The pupils are numbered 1,2,\dots,n.
Then, there are m lines describing the friendships. Each line has two integers a and b: pupils a and b are friends.
Every friendship is between two different pupils. You can assume that there is at most one friendship between any two pupils.
Output
Print an example of how to build the teams. For each pupil, print "1" or "2" depending on to which team the pupil will be assigned. 
You can print any valid team.
If there are no solutions, print "IMPOSSIBLE".
Constraints

1 \le n \le 10^5
1 \le m \le 2 \cdot 10^5
1 \le a,b \le n

Example
Input:
5 3
1 2
1 3
4 5

Output:
1 2 2 1 2
*/

#include <bits/stdc++.h>
using namespace std; // n: #of rows,,,, m: #of columns
int n, m;
vector<int>* grid;
int* visited;
char* color;

bool dfs(int s, char c){
    visited[s] = true;
    color[s] = c;
    c = c == 'R' ? 'B':'R';
    for(auto u:grid[s]){
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
    for(int s=1 ; s<=n ; s++){
        if(!visited[s] && !dfs(s,'B'))
            return false;
    }
    return true;
}

int main(){
    scanf("%d %d", &n, &m);
    grid = new vector<int>[n+1];
    for(int i=0 ; i< m ; i++){
        int a,b;
        scanf("%d %d", &a, &b);
        grid[a].push_back(b);
        grid[b].push_back(a);
    }
    visited = new int[n+1](); //notice the brackets here for -initialization
    color = new char[n+1];

    if(!is_bipartite()) cout<<"IMPOSSIBLE";
    else{
        for(int i=1 ; i<=n ; i++){
            if(color[i] == 'B') cout<<"1 ";
            else if(color[i] == 'R') cout<<"2 ";
        }
    }
}
