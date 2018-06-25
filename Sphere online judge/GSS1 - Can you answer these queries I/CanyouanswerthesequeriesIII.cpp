#include <bits/stdc++.h>
using namespace std;
#define vi vector<long long>


class segmenTree{
    private: vi st, A;
    int n;
    int left(int p){return p<<1;}
    int right(int p){return (p<<1)+1;}
    
    void build(int p, int L, int R){
        if(L==R)    
            st[p] = A[L];
        else{
            build(left(p)  , L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            long long p1=st[left(p)], p2 = st[right(p)];    
            st[p] = (p1+p2 >= p1 && p1+p2 >= p2)? p1+p2 : (p1>=p2)? p1 : p2;
        }
    }
    long long rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L)return -800000000;
        if(L >= i && R <= j) return st[p];
        long long p1 = rmq(left(p), L, (L+R)/2, i, j);
        long long p2 = rmq(right(p), (L+R)/2+1, R, i, j);                               
        return (p1+p2 >= p1 && p1+p2 >= p2)? p1+p2 : (p1>=p2)? p1 : p2;
    }
    
    void update(int p, int L, int R, int i){
        if(L==R)st[p]=L;
        else if(L<=i && i<=R){
            update(left(p), L, (R+L)/2, i);
            update(right(p), (R+L)/2+1, R, i);
            int p1 = st[left(p)], p2 = st[right(p)];
            st[p] = (A[p1] >= A[p2])? p1 : p2;
        }
    }
    public:
    segmenTree(const vi &_A){
        A = _A; n = (int)A.size();
        st.assign(4*n, -800000000);
        build(1, 0, n-1);
    }
    
    long long rmq(int i, int j){
        return rmq(1, 0, n-1, i, j);
    }
    
    void update(int i, int w){A[i]+=w; update(1, 0, n-1, i);}
};


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int N, q, i, j;       
	cin >> N;
	vi v(N);
	for(int i=0; i<N; i++){
	 	cin >> v[i];
	}
	segmenTree s(v);
	cin >> q;
	while(q--){
		cin >> i >> j;
	 	cout << s.rmq(--i, --j) << '\n';
	}
 	return 0;
}