#include <bits/stdc++.h>
using namespace std;

int main(){
 	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	vector<float> v(3);
	for (int i = 0; i < 3; i++) cin>>v[i];
	sort(v.begin(), v.end());
	if(v[2]>=(v[1]+v[0]))cout << "NAO FORMA TRIANGULO\n";
	else{
		if(v[2]*v[2]==(v[1]*v[1]+v[0]*v[0]))cout << "TRIANGULO RETANGULO\n";
		if(v[2]*v[2]>(v[1]*v[1]+v[0]*v[0]))cout << "TRIANGULO OBTUSANGULO\n";
		if(v[2]*v[2]<(v[1]*v[1]+v[0]*v[0]))cout << "TRIANGULO ACUTANGULO\n";
		if(v[2]==v[1]&&v[0]==v[1])cout << "TRIANGULO EQUILATERO\n";
		if((v[2]==v[1]&&v[0]!=v[1])||(v[0]==v[1]&&v[2]!=v[1])||(v[2]==v[0]&&v[0]!=v[1]))cout << "TRIANGULO ISOSCELES\n";
	}
	return 0;
}