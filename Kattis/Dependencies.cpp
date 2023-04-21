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

vvi adjList;
vector<int> ans;

bool compare(int u, int v){
    // v is not a parent of u
    return find(adjList[v].begin(),adjList[v].end(),u) ==adjList[v].end();
}   


void visit(int i, vector<bool>& vis){
    vis[i] = true;
    for (int j : adjList[i]){
        if (!vis[j])
            visit(j,vis);
    }
    ans.pb(i);
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    int n; cin >> n; cin.ignore();

    unordered_map<string,int> id ;
    vector<string> reverse_id;
    
    
    adjList.clear();
    adjList.resize(100000);

    string line;
    int i = 0;
    while (n--){
        getline(cin,line);
        stringstream ss(line);
        string u; ss >> u;
        u = u.substr(0,u.size()-1);
        // cout << u << endl;
        if (id.find(u) == id.end()) {id[u] = i++; reverse_id.pb(u);}        
        string p;
        while(ss >> p){
            if (id.find(p) == id.end()) {id[p] = i++; reverse_id.pb(p);}  
            adjList[id[p]].pb(id[u]);
        }
    }

    
    string file;
    cin >> file;
    int start = id[file];
    vector<bool> vis(i);
    ans.clear();
    visit(start,vis);
    reverse(ans.begin(),ans.end());
    for (auto j : ans) cout << reverse_id[j] << endl;

    /* int cur = id[file];
    queue<int> q;
    q.push(cur);
    while(!q.empty()){
        cout << reverse_id[cur] << endl;
        cur = q.front();
        q.pop();
        for (auto u :)

    }*/
    return 0;
}