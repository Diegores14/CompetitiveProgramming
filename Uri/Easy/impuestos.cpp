#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	double n, res=0;
	cin >> n;
	if(0<=n && n <=2000){cout << "Isento\n"; return 0;}
	n -=2000;
	if(1000<=n)res+=80;
	else if(n>0)res+=n*0.08;
	n-=1000;
	if(1500<=n)res+=1500*0.18;
	else if(n>0)res+=n*0.18;
	n-=1500;
	if(0<=n)res+=n*0.28;
	
	cout << setprecision(2) <<fixed << "R$ " <<	res << "\n";
	return 0;
}