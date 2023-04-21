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

pair<int,int> rotation(int k, int i, int j, int& n){
    if (k==0) return {n-j-1,i};
    if (k==1) return {n-i-1, n-j-1};
    if (k==2) return {j,n-i-1};
    return {i,j};
}

bool one_rotation(int k, vvi& a, vvi& b, int& n){
    pii x;
    for (int i = 0; i<n ;i++){
        for (int j = 0; j<n ; j++){
            x = rotation(k,i,j,n);
            if (a[x.first][x.second] && !b[i][j]){
                return false;
            } 
        }
    }
    return true;
}

bool solve(vvi& a, vvi& b, int& n){
    pii x;
    for (int k =0; k<4; k++){
        if (one_rotation(k,a,b,n)) return true;
    }
    return false;
}

int main(){
    int n; cin >> n;
    vvi a(n);
    vvi b(n);
    int x;
    for (int i = 0; i<n ;i++){
        for (int j = 0; j<n ; j++){
            cin >> x; 
            a[i].pb(x);
        }
    }
    for (int i = 0; i<n ;i++){
        for (int j = 0; j<n ; j++){
            cin >> x; 
            b[i].pb(x);
            //cout << a[i][j] << " ";
        }
    }
    
    
    cout << (solve(a,b,n)? "Yes" : "No") << endl;
    return 0;
}