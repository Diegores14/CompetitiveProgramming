#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
 	int d1,d2,h1,h2,m1,m2,s1,s2;
	int d=0,h=0,m=0,s=0;
	scanf("Dia %d\n", &d1);
	scanf("%d : %d : %d\n", &h1, &m1, &s1); 
	scanf("Dia %d\n", &d2);
	scanf("%d : %d : %d", &h2, &m2, &s2);
	if(s1<s2)s=s2-s1;
	if(s1>s2){s=s2-s1+60;m--;}
	if(m1<m2)m+=m2-m1;
	if(m1>m2){m+=m2-m1+60;h--;}
	if(m<0)h--;
	if(h1<h2)h+=h2-h1;
	if(h1>h2){h+=h2-h1+24;d--;}
	if(m<0)d--;
	if(d1<d2)d+=d2-d1;
	cout << d << " dia(s)\n";
	cout << h << " hora(s)\n";
	cout << m << " minuto(s)\n";
	cout << s << " segundo(s)\n"; 
	return 0;
}
