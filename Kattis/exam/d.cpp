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
    string s;
    ll d;
    cin >> s >> d;
    int n = s.length();
    bitset<32> a(0);
    for (int i = 0; i<n ; i++){
        if (s[i]=='B') a[i]=1;
    }
    bitset<32> b(d);
    int r = 0;
    for (int i = 0; i<n ; i++){
        if ((r+a[i]+b[i])>=2)  {a[i] = r+a[i]+b[i]-2; r=1;}
        else {a[i] = r+a[i]+b[i]; r=0;}
        if (a[i]) s[i] = 'B';
        else s[i] = 'A';
    }
    cout << s << endl;
    return 0;
}