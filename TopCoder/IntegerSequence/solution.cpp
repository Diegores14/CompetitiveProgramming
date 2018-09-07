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
  			if(i==L && R==i){ A[i]=value;}
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

class IntegerSequence{
    public:
    int maxSubsequence(vector<int> v){
        int ans=0;
        map<int,int> m;
        int n = v.size();
        for(int i=0; i<n; i++)m[v[i]]=0;
        int i=1;
        for(map<int,int>::iterator it = m.begin(); it != m.end(); ++it, i++){it->second=i;}
     	vi d1(v.size(), 0), d2(v.size(), 0);
        SegmentTree st1(60), st2(60);
        for(i=0; i<n; i++){
        	d1[i] = st1.rmq(0,m[v[i]]-1)+1;
            st1.update( m[v[i]], d1[i]);
        }
        for(i=n-1; i>=0; i--){
        	d2[i] = st2.rmq(0,m[v[i]]-1)+1;
            st2.update( m[v[i]], d2[i]);
        }
        for(int i=0; i<n; i++){
         	ans = max(ans, d1[i]+d2[i]-1);
        }
        return v.size()-ans;
    }   
};


int main(){
 	vector<int> v = {4,5,65,34,786,45678,987,543,2,6,98,580,4326,754,54,2,1,3,5,6,8,765,43,3,54};
 	IntegerSequence is;
 	cout << is.maxSubsequence(v) << '\n';

}