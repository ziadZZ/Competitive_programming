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
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;

        for (int i = 1 ; i<n-1 ; i++){
            nums[i] = max(nums[i]+i, nums[i-1]); // nums[i] becomes the farest point that can be reached starting from 0 and jumping over the first i'th position.
        }

        // Each time we jump to the farest point
        int i = 0;
        while (i < n-1){
            ++jumps;
            i = nums[i];
        }


        return jumps;
    }
};