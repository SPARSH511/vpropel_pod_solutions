// Sum of First Few Consecutive Prime Numbers
// Given a number 'n', write an algorithm and a code to check if it can be written as sum of first few prime numbers. 
// Print Yes if 'n' can be written as first few prime numbers and No otherwise. For example, if n is 5 then print Yes as it can be written as 2+3, 
// if n is 41 then print Yes as it can be written as 2 + 3 + 5 + 7 + 11 + 13 and if n is 11 then print 'No' as it cannot be written as sum of first few prime numbers.

// Input Format

// First line contains the number, n

// Output Format

// First line contains Yes if the number n can be written as sum of first few prime numbers and No otherwise

//ANS

#include <iostream>
#include <vector>
using namespace std;
void sieve(vector<bool> &prime,int n){
    for(int p=2;p*p<=n;p++){
        if(prime[p] == true)
            for(int i=p*p;i<=n;i+=p) 
                prime[i] = false;
    }
}
int main(){
    int n; cin>>n;
    vector<bool> prime(n,true);
    sieve(prime,n);
    int sum = 0;
    for(int i=2;i<=n;i++){
        if(prime[i]){
            sum+=i;
            if(sum == n) {cout<<"Yes"; return 0;}
        }
    }
    cout<<"No";
}
