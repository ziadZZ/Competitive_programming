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
    while (cin >> s){
        int k = 0;
        unordered_map<char, int> char_int;
        vector<char> int_char;
        int n = s.length();
        for (int i = 0; i<n ; i++){
            if (char_int.find(s[i])==char_int.end()){
                char_int[s[i]] = k;
                k++;
                int_char.pb(s[i]);
            }
        }
        queue<char> q;
        vector<bool> in_queue(k,false);
        int in_q = 0;
        unordered_map<int, int> possible;
       
        for (int i = 0; i<s.length() ; i++){
            char c = s[i];
            while (!q.empty() && q.front()==c){
                q.pop();
            }
            q.push(c);
            if (!in_queue[int_char[c]])  in_q++;
            in_queue[int_char[c]] = 1;
            if (in_q == k){
                possible[i]=q.size();
                q.pop();
                while (q.front()==c){
                    in_queue[int_char[q.front()]] = 0;
                    q.pop();
                }
                if (q.empty()) q.push(c);
                in_q--;
                
            }
        }
        int min_l = inf;
        for (auto [i,j] : possible){
            min_l = min(min_l , j);

        }
        unordered_map<string, int> m;
        int ans = 0;
        for (auto [i,j] : possible){
            if (j == min_l){
                if (m.find(s.substr(i-j+1, j)) == m.end()){
                    m[s.substr(i-j+1, j)] = 1;
                    ans ++;
                }

            }

        }
        cout << ans << endl;
    }
    return 0;
}








/*  for (int i = 0; i<n ; i++){
            if (m[c[i]].empty()) {int_char.pb(c[i]); k++}
            m[c[i]].pb(i);
        }
        int md = 0;
        for (int i = 0; i<k ; i++){
            for (int j = i+1 ; j<k; j++){
                for (auto mi : m[int_char[i]]){
                    for (auto mj : m[int_char[j]]){
                        md = max(md , abs(mi-mj));
                    }
                }
            }
        }
        vector<pii> possible;
        for (int i = 0; i<k ; i++){
            for (int j = i+1 ; j<k; j++){
                for (auto mi : m[int_char[i]]){
                    for (auto mj : m[int_char[j]]){
                        if (md == abs (mi - mj)){
                            possible.pb({min(mi,mj), max(mi,mj)});
                        }
                    }
                }
            }
        }
        unordered_map<string,int> min_propers;
        string min_proper;
        int ans = 0;
        for (auto {i,j} : possible){
            min_proper = s.substr(i,j-i+1);
            if (min_propers.find(min_proper) == min_propers.end()){
                ans ++;
                min_propers[min_proper] = 1;
            }
        }

queue<piii> q;
    q.push({0,{0,0}});
    int cur;
        int i,j;
        piii y;
        pii x;
        while (!q.empty()){
            y = q.front();
            q.pop();
            cut = y.first;
            x = y.second;
            i = x.first;
            j = x.second;
            

        }*/