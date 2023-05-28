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

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& a) {
        int n = a.size();
        if (n&1) return {};
        int mid = (int) n/2;
        multiset<int> q;
        for (auto c : a)
            q.insert(c);
        vector<int> ans;
        int element;
        while(!q.empty()){
            element = *q.begin();
            q.erase(q.begin());
            auto it = q.find(2*element);
            if (it==q.end())
                break;
            ans.push_back(element);
            q.erase(it);
        }
        if (q.empty()) return ans;
        return {};
    }
};

int main(){
    Solution s;
    vi a = {1,3,4,2,6,8};
    a = s.findOriginalArray(a);
    for (auto x: a) cout << x << " ";
    cout << endl;
}