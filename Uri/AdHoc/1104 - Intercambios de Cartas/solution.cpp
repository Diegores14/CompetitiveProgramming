#include <bits/stdc++.h>
using namespace std;


int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int a, b, aux, answer;
	while(cin >> a >> b, a || b){
		answer = 0;
		set<int> s1;
		set<int> s2;
	 	for(int i=0; i<a; i++){cin >> aux; s1.insert(aux);}
	 	for(int i=0; i<b; i++){cin >> aux; s2.insert(aux);}
	 	if(s1.size()<s2.size()){
	 	 	for(set<int>::iterator it = s1.begin(); it != s1.end(); ++it)if(!s2.count(*it))answer++;
		}
	 	else for(set<int>::iterator it = s2.begin(); it != s2.end(); ++it)if(!s1.count(*it))answer++;
	 	cout << answer << '\n';
	}
 	return 0;
}