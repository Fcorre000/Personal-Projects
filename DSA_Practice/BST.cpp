#include <iostream>
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

bool search(TreeNode* root, int target){
    if(!root){
        return false;
    }

    if(target > root -> val_){
        return search(root -> right, target);
    }else if(target < root -> val_){
        return search(root -> left, target);
    }else{
        return true;
    }
}

TreeNode* insert(TreeNode* root, int val){
    if(!root){
        return new TreeNode(val);
    }

    if(val > root -> val_){
        root -> right = insert(root -> right, val);
    }else if(val < root -> val_){
        root -> left = insert(root -> left, val);
    }else{
        return root;
    }
}

TreeNode* minValueNode(TreeNode* root){
    TreeNode* curr = root;
    while(curr && curr -> left){
        curr = curr -> left;
    }

    return curr;
}
