#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vi A;

class SegmentTree{
	private:
	vi  st;
	int n;
	int left(int p){ return p<<1; }
	int right(int p){ return (p<<1)+1; }
	void build(int p, int L, int R){
	 	if(L==R){
	 	 	st[p] = L;
		}else{
			int mid = (L+R)>>1, p1 = left(p), p2 = right(p);
		 	build(p1, L, mid);
			build(p2, mid+1, R);
			st[p] = (A[st[p1]]<= A[st[p2]])? st[p2] : st[p1];
		}
	}

	void update(int p, int L, int R, int pos){
	 	if(pos<L || R<pos)
			return;
		if(L == R && L == pos)
			A[pos] = 0;
		else{
		 	int mid = (L+R)>>1, p1 = left(p), p2 = right(p);
		 	update(p1, L, mid, pos);
			update(p2, mid+1, R, pos);
			st[p] = (A[st[p1]]<= A[st[p2]])? st[p2] : st[p1];
		}
	}

	int rmq(int p, int L, int R, int l, int r){
	 	if( r < L || R < l)
			return -1;
		if( l <= L && R <= r)
			return st[p];
		int mid = (L+R)>>1;
		int p1 = rmq(left(p), L, mid, l, r);
		int p2 = rmq(right(p), mid + 1, R, l, r);
		if(p1==-1) return p2;
		if(p2==-1) return p1;
		return (A[p1]<=A[p2])? p2 : p1;
	}
	
	public:
		SegmentTree(int _n){
		 	n = _n;
			st.assign(4*n, -1);
			build(1, 0, n-1);
		}
		
		int rmq(int l, int r){
		 	return rmq(1, 0, n-1, l, r);
		}
		void update(int pos){
		 	update(1, 0, n-1, pos);
		}
};

int main(){
	ios_base::sync_with_stdio(false);
	int n, k, aux=0;
	long long ans = 0;
	cin >> n >> k;
	int cantidad = n/(k+1);
	A.assign(n, 0);
	for(int &i: A)
		cin >> i;
	SegmentTree st(n);
	for(int i=0; i<n; i++){
	 	if(aux>=k){
			st.update(st.rmq(i, min(n-cantidad, n-1)));
			cantidad--;
			aux -= k;
		}
		if(A[i]!=0){
		 	aux++;
			ans += A[i];
		}
	}
	cout << ans << '\n';
	return 0;
}