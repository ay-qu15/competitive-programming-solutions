#include <iostream>
#include <vector>
using namespace std;

void generate (int k, int n, vector<int> s){
    if(k == n){
        for(int i=0; i<s.size(); i++)
            cout << s[i] << " ";
        cout << endl;    
        return;
    }
    s.push_back(k); 		// include k in the subset
    generate(k+1, n, s);
    s.pop_back();			 // do not include k in the subset
    generate(k+1, n, s);
}



int main()
{
    int n = 3;   // chnage n to any value you want
    vector<int> s;
    generate(0, n, s); 
    return 0;
}