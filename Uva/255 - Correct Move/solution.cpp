#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    map<int, int> row, col;
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            row[8*i+j] = i;
            col[8*i+j] = j;
        }
    }
    int a, b, c;
    while(cin >> a >> b >> c){
        if(a == b){
            cout << "Illegal state\n";
            continue;
        }
        int x1 = col[a], y1 = row[a], x2 = col[b], y2 = row[b], x3 = col[c], y3 = row[c];
        if(!(x2 == x3 || y2 == y3) || a == c || b == c){
            cout << "Illegal move\n";
            continue;
        }
        if((x1 == x2 && x2 == x3) && ((y2-y1<0 && y2-y3<0) || (y2-y1>0 && y2-y3>0)) && (abs(y2-y1) < abs(y2-y3))){
            cout << "Illegal move\n";
            continue;
        }
        if((y1 == y2 && y2 == y3) && ((x2-x1<0 && x2-x3<0) || (x2-x1>0 && x2-x3>0)) && (abs(x2-x1) < abs(x2-x3))){
            cout << "Illegal move\n";
            continue;
        }
        if(y1 == y3 && (x1 - 1 == x3 || x1 + 1 == x3)){
            cout << "Move not allowed\n";
            continue;
        }
        if(x1 == x3 && (y1 - 1 == y3 || y1 + 1 == y3)){
            cout << "Move not allowed\n";
            continue;
        }
        if((a == 56  && c == 49) || (a == 0  && c == 9) || (a == 7  && c == 14) || (a == 63  && c == 54))
            cout << "Stop\n";
        else
            cout << "Continue\n";
    }
    return 0;
}