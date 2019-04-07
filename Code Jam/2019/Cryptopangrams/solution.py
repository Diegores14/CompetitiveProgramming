from sys import stdin, stdout

def gcd(a, b):
        return gcd(b, a%b) if b != 0 else a


def main():
        t = int(stdin.readline())
        for x in range(t) :
                stdout.write("Case #" + str(x+1) + ": ")
                n, l = stdin.readline().split()
                n = int(n)
                l = int(l)
                ans = [int(-1)]*(l+1)
                v = [int(y) for y in stdin.readline().split()]
                i = 1
                primes = set()
                while i < l :
                        if v[i-1] != v[i] :
                                p = gcd(v[i-1], v[i])
                                ans[i] = p
                                primes.add(p)
                                break
                        i += 1
                i = 0
                while i < l :
                        if(ans[i] != -1 and ans[i+1] == -1):
                                ans[i+1] = v[i]/ans[i]
                                primes.add(ans[i+1])
                        i += 1
                i = l-1
                while i >= 0 :
                        if(ans[i] == -1 and ans[i+1] != -1):
                                ans[i] = v[i]/ans[i+1]
                                primes.add(ans[i])
                        i -= 1
                i = 26
                num = []
                while i != 0:
                        num.append(primes.pop())
                        i -= 1
                num.sort()
                primes = {}
                i = 0
                for y in num:
                        primes[y] = i
                        i += 1
                for y in ans:
                        stdout.write(str(chr(ord('A') + primes[y])))
                stdout.write("\n")


if __name__ == "__main__":
        main()