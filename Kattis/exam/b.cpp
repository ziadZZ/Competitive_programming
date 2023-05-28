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
    int l,k,s;
    cin >> l >> k >> s;
    unordered_map<int, int> m;
    unordered_map<int, pii> time;
    vector<pair<int, int>> ranking;
    // vector<int> m(s+1,0);
    // vector<pii> time(s+1);
    /// vector<pair<double, int>> ranking;
    int p;
    string t;
    while (l--){
        cin >> p >> t;
        if (m.find(p)== m.end()) {m[p]=0;  time[p] = {0,0};}
        m[p]++;
        int min = stoi(t.substr(0,2));
        int sec = stoi(t.substr(3,2));
        // cout <<  min << " " << sec << endl;
        if (time[p].second + sec >= 60){
            time[p].second = time[p].second + sec - 60;
            time[p].first += min + 1;
        }
        else {
            time[p].second += sec;
            time[p].first += min;
        }
        // cout << p << " " << time[p].second  << time[p].first << endl;
        if (m[p]==k){
            ranking.pb({time[p].first*100+time[p].second,p});
        } 
    }
    sort(ranking.begin(), ranking.end());
    for (auto x : ranking) cout << x.second << endl;
    return 0;
}