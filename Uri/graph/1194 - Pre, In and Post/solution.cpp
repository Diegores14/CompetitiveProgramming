#include <bits/stdc++.h>
using namespace std;

struct node{
  	char c;
  	node *left, *right;
  	node(char a){ c=a; left=nullptr; right = nullptr;}
};
 

map<char,int> m;

node* insert(node* a, char value){
 	if(a == nullptr) return new node(value);
 	if(m[a->c]>m[value]) a->left = insert(a->left, value);
 	else a->right = insert(a->right, value);
 	return a;
}

void postorden(node* a){
 	if(a==nullptr)return;
 	postorden(a->left);
 	postorden(a->right);
 	cout << a->c;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int t, n;
	string s1, s2;
	cin >> t;
	while(t--){
	 	cin >> n >> s1 >> s2;
	 	m.erase(m.begin(),m.end());
	 	for(int i=0; i<n; i++){
	 	 	m[s2[i]]=i;
	 	}
		node* root = new node(s1[0]);
		for(int i=1; i<n; i++) insert(root, s1[i]);
		postorden(root);
		cout << '\n';
	}
 	return 0;
}