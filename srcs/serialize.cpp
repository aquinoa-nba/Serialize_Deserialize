#include "../includes/SerDeser.hpp"

void	serialize(const node &root, std::ofstream &f_out)
{
	size_t	type_size = root.value->getTypeSize();		//	type of Holder's value
	char	*value = root.value->getValueBytes();		//	Holder's value

	f_out.write((char*)&type_size, sizeof(size_t));		//	keeping value type size
	f_out.write(value, type_size);						//	keeping value
	delete value;
	type_size = root.nodesPtr.size();
	f_out.write((char*)&type_size, sizeof(size_t));		//	keeping the number of branches
	for (size_t i = 0; i < root.nodesPtr.size(); i++)	//	iterating over branches
		serialize(*root.nodesPtr[i], f_out);			//	recursive saving of the next node
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Put name of file for serialize as argument!" << std::endl;
		return 1;
	}
	node			root = make_tree();
	std::ofstream	f_out(av[1]);
	if (!f_out.is_open())
	{
		std::cerr << "file not open!" << std::endl;
		return errno;
	}
	serialize(root, f_out);
	f_out.close();
	print_delete_tree(root);
	return 0;
}
