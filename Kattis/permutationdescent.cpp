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

int pdc[101][101];
int M = 1001113;

int solve(int n, int v){
    if (pdc[n][v]!=-1) return pdc[n][v];
    pdc[n][v] = (solve(n-1,v-1)*(n-v) + solve(n-1,v)*(v+1))% M;
    return pdc[n][v];
}





int main(){
    //intilization 
    memset(pdc,-1,sizeof(pdc));

    for (int n = 0; n<101 ; n++){
        pdc[n][0]=1;
    }

    for (int n = 0; n<101 ; n++){
        for (int v=n ; v<101; v++){
            pdc[n][v]=0;
        }
    }

    int p; cin >> p;
    int k, n, v;
    int ans;

    while (p--){
        cin >> k >> n >> v;
        ans = solve(n,v);
        cout << k  << " " << ans << endl;
    }
    
    return 0;
}