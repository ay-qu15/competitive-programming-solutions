/*
You are given a map of a building, and your task is to count the number of its rooms. The size of the map is n \times m squares, and each square is either floor or wall. You can walk left, right, up, and down through the floor squares.
Input
The first input line has two integers n and m: the height and width of the map.
Then there are n lines of m characters describing the map. Each character is either . (floor) or # (wall).
Output
Print one integer: the number of rooms.
Constraints

1 \le n,m \le 1000

Example
Input:
5 8
########
#..#...#
####.#.#
#..#...#
########

Output:
3
*/

#include <bits/stdc++.h>
using namespace std;//n: #of rows,, m: #of columns
int n,m;
vector<string> grid;
vector<vector<bool>> visited;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x, int y){
    visited[x][y] = true;

    for(int d=0 ; d<4 ; d++){
        int nx = x + dx[d];
        int ny = y + dy[d];

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(grid[nx][ny] == '#') continue;
        if(visited[nx][ny]) continue;

        dfs(nx,ny);
    }
}

void cc(){
    int rooms=0;
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == '.' && !visited[i][j]){
                rooms++;
                dfs(i,j);
            }
        }
    }
    printf("%d", rooms);
}

int main(){
    cin >> n >> m;
    grid.resize(n);
    for(int i=0 ; i<n ; i++) cin >> grid[i];
    visited.assign(n,vector<bool>(m,false));
    cc();
}
