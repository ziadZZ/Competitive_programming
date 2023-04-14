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

vector<vector<char>> to_letter(8);

class Solution {
public:
    void fill(){
        // fill in the matrix of letter corresponding to the telephone's keyboard
        if (!to_letter[0].empty()) return;
        char letter;
        int end;
        int start = 0;
        for (int i=0; i<8 ;i++){
            if (i==5 || i==7) end = 4; 
            else end = 3;
            for (int j = 3*i+start; j<3*i+end+start; j++){
                letter = 'a'+j;
                to_letter[i].push_back(letter);
            }
            if (i==5) start++;
            cout << endl;
        }
    }

    vector<string> letterCombinations(string digits) {
        fill();

        vector<string> now; 

        if (digits=="") return now;

        now.push_back("");
        int n; string q;
        for (auto p : digits){
            n = (int) now.size();
            while (n--){
                q = now[0];
                for (auto r : to_letter[p-'0'-2]){
                    now.push_back(q+r);
                }
                now.erase(now.begin());
            }
            
        }
        
        return now;
    }
};