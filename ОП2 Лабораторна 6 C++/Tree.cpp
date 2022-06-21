#include "Tree.h"

void Tree::print(Branch*& branch)
{
    if (!branch)
    {
        return;
    }
    tabs += 5;
    print(branch->right);
    for (int i = 0; i < tabs; i++)
    {
        cout << " ";
    }
    cout << branch->data << endl;
    print(branch->left);
    tabs -= 5;
}
void Tree::add_elem(Branch*& branch, double value)
{
    if (!branch)
    {
        branch = new Branch;
        branch->data = value;
        branch->left = 0;
        branch->right = 0;
    }
    else
    {
        if (value >= branch->data)
        {
            add_elem(branch->right, value);
        }
        else
        {
            add_elem(branch->left, value);
        }
    }
}
void Tree::swap(Branch*& branch)
{
    *ptrmax = min;
    *ptrmin = max;
}
void Tree::min_elem(Branch*& branch)
{
    if (!branch)
    {
        return;
    }
    if (branch->data < min)
    {
        min = branch->data;
        ptrmin = &(branch->data);
    }
    min_elem(branch->left);
}
void Tree::max_elem(Branch*& branch)
{
    if (!branch)
    {
        return;
    }
    if (branch->data > max)
    {
        max = branch->data;
        ptrmax = &(branch->data);
    }
    max_elem(branch->right);
}

void Tree::print_tree()
{
    print(root);
}
void Tree::create_tree(int amount)
{
    vector<double>vec(amount);
    for (int i = 0; i < amount; i++)
    {
        vec[i] = (double)(rand()) / RAND_MAX * 200 - 100;
        vec[i] = round(vec[i] * 100) / 100;
        add_elem(root, vec[i]);
    }
}
void Tree::add_element(double value)
{
    add_elem(root, value);
}
void Tree::find_min()
{
    min_elem(root);
}
void Tree::find_max()
{
    max_elem(root);
}
void Tree::swap_min_max()
{
    swap(root);
}
double Tree::get_max_element()
{
    return max;
}
double Tree::get_min_element()
{
    return min;
}