#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

class SegmentTree{
	private: vi st, A;
	left(int p){ return p<<1;}
	right(int p){ return (p<<1)+1;}
	void build(int p, int L, int R){
	 	if(L==R) st[p]= L;
	 	else{	
	 		int mid = (L+R)/2;
			build(left(p), L, mid);
			build(right(p), mid+1, R);
			int x = st[left(p)], y = st[right(p)];
			st[p] = (A[x] < A[y])? x: y;
	 	}		 	
	}


};

int main(){
	ios_base::sync_with_stdio(false); cint.tie(NULL);

 	return 0;
}