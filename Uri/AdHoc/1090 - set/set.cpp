#include <bits/stdc++.h>                                                                                                                                                                                           
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;
	while(cin >> n, n){
		vector<vector<int>> v(3);
		int i, j, cont=0,aux;
		string s1,s2;
		for(i=0; i<3;i++)v[i]=vector<int>(3,0); 
		while(n--){
			cin >> s1 >> s2;
			if(s1=="um")i=0;
			if(s1=="dois")i=1;
			if(s1=="tres")i=2;
			if(s2=="circulo")j=0;
			if(s2=="quadrados")j=1;
			if(s2=="triangulo")j=2;
			v[j][i]++;
		}
		for(i=0; i<3;i++)
			for(j=0; j<3; j++){cont+=v[i][j]/3;v[i][j]%=3;}
		for(i=0; i<3;i++){
			aux=0;
			for(j=0; j<3; j++){aux+=v[i][j];}
			cont+=aux/3; 
			for(j=0; j<3; j++){v[i][j]-=aux/3;}
		}
		for(i=0; i<3;i++){
			aux=0;
			for(j=0; j<3; j++){aux+=v[j][i];}
			cont+=aux/3; 
			for(j=0; j<3; j++){v[j][i]-=aux/3;}
		}
		aux=0;
		for(i=0; i<3;i++){aux+=v[i][i];}
		cont+=aux/3;
		for(i=0; i<3;i++){v[i][i]-=aux/3;}
		cout << aux << '\n';
		aux=0;
		for(i=0; i<3;i++){aux+=v[i][2-i];}
		cont+=aux/3;
		cout << aux <<'\n';
		for(i=0; i<3;i++){v[i][2-i]-=aux/3;}
		cout << cont << '\n';
	}
}