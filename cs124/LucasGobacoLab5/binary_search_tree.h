#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

template <typename T>
class BinarySearchTree;

template <typename T>
class BSTNode
{
private:
    T data;
    BSTNode<T>* left;
    BSTNode<T>* right;

    /**
       Inserts a new node as a descendant of a given node.
       @param parent the root node
       @param new_node the node to insert
    */
   public:
    T getData() const {
        return data;
    }

    BSTNode<T>* getLeft() const {
        return left;
    }

    BSTNode<T>* getRight() const {
        return right;
    }

    friend class BinarySearchTree<T>;
};

/*
   This class implements a binary search tree whose
   nodes hold strings.
*/
template <typename T>
class BinarySearchTree
{

public:

    /**
       Constructs an empty tree.
    */
    BinarySearchTree();

    /**
       Inserts a new node into the tree.
       @param element the element to insert
    */
    void insert(T element);

    /**
       Tries to find an element in the tree.
       @param element the element to find
       @return 1 if the element is contained in the tree
    */
    int count(T element) const;

    /**
     * Tries to find an element in the tree.
    */
    T find(T element) const;

    /**
       Tries to remove an element from the tree. Does nothing
       if the element is not contained in the tree.
       @param element the element to remove
    */
    void erase(T element);

    /**
       Prints the contents of the tree in sorted order.
    */
    void print() const;

    /**
     * Returns the root of the tree
     * @return the root of the tree
     */
    BSTNode<T>* getRoot() const;

   private:
    /**
       Prints the contents of the tree in sorted order.
    */
   void print_node(BSTNode<T>* node) const;

    void print_tree(BSTNode<T>* node, map<int, BSTNode<T>*> *index_map, int index, int *max_index) const;


   // BinarySearchTree add_node
    void add_node(BSTNode<T>* new_node) ;

    void add_node(BSTNode<T>*& parent, BSTNode<T>* new_node) ;

    BSTNode<T>* root;

};

//  IMPLEMENTATION OF THE CLASSES

template <typename T>
void BinarySearchTree<T>::add_node(BSTNode<T>* new_node)
{
    add_node(root, new_node);
}

template <typename T>
void BinarySearchTree<T>::add_node(BSTNode<T>*& parent, BSTNode<T>* new_node) {
    if (parent == nullptr) {
        // If the tree is empty, create a new node as the root
        parent = new_node;
    } else if (new_node->data < parent->data) {
       // If the value is less than the root, go to the left subtree
      add_node(parent->left, new_node);
    } else {
        // If the value is greater than or equal to the root, go to the right subtree
        add_node(parent->right, new_node);
    }
}

template <typename T>
void BinarySearchTree<T>::print_tree(BSTNode<T>* node, map<int, BSTNode<T>*> *index_map, int index, int *max_index) const
{
    if (node == nullptr) {
        return;
    }

    *max_index =  max(*max_index, index);

    // Traverse the left subtree
    print_tree(node->left, index_map, 2*index+1, max_index);

    // Visit the current node
    (*index_map)[index] = node; //index_map[index] = node;

    // Traverse the right subtree
    print_tree(node->right, index_map,2*index+2, max_index);
}

template <typename T>
void BinarySearchTree<T>::print_node(BSTNode<T>* node) const
{
    if (node == nullptr) {
        return;
    }

    // Traverse the left subtree
    print_node(node->left);

    // Visit the current node
    cout << node->data<< " ";

    // Traverse the right subtree
    print_node(node->right);
}

template <typename T>
void BinarySearchTree<T>::print() const
{
    int max_index = 0;
    map<int, BSTNode<T>*> index_map;

    // Creating index_map
    cout << "Creating index map:" << endl;
    print_tree(root, &index_map, 0, &max_index);

    cout << "Max index: " << max_index << endl;
    cout << "Index map size: " << index_map.size() << endl;

    // Printing the tree
    cout << "Print the tree:" << endl;
    double previous_depth = 0;
    for (int i = 0; i <= index_map.size(); i++) {

        double current_depth = floor(log2(i+1));
        if (current_depth != previous_depth) {
            cout << "\n";
            previous_depth = current_depth;
        }
        if (index_map.find(i) != index_map.end()) {
            cout << index_map[i]->data << " ";
        } else {
            cout << "null ";
        }
    }
    cout << "\n";

    cout << "In order travesal: " << endl;
    print_node(root);

    cout << "\n";


}

template <typename T>
BSTNode<T>* BinarySearchTree<T>::getRoot() const {
    return root;
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T element)
{
    BSTNode<T>* new_node = new BSTNode<T>;
    new_node->data = element;
    new_node->left = nullptr;
    new_node->right = nullptr;
    if (root == nullptr)
    {
        root = new_node;
    }
    else
    {
        add_node(new_node);
    }
}

template <typename T>
int BinarySearchTree<T>::count(T element) const
{
    BSTNode<T>* current = root;
    while (current != nullptr)
    {
        if (element < current->data)
        {
            current = current->left;
        }
        else if (element > current->data)
        {
            current = current->right;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

template <typename T>
T BinarySearchTree<T>::find(T element) const
{
    BSTNode<T>* current = root;
    while (current != nullptr)
    {
        if (element < current->data)
        {
            current = current->left;
        }
        else if (element > current->data)
        {
            current = current->right;
        }
        else
        {
            return current->data;
        }
    }
    return nullptr;
}

template <typename T>
void BinarySearchTree<T>::erase(T element)
{
    // Find node to be removed

    BSTNode<T>* to_be_removed = root;
    BSTNode<T>* parent = nullptr;
    bool found = false;
    while (!found && to_be_removed != nullptr)
    {
        if (element == to_be_removed->data)
        {
            found = true;
        }
        else
        {
            parent = to_be_removed;
            if (element < to_be_removed->data)
            {
                to_be_removed = to_be_removed->left;
            }
            else
            {
                to_be_removed = to_be_removed->right;
            }
        }
    }

    if (!found)
    {
        return;
    }

    // to_be_removed contains element

    // If one of the children is empty, use the other

    if (to_be_removed->left == nullptr || to_be_removed->right == nullptr)
    {
        BSTNode<T>* new_child;
        if (to_be_removed->left == nullptr)
        {
            new_child = to_be_removed->right;
        }
        else
        {
            new_child = to_be_removed->left;
        }

        if (parent == nullptr) // Found in root
        {
            root = new_child;
        }
        else if (parent->left == to_be_removed)
        {
            parent->left = new_child;
        }
        else
        {
            parent->right = new_child;
        }
        return;
    }

    // Neither subtree is empty

    // Find smallest element of the right subtree

    BSTNode<T>* smallest_parent = to_be_removed;
    BSTNode<T>* smallest = to_be_removed->right;
    while (smallest->left != nullptr)
    {
        smallest_parent = smallest;
        smallest = smallest->left;
    }

    // smallest contains smallest child in right subtree

    // Move contents, unlink child

    to_be_removed->data = smallest->data;
    if (smallest_parent == to_be_removed)
    {
        smallest_parent->right = smallest->right;
    }
    else
    {
        smallest_parent->left = smallest->right;
    }
}
