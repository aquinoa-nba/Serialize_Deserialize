#include "../includes/SerDeser.hpp"

void    deserialize(node &root, std::ifstream &f_in)
{
    char    *value;
    size_t  value_type_size;
    size_t  branch_count;

    if (!f_in.read((char*)&value_type_size, sizeof(size_t)))                 //    find out the type of Holder's value
        throw std::string("Read error");
    value = new char(value_type_size);
    if (!f_in.read(value, value_type_size))
        throw std::string("Read error");
    switch (value_type_size)
    {
    case sizeof(int):
        root.value = new IntHolder(*reinterpret_cast<int*>(value));          //    restoring node with IntHolder ptr
        break;
    case sizeof(char[10]):
        root.value = new CharArrayHolder(value);                             //    restoring node with CharArrayHolder ptr
        break;
    case sizeof(double):
        root.value = new DoubleHolder(*reinterpret_cast<double*>(value));    //    restoring node with DoubleHolder ptr
        break;
    }
    delete value;
    if (!f_in.read((char*)&branch_count, sizeof(size_t)))                    //    find out the number of branches
        throw std::string("Read error");
    for (size_t i = 0; i < branch_count; i++)                                //    iterating over branches
    {
        root.branches.push_back(new node());
        deserialize(*root.branches[i], f_in);                                //    recursive restoring of the next node
    }
}

int    main(int ac, char **av)
{
    node           root;                                                     //    the root of the pointer tree
    std::ifstream  f_in;                                                     //    input stream

    if (ac != 2)
    {
        std::cerr << "Put name of file for serialize as argument!" << std::endl;
        return 1;
    }
    f_in.open(av[1]);
    if (!f_in.is_open())
        error("File not open");
    try
    {
        deserialize(root, f_in);
    }
    catch(const std::string &err_str)
    {
        f_in.close();
        delete_tree(root);
        error(err_str);
    }
    f_in.close();
    print_tree(root);
    delete_tree(root);
    return 0;
}
