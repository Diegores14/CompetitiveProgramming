#include <bits/stdc++.h>
using namespace std;

struct node{
  	int value;
  	node *left, *right;
  	node(int a){value=a; left=nullptr; right=nullptr;}
};

node* insert(node* a, int value){
	if(a==nullptr){return new node(value);}
	if(a->value > value)a->left = insert(a->left, value);
        else a->right = insert(a->right, value);
        return a;
}

void preorden(node* a){
	if(a==nullptr)return;
 	cout << ' ' << a->value;
 	preorden(a->left);
 	preorden(a->right);
}

void inorden(node* a){
 	if(a==nullptr)return;
 	inorden(a->left);
 	cout << ' ' << a->value;
 	inorden(a->right);
}

void postorden(node* a){
 	if(a==nullptr)return;
 	postorden(a->left);
 	postorden(a->right);
 	cout << ' ' << a->value;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, aux;
	cin >> t;
	for(int i=1; i<=t; i++){
		cin >> n;
		node* root = nullptr;
		while(n--){
		 	cin >> aux;
		 	root = insert(root, aux);
		}
		cout << "Case " << i << ":\n";
		cout << "Pre.:";
		preorden(root); cout << '\n';
		cout << "In..:";
		inorden(root); cout << '\n';
		cout << "Post:";
		postorden(root); cout << "\n\n";
	}
 	return 0;
}