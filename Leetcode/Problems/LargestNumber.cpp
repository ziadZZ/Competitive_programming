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
unordered_map<int,int> expo;

bool compare(int& a, int& b){
    return ((long long ) (expo[b])*a+b > (long long) (expo[a])*b+a);
}   
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        expo.clear();
        int zeros = 0;
        int n = nums.size();
        for (auto a : nums){
            zeros += (a==0);
            auto it = expo.find(a);
            if (it != expo.end()) continue;
            int i = 1;
            while(a/i){
                i *= 10;
            }
            expo[a]= i;
            cout << a << " " << expo[a] << endl;
        }
        
        for (int i = 0; i<n ; i++){
            
            int idx = i;
            for (int j = i; j<n ; j++){
                if ((long long) (expo[nums[j]])*nums[idx]+nums[j] < (long long) (expo[nums[idx]])*nums[j]+nums[idx])
                idx = j;
            }
            swap(nums[idx],nums[i]);
        }
        //sort(nums.begin(), nums.end(), compare);
        string s;
        if (zeros == nums.size()) return "0";

        for (int j=0; j<nums.size() ; j++)
            if (nums[j])
            s += to_string(nums[j]);
        s += string(zeros,'0');

        return s;
    }
};