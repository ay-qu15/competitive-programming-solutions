#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct task
{
    int duration;
    int deadline;
};

bool taskComparator(task a, task b) {
    return a.duration < b.duration;
}

int best_score(vector<task> tasks) {
    sort(tasks.begin(), tasks.end(), taskComparator);
    int score = 0;
    int current_time = 0;
    for (task e : tasks) {
        current_time += e.duration;
        score += (e.deadline - current_time);
    }
    return score;
}

int main()
{
    vector<task> tasks;
    tasks.push_back({4,2});     // task A
    tasks.push_back({3,10});    // task B
    tasks.push_back({2,8});     // task C
    tasks.push_back({4,15});    // task D
    int cnt = best_score(tasks);
    cout << cnt << endl;
}