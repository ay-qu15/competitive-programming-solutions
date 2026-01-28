#include <bits/stdc++.h>
using namespace std;

struct event
{
   bool isArrivalEvent;
   int time;
};

bool eventComparator(event a, event b){
   return a.time < b.time;
}

int maximum(vector<event> events){
   sort(events.begin(), events.end(), eventComparator);
   int maxNumOfCustomers = 0;
   int numOfCustomers = 0;
   for(event e: events){
      if(e.isArrivalEvent){
         numOfCustomers++;
         maxNumOfCustomers = max(maxNumOfCustomers,numOfCustomers);
      }else{
         numOfCustomers--;
      }
   }
   return maxNumOfCustomers;
}


int main() {
   
   vector<event> events;
   int n;
   cin>>n;
   while(n-->0){
      int a,b;
      cin >> a >> b;
      event arrival, departure;
      arrival.time = a; arrival.isArrivalEvent = true;
      departure.time = b; departure.isArrivalEvent = false;
      events.push_back(arrival);
      events.push_back(departure);
   }

   cout << maximum(events);
}

