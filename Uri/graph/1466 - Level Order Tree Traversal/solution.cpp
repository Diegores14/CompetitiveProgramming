#include <bits/stdc++.h>
using namespace std;

struct node{
	int value;
	node *left, *right;
	node(int a){value = a; left = nullptr; right = nullptr;}
};

queue<node*> q;

node* insert(node* nodo, int value){
	if(nodo==nullptr) return new node(value);
	if(value<nodo->value)nodo->left = insert(nodo->left, value);
	else nodo->right = insert(nodo->right, value);
	return nodo;
}

void FIFO(node* nodo){
 	q.push(nodo);
 	cout << nodo->value;
 	while(!q.empty()){
 		if(q.front()->left!=nullptr)q.push(q.front()->left);
 		if(q.front()->right!=nullptr)q.push(q.front()->right);
 		q.pop();
 		if(q.empty())break;
 	 	cout << ' ' << q.front()->value; 
 	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, n, aux;
	cin >> t;
	for(int i=1; i<=t; i++){
	 	cin >> n;
	 	cout << "Case " << i << ":\n";
	 	node* root=nullptr;
	 	while(n--){
	 	 	cin >> aux; 
	 	 	root = insert(root, aux);			
	 	}
	 	FIFO(root);
	 	cout << "\n\n";
	}
	return 0;
}