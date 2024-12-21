#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        left = right = NULL;
        this->data = data;
    }
};

class BST
{
private:
    Node *root;

public:
    BST()
    {
        root = NULL;
    }
    void Add(int data)
    {
        root = InsertRec(root, data);
    }

    void Preorder()
    {
        xPreorder(root);
    }

    void Inorder()
    {
        xInorder(root);
    }

    void Postorder()
    {
        xPostorder(root);
    }

    void Delete(int data)
    {
        if (root == NULL)
        {
            cout << "Tree is empty.\n";
            return;
        }
        if (root->data == data)
        {
            cout << "Cannot delete the root node.\n";
            return;
        }
        root = DeleteNode(root, data);
    }

    int FindMin()
    {
        if (root == NULL)
        {
            cout << "Tree is empty.\n";
            return -1;
        }
        Node *minNode = FindMinNode(root);
        return minNode->data;
    }

    int FindMax()
    {
        if (root == NULL)
        {
            cout << "Tree is empty.\n";
            return -1;
        }
        Node *maxNode = FindMaxNode(root);
        return maxNode->data;
    }

private:
    Node *InsertRec(Node *r, int data)
    {
        if (r == NULL)
        {
            Node *newNode = new Node(data);
            r = newNode;
        }
        else if (data < r->data)
        {
            r->left = InsertRec(r->left, data);
        }
        else
        {
            r->right = InsertRec(r->right, data);
        }

        return r;
    }

    Node *DeleteNode(Node *r, int data)
    {
        if (r == NULL)
            return r;

        if (data < r->data)
            r->left = DeleteNode(r->left, data);
        else if (data > r->data)
            r->right = DeleteNode(r->right, data);
        else
        {
            // Node with one child or no child
            if (r->left == NULL)
            {
                Node *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                Node *temp = r->left;
                delete r;
                return temp;
            }

            // Node with two children: Get the inorder successor
            Node *temp = FindMinNode(r->right);
            r->data = temp->data;
            r->right = DeleteNode(r->right, temp->data);
        }
        return r;
    }

    Node *FindMinNode(Node *r)
    {
        while (r->left != NULL)
            r = r->left;
        return r;
    }

    Node *FindMaxNode(Node *r)
    {
        while (r->right != NULL)
            r = r->right;
        return r;
    }

    void xPreorder(Node *r) // root->left-> right
    {
        if (r == NULL)
            return;
        cout << r->data << "\t";

        xPreorder(r->left);
        xPreorder(r->right);
    }

    void xInorder(Node *r) // left->root->right
    {
        if (r == NULL)
            return;

        xInorder(r->left);
        cout << r->data << "\t";
        xInorder(r->right);
    }

    void xPostorder(Node *r) // left->right->root
    {
        if (r == NULL)
            return;

        xPostorder(r->left);
        xPostorder(r->right);
        cout << r->data << "\t";
    }
};

int main()
{
    BST bs;
    bs.Add(45);
    bs.Add(15);
    bs.Add(79);
    bs.Add(90);
    bs.Add(10);
    bs.Add(55);
    bs.Add(12);
    bs.Add(20);
    bs.Add(50);

    cout << "Display the Tree Content \n";
    bs.Preorder();
    cout << "\n ----------- \n";
    bs.Inorder();
    cout << "\n ----------- \n";
    bs.Postorder();

    cout << "\nMinimum value in BST: " << bs.FindMin() << endl;
    cout << "Maximum value in BST: " << bs.FindMax() << endl;

    cout << "\nTry to delete node with value 15:\n";
    bs.Delete(15);
    cout << "\nTry to delete node with value root 45:\n";
    bs.Delete(45);
    cout << "Inorder traversal after delete element 15:\n";
    bs.Inorder();
    return 0;
}
