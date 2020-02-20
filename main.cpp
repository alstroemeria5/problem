#include <iostream>
#include "Tree.hpp"
using namespace std;
int main()
{
    Tree<TreeNode> tree;
    tree + 50 + 40 + 20 + 45 + 10 + 25;
    cout << tree.search(40)->data << endl;
    return 0;
}


