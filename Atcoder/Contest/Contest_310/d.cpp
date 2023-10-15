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


int n, t, m;
int ans;
vector<int> a(10);
vvi g;

bool possible(int i, int j){
    for (int v : g[i]){
        if (a[v]==j) return false;
    }
    return true;
}

void dfs(int i, int l){
    if (i==n && l ==t){
        ans++;
        return;
    }
    if (i<n){
        for (int j = 0; j<l; ++j){
            if (possible(i,j)){
                a[i]=j;
                dfs(i+1,l);
                a[i]=-1;
            }
        }
        if (l!=t){
            a[i]=l;
            dfs(i+1,l+1);
            a[i]=-1;
        }
    }
    return;
}

int main(){
    cin >> n >> t >> m;
    g.clear();
    g.resize(n);
    for (int i = 0; i<n; i++){
        a[i]=-1;
    }
    ans = 0;
    int i,j;
    while (m--){
        cin >> i >> j;
        i--; j--;
        g[i].pb(j);
        g[j].pb(i);
    }
    dfs(0,0);
    cout << ans << endl;
    return 0;
}   

