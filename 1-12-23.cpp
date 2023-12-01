/*
Question: 
Special Numbers in different bases
A number in a base is said to be a special number if it is equal to the sum of its own digits each raised to the power of the number of digits. 
A number in base ‘b’ can have digits from 0 to b-1. By default the numbers used by humans is to base 10 and called as decimal number system. 
A number ‘n’ from decimal number system can be converted to any base ‘b’ by repeated division of ‘n’ by ‘b’ and writing reminder of each division in reverse order. 
For example, number 24 is converted to base 3 as shown below:

Given a number ‘n’ and a base ‘b’, write a code to check if n is a special with respect to base ‘b’. If any digit of ‘n’ is greater than ‘b-1’ then print ‘Invalid’
Example 1:

Input

122

3

Output

Yes

Explanation

122 -> number of digits - 3

1^3 + 2^3 + 2^3 -> 17

17 to base 10 is 122 to base 3

Example 2:

Input

433

5

Output

Yes

Example 3:

Input

121

3

Output

No

Example 4:

Input

125

3

Output

Invalid

Input Format

First line contains the number, n

Next line contains the base of the number,b

Output Format

Print Invalid or Yes or No
*/

//Answer: 

#include <iostream>
#include <cmath>
#define int long long 
using namespace std;
int32_t main(){
    string number; int b; 
    cin>>number>>b;
    int l = number.length(),n = stoll(number),i = 0,ans = 0,chk = 0;
    while(n != 0){
        int dig = n%10;
        if(dig > b-1) {cout<<"Invalid"; exit(0);} 
        ans+=pow(dig,l);
        chk+=pow(b,i++)*dig;
        n/=10;
    }
    if(chk == ans) cout<<"Yes";
    else cout<<"No";
}
    
