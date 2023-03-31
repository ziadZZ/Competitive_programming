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


void solve(int n, int k){
    int ans = 0;
    vector<pair<ll,ll>> ts;
    ll s,t;
    for (int i = 0; i<n ; i++){
        cin >> s >> t;
        ts.pb({t,s});
    }
    sort(ts.begin(),ts.end());
    multiset<ll> q;
    for (int i = 0; i<k ; i++){
       q.insert(0);
    }
    for (int i = 0; i<n ; i++){
        s = ts[i].second;
        auto it = q.upper_bound(s);
        if (it == q.begin()) continue;
        if (it == q.end() || *it > s ){
            it--;
            while (it != q.begin() && *it==s){
                it--;
            }
            if (*it!=s){
                q.erase(it);
                ans++;
                q.insert(ts[i].first);
            }   
        }
    }
    cout << ans << endl;
}

int main () {
    ll n,k;
    cin >> n >> k;
    solve(n,k);
    return 0;
}