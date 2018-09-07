#include <bits/stdc++.h>
using namespace std;


int sumadigit(string n){
	int ans=0;
	for(char to: n)ans += to-'0';
	return ans;
}


int backtracking(string a, string b, int c){
	if(a==b)return ((stoi(a)%c==0 && sumadigit(a)%c==0)? 1 : 0);
	string aux=a;
	aux[aux.size()-1]++;
	for(int i=aux.size()-1; aux[i]=='9'+1 && i>=0; i--){
	 	if(i==0){aux[0]='1'; aux.push_back('0');}
	 	else{aux[i]='0'; aux[i-1]++;}
	}
 	return backtracking(aux, b, c) + ((stoi(a)%c==0 && sumadigit(a)%c==0)? 1 : 0);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b, c;
	cin >> n;
	while(n--){        
		cin >> a >> b >> c;
		cout << backtracking(to_string(a), to_string(b), c) << '\n';
	}                    
 	return 0;
}