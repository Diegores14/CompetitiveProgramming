#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, op, x, cont;
	while(cin >> n){
		queue<int> q;
		priority_queue<int> pq;
		stack<int> s;
		vector<bool> v(3,true);
		cont =0;
	 	while(n--){
			cin >> op >> x;
			if(op==1){
			 	q.push(x);
				pq.push(x);
				s.push(x);
			}else{
			 	if(q.front()!=x)v[0]=false;
				if(pq.top()!=x)v[1]=false;
				if(s.top()!=x)v[2]=false;
				q.pop();
				pq.pop();
				s.pop();
			}                     
		}
		for(int i=0; i<3; i++)cont+=v[i];
		if(cont>1){cout << "not sure\n";continue;}
		if(cont==0){cout << "impossible\n";continue;}
		if(v[0]==1){cout << "queue\n";continue;}
		if(v[1]==1){cout << "priority queue\n";continue;}
		if(v[2]==1)cout << "stack\n";
	}
 	return 0;
}