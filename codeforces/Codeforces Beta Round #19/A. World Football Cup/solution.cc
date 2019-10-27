#include <bits/stdc++.h>
using namespace std;

struct team {
    string name;
    int score, goals, goalsMissed;
    team( int score = 0, int goals=0, int goalsMissed=0 ): score(score), goals(goals), goalsMissed(goalsMissed) {}
    int diff() { return goals - goalsMissed;}
};

bool operator <( team a, team other ) {
    if( a.score == other.score ) {
        if( a.diff() == other.diff() ) return a.goals > other.goals;
        else return a.diff() > other.diff();
    } else return a.score > other.score;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    string s, s1;
    char c;
    team v[n];
    map< string, int > m;
    for( int i = 0; i < n; i++ ) {
        cin >> s;
        v[i].name = s;
        m[s] = m.size();
    }
    int limit = n*(n-1)/2;
    for( int i = 0; i < limit; i++ ) {
        cin.ignore();
        getline( cin, s, '-' );
        cin >> s1;
        int num1, num2;
        cin >> num1 >> c >> num2;
        v[m[s]].goals += num1;
        v[m[s]].goalsMissed += num2;
        v[m[s1]].goals += num2;
        v[m[s1]].goalsMissed += num1;
        if( num1 == num2 ) {
            v[m[s]].score++;
            v[m[s1]].score++;
            continue;
        }
        if( num1 > num2 ) {
            v[m[s]].score += 3;
        } else {
            v[m[s1]].score += 3;
        }
    }
    sort( v, v+n );
    string answer[n/2];
    for( int i = 0; i < n/2; i++ ) {
        answer[i] = v[i].name;
    }
    sort(answer, answer+n/2);
    for( string i: answer ) {
        cout << i << '\n';
    }
    return 0;
}