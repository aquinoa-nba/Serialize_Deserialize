#pragma once

#include "BaseHolder.hpp"

class DoubleHolder : public BaseHolder
{
    private:
        double    _value;

    public:
/*    CONSTRUCTORS    */
        DoubleHolder();
        DoubleHolder(const double &);
        DoubleHolder(const DoubleHolder &);
/*    DESTRUCTOR    */
        ~DoubleHolder();
/*    MEMBER FUNCTIONS    */
        char*     getValueBytes();
        void      printVal();
/*    ASSIGNATION OPERATOR OVERLOAD    */
        DoubleHolder&    operator = (const DoubleHolder &other);
};
