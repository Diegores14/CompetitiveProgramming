#include <bits/stdc++.h>
using namespace std;

struct node{
  	string name, color;
	char size;
	node(){}
	node(string s1, string s2, char c){name=s1; color=s2; size=c;}
};

bool operator <(node a, node b){
 	if(a.color!=b.color)return a.color=="branco";
	else{
		if(a.size != b.size)return a.size > b.size;
		else return a.name < b.name;
	}
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n,k=0;
	string s1,s2;
	char c;
	while(cin >> n, n){
		if(k++)cout << '\n';
		vector<node> lis(n);
	 	for(int i=0; i<n; i++){
			cin.ignore();
			getline(cin, s1);
			cin >> s2 >> c;
			lis[i] = node(s1, s2, c);
		}
		sort(lis.begin(),lis.end());
		for(node to : lis)cout << to.color << ' ' << to.size << ' ' << to.name << '\n';
	}
	return 0;
}