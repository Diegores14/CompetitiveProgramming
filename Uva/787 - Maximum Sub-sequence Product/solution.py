from sys import stdin, stdout

while True:
    line = stdin.readline()
    if not line:
        break
    v = []
    for i in line.split():
        v.append(int(i))
    ans = -10000000
    for i in range(len(v)-1):
        mul = 1
        for j in range(i, len(v)-1):
            mul *= v[j]
            ans = max(ans, mul)
    stdout.write(str(ans) + '\n')