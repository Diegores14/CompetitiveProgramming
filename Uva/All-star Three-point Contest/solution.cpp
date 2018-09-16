#include <bits/stdc++.h>
using namespace std;

struct node{
	string s, s1; 
	int value;
	node(){value=0;}
	node(string aux, string aux1,int val){s=aux; s1=aux1; value=val;}
};

bool operator <(node a, node b){
	if(a.value==b.value)return a.s1 < b.s1;
	else return a.value > b.value;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	int cas = 1;
	while(cin >> n){
	 	string aux;
		cin.ignore();
		vector<node> v(n);
		for(int i=0; i<n; i++){
		 	getline(cin, aux);
			int valor = 0;
			string s = aux.substr(0, (int)aux.size()-50);
			int j = (int)aux.size()-49;
			for(int k=0; k<5; k++){
			 	for(int r=0; r<10; r+=2){
			 	 	if(aux[j] == '1') valor += ((r==8)? 2 : 1);
					j+=2;
				}
			}
			string s1=s;
			for(int k=0; k<(int)s.size(); k++)if('A'<= s1[k] && s1[k] <= 'Z')s1[k]+=32;
			v[i].s = s;
			v[i].s1 = s1;
			v[i].value = valor;
		}
		sort(v.begin(), v.end());
		cout << "Case " << cas++ << ":\n";
		for(node &to : v){
		 	cout << to.s << " " << to.value << '\n';
		}
	}
	return 0;
}