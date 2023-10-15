
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

int log_2(int n){
    if (n==1) return 0;
    else return 1 + log_2(n/2);
}

int solve(string& s){
    char c;
    int m = 0;
    for (int i = 97 ; i<= 122 ; i++){
        c  = (char) i;
        int m_c_max = 0;
        int m_cur = 0;
        for (auto l : s){
            if (l!=c){
                m_cur ++;
                m_c_max = max(m_cur, m_c_max);
            }
            else m_cur = 0;
        }
        if (m == 0 && m_c_max != s.size()) m = m_c_max;
        else m = min(m_c_max,m);
    }
    if (m==0) return 0;
    else return 1 + log_2(m);
}

int main(){
    int t; cin >> t;
    string s;
    while(t--){
        cin >> s; 
        cout << solve(s) << endl;
    }
}
