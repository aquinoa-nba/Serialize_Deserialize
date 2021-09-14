#pragma once

#include "BaseHolder.hpp"

class IntHolder : public BaseHolder
{
    private:
        int        _value;

    public:
/*    CONSTRUCTORS    */
        IntHolder();
        IntHolder(const int &);
        IntHolder(const IntHolder &);
/*    DESTRUCTOR    */
        ~IntHolder();
/*    MEMBER FUNCTIONS    */
        char*     getValueBytes();
        void      printVal();
/*    ASSIGNATION OPERATOR OVERLOAD    */
        IntHolder&    operator = (const IntHolder &other);
};
