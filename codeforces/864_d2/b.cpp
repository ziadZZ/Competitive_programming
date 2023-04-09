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
typedef long double ld;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const int N = 1e5 + 5;


void solve(){
    int n,k; cin >> n >> k;
    vvi a(n,vi(n));
    for (int i=0; i<n ;i++){
        for (int j=0; j<n ;j++){
            cin >> a[i][j];
        }
    } 
    int number_opr=0;
    for (int i=0; i<n ; i++){
        for (int j=0; j<n; j++){
            if ((i!=n-1-i  || j!= n-1-j) && a[i][j]!= a[n-1-i][n-1-j]) number_opr++;
        }
    }
    number_opr/=2;
    if (number_opr <= k && (n%2==1 || (k-number_opr)%2==0))  cout << "YES" << endl;
    else  cout << "NO" << endl;
}

int main(){
    int t ; cin >> t;
    while(t--){
        solve();
    }
    return 0;
}