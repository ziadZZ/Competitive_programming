

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

double solve(int n, double q, vector<double>& p){
    double u = 100;
    double s = 0;
    for (int i = 0; i<n ; ++i){
        double copy_u = u;
        u = max(u, s*p[i]-q);
        s = max(s, (copy_u-q)/p[i]);
    }
    return u;
}

int main(){
    int n ;
    double q;
    cin >> n >> q;
    vector<double> p(n);
    for (int i = 0; i<n ; ++i){
        cin >> p[i];
    }
    cout << solve(n , q, p) << endl;
    return 0;
}