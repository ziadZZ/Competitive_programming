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
    int f,s,g,u,d;
    cin >> f >> s >> g >> u >> d;
    s--; g--; 
    /*if  ((g-s) % (__gcd(u,d)) != 0){
        cout << "use the stairs" << endl; 
    }*/

    vector<int> dist(f,-1);
    dist[s] = 0;
    queue<int> q;
    q.push(s);
    int v;
    while (!q.empty()){
        v = q.front();
        q.pop();
        if (v+u < f && dist[v+u]==-1){
            dist[v+u] = dist[v] + 1;
            if (v+u == g) break;
            q.push(v+u);
        }
        if (v-d>=0 && dist[v-d]==-1){
            dist[v-d] = dist[v] + 1;
            if (v-d == g) break;
            q.push(v-d);
        }
    }
    if (dist[g]==-1) cout << "use the stairs" << endl;
    else cout << dist[g] << endl;

    return 0; 
}