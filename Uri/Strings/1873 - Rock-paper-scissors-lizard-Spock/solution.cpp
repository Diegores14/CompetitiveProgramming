#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
 	int n;
	cin >> n;
	string s1, s2;
	while(n--){
		cin >> s1 >> s2;     
		if(s1=="tesoura" && s2 == "papel"){cout << "rajesh\n"; continue;}
		if(s2=="tesoura" && s1 == "papel"){cout << "sheldon\n"; continue;}
		if(s1=="papel" && s2 == "pedra"){cout << "rajesh\n"; continue;}
		if(s1=="pedra" && s2 == "papel"){cout << "sheldon\n"; continue;}
		if(s1=="pedra" && s2 == "lagarto"){cout << "rajesh\n"; continue;}
		if(s1=="lagarto" && s2 == "pedra"){cout << "sheldon\n"; continue;}
		if(s1=="lagarto" && s2 == "spock"){cout << "rajesh\n"; continue;}
		if(s1=="spock" && s2 == "lagarto"){cout << "sheldon\n"; continue;}
		if(s1=="spock" && s2 == "tesoura"){cout << "rajesh\n"; continue;}
		if(s1=="tesoura" && s2 == "spock"){cout << "sheldon\n"; continue;}
		if(s1=="tesoura" && s2 == "lagarto"){cout << "rajesh\n"; continue;}
		if(s1=="lagarto" && s2 == "tesoura"){cout << "sheldon\n"; continue;}
		if(s1=="lagarto" && s2 == "papel"){cout << "rajesh\n"; continue;}
		if(s1=="papel" && s2 == "lagarto"){cout << "sheldon\n"; continue;}
		if(s1=="papel" && s2 == "spock"){cout << "rajesh\n"; continue;}
		if(s1=="spock" && s2 == "papel"){cout << "sheldon\n"; continue;}
		if(s1=="spock" && s2 == "pedra"){cout << "rajesh\n"; continue;}
		if(s1=="pedra" && s2 == "spock"){cout << "sheldon\n"; continue;}
		if(s1=="pedra" && s2 == "tesoura"){cout << "rajesh\n"; continue;}
		if(s1=="tesoura" && s2 == "pedra"){cout << "sheldon\n"; continue;}
		cout <<"empate\n";
	}
	return 0;
}