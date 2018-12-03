#include <bits/stdc++.h>
using namespace std;

bool newkeys(map<string, string> &oldDictionary, map<string, string> &newDictionary){
    bool ans = false;
    for(auto i: newDictionary)
        if(oldDictionary.count(i.first) == 0){
            if(!ans){
                cout << "+" << i.first;
                ans = true;
            }else{
                cout << "," << i.first;
            }
        }
    if(ans)
        cout << '\n';
    return ans;
}

bool removedkeys(map<string, string> &oldDictionary, map<string, string> &newDictionary){
    bool ans = false;
    for(auto i: oldDictionary)
        if(newDictionary.count(i.first) == 0){
            if(!ans){
                cout << "-" << i.first;
                ans = true;
            }else{
                cout << "," << i.first;
            }
        }
    if(ans)
        cout << '\n';
    return ans;
}

bool changedValue(map<string, string> &oldDictionary, map<string, string> &newDictionary){
    bool ans = false;
    for(auto i: newDictionary)
        if(oldDictionary.count(i.first) && oldDictionary[i.first] != i.second){
            if(!ans){
                cout << "*" << i.first;
                ans = true;
            }else{
                cout << "," << i.first;
            }
        }
    if(ans)
        cout << '\n';
    return ans;
}

void input(map<string, string> & m, string & s){
    stringstream in;
    string key, value;
    for(int i=1; i<s.size()-1; i++){
        if(s[i]!=',' && s[i] != ':')
            in << s[i];
        else
            in << ' ';
    }
    while(in >> key >> value){
        m[key] = value;
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin >> t;
    string s;
    cin.ignore();
    while(t--){
        map<string, string> oldDictionary, newDictionary;
        getline(cin, s);
        input(oldDictionary, s);
        getline(cin, s);
        input(newDictionary, s);
        bool ans = false;
        if(newkeys(oldDictionary, newDictionary))
            ans = true;
        if(removedkeys(oldDictionary, newDictionary))
            ans = true;
        if(changedValue(oldDictionary, newDictionary))
            ans = true;
        if(!ans)
            cout << "No changes\n";
        cout << '\n';
    }
    return 0;
}