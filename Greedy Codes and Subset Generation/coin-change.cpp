#include <bits/stdc++.h>
using namespace std;

enum Currency {DOLLAR=100, FIFTY=50, QUARTER=25, TEN=10, FIVE=5, PENNY=1};

vector<Currency> makeChange(double amount){
   vector<Currency> coins;
   while(amount>0){
      if(amount >= 1.0){
         coins.push_back(DOLLAR);
         amount -= 1.0;
      } else if(amount >= 0.5){
         coins.push_back(FIFTY);
         amount -= 0.5;
      } else if(amount >= 0.25){
         coins.push_back(QUARTER);
         amount -= 0.25;
      } else if(amount >= 0.1){
         coins.push_back(TEN);
         amount -= 0.1;
      } else if(amount >= 0.05){
         coins.push_back(FIVE);
         amount -= 0.05;
      } else{
         coins.push_back(PENNY);
         amount -= 0.01;
      }
   }
   return coins;   
}

int main() {
   vector<Currency> coins = makeChange(2.77);
   for(Currency coin: coins) 
      cout << coin << " ";
   return 0;

}

