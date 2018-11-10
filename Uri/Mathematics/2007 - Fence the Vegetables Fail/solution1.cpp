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

struct nodest{
	long long value;
	nodest *left, *right;
	nodest():value(0), left(nullptr), right(nullptr){}
};

typedef nodest* pnode;

pnode update(pnode cur, int L, int R, int pos, int value){
 	if(!cur) cur = new nodest();
	
	if(pos < L || R < pos)
		return cur;
	if(L==R && L==pos){
	 	cur->value=value;
		return cur;
	}
	int mid = (L + R)>>1;
	cur->left = update(cur->left, L, mid, pos, value);
	cur->right = update(cur->right, mid + 1, R, pos, value);
	cur->value = cur->left->value + cur->right->value;
	return cur;
}

int query(pnode cur, int L , int R, int i, int j){
	if(!cur) return 0;
 	if(j < L || R < i)
		return 0;
	if(i <= L && R <= j)
		return cur->value;
	int mid = (L + R)>>1;
	return query(cur->left, L, mid, i, j) + query(cur->right, mid+1, R, i, j);
}

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
	sort(points.begin(), points.end());
	pnode root = new nodest();
	long long ans = 0;
	for(auto it: points){
	 	if(it.type==0){
			root = update(root, -1000000000, 1000000000, it.y, 0);
			//cout << "delet: " << st.rsq(0) << ' ' << it.x << ' ' << it.y << '\n';
		}
		if(it.type==1){
			update(root, -1000000000, 1000000000, it.y, 1);
			//cout << "insert: " << st.rsq(0) << ' ' << it.x << ' ' << it.y << '\n';
		}
		if(it.type==3){
			if((query(root, -1000000000, 1000000000, it.y, 1000000000)&1) == 0)
				ans += it.valor;
			//cout << "planta: " << st.rsq(0) << ' ' << it.x << ' ' << it.y << '\n';
		}
	}
	cout << ans << '\n';
	return 0;
}