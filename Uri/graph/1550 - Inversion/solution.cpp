#include <bits/stdc++.h>
using namespace std;

set<int> used;

struct node{
  	string a;
  	int cont;
  	node(string _a, int _cont){ a = _a; cont = _cont;}
};

void answer(string a, int b){
 	//if(stoi(a) == b)return 0;
	queue<node> q;
	q.push(node(a, 0));
	used.insert(atoi(a.c_str()));
	while(!q.empty() && stoll(q.front().a) != b){
		string aux = q.front().a;
		int cont = q.front().cont;	 	
	 	if(used.count(stoll(aux)+1)==0){
	 		used.insert(stoll(aux)+1);
	 		q.push(node(to_string(stoll(aux)+1), cont+1));
	 	}
	 	reverse(aux.begin(),aux.end());
	 	if(used.count(stoll(aux))==0){
	 		used.insert(stoll(aux));
	 		q.push(node(aux, cont+1));
		}
	 	q.pop();
	}
	assert(!q.empty());
	cout << q.front().cont << '\n';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t, b;
	string a;
	cin >> t;
	while(t--){
	        cin >> a >> b;
	        used.erase(used.begin(), used.end());
		answer(a, b);

	}	
	return 0;
}