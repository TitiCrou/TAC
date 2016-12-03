#ifndef TOSTRING_H
#define TOSTRING_H

#endif // TOSTRING_H
#include <sstream>
#include <string>
#include <stdexcept>

namespace patch
{

    template < typename T > std::string to_string( const T& n )
    {
       std::ostringstream stm;
       stm << n;
       return stm.str();
    }
}
