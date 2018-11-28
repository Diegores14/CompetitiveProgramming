#include <bits/stdc++.h>
using namespace std;
set<char> pieces;

void Fill(int x, int y, int varx, int vary, vector< vector<char> > & board){
    int _x = x;
    int _y = y;
    for(int i=0; i < 8; i++){
        _x += varx;
        _y += vary;
        if(_x < 0 || _x >=8 || _y < 0 || _y >=8)
            break;
        if(pieces.count(board[_y][_x]))
            break;
        board[_y][_x] = '*';
    }
}

void FillOnePoint(int x, int y, int varx, int vary, vector< vector<char> > & board){
    if(x+varx < 0 || x+varx >= 8 || y+vary < 0 || y+vary >= 8 || pieces.count(board[y+vary][x+varx]))
        return;
    board[y+vary][x+varx] = '*';
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    pieces.insert('P');
    pieces.insert('N');
    pieces.insert('B');
    pieces.insert('R');
    pieces.insert('Q');
    pieces.insert('K');
    pieces.insert('p');
    pieces.insert('n');
    pieces.insert('b');
    pieces.insert('r');
    pieces.insert('q');
    pieces.insert('k');
    while(getline(cin, s)){
        vector< vector<char> > v(8, vector<char>(8, '.'));
        int i=0, j=0;
        for(char it: s){
            if(it == '/'){
                i++;
                j=0;
                continue;
            }
            if('0' <= it && it <= '9'){
                j += it - '0';
            }else{
                v[i][j] = it;
                j++;
            }
        }
        /*for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }*/
        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                if(v[i][j] == 'Q' || v[i][j] == 'q'){
                    Fill(j, i, 1, 1, v);
                    Fill(j, i, -1, 1, v);
                    Fill(j, i, -1, -1, v);
                    Fill(j, i, 1, -1, v);
                    Fill(j, i, 0, -1, v);
                    Fill(j, i, 0, 1, v);
                    Fill(j, i, -1, 0, v);
                    Fill(j, i, 1, 0, v);
                    continue;
                }
                if(v[i][j] == 'R' || v[i][j] == 'r'){
                    Fill(j, i, 0, -1, v);
                    Fill(j, i, 0, 1, v);
                    Fill(j, i, -1, 0, v);
                    Fill(j, i, 1, 0, v);
                    continue;
                }
                if(v[i][j] == 'B' || v[i][j] == 'b'){
                    Fill(j, i, 1, 1, v);
                    Fill(j, i, -1, 1, v);
                    Fill(j, i, -1, -1, v);
                    Fill(j, i, 1, -1, v);
                    continue;
                }
                if(v[i][j] == 'K' || v[i][j] == 'k'){
                    FillOnePoint(j, i, 1, 1, v);
                    FillOnePoint(j, i, 1, -1, v);
                    FillOnePoint(j, i, -1, -1, v);
                    FillOnePoint(j, i, -1, 1, v);
                    FillOnePoint(j, i, 0, 1, v);
                    FillOnePoint(j, i, 0, -1, v);
                    FillOnePoint(j, i, 1, 0, v);
                    FillOnePoint(j, i, -1, 0, v);
                    continue;
                }
                if(v[i][j] == 'N' || v[i][j] == 'n'){
                    FillOnePoint(j, i, 2, 1, v);
                    FillOnePoint(j, i, -2, 1, v);
                    FillOnePoint(j, i, 1, 2, v);
                    FillOnePoint(j, i, -1, 2, v);
                    FillOnePoint(j, i, 2, -1, v);
                    FillOnePoint(j, i, -2, -1, v);
                    FillOnePoint(j, i, 1, -2, v);
                    FillOnePoint(j, i, -1, -2, v);
                    continue;
                }
                if(v[i][j] == 'P'){
                    FillOnePoint(j, i, 1, -1, v);
                    FillOnePoint(j, i, -1, -1, v);
                    continue;
                }
                if(v[i][j] == 'p'){
                    FillOnePoint(j, i, 1, 1, v);
                    FillOnePoint(j, i, -1, 1, v);
                }

            }
        }
        /*for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                cout << v[i][j] << ' ';
            }
            cout << '\n';
        }*/
        int ans = 0;
        for(i=0; i<8; i++){
            for(j=0; j<8; j++){
                if(v[i][j] == '.')
                    ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}