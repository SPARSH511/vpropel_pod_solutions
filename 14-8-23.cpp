/*
Problem:
Last two digits of series

Given total number of test cases and value of x,y.
Find the last 2 digits of the series:
Z=(1^y) + (2^y) + (3^y) + ..... + ( x^y)     
 
Here, (^) is power of that number,not xor
z=(1^y)+....+(x^y)
z=1 to the power of y till x to the power of y
INPUT:
test cases T
next T lines contains value of x,y
 
OUTPUT:
Print the last 2 digits of the series Z for each test case in separate lines 
 
Constraints:
1<=T<=6000
2<=x<=10^16
2<=y<=10^16
 
Input:
3
5 2
7 7
909 9
 
Output:
55
04
85
*/


#include <iostream>
using namespace std;
#define ll long long
ll binpow(ll a, ll b,ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
int main(){
    int t; cin>>t;
    while(t--){
        ll x,y,ans = 0;
        cin>>x>>y;
        for(int i=1;i<=x;i++) ans+=binpow(i,y,100);
        ans = ans%100;
        if(ans < 10) {cout<<"0"<<ans<<"\n"; continue;}
        cout<<ans<<"\n";
    }
}
