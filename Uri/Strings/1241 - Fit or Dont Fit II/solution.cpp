#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
 	int n;
	string s1, s2;
	cin >> n;
	while(n--){
		int aux = 0;
	 	cin >> s1 >> s2;
		if(s1.size()>=s2.size()){
		 	for(int i=s1.size()-s2.size(); i<(int)s1.size(); i++)
				aux += s1[i]^s2[i-(s1.size()-s2.size())];
			if(aux)cout << "nao encaixa\n";
			else cout << "encaixa\n";
		}else cout << "nao encaixa\n";
	}
	return 0;
}