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

int n, m ;
vector<vector<string>> ans;
vector<string> cur;
vector<int> dist(501);
vector<vector<int>> adj(501);
vector<bool> vis(501);

class Solution {
public:

    bool verify(string &p, string &q){    // verify return true if the two strings can be equal by changing exactly  one char
        int count = 0;
        for (int j=0 ; j<p.length(); j++){
            count += (p[j]!=q[j]);
            if (count > 1) break;
        }
        return ((count==1) ? true : false);
    }


    bool containsString(std::vector<std::string>& wordList, std::string& endWord) {
        auto it = find(wordList.begin(), wordList.end(), endWord);
        if (it == wordList.end()) return false;
        swap(*it,*(--wordList.end()));
        return true;
    }

    void fill_in_adj(vector<string>& wordList, string beginWord){
        for (int i = 0; i<n ; i++){
            for (int j = i+1 ; j<n ; j++){
                if (verify(wordList[i],wordList[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i<n ; i++){
            if (verify(wordList[i], beginWord)){
                adj[i].push_back(n);
                adj[n].push_back(i);
            }
        }

    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        n = wordList.size();
        ans.clear();

        if (!containsString(wordList, endWord))  return ans;

        cur.clear();

        for(int i = 0; i<= n; i++) {vis[i]=false; dist[i]=inf; adj[i].clear();}

        
        fill_in_adj(wordList, beginWord);
        
        solve(n, n-1, wordList, beginWord);

        for (int i=0; i<ans.size(); i++) reverse(ans[i].begin(), ans[i].end());
        return ans;
    }

    
    

    //solving the problem
    
    void solve(int s, int f, vector<string>& wordList, string& beginWord){
        
        dist[s] = 0;
        vis[s] = true;

        queue<int> q;
        q.push(s);

        vector<vector<int>> parents(n+1);

        int u;
        while (!q.empty()){

            u = q.front(); q.pop();

            if (u == f) break;

            for (auto v : adj[u]){
                if (!vis[v]){
                    parents[v].push_back(u);
                    vis[v] = true;
                    dist[v] = dist[u]+1;
                    q.push(v);
                }
                else if (dist[v]==dist[u]+1) // if u is in the same depth as v's parents
                parents[v].push_back(u);
            }
        }      

        if (dist[f]==inf) return;
        
        
        all_paths(s, f, parents, wordList, beginWord);
        
    }

    void all_paths(int s, int u , vector<vector<int>> &parents, vector<string>& wordList,string& beginWord  ){
        if (u==s){
            cur.push_back(beginWord);
            ans.push_back(cur);
            return;
        }
        cur.push_back(wordList[u]);
        for (auto v : parents[u]){
            all_paths(s, v, parents, wordList, beginWord);
            cur.pop_back();
        }
    }


};