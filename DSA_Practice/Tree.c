#include <stdio.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode, *TreeNodePT;

TreeNodePT search(TreeNodePT tree, int s_data){
    if(tree == NULL) return NULL;
    else if(s_data == tree -> data)
        return tree;
    else if(s_data < tree -> data)
        return search(tree -> left, s_data);
    else
        return search(tree -> right, s_data);
}

//Create new node, helpder function for insert
TreeNodePT new_tree_node(int data_in){
    TreeNodePT npd = malloc(sizeof(struct TreeNode));
    npd -> data = data_in;
    npd -> left = NULL;
    npd -> right = NULL;
    return npd;
}

//naive approach to insert new node in tree
TreeNodePT insert(TreeNodePT h, int n_data){
    if(h == NULL) return new_tree_node(n_data);
    else if(n_data < h -> data)
        h -> left = insert(h -> left, n_data);
    else if(n_data > h -> data)
        h -> right = insert(h -> right, n_data);
    
    return h;
}

//function recursively counts all the nodes on the left,
//then right, adds them together along with 1 for the root
int count(TreeNodePT h){
    if(h == NULL) return 0;
    int c1 = count(h -> left);
    int c2 = count(h -> right);
    return c1 + c2 + 1;
}

//Counts the number of nodes on the left side, which will equal
//the height, then does the same thing on the right,
//whichever has the most has the actual height of the tree
int height(TreeNodePT h){
    if(h == NULL) return -1;
    int height1 = height(h -> left);
    int height2 = height(h -> right);

    if(height1 > height2)
        return height1 + 1;
    else
        return height2 + 1;
}

//helper function for show function
void print_node(int val, int depth){
    int i;
    for(i = 0; i < depth; i++){
        printf(" ");   
    }
    printf("%d\n", val);
}

void show(TreeNodePT x, int depth){
    if(x == NULL){
        print_node(-1, depth);
        return;
    }
    print_node(x -> data, depth);
    show(x -> left, depth + 1);
    show(x -> right, depth + 1);
}

TreeNodePT minValueNode(TreeNodePT root){
    TreeNodePT curr = root;
    while(curr && curr -> left){
        curr = curr -> left;
    }
    return curr;
}

TreeNodePT remove(TreeNodePT root, int val){
    if(root == NULL){
        return NULL;
    }

    if(val > root -> data){
        root -> right = remove(root -> right, val);
    }else if(val < root -> data){
        root -> left = remove(root -> left, val);
    }else{
        if(!root -> left){
            return root -> right;
        }else if(!root -> right){
            return root -> left;
        }else{
            TreeNodePT minNode = minValueNode(root -> right);
            root -> data = minNode -> data;
            root -> right = remove(root -> right, minNode -> data);
        }
    }
    return root;

}

//post order traversal
void post(TreeNodePT h){
    if(h == NULL) return;
    post(h -> left);
    post(h -> right);
    printf("%d", h -> data);
}

//in order traversal
void inOrder(TreeNodePT h){
    if(h == NULL) return;
    inOrder(h -> left);
    printf("%d", h -> data);
    inOrder(h -> right);
    
}

//preOrder traveral
void Pre(TreeNodePT h){
    if(h == NULL) return;
    printf("%d", h -> data);
    Pre(h -> left);
    Pre(h -> right);
    
}

