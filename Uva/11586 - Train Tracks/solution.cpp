#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n;
	string s;
	cin >> n;
	cin.ignore();
	while(n--){
		getline(cin, s);
		vector<int> v(2,0);
		for(int i=0; i<s.size(); i++){
		 	if(s[i] == 'M')
		 		v[0]++;
		 	if(s[i] == 'F')
		 		v[1]++;	
		}
		if(v[0] == v[1] && v[0]>1)
			cout << "LOOP\n";
		else
			cout << "NO LOOP\n";
	}
	return 0;
}