#if !defined(_MSC_VER) || _MSC_VER>=1900 // VS before 2015 isn't supported
#ifdef _MSC_VER
#pragma warning(disable : 4494) // Ignoring __declspec(allocator) because the function return type is not a pointer or reference
#endif
#ifdef NDEBUG
#undef NDEBUG
#endif
#define BOOST_SP_USE_STD_ATOMIC
#if defined(_MSC_VER) && !defined(BOOST_NO_EXCEPTIONS)
#define __EXCEPTIONS
#endif
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <string>
#include <iterator>
#include <type_traits>
#include <cassert>
#if _HAS_CXX17
#define TEST_STD_VER 17
#else
#define TEST_STD_VER 11
#endif
#include "rbx_test.h"
#include "test_macros.h"
#include "min_allocator.h"
#include "test_allocator.h"
#include "test_iterators.h"


BOOST_AUTO_TEST_SUITE(StringTest)

#define STRING_TEST types
#include "string_test.h"

#define STRING_TEST access, at
#include "string_test.h"
#define STRING_TEST access, back
#include "string_test.h"
#define STRING_TEST access, front
#include "string_test.h"
#define STRING_TEST access, index
#include "string_test.h"


#define STRING_TEST capacity, capacity
#include "string_test.h"
#define STRING_TEST capacity, clear
#include "string_test.h"
#define STRING_TEST capacity, empty
#include "string_test.h"
#define STRING_TEST capacity, length
#include "string_test.h"
#define STRING_TEST capacity, max_size
#include "string_test.h"
#define STRING_TEST capacity, over_max_size
#include "string_test.h"
#define STRING_TEST capacity, reserve
#include "string_test.h"
#define STRING_TEST capacity, resize_size
#include "string_test.h"
#define STRING_TEST capacity, resize_size_char
#include "string_test.h"
#define STRING_TEST capacity, shrink_to_fit
#include "string_test.h"
#define STRING_TEST capacity, size
#include "string_test.h"

#define STRING_TEST cons, alloc
#include "string_test.h"
#define STRING_TEST cons, brace_assignment
#include "string_test.h"
#define STRING_TEST cons, char_assignment
#include "string_test.h"
#define STRING_TEST cons, copy
#include "string_test.h"
#define STRING_TEST cons, copy_alloc
#include "string_test.h"
#define STRING_TEST cons, copy_assignment
#include "string_test.h"
#define STRING_TEST cons, default_noexcept
#include "string_test.h"
#define STRING_TEST cons, dtor_noexcept
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST cons, implicit_deduction_guides
#include "string_test.h"
#endif
#define STRING_TEST cons, initializer_list
#include "string_test.h"
#define STRING_TEST cons, initializer_list_assignment
#include "string_test.h"
#define STRING_TEST cons, iter_alloc
#include "string_test.h"
#define STRING_TEST cons, move
#include "string_test.h"
#define STRING_TEST cons, move_alloc
#include "string_test.h"
#define STRING_TEST cons, move_assignment
#include "string_test.h"
// #define STRING_TEST cons, move_assign_noexcept
// #include "string_test.h"
// #define STRING_TEST cons, move_noexcept
// #include "string_test.h"
#define STRING_TEST cons, pointer_alloc
#include "string_test.h"
#define STRING_TEST cons, pointer_assignment
#include "string_test.h"
#define STRING_TEST cons, pointer_size_alloc
#include "string_test.h"
#define STRING_TEST cons, size_char_alloc
#include "string_test.h"

#if TEST_STD_VER == 17
#define STRING_TEST cons, string_view
#include "string_test.h"
#endif

// #define STRING_TEST cons, substr
// #include "string_test.h"
// #define STRING_TEST cons, T_size_size
// #include "string_test.h"


#define STRING_TEST iterators, begin
#include "string_test.h"
#define STRING_TEST iterators, cbegin
#include "string_test.h"
#define STRING_TEST iterators, cend
#include "string_test.h"
#define STRING_TEST iterators, crbegin
#include "string_test.h"
#define STRING_TEST iterators, crend
#include "string_test.h"
#define STRING_TEST iterators, end
#include "string_test.h"
#define STRING_TEST iterators, iterators
#include "string_test.h"
#define STRING_TEST iterators, rbegin
#include "string_test.h"
#define STRING_TEST iterators, rend
#include "string_test.h"

//#if 0
#define STRING_TEST modifiers, append, initializer_list
#include "string_test.h"
#define STRING_TEST modifiers, append, iterator
#include "string_test.h"
#define STRING_TEST modifiers, append, pointer
#include "string_test.h"
#define STRING_TEST modifiers, append, pointer_size
#include "string_test.h"
#define STRING_TEST modifiers, append, push_back
#include "string_test.h"
#define STRING_TEST modifiers, append, size_char
#include "string_test.h"
#define STRING_TEST modifiers, append, string
#include "string_test.h"
#define STRING_TEST modifiers, append, string_size_size
#include "string_test.h"

#if TEST_STD_VER == 17
#define STRING_TEST modifiers, append, string_view
#include "string_test.h"
#define STRING_TEST modifiers, append, T_size_size
#include "string_test.h"
#endif

#define STRING_TEST modifiers, assign, initializer_list
#include "string_test.h"
#define STRING_TEST modifiers, assign, iterator
#include "string_test.h"
#define STRING_TEST modifiers, assign, pointer
#include "string_test.h"
#define STRING_TEST modifiers, assign, pointer_size
#include "string_test.h"
#define STRING_TEST modifiers, assign, rv_string
#include "string_test.h"
#define STRING_TEST modifiers, assign, size_char
#include "string_test.h"
#define STRING_TEST modifiers, assign, string
#include "string_test.h"
#define STRING_TEST modifiers, assign, string_size_size
#include "string_test.h"

#if TEST_STD_VER == 17
#define STRING_TEST modifiers, assign, string_view
#include "string_test.h"
#define STRING_TEST modifiers, assign, T_size_size
#include "string_test.h"
#endif

#define STRING_TEST modifiers, copy, copy
#include "string_test.h"

#define STRING_TEST modifiers, erase, iter
#include "string_test.h"
#define STRING_TEST modifiers, erase, iter_iter
#include "string_test.h"
#define STRING_TEST modifiers, erase, pop_back
#include "string_test.h"
#define STRING_TEST modifiers, erase, size_size
#include "string_test.h"

#define STRING_TEST modifiers, insert, iter_char
#include "string_test.h"
#define STRING_TEST modifiers, insert, iter_initializer_list
#include "string_test.h"
#define STRING_TEST modifiers, insert, iter_iter_iter
#include "string_test.h"
#define STRING_TEST modifiers, insert, iter_size_char
#include "string_test.h"
#define STRING_TEST modifiers, insert, size_pointer
#include "string_test.h"
#define STRING_TEST modifiers, insert, size_pointer_size
#include "string_test.h"
#define STRING_TEST modifiers, insert, size_size_char
#include "string_test.h"
#define STRING_TEST modifiers, insert, size_string
#include "string_test.h"
#define STRING_TEST modifiers, insert, size_string_size_size
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST modifiers, insert, size_T_size_size
#include "string_test.h"
#endif

#define STRING_TEST modifiers, op_plus_equal, char
#include "string_test.h"
#define STRING_TEST modifiers, op_plus_equal, initializer_list
#include "string_test.h"
#define STRING_TEST modifiers, op_plus_equal, pointer
#include "string_test.h"
#define STRING_TEST modifiers, op_plus_equal, string
#include "string_test.h"


#define STRING_TEST modifiers, replace, iter_iter_initializer_list
#include "string_test.h"
#define STRING_TEST modifiers, replace, iter_iter_iter_iter
#include "string_test.h"
#define STRING_TEST modifiers, replace, iter_iter_pointer
#include "string_test.h"
#define STRING_TEST modifiers, replace, iter_iter_pointer_size
#include "string_test.h"
#define STRING_TEST modifiers, replace, iter_iter_size_char
#include "string_test.h"
#define STRING_TEST modifiers, replace, iter_iter_string
#include "string_test.h"
#define STRING_TEST modifiers, replace, size_size_pointer
#include "string_test.h"
#define STRING_TEST modifiers, replace, size_size_pointer_size
#include "string_test.h"
#define STRING_TEST modifiers, replace, size_size_size_char
#include "string_test.h"
#define STRING_TEST modifiers, replace, size_size_string
#include "string_test.h"
#define STRING_TEST modifiers, replace, size_size_string_size_size
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST modifiers, replace, size_size_T_size_size
#include "string_test.h"
#endif

#define STRING_TEST modifiers, swap, swap
#include "string_test.h"

#define STRING_TEST nonmembers, io,io,.io, get_line
#include "string_test.h"
#define STRING_TEST nonmembers, io,io,.io, get_line_delim
#include "string_test.h"
#define STRING_TEST nonmembers, io,io,.io, get_line_delim_rv
#include "string_test.h"
#define STRING_TEST nonmembers, io,io,.io, get_line_rv
#include "string_test.h"
#define STRING_TEST nonmembers, io,io,.io, stream_extract
#include "string_test.h"
#ifdef _MSC_VER
#define min_allocator std::allocator // c++11 code inside stream_insert doesn't compile with MS compiler
#endif
#define STRING_TEST nonmembers, io,io,.io, stream_insert
#include "string_test.h"
#ifdef _MSC_VER
#undef min_allocator
#endif
#define STRING_TEST nonmembers, special,special,.special, swap
#ifdef _MSC_VER // ADL bug in MS compiler
#define swap(...) std::swap(__VA_ARGS__)
#endif
#include "string_test.h"
#ifdef _MSC_VER
#undef swap
#endif
#define STRING_TEST nonmembers, special,special,.special, swap_noexcept
#include "string_test.h"

#define STRING_TEST nonmembers, op_ne,operator!=,_op!=, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_ne,operator!=,_op!=, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_ne,operator!=,_op!=, string_string
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST nonmembers, op_ne,operator!=,_op!=, string_string_view
#include "string_test.h"
#define STRING_TEST nonmembers, op_ne,operator!=,_op!=, string_view_string
#include "string_test.h"
#endif

#define STRING_TEST nonmembers, op_plus,operator+,_op+, char_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_plus,operator+,_op+, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_plus,operator+,_op+, string_char
#include "string_test.h"
#define STRING_TEST nonmembers, op_plus,operator+,_op+, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_plus,operator+,_op+, string_string
#include "string_test.h"

#define STRING_TEST nonmembers, op_eq,operator==,_operator==, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_eq,operator==,_operator==, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_eq,operator==,_operator==, string_string
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST nonmembers, op_eq,operator==,_operator==, string_string_view
#include "string_test.h"
#define STRING_TEST nonmembers, op_eq,operator==,_operator==, string_view_string
#include "string_test.h"
#endif

#define STRING_TEST nonmembers, op_gt,operator>,_opgt, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_gt,operator>,_opgt, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_gt,operator>,_opgt, string_string
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST nonmembers, op_gt,operator>,_opgt, string_string_view
#include "string_test.h"
#define STRING_TEST nonmembers, op_gt,operator>,_opgt, string_view_string
#include "string_test.h"
#endif

#define STRING_TEST nonmembers, op_gte,operator>=,_opgt=, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_gte,operator>=,_opgt=, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_gte,operator>=,_opgt=, string_string
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST nonmembers, op_gte,operator>=,_opgt=, string_string_view
#include "string_test.h"
#define STRING_TEST nonmembers, op_gte,operator>=,_opgt=, string_view_string
#include "string_test.h"
#endif

#define STRING_TEST nonmembers, op_lt,operator<,_opgt, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_lt,operator<,_opgt, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_lt,operator<,_opgt, string_string
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST nonmembers, op_lt,operator<,_opgt, string_string_view
#include "string_test.h"
#define STRING_TEST nonmembers, op_lt,operator<,_opgt, string_view_string
#include "string_test.h"
#endif

#define STRING_TEST nonmembers, op_lte,operator<=,_opgt=, pointer_string
#include "string_test.h"
#define STRING_TEST nonmembers, op_lte,operator<=,_opgt=, string_pointer
#include "string_test.h"
#define STRING_TEST nonmembers, op_lte,operator<=,_opgt=, string_string
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST nonmembers, op_lte,operator<=,_opgt=, string_string_view
#include "string_test.h"
#define STRING_TEST nonmembers, op_lte,operator<=,_opgt=, string_view_string
#include "string_test.h"
#endif

#define STRING_TEST ops, accessors,accessors,.accessors, c_str
#include "string_test.h"
#define STRING_TEST ops, accessors,accessors,.accessors, data
#include "string_test.h"
#define STRING_TEST ops, accessors,accessors,.accessors, get_allocator
#include "string_test.h"

#define STRING_TEST ops, compare, pointer
#include "string_test.h"
#define STRING_TEST ops, compare, size_size_pointer
#include "string_test.h"
#define STRING_TEST ops, compare, size_size_pointer_size
#include "string_test.h"
#define STRING_TEST ops, compare, size_size_string
#include "string_test.h"
#define STRING_TEST ops, compare, size_size_string_size_size
#include "string_test.h"
#if TEST_STD_VER == 17
#define STRING_TEST ops, compare, size_size_T_size_size
#include "string_test.h"
#endif
#define STRING_TEST ops, compare, string
#include "string_test.h"

#define STRING_TEST ops, find, char_size
#include "string_test.h"
#define STRING_TEST ops, find, pointer_size
#include "string_test.h"
#define STRING_TEST ops, find, pointer_size_size
#include "string_test.h"
#define STRING_TEST ops, find, string_size
#include "string_test.h"

#ifdef not
#undef not // undo mess created by iso646.h
#endif
#define STRING_TEST ops, find_first_not_of,find_first_not_of,_find.first.not.of, char_size
#include "string_test.h"
#define STRING_TEST ops, find_first_not_of,find_first_not_of,_find.first.not.of, pointer_size
#include "string_test.h"
#define STRING_TEST ops, find_first_not_of,find_first_not_of,_find.first.not.of, pointer_size_size
#include "string_test.h"
#define STRING_TEST ops, find_first_not_of,find_first_not_of,_find.first.not.of, string_size
#include "string_test.h"

#define STRING_TEST ops, find_first_of,find_first_of,_find.first.of, char_size
#include "string_test.h"
#define STRING_TEST ops, find_first_of,find_first_of,_find.first.of, pointer_size
#include "string_test.h"
#define STRING_TEST ops, find_first_of,find_first_of,_find.first.of, pointer_size_size
#include "string_test.h"
#define STRING_TEST ops, find_first_of,find_first_of,_find.first.of, string_size
#include "string_test.h"

#define STRING_TEST ops, find_last_not_of,find_last_not_of,_find.last.not.of, char_size
#include "string_test.h"
#define STRING_TEST ops, find_last_not_of,find_last_not_of,_find.last.not.of, pointer_size
#include "string_test.h"
#define STRING_TEST ops, find_last_not_of,find_last_not_of,_find.last.not.of, pointer_size_size
#include "string_test.h"
#define STRING_TEST ops, find_last_not_of,find_last_not_of,_find.last.not.of, string_size
#include "string_test.h"

#define STRING_TEST ops, find_last_of,find_last_of,_find.last.of, char_size
#include "string_test.h"
#define STRING_TEST ops, find_last_of,find_last_of,_find.last.of, pointer_size
#include "string_test.h"
#define STRING_TEST ops, find_last_of,find_last_of,_find.last.of, pointer_size_size
#include "string_test.h"
#define STRING_TEST ops, find_last_of,find_last_of,_find.last.of, string_size
#include "string_test.h"

#define STRING_TEST ops, rfind, char_size
#include "string_test.h"
#define STRING_TEST ops, rfind, pointer_size
#include "string_test.h"
#define STRING_TEST ops, rfind, pointer_size_size
#include "string_test.h"
#define STRING_TEST ops, rfind, string_size
#include "string_test.h"

#define STRING_TEST ops, substr, substr
#include "string_test.h"

#define STRING_TEST require, contiguous
#include "string_test.h"

BOOST_AUTO_TEST_SUITE_END()
#endif
