#include <iostream>
struct TreeNode 
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int element) 
{
    if (!root) 
    {
        return new TreeNode(element);
    }
    if (element < root->data) 
    {
        root->left = insert(root->left, element);
    } 
    else if (element > root->data) 
    {
        root->right = insert(root->right, element);
    }
    return root;
}

bool search(TreeNode* root, int key) 
{
    if (!root) 
    {
        return false;
    }
    if (key == root->data) 
    {
        return true;
    } 
    else if (key < root->data) 
    {
        return search(root->left, key);
    } 
    else 
    {
        return search(root->right, key);
    }
}

TreeNode* findMin(TreeNode* root) 
{
    while (root->left) 
    {
        root = root->left;
    }
    return root;
}

TreeNode* deleteNode(TreeNode* root, int element) 
{
    if (!root) 
    {
        return root;
    }
    if (element < root->data) 
    {
        root->left = deleteNode(root->left, element);
    } 
    else if (element > root->data) 
    {
        root->right = deleteNode(root->right, element);
    } 
    else 
    {
        if (!root->left) 
        {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        } 
        else if (!root->right) 
        {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }
        TreeNode* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(TreeNode* root) 
{
    if (root) 
    {
        inorder(root->left);
        std::cout << root->data << " ";
        inorder(root->right);
    }
}

void preorder(TreeNode* root) 
{
    if (root) 
    {
        std::cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) 
{
    if (root) 
    {
        postorder(root->left);
        postorder(root->right);
        std::cout << root->data << " ";
    }
}

void displayMenu() 
{
    std::cout << "Binary Search Tree Operations:" << std::endl;
    std::cout << "1. Insert" << std::endl;
    std::cout << "2. Search" << std::endl;
    std::cout << "3. Delete" << std::endl;
    std::cout << "4. Inorder Traversal" << std::endl;
    std::cout << "5. Preorder Traversal" << std::endl;
    std::cout << "6. Postorder Traversal" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cout << "Enter your choice: ";
}

int main()
{
    TreeNode* root = nullptr;
    int choice, element, key;
    do {
        displayMenu();
        std::cin >> choice;
        switch (choice) 
        {
            case 1:
                std::cout << "Enter element to insert: ";
                std::cin >> element;
                root = insert(root, element);
                break;
            case 2:
                std::cout << "Enter key to search: ";
                std::cin >> key;
                if (search(root, key)) {
                    std::cout << key << " found in the BST." << std::endl;
                } else {
                    std::cout << key << " not found in the BST." << std::endl;
                }
                break;
            case 3:
                std::cout << "Enter element to delete: ";
                std::cin >> element;
                root = deleteNode(root, element);
                break;
            case 4:
                std::cout << "Inorder Traversal: ";
                inorder(root);
                std::cout << std::endl;
                break;
            case 5:
                std::cout << "Preorder Traversal: ";
                preorder(root);
                std::cout << std::endl;
                break;
            case 6:
                std::cout << "Postorder Traversal: ";
                postorder(root);
                std::cout << std::endl;
                break;
            case 7:
                std::cout << "Exiting program." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 7);
    while (root) 
    {
        root = deleteNode(root, root->data);
    }
    return 0;
}
