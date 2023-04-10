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

ll s,p,m,n;
ll d[1000000];
ll solve(vll& t, ll i){
    if (i==n) return 0;
    if (d[i]!=-1) return d[i];
    else{
        ll j = i;
        while (j<n && ((t[i] +m) > t[j])){
            j++;
        }
        ll cout_s = s + solve(t,i+1);
        ll cout_p = p + solve(t,j);
        d[i]=min(cout_p,cout_s);
        return d[i];
    } 
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> p >> m >> n;
    vll t(n);
    cl(d,-1);
    for(int i = 0; i<n ; i++){
        cin >> t[i];
    }
    cout << solve(t,0) << endl;
    return 0;
}