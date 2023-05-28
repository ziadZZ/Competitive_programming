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

struct ComparePairs {
    bool operator()(const piii& a, const piii& b) const {
        return a.second.second > b.second.second;  // Compare based on the first coordinate
    }
};

int main(){
    int n, m, q, s;
    while (cin >> n >> m >> q >> s && n){
        // vvi g(n,vi(m,-1));
        vector<vector<pii>> g(n);
        int u,v,w;
        for (int i = 0; i<m ; ++i){
            cin >> u >> v >> w;
            g[u].pb({v,w});
            // g[v].pb({u,w});
            // g[u][v] = w;
            // g[v][u] = w;
        }
        vector<int> d(n,-1);
        priority_queue<piii,vector<piii>, ComparePairs> qe;
        d[s] = 0;
        for (auto pair : g[s]) qe.push({s,pair});
        while (!qe.empty()){
            piii x = qe.top();
            qe.pop();
            u = x.first;
            v = x.second.first;
            w = x.second.second;
            d[v] = d[u]+w;
            for (auto pair : g[v]){
                if (d[pair.first]==-1){
                    qe.push({v,pair});
                }
            }
        }
        while (q--){
            cin >> u;
            if (d[u]!=-1) cout <<  d[u]  << endl;
            else cout << "IMPOSSIBLE" << endl;
        }
        cout << endl;
    }
    return 0;
}