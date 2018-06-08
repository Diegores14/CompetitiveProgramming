#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  	int N;
	cin >> N;
	cout << N <<'\n';
	for(int i=100; i>30; i/=2){
	 	cout <<N/i<< " nota(s) de R$ " << i << ",00" << '\n';
		N%=i;
	}
	for(int i=20; i>0; i/=2){
	 	cout <<N/i<< " nota(s) de R$ " << i << ",00" << '\n';
		N%=i;
	}
	return 0;
}