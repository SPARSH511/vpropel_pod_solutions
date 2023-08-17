# Mountain Array
# Given an array A of integers, print Yes if and only if it is a valid mountain array.

# Recall that A is a mountain array if and only if:

# A.length >= 3

# There exists some i with 0 < i < A.length - 1 such that:

# A[0] < A[1] < ... A[i-1] < A[i]

# A[i] > A[i+1] > ... > A[A.length - 1]

# Example 1:

# Input: [2,1]

# Output: No

# Example 2:

# Input: [3,5,5]

# Output: No

# Example 3:

# Input: [0,3,2,1]

# Output: Yes

# Input format:-

# Number of elements

# Elements of arrays separated by comma

# Output format:-

# Yes/No

# ANS.
n = int(input())
if(n < 3): print("No"); exit()
arr = list(map(int,input().split(',')))
part = 0
for i in range(n-1):
    if(arr[i+1] <= arr[i]): part = i; break
if(part == 0): print("No"); exit()
for i in range(part,n-1):
    if(arr[i+1] >= arr[i]): print("No"); exit()
print("Yes")
