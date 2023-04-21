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
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        vi a(n);
        vector<int> aa(n);
        for (int i = 0; i<n ; i++){
            cin >> a[i];
        }
        for (int i = 0; i<n ; i++){
            cin >> aa[i];
        }
        int l_ans = 0;
        int r_ans = 0;
        int l = 0;
        int r = 0;
        bool valid = false;
        for (int i = 0; i<n-1 ; i++){
            if (aa[i]<=aa[i+1]){
                if (a[i]!=aa[i] || a[i+1]!=aa[i+1])  valid = true;
                r++;
            }
            else{
                if (valid){l_ans=l; r_ans=r; valid = false;}
                l = i+1; 
                r = i+1;
            }
        }
        if (valid){l_ans=l; r_ans=r; valid = false;}
        cout << l_ans+1 << " " << r_ans+1 << endl ;
    }
    return 0;
}