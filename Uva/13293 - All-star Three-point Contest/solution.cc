#include <bits/stdc++.h>
using namespace std;

struct node {
  string  s, name;
  int score;
  node() { score = 0; }
  void lower() {
    s = name;
    for( char &i: s ) {
      i = tolower(i);
    }
  }
  bool operator <(const node & other ) const {
    if( score == other.score ) {
      return s < other.s;
    } else {
      return score > other.score;
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s;
  int n;
  int cases = 1;
  while( cin >> n ) {
    cout << "Case " << cases++ << ":\n";
    cin.ignore();
    node v[n];
    for( int i = 0; i < n; i++ ) {
      getline( cin, s );
      v[i].name = s.substr(0, s.size() - 50 );
      v[i].lower();
      int a = s.size() - 49;
      for( int j = a; j < s.size(); j += 2 ) {
        if( s[j] == '1') {
          v[i].score++;
          if( (j-a)%10 == 8 ) v[i].score++;
        }
      }
    }
    sort(v, v+n );
    for( int i = 0; i < n; i++ ) {
      cout << v[i].name <<  ' ' << v[i].score << '\n';
    }
  }
  return 0;
}