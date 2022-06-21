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