#include <bits/stdc++.h>
using namespace std;

const int N = 8;
vector<pair<int,int>> adj [N+1];

void dijkstra(int start) {
    vector<int> distance(N+1, INT_MAX);    // initialize distances to +infinity
    vector<bool> processed(N+1, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    distance[start] = 0; 
    pq.push({0,start}); 
    while (!pq.empty()) {
        int a = pq.top().second; 
        pq.pop(); 
        if (processed[a]) continue; 
        processed[a] = true;
        for (auto u : adj[a]) {
            int b = u.first, weight = u.second;
            if (distance[a] + weight < distance[b]) {  
                distance[b] = distance[a] + weight;
                pq.push({distance[b],b});   // push the updated distance
            }
        }
    } 
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

    dijkstra(1);

}