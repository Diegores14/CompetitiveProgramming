#include <bits/stdc++.h>
using namespace std;
typedef vector<long long> vi;

const long long mmax = 100000000010;

struct node{
	int level, c;
	long long s;
	bool operator <(node other)const
	{
	 	return level > other.level;
	}
};

class SegmentTree{
	private:
		int n;
		vi A, st;
		int left(int p){ return p<<1; }
		int right(int p){ return (p<<1)+1; }
	
		void update(int p, int L, int R, int pos, int value){
			if(L==R && L==pos){
	                 	A[L] = value;
				st[p] = A[L];
			}else{
			 	if( pos < L || R < pos)
					return;
				int p1 = left(p), p2 = right(p), mid = (L + R)>>1;
				update(p1, L, mid, pos, value);
				update(p2, mid + 1, R, pos, value);
				st[p] = min(st[p1], st[p2]);
			}
		}

		long long rmq(int p, int L, int R, int l, int r){
		 	if(r < L || R < l){
		 	 	return mmax;
			} 
			if(l <= L && R <= r)
				return st[p];
			int mid = (L + R)>>1;
			long long a = rmq(left(p), L, mid, l, r);
			long long b = rmq(right(p), mid + 1, R, l, r);
			return min(a, b);
		}

		public:
			SegmentTree(){
			 	A.assign(100005, mmax);
				n = A.size();
				st.assign(n<<2, mmax);
			}
	
			long long rmq(int i, int j){
			 	return rmq(1, 0, n-1, i, j);
			}

			void update(int pos, int value){
			 	update(1, 0, n-1, pos, value);
			}
};



long long solved(vector<node> &shops, vi &prefix, vi & energy){
 	SegmentTree st;      
	st.update(energy.size(), 0);
	for(auto i: shops){
	 	if(i.s >= energy[i.level]){
			int a = -1, b = prefix.size();
			long long aux = prefix[i.level] + i.s;
			// cout << i.level << ' ' << i.s << ' ' << i.c << ' ' << aux << '\n';
	 	 	while(b-a!=1){
				int mid = (a+b)>>1;
	 	 	 	if(prefix[mid]<=aux)
					a = mid;
				else
					b = mid;
			}
			long long mmin = st.rmq(i.level+1, a);
			// cout << mmin << ' ' << a  << ' ' << mmin <<'\n';
			if(mmin != mmax && (mmin + i.c) < st.rmq(i.level, i.level)){
				st.update(i.level, mmin+i.c);
			}
		}
	}
	return st.rmq(0,0);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	vector<long long> v(n), prefix(n+1, 0);
	for(int i=0; i < n; i++){
	 	cin >> v[i];
		prefix[i+1] = prefix[i] + v[i];
	}
	vector<node> shops(m);
	for(int i=0; i<m; i++){
	 	cin >> shops[i].level >> shops[i].s  >> shops[i].c;
		shops[i].level--;
	}
	sort(shops.begin(), shops.end());
	long long ans = solved(shops, prefix, v);
	if(ans == mmax)
		cout << "-1\n";
	else
		cout << ans << '\n';
	return 0;
}