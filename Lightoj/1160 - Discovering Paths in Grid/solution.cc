#include <bits/stdc++.h>
using namespace std;
typedef vector< vector< long long > > matriz;
const int tam = 40, mod = 1e9+7;
matriz base(tam, vector< long long >(tam, 0) );

/* 
    In this problem it is important to see the states as the positions of the four people, 
    and also is important know the edge with others states.
*/

bool check( vector< int > a, vector< int > b ) {
    do {
        bool ok = true;
        for( int i = 0 ; i < 4; i++ ) {
            if( abs(a[i]-b[i]) != 1 ) { ok = false; break; }
        }
        if( ok ) return true;
    } while( next_permutation( b.begin(), b.end() ) );
    return false;
}

vector< vector < int > > st;

void precomputo() {
    for( int i = 0; i < 7; i++ ) 
        for( int j = i+1; j < 7; j++ ) 
            for( int k = j+1; k < 7; k++ ) 
                for( int r = k+1; r < 7; r++ ) {
                    vector< int > temp; temp.push_back(i); 
                    temp.push_back(j); temp.push_back(k); 
                    temp.push_back(r);
                    st.push_back( temp );
                }
    for( int i = 0; i < st.size(); i++ ) {
        for( int j = 0; j < st.size(); j++ ) {
            base[i][j] = check( st[i], st[j] );
        }
    }
}

matriz operator *( matriz &a, matriz &b ) {
    matriz ans( tam, vector< long long >(tam, 0) );
    for( int i = 0; i < tam; i++ ) {
        for( int j = 0; j < tam; j++ ) {
            for( int k = 0; k < tam; k++ ) {
                ans[i][j] = ( ans[i][j] + a[i][k]*b[k][j] )%mod;
            }
        }
    }
    return ans;
}

matriz identidad( ) {
    matriz ans( tam, vector< long long >(tam, 0) );
    for( int i = 0; i < tam; i++ ) {
        ans[i][i] = 1;
    }
    return ans;
}

matriz exp( matriz b, int e ) {
    //printf( "Hello\n" );
    matriz ans = identidad();
    while( e ) {
        if( e&1 ) {
            ans = ans*b;
        }
        e >>= 1;
        b = b*b;
    }
    return ans;
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    precomputo();
    int t, n, aux;
    cin >> t;
    for( int cases = 1; cases <= t; cases++ ) {
        //cout << "Hello\n";
        vector< int > temp;
        cin >> n;
        for( int i = 0; i < 7; i++ ) {
            cin >> aux;
            if( aux ) temp.push_back(i);
        }
        int pos = 0;
        for( int i = 0; i < st.size(); i++ ) {
            if( st[i] == temp ) {
                pos = i; break;
            }
        }
        matriz ans = exp( base, n-1 );
        long long answer = 0;
        for( int i = 0; i < tam; i++ ) {
            answer = ( answer+ans[pos][i] )%mod;
        }
        cout << "Case " << cases << ": " <<  answer << '\n';
    }
    return 0;
}