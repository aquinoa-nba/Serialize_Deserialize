#include "../includes/SerDeser.hpp"

void    serialize(const node &root, std::ofstream &f_out)
{
    size_t    type_size = root.value->getTypeSize();        //    type of Holder's value
    char    *value = root.value->getValueBytes();           //    Holder's value

    f_out.write((char*)&type_size, sizeof(size_t));         //    keeping value type size
    f_out.write(value, type_size);                          //    keeping value
    delete value;
    type_size = root.nodesPtr.size();
    f_out.write((char*)&type_size, sizeof(size_t));         //    keeping the number of branches
    for (size_t i = 0; i < root.nodesPtr.size(); i++)       //    iterating over branches
        serialize(*root.nodesPtr[i], f_out);                //    recursive saving of the next node
}

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

int    main()
{
    std::string        file_name("serialized_data.txt");
    node            root = make_tree();
    std::ofstream    f_out(file_name);

    if (!f_out.is_open())
    {
        std::cerr << "file not open!" << std::endl;
        return errno;
    }
    serialize(root, f_out);
    f_out.close();
    print_delete_tree(root);
    std::cout << "\n<+===============+>\n" << std::endl;
    std::ifstream    f_in(file_name);
    if (!f_in.is_open())
    {
        std::cerr << "file not open!" << std::endl;
        return errno;
    }
    node new_root;
    deserialize(new_root, f_in);
    f_in.close();
    print_delete_tree(new_root);
    return 0;
}
