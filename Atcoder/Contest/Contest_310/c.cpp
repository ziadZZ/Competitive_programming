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

bool equal(string& a , string& b){
    if (a==b){
        return 1;
    }
    if (a.size()!=b.size()){
        return 0;
    }
    int n = a.size();
    int i = 0;
    while (i<n && a[i]==b[n-1-i]){
        i++;
    }
    if (i==n) return 1;
    else return 0;
}



int main(){
    int n; cin >> n;
    // vector<string> s;
    string s;
    string rev_s;
    unordered_map<string,int> m;
    for (int i = 0; i<n ; ++i){
        cin >> s;
        m[s]=1;
        rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        m[rev_s] = 1;
        if (s ==  rev_s){
            m[s] = 2;
        }
    }
    int count = 0;
    for (auto [key, value] : m){
        count += value;
    }
    cout << count /2 << endl;
    return 0;
}

    /* for (int i = 0; i<n ; ++i){
        bool ok = 1;
        for (int j = i+1; j<n ; ++j){
            if (equal(s[i],s[j])){
                ok = 0;
                break;
            }
        }
        count += ok;
    }*/