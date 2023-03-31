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

struct QuotientComparator {
    bool operator()(const pair<ll, ll>& x, const pair<ll, ll>& y) const {
        return x.first * y.second < x.second * y.first;
    }
};


void solve(ll n, ll b){
    ll a;
    priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, QuotientComparator> q;
    for (ll i=0; i<n; i++){
        cin >> a;
        q.push({a,1});
    }
    b-=n; // initialy we give each city one box
    while (b){
        auto x = q.top(); q.pop();
        x.second++;
        b--;
        q.push(x);
    }
    auto x = q.top();
    a = x.first;
    ll b = x.second;
    cout << (a%b==0 ? a/b : a/b+1)<< endl;
}


int main () {
    ll n,b;
    while (true){
        cin >> n >> b;
        if (n==-1 && b==-1) break;
        solve(n,b);
    }
    return 0;

}