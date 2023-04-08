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

int n;
double q;

ld solve(int n,double q){
    
    double p,a,b,copy ;
    a=100.0; b=0.0;
    for (int i =0; i<n ;i++){
        cin >> p;
        copy = a;
        a = max(a,b*p-q);
        b = max(b,(copy-q)/p);
    }
    return a;
}
int main(){
    cin >> n >> q;
    cout << solve(n,q) << endl;
    return 0;
}