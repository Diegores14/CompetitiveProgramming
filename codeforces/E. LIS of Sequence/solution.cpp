#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

vector<int> ans;
int grande=0;

struct node{
  	int first, second;
  	node(){first=0; second=0;}
};



class SegmentTree{
	private:
	vi st, A;
	left(int p){ return p<<1;}
	right(int p){ return (p<<1)+1;}
	void build(int p, int L, int R){
	 	if(L==R)st[p]=R;
	 	else{
	 	 	int mid=(L+R)>>1;
	 	 	build(left(p), L, mid);
	 	 	build(right(p), mid+1, R);
	 	 	int x = st[left(p)], y = st[right(p)];
	 	 	st[p] = (A[x]>=A[y])? x : y;
	 	}
	}
	
	int rmq(int p, int i, int j, int L, int R){
	 	if(R<i || j<L) return -1;
	 	if(i<=L && R<=j){return st[p];}
	 	int mid=(L+R)>>1;
	 	int x = rmq(left(p), i, j, L, mid);
	 	int y = rmq(right(p), i, j, mid+1, R);
	 	if(x==-1)return y;
	 	if(y==-1)return x;
		return (A[x]>=A[y])? x : y;
	}

	void update(int p, int i, int value, int L, int R){
		if(i<L || R<i) return;
	 	if(L==R && L == i){A[i]=value;} 
	 	else{
	 	 	int mid=(L+R)>>1;
	 	 	update(left(p), i, value, L, mid);
	 	 	update(right(p), i, value, mid+1, R);
	 	 	int x = st[left(p)], y = st[right(p)];
	 	 	st[p] = (A[x]>=A[y])? x : y;
	 	}
	}
	public:
	SegmentTree(){
	 	st.assign(4*100001, 0);
	 	A.assign(100001, 0);
	 	build(1, 0, 100000);
	}

	int rmq(int i, int j){                          		                  
	 	return A[rmq(1, i, j, 0, 100000)];
	}

	void update(int i, int value){
		update(1, i, value, 0, 100000);
	}
};

int sol(vector<node> & v, int mx, int n, int value){
	int cont = (n==-1)? 1 : 0;
 	for(int i=n; i>=0; i--){
 	 	if(v[i].second==mx && v[i].first<value){			
			int aux = sol(v, mx-1, i-1, v[i].first);
			cont += aux;
			ans[i] += aux;
			grande = max(grande, ans[i]);
 	 	}
 	} 	
 	return cont;
}

int main(){
	//ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	vector<node> v(n);
	ans.assign(n, 0);
	for(int i=0; i<n; i++) cin >> v[i].first;
	SegmentTree st;	
	for(int i=0; i<n; i++){
	 	v[i].second = st.rmq(0, v[i].first-1)+1;
	 	st.update(v[i].first, v[i].second);
	}
	sol(v, st.rmq(0, 100000), n-1, 1000000);
	for(int i=0; i<n; i++){
	 	if(ans[i]==0)cout <<"1";
	 	else{
	 	 	if(ans[i]==grande) cout << "3";
	 	 	else cout << "2";
	 	}
	}
	cout << '\n';
	return 0;
}