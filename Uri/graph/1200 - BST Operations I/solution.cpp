#include <bits/stdc++.h>
using namespace std;
string inf, pre, post;

struct node{
	char value;
	node *left, *right;
	node(char _value){value = _value; left = nullptr; right = nullptr;}
};

node* insert(node* nodo,char value){
 	if(nodo==nullptr)return new node(value);
 	if(value < nodo->value) nodo->left = insert(nodo->left, value);
 	else nodo->right = insert(nodo->right, value);
 	return nodo;
}

bool Search(node* nodo,char value){
 	if(nodo==nullptr)return false;
 	if(nodo->value == value) return true;
 	if(value < nodo->value)return Search(nodo->left, value);
 	else return Search(nodo->right, value);
}

void preorden(node* nodo){
	if(nodo==nullptr)return;
 	pre.push_back(nodo->value);
 	preorden(nodo->left);
 	preorden(nodo->right);
}

void inorden(node* nodo){
	if(nodo==nullptr)return;
 	inorden(nodo->left);
 	inf.push_back(nodo->value);
 	inorden(nodo->right);
}

void postorden(node* nodo){
	if(nodo==nullptr)return;
 	postorden(nodo->left);
 	postorden(nodo->right);
  	post.push_back(nodo->value);	
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	node* root=nullptr;
	char c;
	int i=0;
	while(cin >> s){	 	
		if(s.size()==1){
		 	if(s=="I"){ cin >> c; root = insert(root, c);}
		 	if(s=="P"){ if(i==0) i++; else cout << '\n'; cin >> c; cout << c << ((Search(root, c))? " existe" : " nao existe");}
		}
		if(s.size()>1){
			if(i==0) i++;
		 	else cout << '\n';
		 	if(s=="INFIXA"){inf=""; inorden(root); for(int i=0; i<(int)inf.size()-1; i++)cout << inf[i] << ' '; cout << inf[inf.size()-1];}
		 	if(s=="PREFIXA"){pre=""; preorden(root); for(int i=0; i<(int)pre.size()-1; i++) cout << pre[i] << ' '; cout << pre[pre.size()-1];}
		 	if(s=="POSFIXA"){post=""; postorden(root); for(int i=0; i<(int)post.size()-1; i++) cout << post[i] << ' '; cout << post[post.size()-1];}
		}
	}
	cout << '\n';
	return 0;
}