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

int main () {
    ll n,m; cin >> n >> m;
    vll w(n);
    for (ll i=0; i<n ;i++){cin >> w[i];}   
    sort(w.begin(),w.end());
    vector<pair<ll,ll>> px; ll x,p;
    for (ll i=0; i<m ;i++){cin >> x >> p; px.pb({p,x});}
    sort(px.begin(),px.end());
    ll i = n-1; ll j = m-1;
    ll gain = 0;
    ll cur = 0;
    while (i>=0 && j>=0){
        p = px[j].first; x = px[j].second;
        if (x==0){gain += cur*p; j--; cur =0;}
        else {
            cur+= w[i];
            i--; 
            px[j].second--;
            if (i<0) gain += cur*p;
        }
    }
    cout << gain << endl;


    return 0;

}