#undef BOOST_AUTO_TU_REGISTRAR
#define BOOST_AUTO_TU_REGISTRAR( test_name )    \
static boost::unit_test::ut_detail::auto_test_unit_registrar BOOST_JOIN( BOOST_JOIN( test_name, _registrar ), __COUNTER__ )

#define _ST_ARG2(...) _ST_ARG2_I((__VA_ARGS__))
#define _ST_ARG2_I(x) _ST_ARG2_II x
#define _ST_ARG2_II(a, b, ...) b

#define _ST_EXP(...) _ST_EXP_I((__VA_ARGS__))
#define _ST_EXP_I(x) _ST_EXP_II x
#define _ST_EXP_II(...) __VA_ARGS__

#define _ST_DO_COUNT(SUITE, S1ns, S1s, S1p, TEST, n, ...) n
#define _ST_COUNT(x) _ST_EXP(_ST_DO_COUNT(x, 5, 4, 3, 2, 1))

#define _ST_IS_char() , Char
#define _ST_TEST_NAME(TEST)  _ST_ARG2(BOOST_JOIN(_ST_IS_, TEST)(), TEST) // return (test == char) ? Char : test
#define _ST_BOOST_AUTO_TEST_CASE(TEST) BOOST_AUTO_TEST_CASE(TEST)
#define _ST_BOOST_AUTO_TEST_SUITE1(TEST) BOOST_AUTO_TEST_SUITE(TEST)

#define _ST_BOOST_AUTO_TEST_SUITE( suite_name, suite_name_str )             \
namespace suite_name {                                                      \
BOOST_AUTO_TU_REGISTRAR( suite_name )( BOOST_STRINGIZE( suite_name_str ) ); \

#if _ST_COUNT(STRING_TEST) == 5
#  define _ST_DO_TEST(SUITE, S1ns, S1s, S1p, TEST)    _ST_BOOST_AUTO_TEST_CASE(_ST_TEST_NAME(TEST))
#  define _ST_DO_SUITE(SUITE, S1ns, S1s, S1p, TEST)   BOOST_AUTO_TEST_SUITE(SUITE)
#  define _ST_DO_SUITE1(SUITE, S1ns, S1s, S1p, TEST)  _ST_BOOST_AUTO_TEST_SUITE(S1ns, S1s)
#  define _ST_DO_NS(SUITE, S1ns, S1s, S1p, TEST)      BOOST_JOIN(BOOST_JOIN(SUITE, TEST), _test)
#  define _ST_DO_INCLUDE(SUITE, S1ns, S1s, S1p, TEST) BOOST_STRINGIZE(strings/basic.string/string.SUITE/BOOST_JOIN(string, S1p)/TEST.pass.cpp)
#elif _ST_COUNT(STRING_TEST) == 3
#  define _ST_DO_TEST(SUITE, SUITE1, TEST)    _ST_BOOST_AUTO_TEST_CASE(_ST_TEST_NAME(TEST))
#  define _ST_DO_SUITE(SUITE, SUITE1, TEST)   BOOST_AUTO_TEST_SUITE(SUITE)
#  define _ST_DO_SUITE1(SUITE, SUITE1, TEST)  BOOST_AUTO_TEST_SUITE(SUITE1)
#  define _ST_DO_NS(SUITE, SUITE1, TEST)      BOOST_JOIN(BOOST_JOIN(SUITE, TEST), _test)
#  define _ST_DO_INCLUDE(SUITE, SUITE1, TEST) BOOST_STRINGIZE(strings/basic.string/string.SUITE/BOOST_JOIN(string_, SUITE1)/TEST.pass.cpp)
#elif _ST_COUNT(STRING_TEST) == 2
#  define _ST_DO_TEST(SUITE, TEST)    BOOST_AUTO_TEST_CASE(TEST)
#  define _ST_DO_SUITE(SUITE, TEST)   BOOST_AUTO_TEST_SUITE(SUITE)
#  define _ST_DO_NS(SUITE, TEST)      BOOST_JOIN(BOOST_JOIN(SUITE, TEST), _test)
#  define _ST_DO_INCLUDE(SUITE, TEST) BOOST_STRINGIZE(strings/basic.string/string.SUITE/TEST.pass.cpp)
#else
#  define _ST_DO_TEST(TEST)    BOOST_AUTO_TEST_CASE(TEST)
#  define _ST_DO_NS(TEST)      BOOST_JOIN(TEST, _test)
#  define _ST_DO_INCLUDE(TEST) BOOST_STRINGIZE(strings/basic.string/TEST.pass.cpp)
#endif

#define _ST_SUITE(x)   _ST_EXP(_ST_DO_SUITE(x))
#define _ST_SUITE1(x)  _ST_EXP(_ST_DO_SUITE1(x))
#define _ST_TEST(x)    _ST_EXP(_ST_DO_TEST(x))
#define _ST_NS(x)      _ST_EXP(_ST_DO_NS(x))
#define _ST_INCLUDE(x) _ST_EXP(_ST_DO_INCLUDE(x))

//int main() => BOOST_AUTO_TEST_CASE(name)
#undef main
#define main() static inline BOOST_JOIN(unused, __COUNTER__)(){ return 0;} _ST_TEST(STRING_TEST)

#if _ST_COUNT(STRING_TEST) >= 2
_ST_SUITE(STRING_TEST)
#if _ST_COUNT(STRING_TEST) >= 3
_ST_SUITE1(STRING_TEST)
#endif
#endif
namespace _ST_NS(STRING_TEST) {
#include _ST_INCLUDE(STRING_TEST)
}
#if _ST_COUNT(STRING_TEST) >= 2
#if _ST_COUNT(STRING_TEST) >= 3
BOOST_AUTO_TEST_SUITE_END()
#endif
BOOST_AUTO_TEST_SUITE_END()
#endif


#undef main
#undef BOOST_AUTO_TU_REGISTRAR
#undef _ST_ARG2
#undef _ST_ARG2_I
#undef _ST_ARG2_II
#undef _ST_EXP
#undef _ST_EXP_I
#undef _ST_EXP_II
#undef _ST_DO_COUNT
#undef _ST_COUNT
#undef _ST_IS_char
#undef _ST_TEST_NAME
#undef _ST_BOOST_AUTO_TEST_CASE
#undef _ST_BOOST_AUTO_TEST_SUITE1
#undef _ST_BOOST_AUTO_TEST_SUITE
#undef _ST_DO_TEST
#undef _ST_DO_SUITE
#undef _ST_DO_SUITE1
#undef _ST_DO_NS
#undef _ST_DO_INCLUDE
#undef _ST_SUITE
#undef _ST_SUITE1
#undef _ST_TEST
#undef _ST_NS
#undef _ST_INCLUDE

#undef STRING_TEST
#define BOOST_AUTO_TU_REGISTRAR( test_name )    \
static boost::unit_test::ut_detail::auto_test_unit_registrar BOOST_JOIN( BOOST_JOIN( test_name, _registrar ), __LINE__ )
