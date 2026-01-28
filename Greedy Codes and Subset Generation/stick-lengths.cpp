#include <bits/stdc++.h>
using namespace std;

long long cost(int n, vector<int> numbers){
   sort(numbers.begin(), numbers.end());
   int m = numbers[n/2];
   long long cost = 0;
   for(int e: numbers)
      cost += abs(e-m);
   return cost;   
}


int main() {
   
   vector<int> numbers;
   int n;
   cin >> n;
   for(int k=0; k<n; k++){
      int i;
      cin>>i;
      numbers.push_back(i);
   }
   cout << cost(n, numbers);
   return 0;
}

