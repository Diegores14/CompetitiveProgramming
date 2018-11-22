#include <bits/stdc++.h>
using namespace std;
int a[1005][1005][2];
int dp[1005][1005][2];
int n;

void dynamicProgramming(){
	dp[0][0][0]=a[0][0][0];
	dp[0][0][1]=a[0][0][1];
	for(int i=1; i<n; i++){
		dp[0][i][0] = a[0][i][0] + dp[0][i-1][0];
		dp[i][0][0] = a[i][0][0] + dp[i-1][0][0];
		dp[0][i][1] = a[0][i][1] + dp[0][i-1][1];
		dp[i][0][1] = a[i][0][1] + dp[i-1][0][1];
	}
	for(int i = 1; i<n; i++){
		for(int j=1; j<n; j++){
		 	dp[i][j][0] = min(dp[i-1][j][0], dp[i][j-1][0]) + a[i][j][0];
		 	dp[i][j][1] = min(dp[i-1][j][1], dp[i][j-1][1]) + a[i][j][1];
		}
	}
}

void solution(int p, int i, int j){
	if(i==0 && j==0)
		return;
	if(i==0){
		solution(p, i, j-1);
		cout << 'R';
		return;
	}
	if(j==0){
		solution(p, i-1, j);
		cout << 'D';
		return;
	}
	if(dp[i][j-1][p] < dp[i-1][j][p]){
		solution(p, i, j-1);
		cout << 'R';
	}else{
		solution(p, i-1, j);
		cout << 'D';
	}
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int aux;
	cin >> n;
	bool isZero = false;
	int pos=0;
	memset(a, 0, sizeof a);
	memset(dp, -1, sizeof dp);
	for(int i=0; i<n; i++){
	 	for(int j=0; j<n; j++){
	 	 	cin >> aux;
	 	 	if(aux==0){
	 	 	 	isZero = true;
	 	 	 	pos = j;
	 	 	 	a[i][j][0] = 1;
	 	 	 	a[i][j][1] = 1;
	 	 	}else{
				while(aux%2 == 0){
				 	aux /= 2;
				 	a[i][j][0]++;
				}
				while(aux%5 == 0){
				 	aux /= 5;
				 	a[i][j][1]++;
				}
	 	 	}
	 	}
	}
	/*for(int i=0; i<n; i++){
	 	for(int j=0; j<n; j++)
	 		cout << a[i][j][1] << ' ';
		cout << '\n';
	}*/
	dynamicProgramming();
	//cout << dp[n-1][n-1][0] << ' ' << dp[n-1][n-1][1] << '\n';
	if(dp[n-1][n-1][0] < dp[n-1][n-1][1]){
		if(isZero && dp[n-1][n-1][0] > 1){
			cout << "1\n";
			for(int i=0; i<pos; i++)
				cout << 'R';
			for(int i=0; i<n-1; i++)
				cout << 'D';
			for(int i=pos; i<n-1; i++)
				cout << 'R';
		}else{
			cout << dp[n-1][n-1][0] << '\n';
		 	solution(0, n-1, n-1);
		}
	}else{
		if(isZero && dp[n-1][n-1][1] > 1){
			cout << "1\n";
			for(int i=0; i<pos; i++)
				cout << 'R';
			for(int i=0; i<n-1; i++)
				cout << 'D';
			for(int i=pos; i<n-1; i++)
				cout << 'R';
		}else{
			cout << dp[n-1][n-1][1] << '\n';
		 	solution(1, n-1, n-1);
		}
	}
	return 0;
}