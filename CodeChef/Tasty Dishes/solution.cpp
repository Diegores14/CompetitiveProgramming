#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
	private: vi st, A;
	int N;
	left(int p){ return p<<1;}
	right(int p){ return (p<<1)+1;}
	void build(int p, int L, int R){
	 	if(L==R) st[p]= L;
	 	else{	
	 		int mid = (L+R)/2;
			build(left(p), L, mid);
			build(right(p), mid+1, R);
			int x = st[left(p)], y = st[right(p)];
			st[p] = (A[x] <= A[y])? x: y;
	 	}		 	
	}
	int rmq(int p, int i, int j, int L, int R){
	 	if(j<L || R<i)return -1;
	 	if(i<=L && R<=j) return st[p];
	 	int mid = (L+R)/2;
	 	int p1 = rmq(left(p), i, j, L, mid);
		int p2 = rmq(right(p), i, j, mid+1, R);
		if(p1==-1) return p2;
		if(p2==-1) return p1;
		return (A[p1]<=A[p2])? p1 : p2;
	}
	public:
	SegmentTree(vi & _A){
		A=_A;
		N=A.size();
	 	st.assign(4*N, 0);
	 	build(1, 0, N-1); 
	}

	int rmq(int i, int j){
	 	return rmq(1, i, j, 0, N-1);
	}

};

long long answer(vi & v, vector<long long> & pre, int & k, int L, int R, SegmentTree & st){
	//cout << L << ' ' << R <<'\n';
	if(L>=R) return 0;
 	long long ans=0;
 	int mini=st.rmq(L,R);
 	for(int i=L; i<=mini; i++){
 	 	for(int j=R; mini<=j && i!=j; j--)if((pre[j+1]-pre[i]-v[mini])%k==0)ans++;
 	}
 	return answer(v, pre, k, L, mini-1, st) + answer(v, pre, k, mini+1, R, st) + ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, k;
	cin >> n >> k;
	vi v(n, 0);
	vector<long long> preffixSum(n+1, 0);
	for(int i=0; i<n; i++){cin >> v[i]; preffixSum[i+1]=preffixSum[i]+v[i];}
 	SegmentTree st(v);
	cout << answer(v, preffixSum, k, 0, n-1, st) << '\n';
 	return 0;
}