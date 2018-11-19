#include <bits/stdc++.h>
using namespace std;

void print(int n){
	if(n<10)
		cout << n;
	if(n==10)
		cout << 'A';
	if(n==11)
		cout << 'B';
	if(n==12)
		cout << 'C';
	if(n==13)
		cout << 'D';
	if(n==14)
		cout << 'E';
	if(n==15)
		cout << 'F';
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	string s;
	cin >> t;
	for(int k=1; k<=t; k++){
		cout << "Case " << k << ':';
	 	cin >> s;
	 	int j = 0;
	 	vector<int> v(100, 0);
	 	for(char i: s){
			if(i == '+')
				v[j]++;
			if(i == '-')
				v[j]--;
			if(i == '<')
				j--;
			if(i == '>')
				j++;
			if(j == -1)
				j = 99;
			if(j == 100)
				j = 0;	
	 	}
	 	for(int i = 0; i < 100; i++){
	 		v[i] = v[i]%255;
	 		cout << ' ';
			print((v[i]>>4)&((1<<4)-1));
			print(v[i]&((1<<4)-1));
	 	}
	 	cout << '\n';
	}
	return 0;
}