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
const int N = 1e5 ;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*int parent(int i){
        return (i-1)/2;
    }
    int log_2(int n){
        int i = 0;
        while(n){
            n /= 2;
            i++;
        }
        return n;
    }*/
    void sumtree(TreeNode* l , TreeNode* r){
        if (l->left != nullptr && r->right!=nullptr){
            l->left += r->right->val;
        }
        if (l->left != nullptr && r->left!=nullptr){
            l->right += r->left->val;
        }
        sum(l->left,r->right); sum(l->right,r->left);
        sum(l->left,r->left); sum(l-> right,r->left);
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        TreeNode* l = replace(root->left);
        TreeNode* r = replace(root->right);
        TreeNode* copy_l = new TreeNode(*l);
        TreeNode* copy_r = new TreeNode(*r);
        sumtree(l,copy_r);
        sumtree(r,copy_l);
        TreeNode* ans = New TreeNode(root->val,l,r);
        return ans;
    }
};