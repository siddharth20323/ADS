#include <iostream>
using namespace std;

struct TreeNode {
    int key;
    TreeNode *left, *right;
    
    TreeNode(int val) {
        key = val;
        left = right = nullptr;
    }
};

class BinarySearchTree {
private:
    TreeNode* root;
    
    TreeNode* insert(TreeNode* node, int key) {
        if (node == nullptr) {
            return new TreeNode(key);
        }
        
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        }
        
        return node;
    }

    bool search(TreeNode* node, int key) {
        if (node == nullptr) {
            return false;
        }
        
        if (key == node->key) {
            return true;
        }
        
        if (key < node->key) {
            return search(node->left, key);
        } else {
            return search(node->right, key); 
        }
    }

    void inorder(TreeNode* node) {
        if (node == nullptr) {
            return;
        }
        
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

public:
    BinarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    bool search(int key) {
        return search(root, key);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    BinarySearchTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    
    cout << "Inorder traversal of the tree: ";
    tree.inorder();
    
    int key = 40;
    if (tree.search(key)) {
        cout << key << " is found in the tree." << endl;
    } else {
        cout << key << " is not found in the tree." << endl;
    }
    
    key = 25;
    if (tree.search(key)) {
        cout << key << " is found in the tree." << endl;
    } else {
        cout << key << " is not found in the tree." << endl;
    }
    
    return 0;
}