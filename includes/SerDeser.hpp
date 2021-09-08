#pragma once

#include "IntHolder.hpp"
#include "CharArrayHolder.hpp"
#include "DoubleHolder.hpp"

#include <vector>
#include <fstream>

struct node
{
    BaseHolder            *value;
    std::vector<node*>    branches;    //    tree branches
/*    CONSTRUCTORS    */
    node() : value(nullptr) {}                                    //    default constructor
    node(const int &val) : value(new IntHolder(val)) {}           //    constructor for IntHolder's node
    node(const char *val) : value(new CharArrayHolder(val)) {}    //    constructor for CharArrayHolder's node
    node(const double &val) : value(new DoubleHolder(val)) {}     //    constructor for DoubleHolder's node
};

node    make_tree();
void    print_tree(const node &);
void    delete_tree(const node &);
void    error(const std::string &);
