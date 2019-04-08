#include <bits/stdc++.h>
using namespace std;

struct node{
    long double x,y,z;
    long double dist(node & o){
        long double a = x - o.x;
        long double b = y - o.y;
        long double c = z - o.z;
        return sqrt(a*a + b*b + c*c);
    }
};


int main(){

    int t, n, e, q;
    cin >> t;
    for(int x = 1; x <= t; x++){
        cin >> n;
        map<int,node> p;
        map<string,int> m;
        for(int i = 0; i < n; i++){
            node a; string s;
            cin >> s >> a.x >> a.y >> a.z;
            m[s] = i;
            p[i] = a;
        }
        long double g[n][n];
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                g[i][j] = p[i].dist(p[j]);
                g[j][i] = p[i].dist(p[j]);
            }
        }
        cin >> e;
        for(int i = 0; i < e; i++){
            string a, b;
            cin >> a >> b;
            g[m[a]][m[b]] = 0;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                for(int k = 0; k < n; k++){
                    g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
                }
            }
        }
        cout << "Case " << x << ":" << endl;
        cin >> q;
        for(int i = 0; i < q; i++){
            string a, b;
            cin >> a >> b;
            cout << "The distance from " << a << " to " << b << " is " << (long long)round(g[m[a]][m[b]]) << " parsecs." << endl;
        }
    }
    return 0;
}