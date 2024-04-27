#include <iostream>
#include <string>
#include <queue>
#include <map>

using namespace std;

template <typename T>
class BinarySearchTree;

template <typename T>
class Node
{
private:
    T data;
    Node<T>* left;
    Node<T>* right;

    /**
       Inserts a new node as a descendant of a given node.
       @param parent the root node
       @param new_node the node to insert
    */
   public:

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
       Tries to remove an element from the tree. Does nothing
       if the element is not contained in the tree.
       @param element the element to remove
    */
    void erase(T element);

    /**
       Prints the contents of the tree in sorted order.
    */
    void print() const;

   private:
    /**
       Prints the contents of the tree in sorted order.
    */
    void print_node(Node<T>* node) const;

    void print_level_order(Node<T>* node) const;

   // BinarySearchTree add_node
    void add_node(Node<T>* new_node) ;

    void add_node(Node<T>*& parent, Node<T>* new_node) ;

    Node<T>* root;

};

//  IMPLEMENTATION OF THE CLASSES

template <typename T>
void BinarySearchTree<T>::add_node(Node<T>* new_node)
{
    add_node(root, new_node);
}

template <typename T>
void BinarySearchTree<T>::add_node(Node<T>*& parent, Node<T>* new_node) {
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
void BinarySearchTree<T>::print_node(Node<T>* node) const
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
class IndexedNode
{
    public:
    int index;
    Node<T>* node;
};

template <typename T>
void BinarySearchTree<T>::print_level_order(Node<T>* node) const
{
    if (node == nullptr) {
        return;
    }

    int max_index = 0;
    queue<IndexedNode<T>*> q;
    map<int, IndexedNode<T>*> index_map;
    IndexedNode<T>* root_node = new IndexedNode<T>;
    root_node->index = max_index;
    root_node->node = node;
    q.push(root_node);
    index_map.insert_or_assign(root_node->index, root_node);

    while (!q.empty()) {
        IndexedNode<T>* current = q.front();
        q.pop();

        //cout << current->data << " ";
        if (current->node->left != nullptr) {
            IndexedNode<T>* lNode = new IndexedNode<T>;
            lNode->index = 2*current->index+1;
            max_index = lNode->index;
            lNode->node = current->node->left;
            q.push(lNode);
            index_map.insert_or_assign(lNode->index, lNode);
        }
        if (current->node->right != nullptr) {
            IndexedNode<T>* lNode = new IndexedNode<T>;
            lNode->index = 2*current->index+2;
            max_index = lNode->index;
            lNode->node = current->node->right;
            q.push(lNode);
            index_map.insert_or_assign(lNode->index, lNode);
        }
    }

    int level = 0;
    int index = 0;
    while (index <= max_index) {
        if (index >= pow(2, level)){
            level++;
            cout << endl;
        }
        if (index_map[index] == nullptr) {
            cout << "null ";
        } else {
            cout << index_map[index]->node->data << " ";
        }

        index++;
    }
    cout << endl;
}



template <typename T>
void BinarySearchTree<T>::print() const
{
   print_level_order(root);
}

template <typename T>
BinarySearchTree<T>::BinarySearchTree()
{
    root = nullptr;
}

template <typename T>
void BinarySearchTree<T>::insert(T element)
{
    Node<T>* new_node = new Node<T>;
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
    Node<T>* current = root;
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
void BinarySearchTree<T>::erase(T element)
{
    // Find node to be removed

    Node<T>* to_be_removed = root;
    Node<T>* parent = nullptr;
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
        Node<T>* new_child;
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

    Node<T>* smallest_parent = to_be_removed;
    Node<T>* smallest = to_be_removed->right;
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
