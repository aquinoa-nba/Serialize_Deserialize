#include "../includes/SerDeser.hpp"

node    make_tree()
{
    node    root(1);

    root.nodesPtr.push_back(new node(2011));
    root.nodesPtr.push_back(new node("C++"));
    root.nodesPtr.push_back(new node(3.14));
    root.nodesPtr[0]->nodesPtr.push_back(new node("FULCRUM"));
    root.nodesPtr[0]->nodesPtr[0]->nodesPtr.push_back(new node("LINUX"));
    root.nodesPtr[0]->nodesPtr[0]->nodesPtr.push_back(new node(7));
    root.nodesPtr[2]->nodesPtr.push_back(new node("TEST"));
    root.nodesPtr[2]->nodesPtr.push_back(new node(9));
    root.nodesPtr[2]->nodesPtr.push_back(new node(6));
    return root;
}

void    print_delete_tree(const node &root)
{
    root.value->printVal();
    for (size_t i = 0; i < root.nodesPtr.size(); i++)    //    iterating over branches
    {
        print_delete_tree(*root.nodesPtr[i]);            //    recursive fall to the next node
        delete root.nodesPtr[i];                         //    free node ptr
    }
    delete root.value;                                   // free Holder ptr
}
