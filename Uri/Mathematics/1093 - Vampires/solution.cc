#include <bits/stdc++.h>
using namespace std;

struct state {
    int x, y;
    state(){}
    state( int x, int y ): x(x), y(y) {}
    bool operator < ( state other ) const {
        if( x == other.x ) return y < other.y;
        else return x < other.x;
    }
};

void gauss( vector< vector< double > > &v ) {
    int i = 0, r = 0, n = v.size() ;
    while( i < n && r < n ) {
        if( v[r][i] == 0 ) {
            for( int k = r+1; k < n; k++ ) {
                if( v[k][i] != 0 ) {
                    swap(v[r], v[k]);
                    break;
                }
            }
        }
        if( v[r][i] ) {
            double temp = v[r][i];
            for( int k = 0; k < v[r].size(); k++ ) {
                v[r][k] /= temp;
            }
            for( int k = 0; k < n; k++ ) {
                if( k != r && v[k][i] != 0 )  {
                    temp = v[k][i];
                    for( int c = 0; c < v[k].size(); c++ ) {
                        v[k][c] -= temp*v[r][c];
                    }
                }
            }
            r++;
        }
        i++;
    }
}

void print( vector< vector< double > > & v ) {
    for( int i = 0; i < v.size(); i++ ) {
        for( int j = 0; j < v[i].size(); j++ )  {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "--------------------\n";
}

bool solve() {
    map< state, int > m;
    int x, y, at, D;
    cin >> x >> y >> at >> D;
    if( x == 0 && y == 0 && at == 0 && D == 0) return false;
    int tempx = x, tempy = y;
    m[ state(x, y) ] = m.size();
    while( tempy > 0 ) {
        tempy -= D;
        tempx += D;
        m[ state(tempx, tempy ) ] = m.size();
    }
    tempx = x, tempy = y;
    while( tempx > 0 ) {
        tempx -= D;
        tempy += D;
        m[ state(tempx, tempy ) ] = m.size();
    }
    double p = double(at)/6;
    int n = m.size();
    vector< vector< double > > v( n, vector< double >(n+1, 0) );
    for( pair<state, int> i: m ) {
        int j = i.second;
        v[ j ][ j ] = 1;
        if( i.first.x <= 0 || i.first.y <= 0 ) {
            v[ j ][ n ] = (i.first.y <= 0);
        } else {
            state a = state(i.first.x+D, i.first.y-D), b = state(i.first.x-D, i.first.y+D);
            v[ j ][ m[a] ] = -p;
            v[ j ][ m[b] ] = p-1;
        }
    }
    //print( v );
    gauss( v );
    //print( v );
    cout << v[ m[state(x, y)] ][n]*100 << '\n';
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cout << fixed << setprecision(1);
    while(solve()) { }
    return 0;
}