#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct node{
	int x, y, type, valor;
	node(int _x,int _y, int _type, int _valor): x(_x), y(_y), type(_type), valor(_valor){}
	bool operator <(node other) const
	{
	        if(x==other.x)
			return type < other.type;
		else
			return x < other.x;
	}	
};

class SegmentTree {
	private: vi st, A;
	int n;
	int left(int p) { return p << 1;}
	int right (int p) { return (p << 1) + 1; }
	
	void build(int p, int L, int R){
	 	if(L==R)
			st[p] = A[L];
		else{
			int mid = (L + R)>>1, izq = left(p), der = right(p);
		 	build(izq, L, mid);
			build(der, mid + 1, R);
			st[p] = st[izq] + st[der];
		}
	}

	void update(int p, int L , int R, int pos, int value){
	 	if(L==R && L==pos){
			A[L] = value;
			st[p] = A[L];
		}else{
			if( pos < L || R < pos)
				return;
			int mid = (L + R)>>1, p1 = left(p), p2 = right(p);
			update(p1, L, mid, pos, value);
			update(p2, mid + 1, R, pos, value);
			st[p] = st[p1] + st[p2];
		}
	}
	
	int rsq(int p, int L, int R, int i, int j){
	 	if( i > R || j <L)
			return 0;
		if(i <= L && R <= j) return st[p];
		int mid = (L + R)>>1;
		return rsq(left(p), L, mid, i, j) + rsq(right(p), mid + 1, R, i, j);
	}

	public:
	SegmentTree(){
	 	A.assign(200005, 0);
		n = A.size();
		st.assign(4*n, 0);
		//build(1, 0, n-1);
	}

	int rsq(int i){
	 	return rsq(1, 0, n-1, i, n-1);
	}

	void update(int i, int value){
	        update(1, 0, n-1, i, value);
	}	
};



int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int p, v, x, y;
	cin >> p >> v;
	vector<node> points;
	set<int> sety;
	for(int i=1; i<=p; i++){
	 	cin >> x >> y;
		sety.insert(y);
		points.emplace_back(node(x,y,3, i));
	}
	cin >> x >> y;
	int primero = points.size();
	points.emplace_back(node(x, y, -1, 0));
	for(int i=1; i<v; i++){
		cin >> x >> y;
		sety.insert(y);
		points.emplace_back(node(x, y, -1, 0));
		int tam = points.size()-2;
		if(x!=points[tam].x){
			if(x<points[tam].x){
			 	points[tam+1].type = 1;
				points[tam].type = 0;
			}else{
				points[tam+1].type = 0;
				points[tam].type = 1;
			}
		}	
	}
	if(points[primero].y==points[points.size()-1].y){
		if(points[primero].x < points[points.size()-1].x){
		 	points[primero].type = 1;
			points[points.size()-1].type = 0;
		}else{
			points[primero].type = 0;
			points[points.size()-1].type = 1;
		}
	}
	int j=1;
	map<int,int> m;
	for(int it: sety){
	 	m[it]=j;
		j++;
	}
	sort(points.begin(), points.end());
	SegmentTree st;
	long long ans = 0;
	for(auto it: points){
	 	if(it.type==0){
			st.update(m[it.y], 0);
			//cout << "delet: " << st.rsq(0) << ' ' << it.x << ' ' << it.y << '\n';
		}
		if(it.type==1){
			st.update(m[it.y], 1);
			//cout << "insert: " << st.rsq(0) << ' ' << it.x << ' ' << it.y << '\n';
		}
		if(it.type==3){
			if((st.rsq(m[it.y])&1) == 0)
				ans += it.valor;
			//cout << "planta: " << st.rsq(0) << ' ' << it.x << ' ' << it.y << '\n';
		}
	}
	cout << ans << '\n';
	return 0;
}