#include <bits/stdc++.h>
using namespace std;

bool operator <(pair<int,int> a, pair<int,int> b){
 	if(a.second<b.second)return true;
	if(a.second>b.second)return false;
	return a.first < b.first;

}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, a, b, sum,i=1, j, sum1;
	cout.precision(2);
	cout << fixed;
	while(cin >> n,n){
		sum = 0;
		sum1=0;
		j=0;
		if(i!=1) cout << '\n';
		cout << "Cidade# " << i++ << ":\n";
		vector<int> v(201,0);
		set<int> s;
		while(n--){
			cin >> a >> b;
			sum += b;     
			sum1 += a;            
			s.insert(b/a);
			v[b/a]+=a;
		}
		for(int to : s){
			cout << v[to] << "-" << to;
			j++;
			if(j<(int)s.size())cout << ' ';
		}
		cout << '\n';
		string aux(to_string((double)(sum)/sum1));                      
		cout << "Consumo medio: ";
		int k=0;
		for(int i=0; i<(int)aux.size();i++){if(k<3)cout << aux[i];if(aux[i]=='.' || k)k++;}
		if(!k) cout << '.';
		for(;k<3;k++)cout << '0';
		cout << " m3.\n";
	}
	return 0;
}