// Length of Closed Figures
// Two lines P1 and P2 are said to be connected if the end point of P1 and start point of P2 are same. In this problem, there is a collection of points in a two dimensional space and the point numbers are given to represent a line. All the lines have distinct starting point and ending point. Given the start and end point numbers of ‘n’ lines and a check point number ‘p’ write a code to find out the length of the closed figure that can be formed that starts with the check point number ‘p’. For example, given ten pairs of point numbers for 10 lines as follows:

// (2, 5)

// (7, 11)

// (13, 14)

// (11, 15)

// (17, 18)

// (15, 17)

// (18, 25)

// (32, 40)

// (25, 32)

// (40, 7)

// and a check point number as 7, a closed figure of length 8 can be formed with the points:

// (7, 11) - (11, 15) - (15, 17) - (17, 18) - (18, 25) - (25, 32) - (32, 40) - (40, 7) - (7, 11)

// Input Format

// First line contains the number of lines, n

// Next ‘n’ lines contain the number of the start and end points

// Next line contains the check point, p

// Output Format

// Length of the closed figure that can be formed with check point, p

// Print zero if a closed figure cannot be formed with check point, p

// Time Complexity - O(nlogn)

// ANS. 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
//binary search function implementation for question
int bin_search(vector<vector<int>> &pt,int chkpt){
    int low = 0,high = pt.size()-1;
    while(low <= high){
        int mid = (low+high)/2;
        if(pt[mid][0] == chkpt) return mid;
        else if(pt[mid][0] < chkpt) low = mid+1;
        else high = mid-1;
    }
    return -1; 
}

int main(){
    //input
    int n; cin>>n;
    vector<vector<int>> pt(n,vector<int>(2));
    for(int i=0;i<n;i++) cin>>pt[i][0]>>pt[i][1];
    
    //len for length and other initial variables 
    int chk,start,len = 0; cin>>chk; start = chk;
    
    //sort array for binary search O(nlogn)
    sort(pt.begin(),pt.end());
    
    //O(nlogn) loop to find the next point for the closed figure from current pt
    //and calculate the length for it
    while(true){
        int search = bin_search(pt,chk);
        if(search == -1) break;
        else{
            len++;
            chk = pt[search][1];
            pt.erase(pt.begin()+search);
        }
    }
    
    //if figure is a cycle then only print len otherwise 0
    if(chk == start) cout<<len;
    else cout<<0;
}
