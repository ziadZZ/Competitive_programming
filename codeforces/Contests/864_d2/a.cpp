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

int n,m;

int incercle(int x,int y){
    if ((x==1 && y==1) || (x==n && y==1) || (x==n && y==m) || (x==1 && y==m))
    return 2;
    if (x==1 || x==n) return 3;
    if (y==1 || y==m) return 3;
    else return 4;
}

int main(){
    int t ;  cin >> t;
    int x1,y1;
    int x2,y2;
    while (t--){
        cin >> n >> m;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << min(incercle(x1,y1),incercle(x2,y2)) << endl;
    }
    return 0;
}