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
            st[p] = L;
        else{
            build(left(p)  , L, (L+R)/2);
            build(right(p), (L+R)/2+1, R);
            int p1=st[left(p)], p2 = st[right(p)];    
            st[p] = (A[p1] >= A[p2])? p1 : p2;
        }
    }
    int rmq(int p, int L, int R, int i, int j){
        if(i > R || j < L)return -1;
        if(L >= i && R <= j) return st[p];
        int p1 = rmq(left(p), L, (L+R)/2, i, j);
        int p2 = rmq(right(p), (L+R)/2+1, R, i, j);
        
        if(p1 == -1)return p2;
        if(p2 == -1)return p1;
        return (A[p1] >= A[p2])? p1 : p2;
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
        st.assign(14*n, 0);
        build(1, 0, n-1);
    }
    
    long long rmq(int i, int j){
        return A[rmq(1, 0, n-1, i, j)];
    }
    
    void update(int i, int w){A[i]+=w; update(1, 0, n-1, i);}
};

int main(){
 	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n,k, ps, s, sum, mx, pos;
	cin >> n >> k;
	ps=n%k;       
	s=(ps)? (n-ps)/(k-1) : n/k;
	ps+=(ps!=0)? ((n-ps)%(k-1)) : 0;
	vector<int> v(n);
	for(int i=0; i<n; i++) cin >> v[i];
	segmenTree st(v);
	mx=0;
	pos=0;
	for(int i=0; i<n-ps; i+=s){
	 	int j=0;
	 	sum=0;
	 	while(j<n-ps){
	 	 	if(j==i && ps != 0){sum+=st.rmq(j,j+ps-1);j+=ps;}
	 	 	else{sum+=st.rmq(j,j+s-1);j+=s;}
	 	}
	 	if(mx < sum){mx=sum; pos=i;}
	}
	cout << mx << '\n';
	for(int i=0; i<k;i++)                     
		cout << ((i == pos && ps!=0)? ps : s) << ((i==k-1)? '\n' : ' ');
	return 0;
}