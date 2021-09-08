#include "../includes/SerDeser.hpp"

void    serialize(const node &root, std::ofstream &f_out)
{
    size_t   type_size;
    char     *value;
    size_t   branch_count;

    type_size = root.value->getTypeSize();               //    type of Holder's value
    value = root.value->getValueBytes();                 //    Holder's value
    f_out.write((char*)&type_size, sizeof(size_t));      //    keeping value type size
    f_out.write(value, type_size);                       //    keeping value
    delete value;
    branch_count = root.branches.size();
    f_out.write((char*)&branch_count, sizeof(size_t));   //    keeping the number of branches
    for (size_t i = 0; i < branch_count; i++)            //    iterating over branches
        serialize(*root.branches[i], f_out);             //    recursive saving of the next node
}

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

int    main()
{
    std::string     file_name("serialized_data.txt");
    node            root;                                //    the root of the pointer tree for serialize
    node            new_root;                            //    the new root of the pointer tree for deserialize
    std::ofstream   f_out;                               //    output stream
    std::ifstream   f_in;                                //    input stream

    f_out.open(file_name);
    if (!f_out.is_open())
        error("File not open");
    root = make_tree();
    serialize(root, f_out);
    f_out.close();
    print_tree(root);
    delete_tree(root);
    std::cout << "\n<+===============+>\n" << std::endl;
    f_in.open(file_name);
    if (!f_in.is_open())
        error("File not open");
    try
    {
        deserialize(new_root, f_in);
    }
    catch(const std::string &err_str)
    {
        f_in.close();
        delete_tree(new_root);
        error(err_str);
    }
    f_in.close();
    print_tree(new_root);
    delete_tree(new_root);
    return 0;
}
