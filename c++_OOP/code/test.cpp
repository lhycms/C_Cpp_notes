#include <iostream>


class HasPtr {

public:
    // Constructor Function
    HasPtr( const std::string &s = std::string() ) :
        ps( new std::string(s) ),
        i(0) 
        {   }
    
    // Copy Constructor Function
    HasPtr( const HasPtr &has_ptr ) :
        *ps( *has_ptr.ps ),
        i(has_ptr.i)
        {   }

private:
    // Data member 
    std::string *ps;
    int i;

}