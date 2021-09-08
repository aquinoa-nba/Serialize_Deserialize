#pragma once

#include "BaseHolder.hpp"

class CharArrayHolder : public BaseHolder
{
    private:
        char    _value[10];

    public:
/*    CONSTRUCTORS    */
        CharArrayHolder();
        CharArrayHolder(const char *);
        CharArrayHolder(const CharArrayHolder &);
/*    DESTRUCTOR    */
        ~CharArrayHolder();
/*    MEMBER FUNCTIONS    */
        size_t    getTypeSize();
        char*     getValueBytes();
        void      printVal();
/*    ASSIGNATION OPERATOR OVERLOAD    */
        CharArrayHolder&    operator = (const CharArrayHolder &);
};
