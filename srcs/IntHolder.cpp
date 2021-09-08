#include "../includes/IntHolder.hpp"

IntHolder::IntHolder() : _value(int()) {}

IntHolder::IntHolder(const int &val) : _value(val) {}

IntHolder::IntHolder(const IntHolder &other) { *this = other; }

IntHolder::~IntHolder() {}

size_t	IntHolder::getTypeSize() { return sizeof(_value); }

char*	IntHolder::getValueBytes()
{
	char	*bytes = new char[sizeof(_value)];
	memcpy(bytes, &_value, sizeof(_value));
	return bytes;
}

void	IntHolder::printVal() { std::cout << _value << std::endl; }

IntHolder&	IntHolder::operator = (const IntHolder &other)
{
	if (this != &other)
		this->_value = other._value;
	return *this;
}
