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
    string s; int n, ans;
    while(t--){
        cin >> s;
        n = s.size();
        ans = 0;
        int i = 0;
        if (n==1 && s[0]=='^') {cout << 1 << endl; continue;}
        if (s[0]!='^') ans++;
        else i++;
        while (i<n){
            if ((s[i]=='_') and (i+1==n || s[i+1]=='_')){
                ans++;  
            }
            i++;
        }
        cout << ans << endl;
    }
    
    return 0;
}