#include <bits/stdc++.h>
using namespace std;
struct node{
	char value;
	node* next;
	node(char s){ value = s; next = nullptr;}
};

class managerStack{
	public:
	node *first, *last;
	managerStack{
		first = last = nullptr;
	}
	void push(char  s){
		node *aux = new node(s);
		if(first == nullptr){
			first = aux;
		}
		aux.next = last;
		last = aux;
	}
	void push1(char  s){
		node *aux = new node(s);
		if(first == nullptr){
			first = aux;
		}
		aux.next = last;
		last = aux;
	}
	char pop(){
		if(last == nullptr)
			return 'w';
		node *aux = last;
		last = last.next;
		return aux.value;
	}
	void clear(){
	 	first last = nullptr;
	}
	void union(managerStack & m){
		first.next = 
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	while(cin >> s, s != "#"){
		stack<string> dealer, noDealer, ;
		noDealer.push(s);
		for(int i = 1; i < 52; i++){
			cin >> s;
			if(i&1)
				dealer.push(s);
			else
				noDealer.push(s);
		}

	}
	return 0;
}