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
const int minus_inf = std::numeric_limits<int>::min();
const int N = 1e5 + 5;

int n, k;
vvi m(200,vi(2));
int dp[201][2][201];
int ans;
int mymax(int a, int b, int c, int d){
    return max(a,max(b,max(c,d)));
}
int main(){
    while(cin >> n >> k && n ){
        for (int i = 0 ; i<n ; i++){
            cin >> m[i][0] >> m[i][1] ;
        }
        for (int repition = 0; repition<2; repition++){
            for (int i = 0; i<=200 ; i++){
                for (int j = 0; j<=200; j++){
                    dp[i][0][j] = minus_inf;
                    dp[i][1][j] = minus_inf;
                }
            }
            dp[200][0][0] = 0;
            dp[200][1][0] = 0;
           
            dp[n-1][0][0] = m[n-1][0]+m[n-1][1];
            dp[n-1][0][1] = m[n-1][0];
            dp[n-1][1][0] = m[n-1][0]+m[n-1][1];
            dp[n-1][1][1] = m[n-1][1];
            for (int i = n-2; i>=0 ; i--){
                for (int r = 0; r<=k ; r++){
                    if (r==0){
                        dp[i][0][r] = m[i][0]+max(dp[i+1][0][r], dp[i+1][1][r]+m[i][1]);
                        dp[i][1][r] = m[i][1]+max(dp[i+1][1][r], dp[i+1][0][r]+m[i][0]);
                        continue;
                    }
                    dp[i][0][r] = m[i][0]+mymax(dp[i+2][1][max(r-1,0)]+m[i][1]+m[i+1][1],
                                            dp[i+1][0][max(r-1,0)], dp[i+1][0][r], dp[i+1][1][r]+m[i][1]);

                    dp[i][1][r] = m[i][1]+mymax(dp[i+2][0][max(r-1,0)]+m[i][0]+m[i+1][0],
                                            dp[i+1][1][max(r-1,0)], dp[i+1][1][r], dp[i+1][0][r]+m[i][0]);
                }
            }
            ans = max(dp[0][0][k],dp[0][1][k]);
            if (repition == 0){
                for (int i = 0 ; i< n/2; i++){
                    swap(m[i][0], m[n-1-i][0]);
                    swap(m[i][1], m[n-1-i][1]);
                }
            }
            ans = max(dp[0][0][k],max(dp[0][1][k],ans));
        }
        if (ans < 0) cout << 0 << endl;
        else cout << ans << endl;
    }
    
    return 0;
}