#include <bits/stdc++.h>
using namespace std;

struct node{
  	int character, cont;
	node(int c){character=c;cont=1;}
};

bool operator <(node a, node b){
 	if(a.cont != b.cont)return a.cont < b.cont;
	else return a.character > b.character;
}

int main(){
 	string s; 
	int k=0;
	while(getline(cin, s)){
		if(k++)cout << '\n';
		vector<int> used(255,-1);
		vector<node> v;
		for(char to : s){
			if(used[(int)to]==-1){
				v.push_back(node((int)to));
				used[(int)to]=v.size()-1;
			}else{
				v[used[(int)to]].cont++;
			}
		}
	 	sort(v.begin(),	v.end());
		for(node to : v)cout << to.character << ' ' << to.cont << '\n';
	}
	return 0;
}