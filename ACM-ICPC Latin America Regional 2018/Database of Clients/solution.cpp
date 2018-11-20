#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	set<string> set1;
	cin >> n;
	while(n--){
	 	string aux;
		cin >> s;
		bool flag=false, flag1 = false;
		for(int i: s){
			if(flag1){
				aux.push_back(i);
				continue;	
			}
			if(i=='@'){
			 	aux.push_back(i);
				flag1=true;
				continue;
			}
		 	if(i == '.')
				continue;
			if(!flag && i == '+'){
			 	flag=true;
			}
			if(!flag){
			 	aux.push_back(i);
			}
		}
		set1.insert(aux);
	}
	cout << set1.size() << '\n';
	return 0;
}