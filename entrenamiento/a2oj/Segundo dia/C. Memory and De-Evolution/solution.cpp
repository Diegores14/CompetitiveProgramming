#include <bits/stdc++.h>
using namespace std;

int sol(int a,int b,int c, int y){
	if(a==y && b==y && c==y) return 1;
 	if(a+b>c && c+b>a && a+c>b){
		int cont=0;
		int aux;
		for(int i=a; i>=y; i--){
		 	for(int j=b; j>=y; j--){
	                 	for(int j=b; j>=y; j--){
	                 		aux=sol(i,j,k,y);
					cont +=
				}
			}
		}
		return cont;
	}else return -1;

}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int x, y, cont=0;
	cin >> x >> y;
	vector<int> v(3,x);
	bool res=false;
	while(!res){
	        if(v[0]>y && (y+v[1])>v[2] && (y+v[2])>v[1] && (v[1]+v[2])>y){cont++; v[0]=y;}
	 	else{
			if(v[0]>y){
			while((v[0]-1+v[1])>v[2] && (v[0]-1+v[2])>v[1] && (v[1]+v[2])>v[0]-1)v[0]--;
			cont++;}
		}
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
		if(v[1]>y && (y+v[0])>v[2] && (y+v[2])>v[0] && (v[0]+v[2])>y){cont++; v[1]=y;}
	 	else{
			if(v[1]>y){
			while((v[1]-1+v[0])>v[2] && (v[1]-1+v[2])>v[0] && (v[0]+v[2])>v[1]-1)v[1]--;
			cont++;}
		}
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';		
		if(v[2]>y && (y+v[1])>v[0] && (y+v[0])>v[1] && (v[1]+v[0])>y){cont++; v[2]=y;}
	 	else{
			if(v[2]>y){
			while((v[2]-1+v[1])>v[0] && (v[2]-1+v[0])>v[1] && (v[1]+v[0])>v[2]-1)v[2]--;
			cont++;}
		}
		cout << v[0] << ' ' << v[1] << ' ' << v[2] << '\n';
		if(v[0]==y && v[1]==y && v[2]==y) res=true;
	}
	cout << cont <<'\n';
        return 0;
}	