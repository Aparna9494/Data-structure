#include <stdio.h>
#include <stdlib.h>

// Definition of a Node in the Binary Search Tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a new node into the BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Function to search for a value in the BST
struct Node* search(struct Node* root, int data) {
    // Base case: root is null or data is present at the root
    if (root == NULL || root->data == data) {
        return root;
    }


    if (data < root->data) {
        return search(root->left, data);
    }

    return search(root->right, data);
}

// In-order Traversal of the BST (Left, Root, Right)
void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Pre-order Traversal of the BST (Root, Left, Right)
void preorderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
    }
}

// Post-order Traversal of the BST (Left, Right, Root)
void postorderTraversal(struct Node* root) {
    if (root != NULL) {
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Driver function to test the Binary Search Tree
int main() {
    struct Node* root = NULL;
    int num, value;
    
    // Ask the user for the number of nodes they want to insert
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &num);

    // Inserting values into the BST
    for (int i = 0; i < num; i++) {
        printf("Enter value %d: ", i + 1);
        scanf("%d", &value);
        root = insert(root, value);
    }
    
    // In-order traversal of the BST
    printf("\nIn-order traversal: ");
    inorderTraversal(root);
    printf("\n");
    
    // Pre-order traversal of the BST
    printf("Pre-order traversal: ");
    preorderTraversal(root);
    printf("\n");

    // Post-order traversal of the BST
    printf("Post-order traversal: ");
    postorderTraversal(root);
    printf("\n");
    
    // Ask the user for a value to search in the BST
    printf("Enter a value to search in the BST: ");
    scanf("%d", &value);
    
    // Searching for a value in the BST
    struct Node* result = search(root, value);
    if (result != NULL) {
        printf("Element %d found in the BST.\n", value);
    } else {
        printf("Element %d not found in the BST.\n", value);
    }
    
    return 0;
}

