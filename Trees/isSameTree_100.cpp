/*
ref link: https://www.gormanalysis.com/blog/making-a-binary-search-tree-in-cpp/
          https://leetcode-cn.com/problems/same-tree/solution/xiang-tong-de-shu-by-leetcode-solution/
说明：
- 深度优先
- 递归
- 时间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点数。
  对两个二叉树同时进行深度优先搜索，只有当两个二叉树中的对应节点都不为空时才会访问到该节点，
  因此被访问到的节点数不会超过较小的二叉树的节点数。
- 空间复杂度：O(min(m,n))，其中 m 和 n 分别是两个二叉树的节点数。
  空间复杂度取决于递归调用的层数，递归调用的层数不会超过较小的二叉树的最大高度，
  最坏情况下，二叉树的高度等于节点数。
*/

#include <iostream>

using namespace std;


struct TreeNode
{
    // member vars
    int data;
    TreeNode *left;
    TreeNode *right;

    // constructor
    TreeNode(int data): data(data), left(nullptr), right(nullptr) {} 
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        } else if (p == nullptr || q == nullptr) {
            return false;
        } else if (p->data != q->data) {
            return false;
        } else {
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
    }  
};

/*===== Main Function =====*/
int main()
{
    Solution solution_obj;
    TreeNode root1(1);
    TreeNode leftChild1(2);
    TreeNode rightChild1(3);
    root1.left  = &leftChild1;
    root1.right = &rightChild1;

    TreeNode root2(1);
    TreeNode leftChild2(3);
    TreeNode rightChild2(3);
    root2.left  = &leftChild2; 
    root2.right = &rightChild2;
    
    cout << solution_obj.isSameTree(&root1, &root2) << endl;
    
    return 0;
}