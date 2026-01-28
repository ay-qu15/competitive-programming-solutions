/*
You are given a map of a labyrinth, and your task is to find a path from start to end. You can walk left, right, up and down.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the labyrinth. Each character is . (floor), # (wall), A (start), or B (end). 
There is exactly one A and one B in the input.
Output
First print "YES", if there is a path, and "NO" otherwise.
If there is a path, print the length of the shortest such path and its description as a string consisting of characters
L (left), R (right), U (up), and D (down). You can print any valid solution.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#.A#...#
#.##.#B#
#......#
########

Output:
YES
9
LDDRRRRRU
*/

#include <bits/stdc++.h>
using namespace std; // n: #of rows,,,, m: #of columns
int n, m;
int startX = -1, startY = -1;
int endX = -1, endY = -1;
vector<string> grid;
vector<vector<bool>> visited;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
 
void bfs(int x, int y){
    queue<pair<int,int>> q;
    vector<vector<char>> parent(n, vector<char>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    visited[x][y] = true;
    dist[x][y] = 0;
    q.push({x,y});
 
    while(!q.empty()){
        pair<int,int> current = q.front();
        q.pop();
 
        int cx = current.first;
        int cy = current.second;
 
        if(cx == endX && cy == endY) break;
 
        for(int d=0 ; d<4 ; d++){
            int nx = cx + dx[d];
            int ny = cy + dy[d];
 
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (grid[nx][ny] == '#') continue;
            if (visited[nx][ny]) continue;
 
            visited[nx][ny] = true;
            dist[nx][ny] = dist[cx][cy] + 1;
 
            if (d == 0) parent[nx][ny] = 'D';
            if (d == 1) parent[nx][ny] = 'U';
            if (d == 2) parent[nx][ny] = 'R';
            if (d == 3) parent[nx][ny] = 'L';
 
            q.push({nx,ny});
        }
    }
 
    if(!visited[endX][endY]){
        printf("NO\n");
        return;
    }
    string path;
    int cx = endX, cy = endY;
 
    while (cx != startX || cy != startY) {
        char move = parent[cx][cy];
        path += move;
 
        // Move in the opposite direction of the parent to backtrack
        if (move == 'U') cx++;      // came from above → move down to backtrack
        else if (move == 'D') cx--; // came from below → move up to backtrack
        else if (move == 'L') cy++; // came from left → move right to backtrack
        else if (move == 'R') cy--; // came from right → move left to backtrack
    }
 
    reverse(path.begin(), path.end());
 
    cout << "YES\n";
    cout << path.size() << '\n'; // length of the path
    cout << path << '\n';        // sequence of moves
}
 
int main()
{
    cin >> n >> m;
    grid.resize(n);
    
    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
        if (startX == -1 || endX == -1 || startY == -1 || endY == -1)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 'A')
                {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] == 'B')
                {
                    endX = i;
                    endY = j;
                }
            }
        }
    }
    visited.assign(n, vector<bool>(m, false));
    bfs(startX, startY);
}
