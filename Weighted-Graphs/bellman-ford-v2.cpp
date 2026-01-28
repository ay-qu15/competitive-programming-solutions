#include <bits/stdc++.h>
using namespace std;

const int N = 8;

vector<pair<int,int>> adj [N+1];

void bellmanFord(int start) {
    vector<int> distance(N+1, INT_MAX); 
    queue<int> q; 
    vector<bool> onQ(N+1, false);

    distance[start] = 0;
    q.push(start);
    onQ[start] = true;
    while(!q.empty()){
        int a = q.front();
        q.pop();
        onQ[a] = false;
        for(auto u: adj[a]){
            int b = u.first, w = u.second;
            if (distance[a]+w < distance[b]){   
                distance[b] = distance[a] + w;
                if(!onQ[b]){
                    q.push(b);
                    onQ[b] = true;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        cout << "vertex " << i << " has distance " << distance[i] << endl; 
} 
 
int main(){

    adj[1].push_back({2,5});
    adj[1].push_back({5,9});
    adj[1].push_back({8,8});
    adj[2].push_back({3,12});
    adj[2].push_back({4,15});
    adj[2].push_back({8,4});
    adj[3].push_back({4,3});
    adj[3].push_back({7,11});
    adj[4].push_back({7,9});
    adj[5].push_back({6,4});
    adj[5].push_back({7,20});
    adj[5].push_back({8,5});
    adj[6].push_back({3,1});
    adj[6].push_back({7,13});
    adj[8].push_back({6,6});
    adj[8].push_back({3,7});

    bellmanFord(1);

}