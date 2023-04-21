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
const int N = 1e5 ;
ll MOD = 998244353;
ll p[6*N+1];
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
ll poweer(ll b){
    if (p[b]!=-1) return p[b]; 
    else p[b]=binpow(10,b,MOD);
    return p[b];
}

int main(){
    int q; cin >> q;
    queue<ll> s;
    s.push(1);
    cl(p,-1);
    p[0]=1;
    for (int i = 1; i <= q; i++){
        p[i]= (p[i-1]*10)%MOD;
    }
    while (q--){
        int t;
        cin >> t;
        if (t==1){
            ll x;
            cin >> x;
            s.push(x);
        }
        else if (t==2){
            s.pop();
        }
        else{
            ll n = s.size();            
            ll a ;
            ll ans = 0;
            while (n--){
                a = s.front();
                ans +=  (a*p[n] % MOD);
                ans %= MOD;
                s.pop();
                s.push(a);
            }
            cout << ans << endl;
        }
    }
    return 0;
}