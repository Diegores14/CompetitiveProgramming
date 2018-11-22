#include <bits/stdc++.h>
using namespace std;
struct node{
	char value;
	node *next;
	node(char s){ value = s; next = nullptr;}
};

class managerStack{
	public:
	node *first, *last;
	int size;
	managerStack(){
		first = last = nullptr;
		size = 0;
	}
	void push(char  s){
		size++;
		node *aux = new node(s);
		if(first == nullptr){
			first = aux;
		}
		aux->next = last;
		last = aux;
	}
	void push1(char  s){
		size++;
		node *aux = new node(s);
		if(last == nullptr){
			last = aux;
			first = aux;
		}else{
			first->next = aux;
		}
		first = aux;
	}
	char pop(){
		size--;
		if(last == nullptr)
			return 'w';
		node *aux = last;
		last = last->next;
		return aux->value;
	}
	void clear(){
		size = 0;
	 	first = last = nullptr;
	}
	void Union(managerStack & m){
		size += m.size;
		first->next = m.last;
		first = m.first;
		m.clear();
	}
};

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	while(cin >> s, s != "#"){
		managerStack dealer, noDealer, pila;
		noDealer.push(s[1]);
		for(int i = 1; i < 52; i++){
			cin >> s;
			if(i&1)
				dealer.push(s[1]);
			else
				noDealer.push(s[1]);
		}
		int cant = 0;
		bool turn = true, winPila = false; 
		while(true){
			// cout << "hello\n";
			if(turn){
				char aux = noDealer.pop();
				// cout << aux << ' ' << turn << '\n';
				pila.push1(aux);
				if(aux == 'w')
					break;
				if(aux == 'J'){
					cant = 1;
					turn = !turn;
					winPila = true;
				}
				if(aux == 'Q'){
					cant = 2;
					turn = !turn;
					winPila = true;
				}
				if(aux == 'K'){
					cant = 3;
					turn = !turn;
					winPila = true;
				}
				if(aux == 'A'){
					cant = 4;
					turn = !turn;
					winPila = true;
				}
				// cout << "hi\n";
			}else{
				char aux = dealer.pop();
				// cout << aux << ' ' << turn << '\n';
				pila.push1(aux);
				if(aux == 'w')
					break;
				if(aux == 'J'){
					cant = 1;
					turn = !turn;
					winPila = true;
				}
				if(aux == 'Q'){
					cant = 2;
					turn = !turn;
					winPila = true;
				}
				if(aux == 'K'){
					cant = 3;
					turn = !turn;
					winPila = true;
				}
				if(aux == 'A'){
					cant = 4;
					turn = !turn;
					winPila = true;
				}
			}
			if(cant > 0)
				cant--;
			else{
				turn = !turn;
				if(winPila){
					if(turn){
						noDealer.Union(pila);
					}else{
						dealer.Union(pila);
					}
					winPila = false;
				}
			}
		}
		if(turn)
			cout << "1 " << dealer.size << '\n';
		else
			cout << "2 " << noDealer.size << '\n';
	}
	return 0;
}