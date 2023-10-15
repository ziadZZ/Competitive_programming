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
    int t; cin >> t;
    while (t--){
        int x,k,n;
        cin >> n >> k >> x;
        if (x!=1){
            cout << "YES" << endl;
            cout << n << endl;
            while (n--){
                cout << 1 << " " ;
            }
            cout << endl;
        }
        else if (k > 1 && n%2==0){
            cout << "YES" << endl;
            cout << n/2 << endl;
            n = n/2;
            while (n--){
                cout << 2 << " " ;
            }
            cout << endl;
        }
        else if (k>2 && n>=3){
            cout << "YES" << endl;
            cout << (n-3)/2 +1 << endl;
            n = (n-3)/2;
            cout << 3 << " ";
            while (n--){
                cout << 2 << " " ;
            }
            cout << endl;
        }
        else cout << "NO" << endl;
    }
    return 0;
}