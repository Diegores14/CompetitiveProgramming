#include <bits/stdc++.h>
using namespace std;

int value( int x) {
   int l = 1, r = 1e6+1;
   while( r-l != 1 )  {
       int mid = (l+r)/2;
       if( (1LL*mid*(mid-1))/2 <= x ) {
           l = mid;
       } else {
           r = mid;
       }
   }
   return x? l : 0;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    int c0 = value(a00), c1 = value(a11);
    string ans;
    if( (1LL*c0*(c0-1))/2 != a00 || (1LL*c1*(c1-1))/2 != a11 ) {
        cout << "Impossible\n";
        return 0;
    }
    if( c0 == 0 && a01+a10 == c1 ) {
        for( int i = 0; i < a10; i++ ) {
            ans.push_back('1');
        }
        ans.push_back('0');
        for( int i = 0; i < a01; i++ ) {
            ans.push_back('1');
        }
        cout << ans << '\n';
        return 0;
    }
    if( c1 == 0 && a01+a10 == c0 ) {
        for( int i = 0; i < a01; i++ ) {
            ans.push_back('0');
        }
        ans.push_back('1');
        for( int i = 0; i < a10; i++ ) {
            ans.push_back('0');
        }
        cout << ans << '\n';
        return 0;
    }
    if( c1 == 0 && c1 == 0 && a01 + a10 == 1 ) {
        if( a01 ) {
            cout << "01" << '\n';
        } else {
            cout << "10" << '\n';
        }
        return 0;
    }
    if( (1LL*c0*(c0-1))/2 == a00 && (1LL*c1*(c1-1))/2 == a11 && 1LL*c0*c1 == a01 + a10 ) {
        for( int i = 0 ; i < c0; i++ ) {
            ans.push_back('0');
        }
        for( int i = 0 ; i < c1; i++ ) {
            ans.push_back('1');
        }
        long long sum = 0;
        int x = c0-1, y = c0+c1-1;
        while( x && sum + c1 <= a10 ) {
            swap( ans[x], ans[y] );
            x--; y--;
            sum += c1;
        }
        while( sum != a10 ) {
            sum++;
            swap(ans[x], ans[x+1]);
            x++;
        }
        cout << ans << '\n';
    } else {
        cout << "Impossible\n";
    }
    return 0;
}