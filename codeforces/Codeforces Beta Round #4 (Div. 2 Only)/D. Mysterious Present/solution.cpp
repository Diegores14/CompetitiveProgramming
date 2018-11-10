#include <bits/stdc++.h>
using namespace std;      

struct node{
	int first, second, tim;
	node(){ first=0; second=0;}
};

bool operator <(node a, node b){
	return (a.first <= b.first) && (a.second <= b.second);
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, w, h;
	cin >> n >> w >> h;
	node aux;
	set<node> s;
	vector<node> envelope(n);
	for(int i=0; i<n; i++){
		cin >> envelope[i].first >> envelope[i].second;
		envelope[i].tim = i+1;
	}
	sort(envelope.begin(), envelope.end());
	for(int i=0; i<n; i++){
		cout << "Debug " << envelope[i].first << ' ' << envelope[i].second << '\n';
		if(w < envelope[i].first  && h < envelope[i].second)s.insert(envelope[i]);
	}
	cout << s.size() << '\n';
	int i=0;
	//if(w < aux.first  && h < aux.second && s.count(aux)==0)s[aux]=i+1;
	if(s.size()!=0){
		for(node to : s){
			cout << ((i==0)? "": " ") << to.tim;
			i++;
		} 
		cout << '\n';
	}
	return 0;
}