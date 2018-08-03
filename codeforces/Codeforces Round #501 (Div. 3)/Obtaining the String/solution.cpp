#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, cont=0;
	vector<int> mov;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for(int i=0; i<n-1; i++){
	 	if(s1[i]!=s2[i])
	 	for(int j=i; j<n-1; j++){
	 		if(s1[j+1]==s2[i]){
	 			for(int k=j; k>=i; k--){ swap(s1[k], s1[k+1]); cont++; mov.emplace_back(k+1);}
	 			j=n;
	 		}
	 	}        
	}
	if(s1!=s2) cout << "-1\n";
	else{
		cout << cont << '\n';
		for(int i=0; i<(int)mov.size(); i++)cout << mov[i] << ((i==(int)mov.size()-1)? '\n' : ' ');
	}
 	return 0;
}