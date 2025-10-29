#include <iostream>
#include <queue>
#include <cmath>
#include <iomanip>
using namespace std;


class clsTreeNode {
private:
    int _data;
    clsTreeNode* _left;
    clsTreeNode* _right;

public:

   //setters and getters
    int data() { return _data; }
    clsTreeNode* left() { return _left; }
    clsTreeNode* right() { return _right; }

    void setLeft(clsTreeNode* left) { _left = left; }
    void setRight(clsTreeNode* right) { _right = right; }

    clsTreeNode(int data) {
        _data = data;
        _left = _right = nullptr;
    }

    clsTreeNode(int data, clsTreeNode* left, clsTreeNode* right) {
        _data = data;
        _left = left;
        _right = right;
    }
};

class clsBinaryTree {
private:
    clsTreeNode* root;
    

    void deleteTree(clsTreeNode* node) {
        //base case
        if (node == nullptr) return;

        deleteTree(node->left());
        deleteTree(node->right());
        delete node;
    }

    int internalHeight(clsTreeNode* node){
        //base case
        if(node == nullptr) return 0;
        //recursive case
        return 1 + max(internalHeight(node->left()), internalHeight(node->right()));
    }

    void internalPreOrder(clsTreeNode* node){
        //base case
        if(node == nullptr) return;

        cout << node->data() << ", ";
        internalPreOrder(node->left());
        internalPreOrder(node->right());
    }

    void internalInOrder(clsTreeNode* node){
        //base case
        if(node == nullptr) return;

        internalInOrder(node->left());
        cout << node->data() << ", ";
        internalInOrder(node->right());
    }

    void internalPostOrder(clsTreeNode* node){
         //base case
        if(node == nullptr) return;

        internalPostOrder(node->left());
        internalPostOrder(node->right());
        cout << node->data() << ", ";
    }

    clsTreeNode* internalFind(clsTreeNode* node, int data){
        //base case
        if(node == nullptr) return nullptr;

        //recursive case 
        //using the pretraversal method

        
        if(node->data() == data){
            return node;
        }
        //search in left sub tree
        clsTreeNode* leftResult = internalFind(node->left(), data);
        if(leftResult != nullptr){
            return leftResult;
        }

         //search in right sub tree
        return internalFind(node->right(), data);
    }

public:
    clsBinaryTree() {
        root = nullptr;
    }

    void insert(int data) {
        //create the new node
        clsTreeNode* newNode = new clsTreeNode(data);
        //if the inserted node is the first node
        if (root == nullptr) {
            root = newNode;
            return;
        }

        queue<clsTreeNode*> q;
        q.push(root);
        clsTreeNode* currentNode;

        while (!q.empty()) {
            currentNode = q.front();
            q.pop();
            if (currentNode->left() == nullptr) {
                currentNode->setLeft(newNode);
                return;
            }
            else {
                q.push(currentNode->left());
            }

            if (currentNode->right() == nullptr) {
                currentNode->setRight(newNode);
                return;
            }
            else {
                q.push(currentNode->right());
            }
        }

    }

    // Recursive helper to print the tree structure
    void printTree(clsTreeNode* node, int space = 0, int height = 5) {
        if (node == nullptr)
            return;

        // Increase distance between levels
        space += height;

        // Print right child first
        printTree(node->right(), space);

        // Print current node after spaces
        cout << endl;
        for (int i = height; i < space; i++)
            cout << " ";
        cout << node->data() << "\n";

        // Print left child
        printTree(node->left(), space);
    }

    void drawBinaryTree() {
        //the root in the left and continue drawing to the right direction
        printTree(root);
    }

    void display() {
        if (root == nullptr) {
            return;
        }

        queue<clsTreeNode*> q;
        q.push(root);
        clsTreeNode* currentNode;

        while (!q.empty()) {
            int levelSize = q.size();

            while (levelSize--) {
                currentNode = q.front();
                q.pop();
                cout << currentNode->data() << "  ";
                if (currentNode->left() != nullptr) {
                    q.push(currentNode->left());
                }
                if (currentNode->right() != nullptr) {
                    q.push(currentNode->right());
                }
            }

            cout << endl;
        }
    }

    int treeHeight() {
        return internalHeight(root);
    }

    void preOrder(){// node -> left -> right
        internalPreOrder(root);
        cout << endl;
    }
    
    void inOrder(){// left -> node -> right
        internalInOrder(root);
        cout << endl;
    }
    
    void postOrder(){// left -> right -> node
        internalPostOrder(root);
        cout << endl;
    }

    clsTreeNode* find(int data){//use any traversal method
        return internalFind(root, data);
    }

    void deleteNode(int data){
        //find the node of data and it's parent
        //find the most right node and it's parent
        //replace the deleted node with the most right node
            // parentOfDeletedNode = mostRightNode
            // mostRightNode.left = deletedNode.left 
            // mostRightNode.right = deletedNode.right 
            // delete the node of data
            // parentOfMostRight = null

    }

    ~clsBinaryTree() {
        deleteTree(root);
    }
};


int main() {
    clsBinaryTree T1;
    T1.insert(1);
    T1.insert(2);
    T1.insert(3);
    T1.insert(4);
    T1.insert(5);
    T1.insert(6);
    T1.insert(7);
    T1.insert(8);
    T1.insert(9);


    clsTreeNode* node = T1.find(9);
    cout << node->data() << endl;

    return 0;
}
