#include <stdio.h>
#include <malloc.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(struct node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(struct node* root) {
    if (root != NULL) {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(struct node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int isBST(struct node* root) {
    static struct node* prev = NULL;
    if (root != NULL) {
        if (!isBST(root->left)) {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data) {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else {
        return 1;
    }
}

struct node* searchIter(struct node* root, int key) {
    while (root != NULL) {
        if (key == root->data) {
            return root;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    return NULL;
}

void insert(struct node* root, int key) {
    struct node* prev = NULL;
    while (root != NULL) {
        prev = root;
        if (key == root->data) {
            printf("Cannot insert %d, already in BST\n", key);
            return;
        }
        else if (key < root->data) {
            root = root->left;
        }
        else {
            root = root->right;
        }
    }
    struct node* new = createNode(key);
    if (key < prev->data) {
        prev->left = new;
    }
    else {
        prev->right = new;
    }
}

struct node* inOrderPredecessor(struct node* root) {
    root = root->left;
    while (root->right != NULL) {
        root = root->right;
    }
    return root;
}

struct node* deleteNode(struct node* root, int value) {

    struct node* iPre;
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        free(root);
        return NULL;
    }

    // searching for the node to be deleted
    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    // deletion strategy when the node is found
    else {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = deleteNode(root->left, iPre->data);
    }
    return root;
}

int main() {
    struct node* root = NULL;
    int choice, value;

    do {
        printf("\nBinary Search Tree Operations:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a key\n");
        printf("4. In-order Traversal\n");
        printf("5. Pre-order Traversal\n");
        printf("6. Post-order Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter a value to insert: ");
            scanf("%d", &value);
            if (root == NULL) {
                root = createNode(value);
            }
            else {
                insert(root, value);
            }
            printf("Node with value %d inserted.\n", value);
            break;

        case 2:
            printf("Enter a value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Node with value %d deleted.\n", value);
            break;

        case 3:
            printf("Enter a key to search: ");
            scanf("%d", &value);
            struct node* result = searchIter(root, value);
            if (result != NULL) {
                printf("Found: %d\n", result->data);
            }
            else {
                printf("Element not found\n");
            }
            break;

        case 4:
            printf("Inorder Traversal: ");
            inOrder(root);
            printf("\n");
            break;

        case 5:
            printf("Preorder Traversal: ");
            preOrder(root);
            printf("\n");
            break;

        case 6:
            printf("Postorder Traversal: ");
            postOrder(root);
            printf("\n");
            break;

        case 7:
            printf("Exiting the program.\n");
            break;

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice !=7);
}
