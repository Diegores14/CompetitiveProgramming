#include <bits/stdc++.h>
using namespace std;


int main(){
	srand(time(NULL));
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	cout << "100\n";
	cout << "0 100\n";
	for(int i=1; i<100; i++){
	 	int n = rand()%100;
		int d = (rand()%1000000000)+1;
		cout << n << ' ' << d <<'\n';
		int con=n;
		set<int> s;
		while(n){
		 	int aux=(rand()%(d-1))+1;
			if(s.count(aux)==0){s.insert(aux); n--;}
		}         
		for(int to : s) cout << ((rand()%2)? "B-" : "S-") << to << ((--con)? ' ' : '\n');
	}
 	return 0;
}