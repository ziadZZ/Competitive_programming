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
    string s;
    cin >> s;
    string rev_s = s;
    reverse(rev_s.begin(), rev_s.end());
    // cout << rev_s << endl;
    int n = s.length();
    bool ans = 0;
    for (int i = 0; i<n ; ++i){
        bool ok = 1;
        for (int j = i ; j < i+n; ++j){
            if (rev_s[j-i] != s[j%n]) {ok = 0; break;}
        }
        if (ok) {
            ans = 1; 
            // cout << i << endl; 
            break;
        }
    }
    cout << ans << endl;
    return 0;
}