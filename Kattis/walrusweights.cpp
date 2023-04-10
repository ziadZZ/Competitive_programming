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

int main(){
    int n; cin >> n;
    vector<int> w(n);
    for (int i=0; i<n; i++){
        cin >> w[i];
    }
    vvi dp(1001,vi(1001,0));

    for (int m = 1 ; m<= 1000 ; m++){
        if (w[0]%2==0 && m>= w[0]/2) dp[0][m]=w[0];
        else if (w[0]%2!=0 && m> w[0]/2) dp[0][m]=w[0];
    }
    for (int m=1; m<= 1000;m++){
        for (int i=1; i<n ; i++){
            if (abs(w[i]+dp[i-1][max(0,m-w[i])]-m)<abs(dp[i-1][m]-m)){
                dp[i][m]=w[i]+dp[i-1][max(0,m-w[i])];

            }
            else if (abs(w[i]+dp[i-1][max(0,m-w[i])]-m)> abs(dp[i-1][m]-m))
            {
               dp[i][m] = dp[i-1][m];
            }
            else
            {
                dp[i][m]=max(dp[i-1][m],w[i]+dp[i-1][max(0,m-w[i])]);
            }
            
        }
    }
    cout << dp[n-1][1000] << endl;
    return 0;
}