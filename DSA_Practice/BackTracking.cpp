#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
        int val_;
        TreeNode* left = nullptr;
        TreeNode* right = nullptr;

        TreeNode(int val){
            val_ = val;
        }       
};

bool canReachLeaf(TreeNode *root) {
    if (!root || root->val_ == 0) {
        return false;
    }
    if (!root->left && !root->right) {
        return true;
    }
    if (canReachLeaf(root->left)) {
        return true;
    }
    if (canReachLeaf(root->right)) {
        return true;
    }
    return false;
}

bool leafPath(TreeNode *root, vector<int>* path){
    if(!root || root -> val_ == 0){
        return false;
    }
    path -> push_back(root -> val_);

    if(!root -> left && !root -> right){
        return true;
    }
    if(leafPath(root -> left, path)){
        return true;
    }
    if(leafPath(root -> right, path)){
        return true;
    }
    path -> pop_back();
    return false;

}

int main() {
    // Create a sample tree:
    //       1
    //      / \
    //     2   3
    //    /   / \
    //   4   0   5
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(5);

    // Test canReachLeaf function
    bool canReach = canReachLeaf(root);
    cout << "Can reach leaf: " << (canReach ? "Yes" : "No") << endl;

    // Test leafPath function
    vector<int> path;
    bool hasPath = leafPath(root, &path);
    if (hasPath) {
        cout << "Path to leaf: ";
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        cout << "No path to leaf found." << endl;
    }

    // Clean up memory
    delete root->left->left;
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}