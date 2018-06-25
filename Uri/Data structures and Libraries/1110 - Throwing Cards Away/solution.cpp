#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n, n){
	 	queue<int> q;
		for(int i=1; i<=n; i++)q.push(i);
		cout << "Discarded cards:";
		while(q.size()!=2){
		 	cout << ' ' << q.front() << ',';
			q.pop();
			q.push(q.front());
			q.pop();
		}
		cout << ' ' << q.front() << '\n';
		q.pop();
		cout << "Remaining card: " << q.front() << '\n';
	}
 	return 0;
}