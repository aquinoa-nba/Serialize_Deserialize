#include "../includes/SerDeser.hpp"

node    make_tree()
{
    node    root(1);

    root.branches.push_back(new node(2011));
    root.branches.push_back(new node("C++"));
    root.branches.push_back(new node(3.14));
    root.branches[0]->branches.push_back(new node("FULCRUM"));
    root.branches[0]->branches[0]->branches.push_back(new node("LINUX"));
    root.branches[0]->branches[0]->branches.push_back(new node(7));
    root.branches[2]->branches.push_back(new node("TEST"));
    root.branches[2]->branches.push_back(new node(9));
    root.branches[2]->branches.push_back(new node(6));
    return root;
}

void    print_tree(const node &root)
{
    root.value->printVal();
    for (size_t i = 0; i < root.branches.size(); i++)    //    iterating over branches
        print_tree(*root.branches[i]);                   //    recursive fall to the next node
}
void    delete_tree(const node &root)
{
    for (size_t i = 0; i < root.branches.size(); i++)    //    iterating over branches
    {
        delete_tree(*root.branches[i]);                  //    recursive fall to the next node
        delete root.branches[i];                         //    free node ptr
    }
    delete root.value;                                   // free Holder ptr
}

void    error(const std::string &err_str)
{
    std::cerr << err_str << ": [ " << strerror(errno) << " ]" << std::endl;
    exit(errno);
}
