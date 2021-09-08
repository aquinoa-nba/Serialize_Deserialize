#include "../includes/CharArrayHolder.hpp"

CharArrayHolder::CharArrayHolder() { bzero(_value, 10); }

CharArrayHolder::CharArrayHolder(const char *val)
{
    for (size_t i = 0; i < 10; i++)
        _value[i] = val[i];
}

CharArrayHolder::CharArrayHolder(const CharArrayHolder &other) { *this = other; }

CharArrayHolder::~CharArrayHolder() {}

size_t    CharArrayHolder::getTypeSize() { return sizeof(_value); };

char*    CharArrayHolder::getValueBytes()
{
    char*    bytes = new char[10];
    memcpy(bytes, _value, sizeof(_value));
    return bytes;
}

void    CharArrayHolder::printVal() { std::cout << _value << std::endl; }

CharArrayHolder&    CharArrayHolder::operator = (const CharArrayHolder &other)
{
    if (this != &other)
    {
        bzero(_value, 10);
        for (size_t i = 0; i < 10; i++)
            this->_value[i] = other._value[i];
    }
    return *this;
}
