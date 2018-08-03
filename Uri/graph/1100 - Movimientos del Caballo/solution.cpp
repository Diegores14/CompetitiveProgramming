#include <bits/stdc++.h> 
using namespace std;

set<string> used;

struct node{
  	string s;
  	int cont;
  	node(string a, int b){s=a; cont = b;}
};


int BFS(string a, string & b){
	list<node> l;
	l.push_back(node(a, 0));
	while(l.front().s != b){
		if(!used.count(l.front().s)){
			used.insert(l.front().s);
			string s = l.front().s;
			int cont = l.front().cont;
			if((s[0]-'a'-2)>=0){
				string aux=s;
				aux[0]-=2;
			 	if((s[1]-'0'+1)<=8){aux[1]=s[1]+1;l.push_back(node(aux, cont+1));}
	 			if((s[1]-'0'-1)>0){aux[1]=s[1]-1;l.push_back(node(aux, cont+1));}
			}
			if((s[0]-'a'+2)<8){
				string aux=s;
				aux[0]+=2;
	 			if((s[1]-'0'+1)<=8){aux[1]=s[1]+1;l.push_back(node(aux, cont+1));}
		 		if((s[1]-'0'-1)>0){aux[1]=s[1]-1;l.push_back(node(aux, cont+1));}
			}
			if((s[1]-'0'+2)<=8){
				string aux=s;
				aux[1]+=2;
			 	if((s[0]-'a'-1)>=0){aux[0]=s[0]-1;l.push_back(node(aux, cont+1));}
	 			if((s[0]-'a'+1)<8){aux[0]=s[0]+1;l.push_back(node(aux, cont+1));}
			}
			if((s[1]-'0'-2)>0){
				string aux=s;
				aux[1]-=2;
	 			if((s[0]-'a'-1)>=0){aux[0]=s[0]-1;l.push_back(node(aux, cont+1));}
		 		if((s[0]-'a'+1)<8){aux[0]=s[0]+1;l.push_back(node(aux, cont+1));}
			}
		}
		l.pop_front();
	}
	return l.front().cont;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s1, s2;
	while(cin >> s1 >> s2){
		used.erase(used.begin(), used. end());
	 	cout << "To get from " << s1 << " to " << s2 << " takes " << BFS(s1, s2) << " knight moves.\n";
	}
	return 0;
}