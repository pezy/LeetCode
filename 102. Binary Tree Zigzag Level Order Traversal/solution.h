#include <vector>
#include <queue>
#include <cstddef>

using std::vector;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int>> retv;
		if (!root) return retv;
		std::queue<TreeNode*> q; 
		q.push(root);
		bool reverse = false;
		vector<int> v;
		for (int cur_level_sz = 1, next_level_sz = 0; !q.empty(); ) {
			TreeNode *node = q.front(); q.pop();
			v.push_back(node->val); --cur_level_sz;
			if (node->left) { q.push(node->left); ++next_level_sz; }
			if (node->right) { q.push(node->right); ++next_level_sz; }
			if (!cur_level_sz) {
				retv.push_back(reverse ? vector<int>(v.crbegin(), v.crend()) : v); v.clear();
				cur_level_sz = next_level_sz; next_level_sz = 0;
				reverse = !reverse;
			}
		}
		return retv;
    }
};