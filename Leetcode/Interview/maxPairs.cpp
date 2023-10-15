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
const int N = 2*1e5;

int n, z;
int a[N];

int main (){
    scanf("%d", &n);
    scanf("%d", &z);
    for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
    sort(a, a+n);
    int l = 0;
    int r = n/2 +1;
    while (r-l > 1){
        int k = (l+r)/2;
        bool ok = true;
        for (int i = 0; i<k ; ++i){
            if (a[n-k+i]-a[i] < z){
                ok = false;
                break;
            }
        }
        if (ok) l = k;
        else r = k;
    }
    cout << l << endl;
    return 0;
}