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

bool update(string& cur, string& suffix, int& l, int& pos){
    int n = suffix.length();
    if (l-n-pos+2 < 0) return false;
    int p = -1;
    for (int i = 0; i<n ; i++){
        if (suffix[i] == '*') {p = i; break;}
    }

    if (p == -1) {
        if (n+pos-1 != l) return false;
        for (int j = pos-1; j<l; j++){
            if (cur[j]!='#'  && cur[j]!=suffix[j+1-pos]) return false;
            cur[j] = suffix[j+1-pos];
        }
        return true;
    }

    for (int j = 0; j<p ; j++){
        if (cur[j+pos-1]!='#'  && cur[j+pos-1]!=suffix[j]) return false;
        cur[j+pos-1] =suffix[j];
    }
    int jump = l-n-pos+2;

    for(int j = 1+p; j<n; j++){
        // cout << j+jump-1+pos-1 << endl;
        // cout << cur[j+jump-1+pos-1]  << endl;
        if (cur[j+jump-1+pos-1] != '#' && cur[j+jump-1+pos-1] != suffix[j]) return false;
        cur[j+jump-1+pos-1] = suffix[j];
    }



    /*for(int j = l-n+1+p; j<l; j++){
        if (cur[j] != '#' && cur[j] != suffix[j+n-l]) return false;
        cur[j] == suffix[j+n-l];
    }*/

    return true;
}

bool valid(string& ans, int& l){
    for (int i = 0; i<l ; i++){
        if (ans[i] == '#') return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
	cin.tie(NULL);
    int t; cin >> t;
    while (t--){
        int l , s;
        cin >> l >> s;
        string ans(l,'#');
        int pos; string suffix;
        bool found = true;
        for (int i = 0; i<s ; i++){
            // cout << ans << endl;
            cin >> pos >> suffix;
            if (found) {
                if (!update(ans,suffix,l,pos)){
                    found = false;
                }
            }
        }
        // cout << ans << endl;
        if (found) found = valid(ans, l);
        if (found) cout << ans << endl;
        else cout << "IMPOSSIBLE" << endl;
        
        //cout << ((found)? ans : "IMPOSSIBLE") << endl;
    }
    cout << flush;
    return 0;
}