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

void solve(int c, int n){
    vi v(n);
    vi w(n);
    for (int i =0; i< n ; i++){
        cin >> v[i] >> w[i];
    }
    int dp[c+1];
    cl(dp,0);
    int parent[n][c+1]; int count[c+1];
    cl(count,0);
    
    for (int m = w[0]; m<=c ; m++){
        dp[m]=v[0];
        count[m]++;
        parent[0][m]=0;
    }
    
    for (int i = 1 ; i <n ; i++){
        for (int m = c; m >=0 ; m--){
            if (m>= w[i] && dp[m-w[i]]+v[i] > dp[m]){
                dp[m]=dp[m-w[i]]+v[i] ;
                parent[i][m]=i;
                count[m] =count[m-w[i]]+1;
            }
            else {
                parent[i][m]=parent[i-1][m];
            }
        }
    }
    cout << count[c]<< endl;
    int i = n-1;
    int ww = c;
    while (count[c]--){
        cout << parent[i][ww] << " ";
        i = parent[i][ww];
        ww = ww -  w[i];
        i--;
    }
    cout << endl;


}

int main(){
    int c,n; 
    while (cin >> c >> n){
        solve(c,n);
    }
    return 0;
}