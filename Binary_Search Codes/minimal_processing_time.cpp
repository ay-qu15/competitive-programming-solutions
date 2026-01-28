#include <iostream>
#include <vector>
using namespace std;

vector<int> processing_times;
int k;  // number of jobs
int n;  // number of machines

bool valid(int x) {
    int t = 0;
    for (int p : processing_times)
        t += x / p;
    return t >= k;
}

int minimum_time(int z) {
    int x = -1;
    for (int b = z; b >= 1; b /= 2) {
        while (!valid(x + b))
            x += b;
    }
    return x + 1;
}


int main()
{
    k = 8;
    n = 3;
    processing_times.assign({2,3,7}); 

    int z = 2 * 8;    // initial solution 
    
    cout << minimum_time(z) << endl;
}