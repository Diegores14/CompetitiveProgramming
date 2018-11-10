#include <bits/stdc++.h>
using namespace std;

int n;

vector<int> a(100010, 0);
vector<vector<int>> push(100010);
vector<int> loc(100010, 0);

struct node{
	int value;
	node *left, *right;
	node(){
	 	value = 0;
		left = right = nullptr;
	}
	node(node* nod){
	 	value = nod->value;
		left = nod->left;
		right = nod->right;
	}
};

void update(node* & p, int l, int r, int pos){
	if(!p) p = new node();
	else p = new node(p);
	
	if(l == r)
		p->value++;
	else{
		int mid = (l + r)>>1;
		if(pos <= mid)
			update(p->left, l, mid, pos);
		else
			update(p->right, mid+1, r, pos);
		int a = p->left? p->left->value : 0;
		int b = p->right? p->right->value : 0;
		p->value = a + b;
	}
}

int query(node* & p, int l, int r, int limit){
	if(!p) return r;
	if(l==r) return r;
	int value = (p->left? p->left->value : 0), mid = (l + r)>>1;
	if(value > limit)
		return query(p->left, l, mid, limit);
	else
		return query(p->right, mid + 1, r, limit-value);
}

vector<node*> segments(100010);

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n;
	for(int i=1; i<=n; i++){
	 	cin >> a[i];
		push[loc[a[i]]+1].emplace_back(i);
		loc[a[i]] = i;
	}
	segments[0] = new node();
	for(int i=1; i<=n; i++){
	 	segments[i] = new node(segments[i-1]);
		for(int on : push[i]){
		 	update(segments[i], 0, n+1, on);
		}
	}
	for(int k=1; k<=n; k++){
		int ans = 0;
	 	int on = 1;
		while(on<=n){
		 	on = query(segments[on], 0, n+1, on-1+k);
			ans++;
		}
		cout << ans << ((k==n)? '\n' : ' ');
	}
	return 0;
}