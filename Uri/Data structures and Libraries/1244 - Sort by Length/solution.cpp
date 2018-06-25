#include <bits/stdc++.h>
using namespace std;

struct node{
  	int size;
	string s;
	node(string b){s=b;size=(int)s.size();}
	node(){}
};

bool operator >(node a, node b){
 	if(a.size > b.size)return true;
	else return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	cin >> n;
	cin.ignore();
	string s;
	while(n--){
	 	getline(cin,s);    
		int j=1,k=0;
		for(int i=0; i<(int)s.size(); i++)if(s[i]==' ')j++;
		vector<node> v(j);
		string::iterator itb = s.begin();
		for(string::iterator it = s.begin(); it!=s.end();it++)
			if(*it==' '){
				string aux1(itb,it);
				node aux(aux1);
				v[k]=aux;
				itb= it+1;
				k++;
			}
		if(itb!=s.end()){string aux1(itb,s.end());node aux(aux1);v[k]=aux;}		
		bool IsEnd=false;
		while(!IsEnd){
			IsEnd = true;
		 	for(int i=1; i<(int)v.size(); i++)
				if(v[i]>v[i-1]){
				 	swap(v[i],v[i-1]);
					IsEnd=false;
				}                         
		}
		for(int i=0; i<(int)v.size()-1; i++)cout << v[i].s << ' ';
		cout << v[v.size()-1].s << '\n';
	}
 	return 0;
}