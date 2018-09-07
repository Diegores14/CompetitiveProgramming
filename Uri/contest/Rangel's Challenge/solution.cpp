#include <bits/stdc++.h>
using namespace std;

struct node{
  	int value;
  	node *left, *right;
  	node(int valor){ value=valor; left=nullptr; right=nullptr;}
};

node* insert(node *nodo, int value){
 	if(nodo==nullptr) return new node(value);
 	if(nodo->value==value) return nodo;
 	if(nodo->value<value) nodo->right = insert(nodo->right, value);
 	else nodo->left = insert(nodo->left, value);
 	return nodo;
}

int busqueda(node* nodo, int value){
 	if(nodo->value==value){   
 	 	if(nodo->right==nullptr) return -1;
 	 	else return nodo->right->value;
 	}
 	if(nodo->value<value) return busqueda(nodo->right, value);
 	else return busqueda(nodo->left, value);
}

int main(){
	//ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	cin >> n;
	vector<int> v(n);        
	node* root=nullptr;
	for(int i=0; i<n; i++){ cin >> v[i]; root = insert(root, v[i]);}
	for(int i=0; i<n; i++){		
	 	int x = busqueda(root, v[i]);
	 	if(x==-1) cout << "*";
	 	else cout << x;
	 	cout << ((n-1==i)? '\n' : ' ');
	}
	return 0;
}