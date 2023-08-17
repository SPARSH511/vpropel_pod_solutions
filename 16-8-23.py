# Merge Items
# Given a collection of intervals, merge all overlapping intervals.

# Example 1:

# Input: [[1,3],[2,6],[8,10],[15,18]]

# Output: [[1,6],[8,10],[15,18]]

# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].

# Example 2:

# Input: [[1,4],[4,5]]

# Output: [[1,5]]

# Explanation: Intervals [1,4] and [4,5] are considered overlapping.

# Input format:-

# Number of pairs

# Next n lines – n pairs

# Output format:-

# Final set of pairs each in one line


#ANS.

def merge(pts):
    pts.sort()
    n = len(pts)
    ans = []
    ans.append(pts[0])
    pt,test = [],[]
    k = 1
    for i in range(1,n):
        pt = pts[i]
        test = ans[k-1]
        if(test[0] < pt[0] and test[1] < pt[0]): ans.append(pt); k+=1
        else:
            ans.pop()
            ans.append([min(test[0],pt[0]),max(test[1],pt[1])])
    return ans
n = int(input())
pts = []
for i in range(n):
    pts.append(list(map(int,input().split(','))))
pts = merge(pts)
for pt in pts:
    print(pt[0],pt[1],sep=',')
