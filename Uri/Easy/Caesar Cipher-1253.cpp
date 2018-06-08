#include <bits/stdc++.h>
using namespace std;

int main (){
    int N,paso;
    string s;
    scanf("%d", &N);
    while(N--){
        cin>>s;
        cin>>paso;
        for(string::iterator it=s.begin(); it!=s.end(); ++it){
            *it -= paso;
            if(*it < 65)
                *it += 26;
            if(*it > 90)
                *it -= 26;
            cout<<*it;
        }
        printf("\n");
    }
    return 0;
}
