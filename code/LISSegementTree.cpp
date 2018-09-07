#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
  	private:
  		vi A, st;
  		int n;
  		int right(int i){ return (i<<1)+1;}
  		int left(int i){ return (i<<1);}
  		void build(int p, int L, int R){
  		 	if(L==R) st[p]=R;
  		 	else{
	  		 	int mid = (L+R)/2;
  			 	build(left(p), L, mid);
  			 	build(right(p), mid+1, R);
  		 		int x = st[left(p)], y = st[right(p)];
	  		 	st[p] = (A[x] >= A[y])? x : y;
			}
  		}

  		int rmq(int p, int i, int j, int L, int R){
  		 	if(R<i || j<L)return -1;
  		 	if(i<=L && R<=j) return st[p];
  		 	int mid=(L+R)>>1;
  		 	int x=rmq(left(p), i, j, L, mid),
  		 		y = rmq(right(p), i, j, mid+1, R);
  		 	if(x==-1) return y;
  		 	if(y==-1) return x;
  		 	return (A[x]>=A[y])? x : y;
  		}

  		void update(int p, int i,  int value, int L, int R){
  			if(i<L || R<i)return;
  			if(i==L && R==i){ A[i]++;}
  			else{ 
  				int mid = (L+R)/2;
  				update(left(p), i, value, L, mid);
	  		 	update(right(p), i, value, mid+1, R);
  		 		int x = st[left(p)], y = st[right(p)];
	  		 	st[p] = (A[x] >= A[y])? x : y;
			}
		}

		public:
		SegmentTree(int a){
			n=a;
			A.assign(n+1, 0);
			st.assign(4*(n+1), 0);
			build(1, 0, n);
		}

		int rmq(int i, int j){
		 	return A[rmq(1, i, j, 0, n)];
		}

		void update(int i, int value){
		 	update(1, i, value, 0, n);
		}

};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, mx=0; 
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; i++){ cin >> v[i]; mx = max(mx, v[i]);}
	SegmentTree st(mx);
	vector<int> d(n,0);
	for(int i=0; i<n; i++){
	 	d[i]=st.rmq(0, v[i]-1);
	}
	cout << st.rmq(0, mx) << '\n';
	return 0;
}