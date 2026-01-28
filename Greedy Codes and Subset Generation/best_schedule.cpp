#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct event
{
    int start;
    int end;
};

bool eventComparator(event a, event b) {
    return a.end < b.end;
}

int best_schedule(vector<event> events) {
    sort(events.begin(), events.end(), eventComparator);
    int cnt = 0;
    event current;
    for (event e : events) {
        if (cnt == 0 || e.start >= current.end) {
            current = e;
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    vector<event> events;
    events.push_back({1,3});   // event A
    events.push_back({2,5});   // event B
    events.push_back({3,9});   // event C
    events.push_back({6,8});   // event D
    int cnt = best_schedule(events);
    cout << cnt << endl;
}