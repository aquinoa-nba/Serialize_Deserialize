#pragma once

#include <iostream>

class BaseHolder
{
    public:
/*    CONSTRUCTOR    */
        BaseHolder() {}
/*    DESTRUCTOR    */
        virtual    ~BaseHolder() {};
/*    MEMBER FUNCTIONS    */
        virtual    char*     getValueBytes() = 0;
        virtual    void      printVal() = 0;
};
