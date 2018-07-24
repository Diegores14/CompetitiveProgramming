#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	string s;
	map<char,char> m;
	m['1']='`',m['2']='1';m['3']='2';m['4']='3';m['5']='4';m['6']='5';m['7']='6';m['8']='7';m['9']='8';m['0']='9';m['-']='0';m['=']='-';
	m['W']='Q';m['E']='W';m['R']='E';m['T']='R';m['Y']='T';m['U']='Y';m['I']='U';m['O']='I';m['P']='O';m['[']='P';m[']']='[';m['\\']=']';
	m['S']='A';m['D']='S';m['F']='D';m['G']='F';m['H']='G';m['J']='H';m['K']='J';m['L']='K';m[';']='L';m['\'']=';';
	m['X']='Z';m['C']='X';m['V']='C';m['B']='V';m['N']='B';m['M']='N';m[',']='M';m['.']=',';m['/']='.';
	while(getline(cin, s)){
		for(char to: s)if(m.count(to))cout << m[to]; else cout << to;
		cout << '\n';
	}
 	return 0;
}