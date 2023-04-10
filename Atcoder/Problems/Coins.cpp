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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin>>n;
    vector<double> p(n);
    for(int i = 0; i<n ; i++){
        cin >> p[i];
    }
    vector<double> P(n+1,0.0);
    P[0]=1.0;
    for (int i= 0; i<n ; i++){
        for(int m = i+1; m>=1 ; m--){
            P[m]=p[i]*P[m-1]+(1-p[i])*P[m] ;
        }
    }
    cout << P[n/2+1]<< endl;
    return 0;
}
 
