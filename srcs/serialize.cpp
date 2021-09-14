#include "../includes/SerDeser.hpp"

void    serialize(const node &root, std::ofstream &f_out)
{
    size_t   type_size = 0;                                  //    type of Holder's value
    char     *value;
    size_t   branch_count;

    if (dynamic_cast<IntHolder*>(root.value))
        type_size = sizeof(int);
    else if (dynamic_cast<CharArrayHolder*>(root.value))
        type_size = sizeof(char[10]);
    else if (dynamic_cast<DoubleHolder*>(root.value))
        type_size = sizeof(double);
    value = root.value->getValueBytes();                 //    Holder's value
    f_out.write((char*)&type_size, sizeof(size_t));      //    keeping value type size
    f_out.write(value, type_size);                       //    keeping value
    delete value;
    branch_count = root.branches.size();
    f_out.write((char*)&branch_count, sizeof(size_t));   //    keeping the number of branches
    for (size_t i = 0; i < branch_count; i++)            //    iterating over branches
        serialize(*root.branches[i], f_out);             //    recursive saving of the next node
}

int    main(int ac, char **av)
{
    node            root;                                //    the root of the pointer tree
    std::ofstream   f_out;                               //    output stream

    if (ac != 2)
    {
        std::cerr << "Put name of file for serialize as argument!" << std::endl;
        return 1;
    }
    f_out.open(av[1]);
    if (!f_out.is_open())
        error("File not open");
    root = make_tree();
    serialize(root, f_out);
    f_out.close();
    print_tree(root);
    delete_tree(root);
    return 0;
}
