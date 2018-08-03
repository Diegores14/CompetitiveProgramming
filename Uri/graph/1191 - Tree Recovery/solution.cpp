#include <bits/stdc++.h>
using namespace std;

map<char,int> m;

struct node{
	char value;
	node *left, *right;
	node(int a){value=a; left=nullptr; right= nullptr;}
};

node* insert(node *nodo, char value){
	if(nodo == nullptr)return new node(value);
	if(m[nodo->value] > m[value])nodo->left = insert(nodo->left, value);
	else nodo->right = insert(nodo->right, value);
	return nodo;
}

void postorden(node *nodo){
 	if(nodo ==nullptr) return;
 	postorden(nodo->left);
 	postorden(nodo->right);
 	cout << nodo->value;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s1, s2;
	while(cin >> s1 >>s2){
		m.erase(m.begin(), m.end());
		for(int i=0; i<(int)s2.size(); i++)m[s2[i]] = i;
		node* root= new node(s1[0]);
		for(int i=1; i<(int)s1.size(); i++){
		 	insert(root, s1[i]);
		}
		postorden(root);
		cout <<'\n';
	}
 	return 0;
}