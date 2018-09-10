#include <vector>
using std::vector;
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMaximumBinaryTree(nums.cbegin(), nums.cend());
    }
private:
    using Iter = vector<int>::const_iterator;
    TreeNode* constructMaximumBinaryTree(Iter beg, Iter end) {
        if (beg == end) return nullptr;
        auto max = std::max_element(beg, end);
        TreeNode* root = new TreeNode(*max);
        auto max_pos = std::distance(beg, max);
        root->left = constructMaximumBinaryTree(beg, max);
        root->right = constructMaximumBinaryTree(std::next(max), end);
        return root;
    }
};