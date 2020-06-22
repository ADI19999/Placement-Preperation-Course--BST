// { Driver Code Starts
#include<bits/stdc++.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct node
{
	int key;
	struct node *left;
	struct node *right;
	
	node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};

void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

struct node* insert(struct node* root, int key)
{

	if (root == NULL) return (new node(key));
	if (key < root->key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}

// Function to change a key value in Binary Search Tree
struct node *changeKey(struct node *root, int oldVal, int newVal);

// Driver Program to test above functions
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        struct node *root = NULL;
        int n, temp, oldKey, new_key;
        cin>>n;
        while(n--)
        {
            cin>>temp;
            root = insert(root, temp);
        }
        cin>>oldKey;
        cin>>new_key;
        root = changeKey(root, oldKey, new_key);
        inorder(root);
        printf("\n");
    }
	return 0;
}


// } Driver Code Ends


/*
Structure of the binary Search Tree is as
struct node
{
	int key;
	struct node *left, *right;
};
*/
// your task is to complete the Function
// Function is used to change a key value in the given BST
// Note: Function should return root node to the new modified BST
struct node *newNode(int item)  
{  
    struct node *temp = new node(item);  
    temp->key = item;  
    temp->left = temp->right = NULL;  
    return temp;  
} 
struct node* insertnew(struct node* node, int key)  
{  
    if (node == NULL) return newNode(key);  

    if (key < node->key)  
        node->left = insertnew(node->left, key);  
    else
        node->right = insertnew(node->right, key);  
  
    return node;  
}  
struct node * minValueNode(struct node* Node)  
{  
    struct node* current = Node;  
 
    while (current->left != NULL)  
        current = current->left;  
  
    return current;  
} 

struct node* deleteold(struct node* root, int key)  
{  
    if (root == NULL) return root;  

    else if (key < root->key)  
        root->left = deleteold(root->left, key);  
   
    else if (key > root->key)  
        root->right = deleteold(root->right, key);  
 
    else
    {  
        if (root->left == NULL)  
        {  
            struct node *temp = root->right;  
            free(root);  
            return temp;  
        }  
        else if (root->right == NULL)  
        {  
            struct node *temp = root->left;  
            free(root);  
            return temp;  
        }  

        struct node* temp = minValueNode(root->right);  
  
        root->key = temp->key;  

        root->right = deleteold(root->right, temp->key);  
    }  
    return root;  
}  
struct node *changeKey(struct node *root, int oldVal, int newVal)
{
    root = deleteold(root,oldVal);
    root = insertnew(root,newVal);
    return root;
	// Code here
}