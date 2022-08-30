def find_max(S, n):
    if (n == 1):
        return S[0]
    return max(S[n-1], find_max(S, n-1))


# Testing
S = [2,4,1,5,3]
n = len(S)
find_max(S, n)
print(find_max(S, n-1))



