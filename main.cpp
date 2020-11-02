// CPP program to Select a Random Node from a tree 
#include <bits/stdc++.h> 
using namespace std; 
  
struct Node { 
    int data; 
    int children;
    Node *left, *right, *parent; 
}; 
  
Node* newNode(int data) 
{ 
    Node *temp = new Node; 
    temp->data = data; 
    temp->left = temp->right = NULL; 
    temp->children = 0; 
    return temp; 
} 
  
// This is used to fill children counts. 
int getElements(Node* root) 
{ 
    if (!root) 
        return 0; 
    return getElements(root->left) + 
          getElements(root->right) + 1; 
} 
  
// Inserts Children count for each node 
void insertChildrenCount(Node*& root) 
{ 
    if (!root) 
        return; 
  
    root->children = getElements(root) - 1; 
    insertChildrenCount(root->left); 
    insertChildrenCount(root->right); 
} 
  
// returns number of children for root 
int children(Node* root) 
{ 
    if (!root) 
        return 0; 
    return root->children + 1; 
} 
  
// Helper Function to return a random node 
int randomNodeUtil(Node* root, int count) 
{ 
    if (!root) 
        return 0; 
  
    if (count == children(root->left)) 
        return root->data; 
  
    if (count < children(root->left)) 
        return randomNodeUtil(root->left, count); 
  
    return randomNodeUtil(root->right, 
              count - children(root->left) - 1); 
} 
  
// Returns Random node 
int randomNode(Node* root) 
{ 
    srand(time(0)); 
  
    int count = rand() % (root->children + 1); 
    return randomNodeUtil(root, count); 
} 

 //begin insert 

Node * Insert(Node * node, int data)
{
    // If BST doesn't exist
    // create a new node as root
    // or it's reached when
    // there's no any child node
    // so we can insert a new node here
    if(node == NULL)
    {
        node = new Node;
        node->Data = data;
        node->Left = NULL;
        node->Right = NULL;
        node->Parent = NULL;
    }
    // If the given key(data) is greater than
    // node's key then go to right subtree
    else if(node->Data < data)
    {
        node->Right = Insert(node->Right, data);
        node->Right->Parent = node;
    }
    // If the given key(data) is smaller than
    // node's key then go to left subtree
    else
    {
        node->Left = Insert(node->Left, data);
        node->Left->Parent = node;
    }
return node;
}

void Insert(int data)
{
    // Invoking Insert() function
    // and passing root node and given key(data)
    root = Insert(root, data);
}

int main() 
{ 
    // Creating Above Tree 
    Node* root = newNode(10); 
    root->left = newNode(20); 
    root->right = newNode(30); 
    root->left->right = newNode(40); 
    root->left->left = newNode(50); 
    root->right->left = newNode(60); 
    root->right->right = newNode(70); 
  
    insertChildrenCount(root); 
  
    cout << "A Random Node From Tree : "
         << randomNode(root) << endl; 
  
    return 0; 
} 

//https://github.com/jweir136/Group6Tree/tree/insert
