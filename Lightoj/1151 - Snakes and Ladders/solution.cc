#include <bits/stdc++.h>
using namespace std;
const int tam = 100;

void cambiar( vector< double > &a, vector< double > &b ) {
    for( int i = 0; i < a.size(); i++ ) {
        swap( a[i], b[i] );
    }
}

void dividir( vector< double > &a, double k ) {
    for( int i = 0; i < a.size(); i++ ) {
        a[i] /= k;
    }
}

vector< double > multiplicar( vector< double > &a, double k ) {
    vector< double > ans = a;
    for( int i = 0; i < a.size(); i++ ) {
        ans[i] *= k;
    }
    return ans;
}

void suma( vector< double > &a, vector< double > b ) {
    for( int i = 0; i < a.size(); i++ ) {
        a[i] += b[i];
    }
}

void gauss( vector< vector< double > > &v ) {
    for( int i = 0; i < tam; i++ ) {
        if( v[i][i] == 0 ) {
            for( int k = i+1; k < tam; k++ ) {
                if( v[k][i] != 0 ) {
                    cambiar( v[i], v[k] );
                    break;
                }
            }
        }
        dividir( v[i], v[i][i] );
        for( int j = 0; j < tam; j++ ) {
            if( j != i && v[j][i] != 0 ) {
                suma( v[j], multiplicar( v[i], -v[j][i] ) );
            }
        }
    }
}

void solve() {
    int n, a, b;
    int to[tam];
    cin >> n;
    for( int i = 0; i < tam; i++ ) {
        to[i] = i;
    }
    for( int i = 0; i < n; i++ ) {
        cin >> a >> b; a--; b--;
        to[a] = b;
    }
    double temp = double(1)/6;
    vector< vector< double > > ecuation( tam, vector< double >(tam+1, 0) );
    for( int i = 0; i+1 < tam; i++ ) ecuation[i][tam] = 1;
    for( int i = 0; i < tam; i++ ) {
        ecuation[i][i] = 1;
        for( int j = 1; j <= 6; j++ ) {
            int t = i+j;
            if( t < tam ) 
                ecuation[i][to[t]] -= temp;
            else 
                ecuation[i][i] -= temp;
        }
    }
    ecuation[99][99] = 1;
    gauss( ecuation );
    cout << ecuation[0][tam] << '\n';
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    cout << fixed << setprecision(10);
    for( int cases = 1; cases <= t; cases++ ) {
        cout << "Case " << cases << ": ";
        solve();
    }
    return 0;
}