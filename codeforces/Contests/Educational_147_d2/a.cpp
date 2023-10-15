
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
    int t; cin >> t;
    while(t--){
        string s;
        cin >> s;
        int ans = 1;
        if (s[0]=='0') {cout << 0 << endl; continue;}
        if (s[0]=='?') ans *= 9;
        for (int i = 1; i<s.size() ; i++){
            if (s[i]=='?') ans *= 10;
        }
        cout << ans << endl;
    }
}