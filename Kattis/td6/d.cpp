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
vector<int> s(20);
vector<bool> cur1(20);
vector<bool> cur2(20);
int cnt ;
bool solve(vi& a, int i, int s1, int s2){
    if (s1 == s2 && s1) return true;

    if (i == n) return false;
    
    if (solve(a,i+1,s1,s2)) return true;
    cur1[i]= true;
    if (solve(a,i+1,s1+a[i],s2)) return true;
    cur1[i]= false;
    cur2[i]= true;
    if (solve(a,i+1,s1,s2+a[i])) return true;
    cur1[i]= false;
    cur2[i]= false;

    return false;
}

int main(){
    int t; cin >> t;
    
    for (int x = 1; x<= t ; x++){
        cin >> n;
        //cnt = 0;
        for (int i = 0; i<n ; i++){
            cin >> s[i];
            cur1[i] = false;
            cur2[i] = false;
        }
        cout << "Case #" << x << ":" << endl;
        if (!solve(s,0,0,0)) cout << "Impossible" << endl;
        else{
            for (int i = 0; i<n ; i++){
                if (cur1[i]) cout << s[i] << " ";
            }
            cout << endl;
            for (int i = 0; i<n ; i++){
                if (cur2[i]) cout << s[i] << " ";
            }
            cout << endl;
        }
        
    }
}