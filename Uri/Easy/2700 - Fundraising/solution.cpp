#include <bits/stdc++.h>
using namespace std;

struct node{
	long long value;
	node *left, *right;
	node():value(0), left(nullptr), right(nullptr){}
};

typedef node* pnode;
int tope = 1000000005;

struct guest{
	int b, f;
	guest(int _b, int _f): b(_b), f(_f){}
	bool operator <(guest other)const
	{
	 	if(b == other.b){
	 	 	return f < other.f;
		}else
			return b > other.b;
	}
};

pnode update(pnode p, int L, int R, int pos, long long value){
	if(!p) p = new node();
	if(pos < L || R < pos)
		return p;
	if(L==R && pos == L){
	        p->value = value;
		return p;
	}	
	int mid = (L + R)>>1;
	p->left = update(p->left, L, mid, pos, value);
	p-> right = update(p->right, mid + 1, R, pos, value);
	p->value = max(p->left->value, p->right->value);
	return p;
}

long long query(pnode p, int L, int R, int i, int j){
	if(!p)
		return 0;
	if(j < L || R < i)
		return 0;
	if(i <= L && R <= j)
		return p->value;
	int mid = (L + R)>>1;
	long long a = query(p->left, L, mid, i, j);
	long long b = query(p->right, mid + 1, R, i, j);
	return max(a, b);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b, c;
	cin >> n;
	map<guest, long long> guests;
	for(int i=0; i<n; i++){
	 	cin >> a >> b >> c;
		guests[guest(a, b)] += c;
	}                                  
	pnode root = nullptr;
	for(auto it: guests){
		long long mmax = it.second + query(root, 0, tope, it.first.f+1, tope);
		// cout << mmax << '\n';
		if(mmax > query(root, 0, tope, it.first.f, it.first.f)){
		 	root = update(root,0, tope, it.first.f, mmax);
		}
	}
	cout << query(root, 0, tope, 0, tope) << '\n';
	return 0;
}