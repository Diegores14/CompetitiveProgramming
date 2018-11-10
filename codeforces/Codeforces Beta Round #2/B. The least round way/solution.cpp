#include <bits/stdc++.h>
using namespace std;

int a[1001][1001][2];
int dp[1001][1001][2];
int n;

void minimo(int m){
	dp[0][0][m]=a[0][0][m];
	//primer fila y primera columna
	for(int i=1; i<n; i++){
		//cout << i << ' ' << a[0][i][m] << ' ' << a[i][0][m] << '\n';
		dp[0][i][m]=dp[0][i-1][m]+a[0][i][m];
		dp[i][0][m]=dp[i-1][0][m]+a[i][0][m];
	}
	for(int i=1; i<n; i++){
	 	for(int j=1; j<n; j++){
			//cout << i << ' ' << j << ' ' << a[0][i][m] << '\n';
	 	 	dp[i][j][m]=min(dp[i-1][j][m],dp[i][j-1][m])+a[i][j][m]; 
		}
	}
}

void print(int i, int j, int m){
	if(i==0 && j==0) return;
	if(i==0){
	 	print(i,j-1, m);
		cout << 'R';
		return;
	}
	if(j==0){
	 	print(i-1,j, m);
		cout << 'D';
		return;
	}
	if((dp[i][j-1][m]+a[i][j][m])==dp[i][j][m]){
	 	print(i, j-1, m);
		cout << 'R';
	}else{
		print(i-1, j, m);
		cout << 'D';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int aux, val=0, posi;
	cin >> n;
	// Tomar los datos y descomponer en los primos 2 y 5, y tener en cuenta el caso de quq e
	for(int i=0; i<n; i++)
	 	for(int j=0; j<n; j++){
	 	 	cin >> aux;
			if(aux==0){val=1; aux=10; posi=i;}
			a[i][j][0]=a[i][j][1]=0;
			while(aux%2==0){
				a[i][j][0]++;
				aux/=2;
			}
			while(aux%5==0){
				a[i][j][1]++;
				aux/=5;
			}
		}
	minimo(0);
	minimo(1);
	// Imprimir en Pantalla;
	if(val && dp[n-1][n-1][0]!=0 && dp[n-1][n-1][1]!=0){
		cout << "1\n";
	 	for(int i=0; i<posi; i++)cout << 'D';
		for(int i=1; i<n; i++) cout << 'R';
		for(int i=posi+1; i<n; i++) cout << 'D';
	}else{
		cout << min(dp[n-1][n-1][0], dp[n-1][n-1][1]) << '\n';
		if(dp[n-1][n-1][0]==0) print(n-1, n-1, 0);
		else{ 
			if(dp[n-1][n-1][1]==0) print(n-1, n-1, 1);
		 	else {
				if(dp[n-1][n-1][0] < dp[n-1][n-1][1]) print(n-1, n-1, 0);
				else print(n-1, n-1, 1);
			}
		}
	}
	return 0;
}