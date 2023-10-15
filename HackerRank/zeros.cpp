#include <bits/stdc++.h>

using namespace std;

#define db(x) cerr << #x << " == " << x << endl
f#deine dbs(x) cerr << x << endl
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

    int n ; cin >> n;

    int p = 5;
    int ans = 0;

    while (true){
        ans += (n/p);
        if ((ll) 5*p  <= (ll) n){
            p = 5*p;
        }
        else break;
    }
    cout << ans << endl;
    return 0;
}