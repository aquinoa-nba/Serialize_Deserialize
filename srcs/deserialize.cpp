#include "../includes/SerDeser.hpp"

void    deserialize(node &root, std::ifstream &f_in)
{
    char    *value;
    size_t    value_type_size;

    f_in.read((char*)&value_type_size, sizeof(size_t));                      //    find out the type of Holder's value
    value = new char(value_type_size);
    f_in.read(value, value_type_size);
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
    f_in.read((char*)&value_type_size, sizeof(size_t));                      //    find out the number of branches
    for (size_t i = 0; i < value_type_size; i++)                             //    iterating over branches
    {
        root.nodesPtr.push_back(new node());
        deserialize(*root.nodesPtr[i], f_in);                                //    recursive restoring of the next node
    }
}

int    main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Put name of file for serialize as argument!" << std::endl;
        return 1;
    }
    std::ifstream    f_in(av[1]);
    if (!f_in.is_open())
    {
        std::cerr << "file not open!" << std::endl;
        return errno;
    }
    node root;
    deserialize(root, f_in);
    f_in.close();
    print_delete_tree(root);
    return 0;
}
