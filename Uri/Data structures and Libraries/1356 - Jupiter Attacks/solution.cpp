#include <bits/stdc++.h>
using namespace std;
vector<long long> B;
long long p;

struct node{
	long long value;
	node *left, *right;
	node(){
	 	value=0;
		left = nullptr;
		right = nullptr;
	}
};

node* update(node* cur, int L, int R,const int & pos, const long long & value) {
	if(!cur)
		cur = new node();
	if(pos<L || pos>R)
		return cur;
	if(L==R && L==pos){
	 	cur->value = ((B[pos]%p)*(value%p))%p;
	}else{
	 	int mid = (L+R)>>1;
		cur->left = update(cur->left, L, mid, pos, value);
		cur->right = update(cur->right, mid+1, R, pos, value);
		cur->value = ((cur->left->value)%p + (cur->right->value)%p)%p;
	}
	return cur;
}

long long query(node* cur, int L, int R, const int &l, const int &r){
	if(!cur || r < L || R < l)
		return 0;
	if(l<=L && R<=r)
		return cur->value;
	int mid = (L+R)>>1;
	long long a = query(cur->left, L, mid, l, r);
	long long b = query(cur->right, mid+1, R, l, r);
	return (a%p + b%p)%p;
}

int extended_euclidean(int a, int b, int & x, int & y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    int x1, y1;
    int d = extended_euclidean(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	long long b, l, n;
	char c;
	long long L, R;
	while(cin >> b >> p >> l >> n, b || p || l || n){
		B.assign(l, 1);
		node* st = new node();
		vector<long long> f(l, 0);
		long long x = 1;
		for(int i=l-1; i>=0; i--){
		 	B[i] = x;
			x = (x%p * b%p)%p;
		}
		for(int i=0; i < n; i++){
		 	cin >> c >> L >> R;
			if(c == 'E'){
				L--;
				st = update(st, 0, l, L, R);
			}else{
				L--; R--;
				int x, y;
				int g = extended_euclidean(B[R], p, x, y);
				x = (x % p + p) % p;
			 	cout << (query(st, 0, l, L, R)*x)%p << '\n';
			}
		}
		cout << "-\n";
	}
	return 0;
}