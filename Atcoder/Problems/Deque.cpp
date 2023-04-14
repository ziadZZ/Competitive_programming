#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " == " << x << endl
#define dbs(x) cerr << x << endl
#define st first
#define nd second
#define pb push_back
#define mp make_pair
#define cl(x, y) memset(x, y, sizeof(x))
#define endl '\n'

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<int> vi;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const int N = 1e5 + 5;

ll a[3000];
ll d[3000][3000][2];
int n;

ll dp(int i, int j, ll turn){

    if (d[i][j][turn]!=linf) return d[i][j][turn];

    if (i==j) d[i][j][turn] = a[i]*(-2*turn+1);
    // -2*turn+1 = 1 if turn = 0 (ie first player's turn)
    // otherwise it's equal to -1

    else if (turn == 0){ // player 1's turn
        d[i][j][turn] = max(dp(i+1,j,1)+a[i], dp(i,j-1,1)+a[j]);
    }
    else{ // player 2's turn
        d[i][j][turn] = min(dp(i+1,j,0)-a[i], dp(i,j-1,0)-a[j]);
    }
    return d[i][j][turn];
}


int main(){
    // reading inputs
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }

    // initialization 
    for (int i=0 ; i<n ; i++){
        for (int j=0 ; j< n; j++){
            for (int turn = 0 ; turn <2 ; turn++){
                d[i][j][turn]=linf;
            }
        }
    }
    
    // OUTPUT
    cout << dp(0,n-1,0) << endl;
}