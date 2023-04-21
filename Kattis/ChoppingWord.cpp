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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

    int n; cin >> n;
    priority_queue<int> leaf;
    vector<int> frq(n+2);
    vector<int> v(n);
    vector<int> u;
    int m = 0;
    for (int i = 0; i<n ; i++){
        cin >> v[i];
        m = max(v[i],m);
        frq[v[i]]++;
    }
    if (m != n+1) {cout << "Error" << endl; return 0;}
    
    for (int i = 1  ; i<= n+1 ; i++){ 
        if (!frq[i]) leaf.push(-i);
    }

    for (int i = 0; i<n ; i++){
        if (leaf.empty()) {cout << "error " << i << endl; break;}
        u.pb(-leaf.top());
        leaf.pop();
        frq[v[i]]--;
        if (!frq[v[i]]) leaf.push(-v[i]);
    }

    for (int uu : u) cout << uu << endl;

    return 0;
}