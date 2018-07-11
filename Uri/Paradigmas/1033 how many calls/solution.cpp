#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> aux1, v(3, vector<int>(3,1));

vector<vector<int>> mul(vector<vector<int>>& v, vector<vector<int>>& b, int m){
	vector<vector<int>> aux(3, vector<int>(3,0));
 	unsigned int s;
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			s=0;
			for(int k=0; k<3; k++)s=(s+((v[i][k]%m)*(b[k][j]%m))%m)%m;
			aux[i][j]=s;
		}
	}
	return aux;
}

vector<vector<int>> sum(vector<vector<int>> v1, long long p,int m){
	//vector<vector<int>> aux1;
	if(p==1)return v1;
 	if(p%2==0){
		aux1 = sum(v1,p/2,m);
		return mul(aux1,aux1,m);
	}
	aux1 = sum(v1,p-1, m);
	//aux2 = mul(aux1,aux1);
	return mul(aux1, v1, m);
}


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	v[1][1]=v[1][2]=v[2][0]=v[2][1]=0;
 	long long n;
	int m, i=1;
	vector<vector<int>> v1;       
	while(cin >> n >> m, n || m){
		cout <<"Case " << i++ << ": "<< n << ' ' << m << ' ';
		if(n==0 || n==1)cout << "1\n";
		else{
	         	v1 = sum(v, n-1, m);
			cout << (v1[0][0]%m+v1[0][1]%m+v1[0][2]%m)%m << '\n';
		} 
	}
 	return 0;
}