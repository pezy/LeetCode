#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        auto n = [](ListNode *p){
            int count{0};
            for ( ; p; p=p->next, ++count);
            return count;
        }(head);
        return sortedListToBST(&head, n);
    }
    TreeNode *sortedListToBST(ListNode **head_ref, int n) {
        if (n<1) return NULL;
        TreeNode *left = sortedListToBST(head_ref, n/2);
        TreeNode *root = new TreeNode((*head_ref)->val);
        root->left = left;
        *head_ref = (*head_ref)->next;
        root->right = sortedListToBST(head_ref, n-n/2-1);
        return root;
    } 
};
