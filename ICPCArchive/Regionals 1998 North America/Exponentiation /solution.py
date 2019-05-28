from sys import stdin, stdout

while True:
    R = stdin.readline()
    if not R:
        break    
    R, n = R.split()
    R, l = R.split('.')
    n = int(n)
    R = int(R)
    r2 = 0
    for x in range(len(l)) :
        if l[x] != '0' :
            r2 = x + 1
    ans = 1
    for x in range(r2):
        R = R * 10 + int( l[x] )
    for x in range(n):
        ans *= R
    ans = str(ans)
    temp = len(ans) - n * r2
    i = 0
    limit = r2 * n
    if i < limit:
        for x in range(temp) :
            stdout.write(ans[i])
            i += 1
    limit = r2 * n + i
    if r2 != 0:
        stdout.write('.')
        while limit > len(ans):
            stdout.write('0')
            limit -= 1
        while i < limit :
            stdout.write(ans[i])
            i += 1
    stdout.write('\n')