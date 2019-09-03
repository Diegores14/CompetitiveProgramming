#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

long long gcd(long long a, long long b){
  return b ? gcd(b, a%b) :  a;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long l,n,d;
  while(cin >> l >> n >> d){
    if(l == 0 && d == 0 && d == 0)break;
    long long x, y;
    long double ans = 1e12;
    for(int i = 1; i <= n; i++){
      long long a = ((d*i)+l-1)/l;
      if(ans > (long double)(a*l)/i){
          x = a*l;
          y = i;
          ans = (long double)(a*l)/i;
      }
    }
    long long g = gcd(x,y);
    x /= g;
    y /= g;
    cout << x << '/' << y << endl;
  }
  return 0;
}