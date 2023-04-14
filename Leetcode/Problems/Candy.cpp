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

//Hard one 

class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        int ans = n;
        int precedent = 1;
        int incr = 0 ;
        int decr = 0;
        for (int i=0; i<n-1 ; i++){
            if (a[i+1]>a[i]) {
                // set the pick and valley
                /*
                      /\
                        \ 
                         \/

                */
                if (i && a[i-1] > a[i])  {ans+= decr ; ans -= min(incr,decr); incr=0; decr=0; }
                
                /* else
                        /
                       /
                      /   
                */
                ans += incr;
                incr++;

                // if we reach the end incrisingly
                if (i+1==n-1) ans+=incr;
            }
            else if (a[i+1]==a[i]) {
                // set the pick
                /*
                      /\
                        \ 
                         \__

                */
                if (i && a[i-1] > a[i]) {ans+= decr ; ans -= min(incr,decr); }

                // when it's this case
                /*    __
                     / 
                    /
                */
                if (decr == 0) ans+= incr;

                incr=0; decr = 0; 
                
            }
            else {
                /*
                         / \
                        /   \
                       /

                */

                if (decr == 0) ans+= incr; // first time to decrease, after being increasing
                ans += decr;
                decr++;
            }
            
        }
        // set the pick and valley
                /*
                      /\
                        \ 
                         \ <-- end of the array

                */

        if ((n-1) && a[n-2] >= a[n-1]) {ans+= decr ; ans -= min(incr,decr); }

        
        return ans;
    }
};

