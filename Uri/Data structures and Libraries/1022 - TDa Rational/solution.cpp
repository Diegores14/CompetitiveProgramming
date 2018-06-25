#include <bits/stdc++.h>
using namespace std;

struct racional{
  	int x,y;
	racional(int a, int b){x=a; y=b;}
	racional(){}

	void simplificar(){
		int m= min(abs(x),abs(y));
	 	for(int i=2;i<=m; i++){
	 	 	if(!(x%i) && !(y%i)){x/=i;y/=i;i=1;}
		}
	}
};

racional suma(racional a, racional b){
	racional aux((a.x*b.y+b.x*a.y),(a.y*b.y));
 	return aux;
} 

racional resta(racional a, racional b){
	racional aux((a.x*b.y-b.x*a.y),(a.y*b.y));
 	return aux;
}

racional multiplicacion(racional a, racional b){
	racional aux((a.x*b.x),(a.y*b.y));
 	return aux;
}

racional division(racional a, racional b){
	racional aux((a.x*b.y),(a.y*b.x));
 	return aux;
}
	
int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, n1,n2,d1,d2;
	char aux, operation;
	cin >> n;
	while(n--){
	 	cin >> n1 >> aux >> d1 >> operation >> n2 >> aux >> d2;
		racional r1(n1,d1),  r2(n2,d2);
		racional res;
		if(operation == '+')res=suma(r1,r2);
		if(operation == '-')res=resta(r1,r2);
		if(operation == '*')res=multiplicacion(r1,r2);
		if(operation == '/')res=division(r1,r2);
		cout << res.x << '/' << res.y << " = ";
		res.simplificar();
		cout << res.x << '/' << res.y << '\n';
	}
 	return 0;
}