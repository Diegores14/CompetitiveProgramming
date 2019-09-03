#include <bits/stdc++.h>
using namespace std;
typedef vector< vector< long long > > matriz;
const int mod = 1e9+9;

matriz identidad( int n ) {
  matriz I(n, vector< long long >(n));
  for(int i = 0; i < n; i++) {
    I[i][i] = 1;
  }
  return I;
}

matriz newMatriz( int n ) {
  matriz I(n, vector< long long >(n));
  for(int i = 0; i < n; i++) {
    I[0][i] = 1;
    if(i+1 < n) I[i+1][i] = 1;
  }
  return I;
}

matriz producto( const matriz &a, const matriz &b ) {
  matriz ans(a.size(), vector< long long >( a.size() ) );
  for( int i = 0; i < a.size(); i++ ) {
      for( int j = 0; j < a.size(); j++ ) {
        for( int k = 0; k  < a.size(); k++ ) {
          ans[i][j] = (ans[i][j] +(a[i][k]*b[k][j])%mod ) % mod;
        }
      }
  }
  return ans;
}

long long exponentation( int b, long long e ) {
  matriz ans = identidad(b);
  matriz pro = newMatriz(b);
  while( e ) {
    if( e&1 ) {
      ans = producto( ans, pro );
    }
    pro = producto( pro, pro );
    e >>= 1;
  }
  long long second = 1;
  long long answer = ans[0][b-1];
  for( int i = b-2; i >= 0; i--) {
      answer = ( answer + (ans[0][i]*second)%mod )%mod;
      second = (second * 2)%mod;
  }
  return answer;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  long long n, k;
  while( cin >> k >> n, n || k ) {
      if( n == 0 ) { cout << 1 << '\n'; continue; }
      if( n >= k ) {
          cout << exponentation(k, n-k+1) << '\n';
      } else {
        long long ans = 1;
        for( int i = 2; i <= n; i++ ) {
          ans = (ans*2)%mod;
        }
        cout << ans << '\n';
      }
  }
  return 0;
}
