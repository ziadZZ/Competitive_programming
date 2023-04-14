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
typedef long double ld;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<vector<int>> vvi;

const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const ll mod = 1e9+7;
const int N = 1e5 + 5;
string s = "welcome to code jam";

int lt;
int ans = 0;
int mod4 = 10000;
int ls;

void solve(string& txt, int i, int j){
    if (j==ls){
        ans = (ans +1) % mod4;
        return;
    }
    if (i == lt) return;
    if (txt[i]=txt[j]) solve(txt,i+1,j+1);
    solve(txt,i+1,j);
}


int main(){
    int t; cin >> t;
    string txt;
    ls = s.length();
    for (int x = 1; x<=t ; x++){
        getline(cin, txt);
        lt = txt.length();
        solve(txt, 0,0);
        cout << ans << endl;
    }
    return 0;
}