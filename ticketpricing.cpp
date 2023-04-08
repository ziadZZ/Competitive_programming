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

int d[53][301];
int n, w; 
int p_firstweek;

int solve(vvi& p, vvi& s, int ww, int ss){
    if (ww==w+1) return 0;
    if (d[ww][ss]!=-1) return d[ww][ss];
    int k = p[ww].size();
    int m = 0;
    for (int i=0; i<k ;i++){
        if (m < solve(p,s,ww+1,max(ss-s[ww][i],0))+ min(s[ww][i],ss)*p[ww][i]){
        m = solve(p,s,ww+1,max(ss-s[ww][i],0))+min(s[ww][i],ss)*p[ww][i];
        if (ww==0) p_firstweek = p[ww][i];
        }
    }
    d[ww][ss]=m;
    return m;
}

int main(){
    cin >> n >> w;
    int k, price, seat;
    vvi p(w+1); vvi s(w+1);
    for (int i=0; i<= w; i++){
        cin >> k; int copy_k = k;
        while (copy_k--){
            cin >> price; p[i].pb(price);
        }
        copy_k = k;
        while (copy_k--){
            cin >> seat; s[i].pb(seat);
        }
    }
    memset(d,-1,sizeof(d));
    cout << solve(p,s,0,n) << endl;
    cout << p_firstweek << endl;

    return 0;
}