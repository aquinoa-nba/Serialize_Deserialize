#include "../includes/DoubleHolder.hpp"

DoubleHolder::DoubleHolder() : _value(double()) {}

DoubleHolder::DoubleHolder(const double &val) : _value(val) {}

DoubleHolder::DoubleHolder(const DoubleHolder &other) { *this = other; }

DoubleHolder::~DoubleHolder() {}

char*    DoubleHolder::getValueBytes()
{
    char*    bytes = new char[sizeof(_value)];
    memcpy(bytes, &_value, sizeof(_value));
    return bytes;
}

void    DoubleHolder::printVal() { std::cout << _value << std::endl; }

DoubleHolder&    DoubleHolder::operator = (const DoubleHolder &other)
{
    if (this != &other)
        this->_value = other._value;
    return *this;
}
