from python_codes import max_


def longest_palindrome(s:str)->str:
    n = len(s)
    if n < 2:
        return s
    dp = [[False]*n for _ in range(n)]

    for i in range(n):
        dp[i][i] = True
    
    start_index = 0
    max_length = 1

    for i in range(n-1):
        if s[i] == s[i+1]:
            dp[i][i+1] = True
            start_index = i
            max_length = 2

    for length in range(3,n+1):
        for i in range(n - length + 1):
            j = i + length - 1

            if s[i] == s[j] and dp[i+1][j-1]:
                dp[i][j] = True

                if length > max_length:
                    max_length = length 
                    start_index = i
    return s[start_index : start_index + max_length]
