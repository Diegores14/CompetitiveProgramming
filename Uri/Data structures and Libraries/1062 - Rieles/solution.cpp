#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n, n){
		//if(k++)cout << '\n';
	 	vector<int> v(n);
		while(cin >> v[0],v[0]){
			stack<int> s;
			int j=0;
			for(int i=1; i<n; i++)cin >> v[i];
			for(int i=1; i<=n; i++){s.push(i);while(j<n && !s.empty() && s.top()==v[j]){s.pop();j++;} }
			if(s.empty())cout << "Yes\n";
			else cout << "No\n";
		}
		cout << '\n';
	}
	return 0;
}