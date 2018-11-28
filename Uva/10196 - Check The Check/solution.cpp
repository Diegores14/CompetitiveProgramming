#include <bits/stdc++.h>
using namespace std;
set<char> verticalMove; // here I save the pieces that move vertically and horiztally.
set<char> diagonalMove; // here I save the pieces taht move diagonally.

struct point{
    int x, y;
    point(){x=-1; y=-1;}
};

bool checkDiagonal(const int & x, const int & y, const char & letter1, const char & letter2, int varx, int vary, vector<string> board){
    int _X = x, _Y = y;
    for(int i=1; i<8; i++){
        _X += varx;
        _Y += vary;
        if(_X<0 || _X >= 8 || _Y<0 || _Y >= 8)
            break;
        if(board[_Y][_X] == '.')
            continue;
        if((letter1 <= board[_Y][_X] && board[_Y][_X] <= letter2) && diagonalMove.count(board[_Y][_X])){
            return true;
        }
        if(board[_Y][_X] != '.')
            break;
    }
    return false;
}

// this funtion check if there is check in horizontally and vertically.
bool checkVH(const int & x, const int & y, const char & letter1, const char & letter2, int varx, int vary, vector<string> board){
    int _X = x, _Y = y;
    for(int i=1; i<8; i++){
        _X += varx;
        _Y += vary;
        if(_X<0 || _X >= 8 || _Y<0 || _Y >= 8)
            break;
        if(board[_Y][_X] == '.')
            continue;
        if( (letter1 <= board[_Y][_X] && board[_Y][_X] <= letter2) && verticalMove.count(board[_Y][_X])){
            return true;
        }
        if(board[_Y][_X] != '.')
            break;
    }
    return false;
}

bool checkKnight(const int & x, const int & y, char N, int varx, int vary, vector<string> board){
    int _X = x + varx, _Y = y + vary;
    if(_X<0 || _X >= 8 || _Y<0 || _Y >= 8)
        return false;
    if(board[_Y][_X] != '.' && board[_Y][_X] == N)
        return true;
    return false;
}

bool checkPawn(bool color, const int & x, const int &y, const vector<string> & board){
    if(color){
        if((y > 0 && x > 0 && board[y-1][x-1] == 'p') || (y > 0 && x < 7 && board[y-1][x+1] == 'p'))
            return true;
    }else{
        if((y < 7 && x > 0 && board[y+1][x-1] == 'P') || (y < 7 && x < 7 && board[y+1][x+1] == 'P'))
            return true;
    }
    return false;
}

bool isCheck(bool color, int x, int y, vector<string> & board){
    char letter1 = color? 'a' : 'A', letter2 = color? 'z' : 'Z';
    char N = color? 'n' : 'N';
    if(checkDiagonal(x, y, letter1, letter2, 1, 1, board))
        return true;
    if(checkDiagonal(x, y, letter1, letter2, -1, 1, board))
        return true;
    if(checkDiagonal(x, y, letter1, letter2, -1, -1, board))
        return true;
    if(checkDiagonal(x, y, letter1, letter2, 1, -1, board))
        return true;
    if(checkVH(x, y, letter1, letter2, 0, -1, board))
        return true;
    if(checkVH(x, y, letter1, letter2, 0, 1, board))
        return true;
    if(checkVH(x, y, letter1, letter2, -1, 0, board))
        return true;
    if(checkVH(x, y, letter1, letter2, 1, 0, board))
        return true;
    if(checkKnight(x, y, N, 2, 1, board))
        return true;
    if(checkKnight(x, y, N, 2, -1, board))
        return true;
    if(checkKnight(x, y, N, -2, 1, board))
        return true;
    if(checkKnight(x, y, N, -2, -1, board))
        return true;
    if(checkKnight(x, y, N, 1, 2, board))
        return true;
    if(checkKnight(x, y, N, -1, 2, board))
        return true;
    if(checkKnight(x, y, N, 1, -2, board))
        return true;
    if(checkKnight(x, y, N, -1, -2, board))
        return true;
    if(checkPawn(color, x, y, board))
        return true;
    return false;
}

int main(){
    // ios_base::sync_with_stdio(false); cin.tie(NULL);
    string s;
    int i = 0;
    verticalMove.insert('R');
    verticalMove.insert('r');
    verticalMove.insert('Q');
    verticalMove.insert('q');
    diagonalMove.insert('Q');
    diagonalMove.insert('q');
    diagonalMove.insert('B');
    diagonalMove.insert('b');
    while(true){
        point kingW, kingB;
        vector<string> board(8);
        for(int i = 0; i < 8; i++){
            getline(cin, board[i]); 
            for(int j = 0; j < 8; j++){
                // cout << i << ' ' << j << '\n';
                if(board[i][j] == 'k'){
                    kingB.x = j;
                    kingB.y = i;
                }
                if(board[i][j] == 'K'){
                    kingW.x = j;
                    kingW.y = i;
                }
            }
            // cout << "hello\n";
        }
        if(kingB.x == -1)
            return 0;
        cout << "Game #" << ++i << ": ";
        if(isCheck(true, kingW.x, kingW.y, board))
            cout << "white king is in check.\n";
        else{
            if(isCheck(false, kingB.x, kingB.y, board))
                cout << "black king is in check.\n";
            else
                cout << "no king is in check.\n";
        }
        cin.ignore();
    }
    return 0;
}