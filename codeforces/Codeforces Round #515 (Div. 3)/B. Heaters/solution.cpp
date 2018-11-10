#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, r, aux;
	cin >> n >> r;
	vector<int> v(n,-1);
	for(int i=0; i<n; i++){
	 	cin >> aux;
		if(aux)
			for(int j=i-r+1; j<i+r && j < n; j++){
			 	if(j>=0)v[j]=i;
			}
	}
	/*for(int to : v)
		cout << to << ' ';
	cout <<  '\n';*/
	set<int> s;
	bool flag=true;
	int i=0;
	while(i<n){
		if(v[i]!=-1){
		 	s.insert(v[i]);
			i=v[i]+r;
		}else{
		 	flag = false;
			break;
		}
	}
	if(flag)
		cout << s.size() << '\n';
	else
		cout << "-1\n";
	return 0;
}