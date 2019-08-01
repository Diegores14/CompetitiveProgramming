#include <bits/stdc++.h>
using namespace std;
const int tam = 45;
int R, C;
char v[tam][tam];
bool used[tam][tam][tam][tam];

struct state {
    int x, y, a, b, p;
    state() { p = 0; }
    state(int x, int y, int a, int b, int p = 0): x(x), y(y), a(a), b(b), p(p) {}
};

int dx[4] = { 1, -1, 0, 0 };
int dx1[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int dy1[4] = { 0, 0, -1, 1 };

void solve(state s, state e) {
    queue<state> q;
    used[s.x][s.y][s.a][s.b] = true;
    q.push(s);
    while(!q.empty()) {
        state st = q.front();
        q.pop();
        if(st.x == e.x && st.y == e.y && st.a == e.a && st.b == e.b) {
            cout << st.p << '\n';
            return;
        }
        for(int i = 0; i < 4; i++) {
            state temp = st;
            temp.x += dx[i];
            temp.y += dy[i];
            if(temp.x < 0 || temp.x >= R || temp.y < 0 || temp.y >= C || v[temp.x][temp.y] != '.') {
                continue;
            }
            temp.a += dx1[i];
            temp.b += dy1[i];
            if(temp.a < 0 || temp.a >= R || temp.b < 0 || temp.b >= C || v[temp.a][temp.b] != '.') {
                temp.a -= dx1[i];
                temp.b -= dy1[i];
            }
            if(!used[temp.x][temp.y][temp.a][temp.b]) {
                used[temp.x][temp.y][temp.a][temp.b] = true;
                temp.p += 1;
                q.push(temp);
            }
        }
        for(int i = 0; i < 4; i++) {
            state temp = st;
            temp.a += dx1[i];
            temp.b += dy1[i];
            if(temp.a < 0 || temp.a >= R || temp.b < 0 || temp.b >= C || v[temp.a][temp.b] != '.') {
                continue;
            }
            temp.x += dx[i];
            temp.y += dy[i];
            if(temp.x < 0 || temp.x >= R || temp.y < 0 || temp.y >= C || v[temp.x][temp.y] != '.') {
                temp.x -= dx[i];
                temp.y -= dy[i];
            }
            if(!used[temp.x][temp.y][temp.a][temp.b]) {
                used[temp.x][temp.y][temp.a][temp.b] = true;
                temp.p += 1;
                q.push(temp);
            }
        }
    }
    cout << "NO LOVE\n";
    return;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    while( cin >> R >> C ) {
        state e; cin >> e.x >> e.y; e.x--; e.y--; e.a = e.x; e.b = e.y;
        state s; cin >> s.x >> s.y >> s.a >> s.b;
        s.x--; s.y--; s.a--; s.b--;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> v[i][j];
            }
        }
        memset(used, 0, sizeof used);
        solve(s, e);
    }
    return 0;
}