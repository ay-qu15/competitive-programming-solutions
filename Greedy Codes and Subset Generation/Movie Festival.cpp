/*
In a movie festival n movies will be shown. You know the starting and ending time of each movie. What is the maximum number of movies
you can watch entirely?

Input
The first input line has an integer n: the number of movies.
After this, there are n lines that describe the movies. Each line has two integers a and b: the starting and ending times of a movie.
Output
Print one integer: the maximum number of movies.
Constraints

1 \le n \le 2 \cdot 10^5
1 \le a < b \le 10^9

Example
Input:
3
3 5
4 9
5 8

Output:
2

*/


#include <bits/stdc++.h>
using namespace std;
 
struct event{
    int start;
    int end;
};
 
bool eventComparator(event a, event b){
    return a.end < b.end;
}
int schedule(vector<event>& events){
    sort(events.begin(),events.end(),eventComparator);
    event current = events[0];
    int cnt=0;
    for(event e:events){
        if(cnt==0 || e.start >= current.end){
            current = e;
            cnt++;
        }
    }
    return cnt;
}
int main() {
    int n;
    cin >>n;
 
    vector<event> events(n,{0,0});
    for(int i=0 ; i<n ; i++) cin >> events[i].start >> events[i].end;
    cout<<schedule(events);
 
 
    return 0;
}
