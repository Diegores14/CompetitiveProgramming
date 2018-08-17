#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, g, a, b;
	while(cin >> n >> g){
		priority_queue<int> q;
		int ans=0;
	 	for(int i=0; i<n; i++){ cin >> a >> b; if(a-b>0)ans+=3;else q.push(a-b);}
	 	while(!q.empty()){
	 	 	int x=1-q.top();
	 	 	if(g-x+1==0){q.pop(); ans++; break;}
			if(g-x<0)break;			
			q.pop();
			ans+=3;
			g-=x;
	 	}
	 	while(!q.empty() && q.top()==0){
	 	 	ans+=1;
	 	 	q.pop();
	 	}
	 	cout << ans << '\n';
	}
	return 0;
}