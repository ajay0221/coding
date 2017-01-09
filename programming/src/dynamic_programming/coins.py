def count(coins, n, m):
    if str(n)+'#'+str(m) in arr and arr[str(n)+'#'+str(m)] > 0:
        return arr[str(n)+'#'+str(m)]
    if n == 0:
        return 1
    if n < 0:
        return 0
    if m < 0 and n >= 1:
        return 0
    arr[str(n-coins[m]) + '#' + str(m)] = count(coins, n - coins[m], m) 
    arr[str(n) + '#' + str(m-1)] = count(coins, n, m-1)
    return arr[str(n-coins[m]) + '#' + str(m)] + arr[str(n) + '#' + str(m-1)]

x = raw_input()
temp = x.strip().split(' ')
n = int(temp[0])
m = int(temp[1])

x = raw_input()
coins = [int(i) for i in x.strip().split(' ')]

coins.sort()
arr = {}
print (count(coins, n, len(coins)-1))

