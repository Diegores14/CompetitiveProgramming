#include <bits/stdc++.h>
using namespace std;

struct node{
  	int a, b;
  	node(){}
};

bool operator<(node a, node b){
 	return a.a < b.a;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, answer;
	while( cin >> n){
		answer=1;
	 	vector<node> v(n);
	 	for(int i=0; i<n; i++)cin >> v[i].a >> v[i].b;
	 	sort(v.begin(), v.end());
	 	for(int i=0; i<n; i++){
			if(v[i].a<=answer)answer+=v[i].b;
			else answer = v[i].a + v[i].b;
	 	}
	 	cout << answer << '\n';
	}
 	return 0;
}