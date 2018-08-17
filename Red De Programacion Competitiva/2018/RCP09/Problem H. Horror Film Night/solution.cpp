#include <bits/stdc++.h>
using namespace std;

int answer(set<int>::iterator it1, set<int>::iterator it2, set<int> & s1, set<int> & s2, bool turn){
	vector<int> v(1,-1);
	while((turn && it1!=s1.end()) || (!turn && it2!=s2.end())){
	 	if(turn){
			while(it1!=s1.end() && v[v.size()-1]>=*it1)it1++;
			if(it1!=s1.end()){
				v.push_back(*it1);
				turn=false;
			}
	 	}else{
	 	 	while(it2!=s2.end() && v[v.size()-1]>=*it2)it2++;
			if(it2!=s2.end()){
				v.push_back(*it2);
				turn=true;
			}
	 	}
	}
 	return v.size()-1;
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int aux, k, ans=0;
	set<int> s1, s2;
	cin >> k;
	for(int i=0; i<k; i++){
	 	cin >> aux;
	 	s1.insert(aux);
	}
	cin >> k;
	for(int i=0; i<k; i++){
	 	cin >> aux;
	 	s2.insert(aux);
	}
	set<int>::iterator it1 = s1.begin(), it2 = s2.begin();
	if(s1.size()!=0 && s2.size()!=0){
		if(*it1 == *it2){                                    
			ans = max(ans, answer(it1, it2, s1, s2, true));
			ans = max(ans, answer(it1, it2, s1, s2, false));
		}else{
	 		if(*it1 > *it2){
				ans = max(ans, answer(it1, it2, s1, s2, false));
		 	}else{
	 	  		ans = max(ans, answer(it1, it2, s1, s2, true));
		 	}
		}
	}else{
	 	if(s1.size()!=0) ans = max(ans, answer(it1, it2, s1, s2, true));
	 	else ans = max(ans, answer(it1, it2, s1, s2, false));
	}
	cout << ans << '\n';
	return 0;
}