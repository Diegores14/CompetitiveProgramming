#include <bits/stdc++.h>
using namespace std;

struct node {
    char a, c, b;
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    vector<int> v({1,2,3});
    vector<node> condition(3);
    for(node &i: condition) {
        cin >> i.a >> i.c >> i.b;
    }
    do {
        bool temp = true;
        for(node &i: condition) {
            if(i.c == '<' && v[i.a-'A'] > v[i.b-'A']) {
                temp = false;
            }
            if(i.c == '>' && v[i.a-'A'] < v[i.b-'A']) {
                temp = false;
            }
        }
        if(temp) {
            for(int i = 1; i<=3; i++) {
                for(int j=0; j<3; j++) {
                    if(v[j] == i) {
                        cout << char(j+'A');
                    }
                }
            }
            cout << '\n';
            return 0;
        }
    }while (next_permutation(v.begin(), v.end()));
    cout << "Impossible\n";
    return 0; 
}