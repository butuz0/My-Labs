#include "Tree.h"
#include "Header.h"

int main()
{
    srand(time(NULL));
    Tree tree;
    
    int amount;
    cout << "amount of elements in a tree: ";
    cin >> amount;

    cout << "tree: "<<endl;
    tree.create_tree(amount);
    tree.print_tree();
    tree.find_max();
    tree.find_min();

    cout << endl << "max element: " << tree.get_max_element() << endl;
    cout << "min element: " << tree.get_min_element() << endl;

    cout << endl << "tree with min and max elements swapped: "<<endl;
    tree.swap_min_max();
    tree.print_tree();
}