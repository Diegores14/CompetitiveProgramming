#include <bits/stdc++.h>
using namespace std;
vector<int> calls(100000000000000000000,-1);

void fibonacci(int n,int b){
 	if(calls[n]!=-1){return;}
	fibonacci(n-1,b);
	fibonacci(n-2,b);
	calls[n]=(calls[n-1]+calls[n-2]+1)%10000;
}

int main(){
 	long long x, y, i=0;
	//int res;
	calls[0]=calls[1]=1;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(cin >> x >> y, x || y){
		res=0;
		fibonacci(x,y);
		cout << "Case " << i++ << ": " << x << ' ' << y << ' ' << calls[x]%y << '\n';
	}
	return 0;
}