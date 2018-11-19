#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s;
	getline(cin, s);
	int row = s.size()/20 + ((s.size()%20)? 1 : 0);
	int col = s.size()/row + ((s.size()%row)? 1 : 0);
	int cantidadAsterisco = row*col - s.size();
	vector<int> v(row,0);
	int k = 0;
	while(cantidadAsterisco){
		v[k]++;
		cantidadAsterisco--;
		k++;
		if(k==row) k=0;
	}


	cout << row << ' ' << col << '\n';
	k=0;
	int j=0;
	while(k < s.size()){
		for(int i=0; i<col-v[j]; i++){
		 	cout << s[k];
		 	k++;
		}
		for(int i=0; i<v[j]; i++)
			cout << '*';
		j++;
		cout << '\n';
	}
	return 0;
}