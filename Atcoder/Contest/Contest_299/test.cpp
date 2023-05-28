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
    freopen("exo1.in","r",stdin);
    freopen("exo.out","w",stdout);
    int n; cin >> n;
    int m = 0;
    int r;
    int id;
    for (int i =0; i<n ; i++){
        cin >> r;
        if (r>m){
            id = i;
            m = r;
        }
    }
    cout << id << endl;
    return 0;
}