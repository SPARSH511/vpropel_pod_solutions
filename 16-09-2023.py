# Ramu and cakes
# After joining pipes, Ramu is facing another trouble and this time he has no one to help except you. You are the only friend of Ramu who knows how to make birthday cakes! The cake has to be decorated with stars. You are given the value of N,  the maximum number of stars in a single segment of the pattern. You have to print the final pattern after decorating the cake with the stars. For more clarity, see below:

# For  N = 5:


# ***** *****
# ****   ****
# ***     ***
# **       **
# *         *
# **       **
# ***     ***
# ****   ****
# ***** *****
# Another example:

# For N = 4:


# **** ****
# ***   ***
# **     **
# *       *
# **     **
# ***   ***
# **** ****

# So as shown in the above figures. This is how the cakes look for given N=5 and N=4. The first row has 1 space between the two segments and the next row has 3 spaces and so on until the last row has 1 space again.

 

# If in case it's not possible to make the diamond as can be seen in the figure, print "impossible" without quotes.

 

# Input Format:

# The only line contains the value of N as described above

 

# Output Format:

# Print the pattern as described above, or else print "impossible" if it is not possible to make the diamond.

 

# Constraints:

# 0 <= N <= 50


# ANS.

n = int(input()) 
if(n <= 3): print("impossible")
else:
    oddsp = 1
    for i in range(n,0,-1):
        print('*'*i+' '*oddsp+'*'*i)
        oddsp+=2
    oddsp-=4
    for i in range(2,n+1):
        print('*'*i+' '*oddsp+'*'*i)
        oddsp-=2
