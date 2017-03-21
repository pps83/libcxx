#define BOOST_TEST_MODULE Base
#include <boost/test/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>

#ifdef _WIN32
int BOOST_TEST_CALL_DECL
main(int argc, char* argv[])
{
	// prototype for user's unit test init function
#ifdef BOOST_TEST_ALTERNATIVE_INIT_API
	boost::unit_test::init_unit_test_func init_func = &init_unit_test;
#else
	boost::unit_test::init_unit_test_func init_func = &init_unit_test_suite;
#endif

	int ret = ::boost::unit_test::unit_test_main(init_func, argc, argv);
	system("pause");
	return ret;
}
#endif
