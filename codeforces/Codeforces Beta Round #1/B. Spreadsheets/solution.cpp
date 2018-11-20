#include <bits/stdc++.h>
using namespace std;
int k;

long long string_to_long(string s){
	long long ans = 0;
	for(; k<s.size() && '0' <= s[k] && s[k] <= '9'; k++){
	 	ans = ans*10 + (s[k] - '0');
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int t;
	cin >> t;
	string s;
	while(t--){
	 	cin >> s;
	 	bool flag = true;
	 	if('R' == s[0] && '0' <= s[1]  && s[1] <= '9')
	 	for(int i=1; i<s.size(); i++){
	 	 	if(s[i] == 'C')
	 	 		flag = false;
	 	}
	 	if(flag){
			 long long ans = 0;
       			cout << "R";
			for(int i=0; i<s.size(); i++){
				if('A' <= s[i] && s[i] <= 'Z')
			 		ans = ans*26 + (s[i] - 'A' + 1);
			 	else
			 		cout << s[i];	
			}
			cout << "C" << ans << '\n';
	 	}else{
	 		k=1;
	 	 	long long aux = string_to_long(s);
	 	 	k++;
	 	 	long long aux1 = string_to_long(s);
	 	 	string s1;
	 	 	while(aux1){
	 	 		int res = aux1%26;
	 	 		if(res)
					s1.push_back(res + 'A' - 1);
				else{
					s1.push_back('Z');
					aux1--;
				}
				aux1 -= res;
				aux1 /= 26;
			}
			for(int i=s1.size()-1; i>=0; i--)
				cout << s1[i];
			cout << aux << '\n';
	 	}
	}
	return 0;
}