#pragma once
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

struct Branch
{
    double data;
    Branch* left;
    Branch* right;
};

class Tree
{
private:
    Branch* root = 0;
    int tabs = 0;
    double max = -101;
    double min = 101;
    double* ptrmax = 0;
    double* ptrmin = 0;

    void print(Branch*& branch)
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
    void add_elem(Branch*& branch, double value)
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
    void swap(Branch*& branch)
    {
        *ptrmax = min;
        *ptrmin = max;
    }
    void min_elem(Branch*& branch)
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
        min_elem(branch->right);
    }
    void max_elem(Branch*& branch)
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
        max_elem(branch->left);
        max_elem(branch->right);
    }

public:
    void print_tree()
    {
        print(root);
    }
    void create_tree(int amount)
    {
        vector<double>vec(amount);
        for (int i = 0; i < amount; i++)
        {
            vec[i] = (double)(rand()) / RAND_MAX * 200 - 100;
            vec[i] = round(vec[i] * 100) / 100;
            add_elem(root, vec[i]);
        }
    }
    void add_element(double value)
    {
        add_elem(root, value);
    }

    void find_min()
    {
        min_elem(root);
    }
    void find_max()
    {
        max_elem(root);
    }
    void swap_min_max()
    {
        swap(root);
    }

    double get_max_element()
    {
        return max;
    }
    double get_min_element()
    {
        return min;
    }
};