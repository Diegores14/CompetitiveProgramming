#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	stack<char> pila;
	while(n--){
	 	cin >> s;
		for(char to : s){
			//char to =s[i];
			//cout << s[i];
			if(('0'<= to && to <='9') || ('a'<= to && to <='z') || ('A'<= to && to <='Z'))cout << to;
			else{
			 	if(to=='('){pila.push(to);continue;}
				if(to==')'){
					while(pila.top()!='('){cout << pila.top(); pila.pop();}
					pila.pop();
					continue;
				}
				if(!pila.empty() && (to=='*' || to=='/') && (pila.top()=='^')){
					while(!pila.empty() && pila.top()!='('){
						cout << pila.top();
						pila.pop();
					}
					pila.push(to);
					continue;
				}
				if(!pila.empty() && (to=='*' || to=='/') && (pila.top()=='/' || pila.top()=='*')){
					cout << pila.top(); 
					pila.pop();pila.push(to);
					continue;
				}
				//if(to=='*'){pila.push(to);continue;}
				//if(to=='/' && pila.top()=='*'){cout << pila.top(); pila.pop();pila.push(to);continue;}
				//if(to=='/'){pila.push(to);continue;}
				if(!pila.empty() && (to=='+' || to=='-') && (pila.top()=='/' || pila.top()=='*' || pila.top()=='^')){
					while(!pila.empty() && pila.top()!='('){
						cout << pila.top();
						pila.pop();
					}
					pila.push(to);
					continue;
				}
				if(!pila.empty() && (to=='+' || to=='-') && (pila.top()=='+' || pila.top()=='-')){
					cout << pila.top(); 
					pila.pop();
					pila.push(to);
					continue;
				}
				//if(to=='+'){pila.push(to);continue;}
				pila.push(to);
			}
		}
		while(!pila.empty()){cout << pila.top(); pila.pop();}
		cout << '\n';
	}
 	return 0;
}