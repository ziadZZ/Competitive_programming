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

int main(){
    int n; cin >> n;
    vector<ll> s(3);
    vll a(3,0);
    vll b(3,0);
    ll x;
    for (int i = 1; i<=n; i++){
        cin >> x;
        a[i%3] +=x;
    }
    for (int i = 1; i<=n; i++){
        cin >> x;
        b[i%3] +=x;
    }
    s[0] = a[0]*b[0]+a[1]*b[2]+a[2]*b[1];
    s[1] = a[0]*b[1]+a[1]*b[0]+a[2]*b[2];
    s[2] = a[0]*b[2]+a[2]*b[0]+a[1]*b[1];

    for (auto ss : s) cout << ss << " ";
    cout << endl;

    return 0;
}