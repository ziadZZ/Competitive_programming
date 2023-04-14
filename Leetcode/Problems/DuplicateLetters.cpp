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
    int last_ocr[26];
    bool vis[26];
    string removeDuplicateLetters(string s) {
        int n = s.size();

        memset(last_ocr, -1, sizeof(last_ocr));
        memset(vis, false, sizeof(vis));

        for(int i = n-1; i>=0; i--){
            if (last_ocr[s[i]-'a'] == -1) last_ocr[s[i]-'a'] = i;
        }

        stack<char> p;
        p.push(s[0]); vis[s[0]-'a'] = true;

        char c;
        for(int i = 1; i<n ;i++){
            c = p.top();
            if (vis[s[i]-'a']) continue;

            if (c > s[i]){
                while (c > s[i] && last_ocr[c -'a']>=i){
                    p.pop(); 
                    vis[c-'a'] = false;
                    if (p.empty()) break;
                    c = p.top();
                }
                p.push(s[i]);
                vis[s[i]-'a'] = true;
            }

            else{
                p.push(s[i]);
                vis[s[i]-'a'] = true;
            }

        }

        string ans;
        while(!p.empty()){
            ans += p.top(); p.pop();
        }
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main(){
    int t;
    cin >> t;
    string s;
    while(t--){
        Solution test;
        cin >> s;
        cout << test.removeDuplicateLetters(s) << endl;
    }
    return 0;
}