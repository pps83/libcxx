// no pragma once

#include <boost/test/unit_test.hpp>

#undef assert
#define assert(x) do{ BOOST_CHECK(x); }while(0)

#if defined(_MSC_VER) && defined(_CPPUNWIND) && !defined(__EXCEPTIONS)
#define __EXCEPTIONS
#endif
