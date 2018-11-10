#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	bool flag = true;
	while(getline(cin, s)){
	        for(char to : s){
	         	if(to=='\"'){
				if(flag){
					cout << "``";
				}else{
					cout << "\'\'";
				}
				flag = !flag;
			}else{
			 	cout << to;
			}
		}
		cout << '\n';
	}
	return 0;
}