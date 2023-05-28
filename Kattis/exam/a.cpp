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

int sum_v(vector<int>& lines, int v){
    int sum = 0;
    for (auto u : lines){
        sum += (int) (u/v);
        sum += u%v;
    }
    return sum;
}

int main(){
    int f; cin >> f;
    int ans = 0;
    int n,u;
    int u_max = 0;
    vector<int> lines;
    while (f--){
        cin >> n;
        while (n--){
            cin >> u;
            lines.pb(u);
            u_max = max(u, u_max);
        }
    }
    if (u_max == 0){
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }
    int min_sum = inf;
    int arg_min;
    int cur_sum;
    for (int v = u_max; v>0; v--){
        cur_sum = sum_v(lines, v);
        if (cur_sum <= min_sum){
            min_sum = cur_sum;
            arg_min = v;
        }
    }
    cout << arg_min << endl;
    for (auto i : lines){
        min_sum -= i;
    }
    cout << - min_sum << endl;
    return 0;
}