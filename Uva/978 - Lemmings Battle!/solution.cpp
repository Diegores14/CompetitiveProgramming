#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t, n, cantg, cantb, temp;
    multiset<int>::iterator it1, it2;
    vector<int> fightB, fightG;
    cin >> t; 
    while(t--){
        cin >> n >> cantg >> cantb;
        multiset<int, greater<int> > g, b;
        for(int i=0; i<cantg; i++){
            cin >> temp;
            g.insert(temp);
        }
        for(int i=0; i<cantb; i++){
            cin >> temp;
            b.insert(temp);
        }
        while(!g.empty() && !b.empty()){
            int limit = min(n, (int)min(g.size(), b.size()));
            it1 = g.begin();
            it2 = b.begin();
            for(int i=0; i < limit; i++, it1++, it2++){
                fightB.emplace_back(*it2);
                fightG.emplace_back(*it1);
                g.erase(it1);
                b.erase(it2);
            }
            for(int i=0; i<limit; i++){
                if(fightB[i] > fightG[i]){
                    b.insert(fightB[i] - fightG[i]);
                }
                if(fightB[i] < fightG[i]){
                    g.insert(fightG[i] - fightB[i]);
                }
            }
            fightB.clear();
            fightG.clear();
        }
        if(g.empty() && b.empty())
            cout << "green and blue died\n";
        else{
            if(g.empty()){
                cout << "blue wins\n";
                for(multiset<int>::iterator it = b.begin(); it != b.end(); it++)
                    cout << *it << '\n';
            }
            else{
                cout << "green wins\n";
                for(multiset<int>::iterator it = g.begin(); it != g.end(); it++)
                    cout << *it << '\n';
            }
        }
        if(t)
            cout << '\n';
    }
    return 0;
}