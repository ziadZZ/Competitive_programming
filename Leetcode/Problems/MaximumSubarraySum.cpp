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

// using dp

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int m = nums[n-1];
        int cur = nums[n-1];
        for (int i = n-2; i>= 0 ; i--){
            cur = max(nums[i], cur + nums[i]);
            m = max(m,cur);
        }
        return m;
    }
};

// using Devide and conquer O(n*log(n)) time complexity

class Solution {
public:

    int maxSubArray(vector<int>& nums) {
        return solve(nums, 0, nums.size()-1);
    }

    int solve(vector<int>& nums, int l , int r){
        if (r==l) return nums[l];

        int mid = (r-l)/2+l;
        int sum_left = solve(nums, l, mid);
        int sum_right = solve(nums, mid+1, r);
        
        int m_right = nums[mid+1];
        int cur = nums[mid+1];
        for (int i = mid+2; i <= r ; i++){
            cur += nums[i];
            m_right = max(m_right,cur);
        }

        if (m_right <= 0) return max(sum_right, sum_left);

        int m_left = nums[mid];
        cur = nums[mid];
        for (int i = mid-1 ; i>= l; i--){
            cur += nums[i];
            m_left= max(m_left,cur);
        }

        int sum_mid = m_right + m_left;

        return max(max(sum_right, sum_left), sum_mid);
    }
};