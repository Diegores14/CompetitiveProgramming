#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

class SegmentTree{
 	private: vi st;
 	string A;
 	int n;
 	int left(int p){return (p<<1);}
 	int right(int p){ return (p<<1)+1;}
 	void build(int p, int L, int R){
 	 	if(L==R)
 	 		st[p]=L;
 	 	else{
 	 		int mid = (L+R)/2;
 	 	        build(left(p), L, mid);
 	 	        build(right(p), mid + 1, R);
			int p1= st[left(p)], p2 = st[right(p)];
			st[p]=(A[p1]>=A[p2])? p1 : p2;
 	 	}
 	}
 	int rmq(int p, int L, int R, int i, int j){
 	 	if(i>R || j<L) return -1;
 	 	if(i <= L && R <= j)return st[p];
 	 	int mid = (L+R)/2;
 	 	int p1 = rmq(left(p), L, mid, i, j);
 	 	int p2 = rmq(right(p), mid+1, R, i, j);
 	 	if(p1==-1)return p2;
 	 	if(p2==-1)return p1;
 	 	return (A[p1]>=A[p2])? p1 : p2;
 	}

 	public:
 	SegmentTree(string & _A){
 	 	A=_A;n=(int)A.size();
 	 	st.assign(4*n,0);
 	 	build(1, 0, n-1);
 	}
 	int rmq(int i, int j){ return rmq(1, 0, n-1, i, j);}
};


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, d, aux, pos;
	string s;
	while(cin >> n >> d, n || d){
	 	cin >> s;
	 	pos=0;
	 	aux = n-d;
	 	SegmentTree t(s);
		while(aux){
			--aux;
			pos=t.rmq(pos,n-aux-1);
			cout << s[pos];
			pos++;	
		}
		cout << '\n';
	}
	return 0;
}