#include <bits/stdc++.h>
using namespace std;

struct state {
    int pos, seat, dist;
    state( int pos = 0, int seat = 0, int dist = 0 ): pos(pos), seat(seat), dist(dist) {}
    bool operator <( state other ) const {
        if( seat == other.seat ) {
            if( dist == other.dist )
                return pos > other.pos;
            else 
                return dist > other.dist;
        }
        return seat < other.seat;
    }
};

bool check( char &a, char &b, char &ans, int &n, int &left, int &right ) {
    if( a == '-' || b == '-' ) {
        if( a == '-' && b == '-' ) {
            if( left >= right ) {
                a = ans;
                left--;
            } else {
                b = ans;
                right--;
            }
        } else {
            if( a == '-' ) {
                left--;
                a = ans;
            } else {
                b = ans;
                right--;
            }
        }
        ans++;
        n--;
        return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int r, n;
    while( cin >> r >> n ) {
        string v[r+3];
        priority_queue< state > Q;
        for( string &i: v ) {
            cin >> i;
        }
        int left = 0, right = 0;
        for( int i = 0; i < r+3; i++ ) {
            left += (v[i][0] == '-') + (v[i][1] == '-') + (v[i][2] == '-') + (v[i][4] == '-');
            right += (v[i][6] == '-') + (v[i][8] == '-') + (v[i][9] == '-') + (v[i][10] == '-');
        }
        int cnt = 0;
        for( int i = 0; i <= 10; i++ ) {
            cnt += ( v[1][i] == '-' );
        }
        if( cnt )
            Q.push( state(1, cnt, 1) );
        cnt = 0;
        for( int i = 0; i <= 10; i++ ) {
            cnt += ( v[r/2 + 2][i] == '-' );
        }
        if( cnt )
            Q.push( state(r/2+2, cnt, 1) );
        char ans = 'a';
        while( n && !Q.empty() ) {
            state temp = Q.top(); Q.pop();
            int pos = temp.pos;
            if( check( v[pos][4], v[pos][6], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( check( v[pos][2], v[pos][8], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( check( v[pos][0], v[pos][10], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( v[pos][5] == '-' ) {
                v[pos][5] = ans;
                ans++;
                n--;
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( check( v[pos][1], v[pos][9], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
        }
        for( int i = 0; i < r+3; i++ ) {
            cnt = 0; 
            for( int j = 0; j <= 10; j++ ) {
                cnt += (v[i][j] == '-');
            }
            if( cnt ) {
                //cout << i << ' ' << min(r+2-i, min(abs(r/2+1-i), i)) << '\n';
                Q.push( state(i, cnt, min(r+2-i, min(abs(r/2+1-i), i)) ));
            }
        }
        while( n && !Q.empty() ) {
            state temp = Q.top(); Q.pop();
            int pos = temp.pos;
            if( check( v[pos][4], v[pos][6], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( check( v[pos][2], v[pos][8], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( check( v[pos][0], v[pos][10], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( v[pos][5] == '-' ) {
                v[pos][5] = ans;
                ans++;
                n--;
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
            if( check( v[pos][1], v[pos][9], ans, n, left, right) ) {
                temp.seat--;
                if( temp.seat ) {
                    Q.push( temp );
                }
                continue;
            }
        }
        for( int i = 0; i < r+3; i++ ) {
            cout << v[i] << '\n';
        }
    }
    return 0;
}