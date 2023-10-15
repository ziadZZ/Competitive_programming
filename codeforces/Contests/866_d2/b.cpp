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
    string s;
    while(t--){
        cin >> s;
        ll l =0;
        ll cur = 0;
        int n = s.length();
        char c;
        for (int i = 0; i< 2*n; i++){
            c = s[i%n];
            if (c=='1') cur++;
            else{l = max(l,cur); cur = 0;}
        }
        l = max(cur,l);
        if (l==2*n) { l = l/2 ;  cout << l << endl; cout << l*l << endl; continue;}
        cout << (ll) (((l+1)/2) * ((l+1)-(l+1)/2)) << endl;
    }
    return 0;
}