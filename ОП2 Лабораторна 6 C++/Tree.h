#pragma once
#include "Header.h"

class Tree
{
private:
    Branch* root = 0;
    int tabs = 0;
    double max = -101;
    double min = 101;
    double* ptrmax = 0;
    double* ptrmin = 0;

    void print(Branch*& branch);
    void add_elem(Branch*& branch, double value);
    void swap(Branch*& branch);
    void min_elem(Branch*& branch);
    void max_elem(Branch*& branch);

public:
    void print_tree();
    void create_tree(int amount);
    void add_element(double value);

    void find_min();
    void find_max();
    void swap_min_max();

    double get_max_element();
    double get_min_element();
};