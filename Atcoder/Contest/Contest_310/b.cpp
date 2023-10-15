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
    int n, m;
    cin >> n >> m;
    vector<int> p;
    vector<int> c;
    vector<vector<bool>> f(n,vector<bool>(m,0));
    int pp, cc, v;
    for (int i = 0; i<n ; ++i){
        cin >> pp >> cc;
        p.pb(pp);
        c.pb(cc);
        while (cc--){
            cin >> v;
            f[i][v-1] = 1;
        }
    }
    for (int i = 0; i<n ; i++){
        for (int j = 0; j<n ; ++j){
            if (j!=i && p[i]>=p[j]){
                bool ok = 1;
                for(int fi = 0; fi<m; fi++){
                    if (f[i][fi]){
                        if (!f[j][fi]) {ok = 0; break;}
                    }
                }
                if (ok){
                    if (p[i]>p[j] || (p[i]==p[j] && c[j]>c[i])){
                        cout << "Yes" << endl;
                        return 0;
                    }
                }
            }

        }
    }
    cout << "No" << endl;
    return 0;
}