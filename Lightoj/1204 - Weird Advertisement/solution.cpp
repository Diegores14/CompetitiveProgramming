#include <bits/stdc++.h>
using namespace std;
int n, k;
const int tam = 30000;

struct node {
    int count, sum;
    node *left, *right;
    node(): count(0), sum(0), left(NULL), right(NULL) {}
};

struct edge {
    int x, y1, y2, value; 
    bool operator <(const edge & other) {
        return x < other.x;
    }
} lines[2*tam];

void update(node* &p, int b, int e, int l, int r, int val, int up) {
    if(r < b || e < l) return;
    if(!p) p = new node();
    int mid = (b+e)>>1;
    if(l <= b && e <= r) {
        p->count += val;
        if(p->count + up >= k) {p->sum = (e - b + 1); }
        else {
            p->sum = 0;
            if(p->left){
                update(p->left, b, mid, l, r, 0, p->count + up);
                p->sum += p->left->sum;
            }
            if(p->right){
                update(p->right, mid+1, e, l, r, 0, p->count + up);
                p->sum += p->right->sum;
            }
        }
    } else {
        update(p->left, b, mid, l, r, val, p->count + up);
        update(p->right, mid+1, e, l, r, val, p->count + up);
        if(p->count + up >= k) {
            p->sum = (e - b + 1);
            return ;
        }
        p->sum = 0;
        if(p->left)
            p->sum += p->left->sum;
        if(p->right)
            p->sum += p->right->sum;
    }
}

int main() {
    //ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, x1, x2, y1, y2;
    scanf("%d", &t);
    for(int cases = 1; cases <= t; cases++) {
        scanf("%d %d", &n, &k);
        int j = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x2++; y2++;
            lines[j].x = x1;
            lines[j].y1 = y1;
            lines[j].y2 = y2;
            lines[j++].value = 1;
            lines[j].x = x2;
            lines[j].y1 = y1;
            lines[j].y2 = y2;
            lines[j++].value = -1;
        }
        sort(lines, lines+j);
        long long ans = 0;
        long long dx = lines[0].x;
        node *root = new node();
        for(int i = 0; i < j; i++) {
                ans += (lines[i].x - dx) * root->sum;
                dx = lines[i].x;
            update(root, 0, 1e9, lines[i].y1, lines[i].y2 - 1, lines[i].value, 0);
        }
        printf("Case %d: %lld\n", cases, ans);
    }
    return 0;
}