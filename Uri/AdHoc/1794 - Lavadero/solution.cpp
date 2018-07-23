#include<bits/stdc++.h>
using namespace std;

bool answer(int a, int b, int c, int d, int e){
        if(e==0) return true;
 	if(a>b)return false;
 	for(int i=a; i<=b; i++)
 		for(int j=1; j*i<=e; j++)
 			for(int k=c; k<=d; k++)
 				if((i*j)%k==0)
 					if(answer(i+1, b, c, d, e-i*j))return true;
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n, a, b, c, d;
	cin >> n >> a >> b >> c >> d;
	cout << ((answer(a,b,c,d,n))? "possivel\n" : "impossivel\n");
	return 0;
}