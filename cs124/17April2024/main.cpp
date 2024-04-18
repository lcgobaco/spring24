/*******************************************************

 * Program Name: main.cpp

 * Author: Lucas Gobaco

 * Date: 17 April 2024

 * Description: This program tests a program that implements a binary tree and a function that counts the number of nodes with one child in the tree.

 *******************************************************/

#include <iostream>
#include <string>
#include "binarytree.h"

using namespace std;

int ind = 0;
void indent()
{
    for (int i = 0; i < ind; i++ )
    {
        cout <<  ' ';
    }
}

void display(const Binary_tree<string>& tree)
{
    if (!tree.empty())
    {
        indent();
        cout << tree.data() << endl;
        ind += 4;
        display(tree.left());
        display(tree.right());
        ind -= 4;
    }
}

int main()
{
    Binary_tree<string> tree (
        Binary_tree<string>("Larry",
                    Binary_tree<string>("Donald",
                                Binary_tree<string>("Bob",
                                            Binary_tree<string>(),
                                            Binary_tree<string>("Cramer")
                                           ),
                                Binary_tree<string>("Elanore")
                               ),
                    Binary_tree<string>("Stephen",
                                Binary_tree<string>(),
                                Binary_tree<string>("Ursula",
                                            Binary_tree<string>("Thomas"),
                                            Binary_tree<string>()
                                           )
                               )

                   )
    );
    display(tree);
    cout << "There are "
         <<  tree.count_nodes_with_one_child()
         << " nodes with one child in this tree." << endl;
         
    return 0;
}