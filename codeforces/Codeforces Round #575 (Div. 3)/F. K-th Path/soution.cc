#include <bits/stdc++.h>
using namespace std;
typedef pair<long long, int> li;
typedef pair<int, int> ii;
typedef vector < vector <li> > Graph;

struct data {
    long long weight; int index, last, start;
    data(int s, int l, long long w, int i): start(s), last(l), weight(w), index(i) {}
    bool operator<(const data &other) const{
        return (weight > other.weight);
    }
};


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, a, b;
    long long c;
    cin >> n >> m >> k;
    Graph G(n);
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c; a--; b--;
        G[a].push_back(li(c, b));
        G[b].push_back(li(c, a));
    }
    for(auto &i: G) {
        sort(i.begin(), i.end());
    }
    set < ii > visited;
    k *= 2;
    priority_queue < data > q;
    for(int i = 0; i < n; i++) {
        q.push(data(i, i, G[i][0].first, 0) );
        visited.insert( ii(i, i) );
    }
    while(!q.empty()) {
        data cur = q.top();
        q.pop();
        int next = G[cur.last][cur.index].second;
        if( !visited.count( ii(cur.start, next) ) ) {
            visited.insert( ii(cur.start, next) );
            k--;
            if(k == 0) {
                cout << cur.weight << '\n';
                return 0;
            }
            q.push( data(cur.start, next, cur.weight + G[next][0].first, 0) );
        }
        if (cur.index + 1 < G[cur.last].size() ) {
            q.push( data(cur.start, cur.last, cur.weight - G[cur.last][cur.index].first + G[cur.last][cur.index + 1].first, cur.index + 1) );
        }
    }
    return 0;
}