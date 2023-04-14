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

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> e(n);
    vi t(m);
    for (int i =0; i<n ; i++){
        cin >> e[i];
    }
    for (int j = 0; j<m ; j++){
        cin >> t[j];
    }
    unordered_map<int , int > ocr;
    int time = 0;
   
    for (int i =0; i<n ; i++){
        for (int j = 0; j<m ; j++){
            time = t[j]-e[i];
            if (time < 0) continue;
            auto it = ocr.find(time);
            if (it == ocr.end()) ocr[time] = 1;
            else it->second++;
        }
    }
    
    int ans = inf;
    int max_freq = 0;
    for (auto [t,frq] : ocr){
        // cout << t << " " << frq << endl;
        if (frq == max_freq && t<ans){
            ans = t;
            max_freq = frq;
        }
        else if (frq > max_freq){
            ans = t;
            max_freq = frq;
        }
    }
    if (ans == inf) cout << 0 << endl;
    else cout << ans << endl;
    return 0;
}