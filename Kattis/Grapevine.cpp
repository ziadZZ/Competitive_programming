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


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int n , m, d;
    cin >> n >> m >> d;

    vi count(n); 
    
    vi t(n);
    unordered_map<string , int> id;
    string name;
    for (int i = 0; i<n ; i++){
        cin >> name >> t[i];
        id[name]=i;
    }

    vvi adjList(n);
    string name1 , name2;
    for (int i = 0; i<m ; i++){
        cin >> name1 >> name2;
        adjList[id[name1]].pb(id[name2]);
        adjList[id[name2]].pb(id[name1]);
    }

    string r;
    cin >> r;
    int u = id[r];

    int ans  = 0;
    queue<pii> q; // {id,day}
    q.push({u,0});
    pii x;
    int days;
    while(!q.empty()){
        x = q.front(); q.pop();
        u = x.first;
        days = x.second;
        if (days >= d) break;
        for (auto v : adjList[u]){
            if (count[v]==t[v]) continue;
            if (count[v]==0) ans++;
            count[v]++;
            if (count[v]==t[v]) q.push({v,days+1});
        }
    }
    cout << ans << endl;
    return 0;
}