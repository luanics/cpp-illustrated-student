#include "luanics/testing/unit.hpp"
#include "luanics/testing/core/simple_reporter.hpp"

namespace luanics::testing::core {

BEGIN_TEST_SET(test_leaf)

TEST(install) {
	composite test_suite{"test_suite"};
	composite test_case{"test_case"};
	EXPECT_EQ(0, test_suite.children().size());
	EXPECT_EQ(0, test_case.children().size());

	installer test_case_installer(test_suite, test_case);
	EXPECT_EQ(1, test_suite.children().size());
	EXPECT_EQ(0, test_case.children().size());
}

class passing_test : public leaf {
public:
	passing_test() : leaf{"passing"} {}
private:
	void do_run(reporter & reporter) {
		reporter.record(result{true, __FILE__, __LINE__, "passing"});
	}
};

TEST(Pass) {
	composite test_suite{"test_suite"};
	composite test_case{"test_case"};
	installer test_case_installer(test_suite, test_case);
	passing_test passing_test;
	installer test_installer(test_case, passing_test);
	EXPECT_EQ(1, test_suite.children().size());
	EXPECT_EQ(1, test_case.children().size());

	simple_reporter reporter;
	test_suite.run(reporter);
	EXPECT_EQ(1, reporter.num_pass_results());
	EXPECT_EQ(0, reporter.num_fail_results());
	EXPECT_EQ(0, reporter.num_errors());
	EXPECT_EQ(0, reporter.num_logs());
}

class failing_test : public leaf {
public:
	failing_test() : leaf{"failing"} {}
private:
	void do_run(reporter & reporter) {
		reporter.record(result{false, __FILE__, __LINE__, "failing"});
	}
};

TEST(fail) {
	composite test_suite{"test_suite"};
	composite test_case{"test_case"};
	installer test_case_installer{test_suite, test_case};
	failing_test failing_test;
	installer test_installer{test_case, failing_test};
	EXPECT_EQ(1, test_suite.children().size());
	EXPECT_EQ(1, test_case.children().size());

	simple_reporter reporter;
	test_suite.run(reporter);
	EXPECT_EQ(0, reporter.num_pass_results());
	EXPECT_EQ(1, reporter.num_fail_results());
	EXPECT_EQ(0, reporter.num_errors());
	EXPECT_EQ(0, reporter.num_logs());
}

class erring_test : public leaf {
public:
	erring_test() : leaf{"erring"} {}
private:
	void do_run(reporter & reporter) {
		throw std::runtime_error("error");
	}
};

TEST(error) {
	composite test_suite{"test_suite"};
	composite test_case{"test_case"};
	installer test_case_installer{test_suite, test_case};
	erring_test erring_test;
	installer test_installer{test_case, erring_test};
	EXPECT_EQ(1, test_suite.children().size());
	EXPECT_EQ(1, test_case.children().size());

	simple_reporter reporter;
	test_suite.run(reporter);
	EXPECT_EQ(0, reporter.num_pass_results());
	EXPECT_EQ(0, reporter.num_fail_results());
	EXPECT_EQ(1, reporter.num_errors());
	EXPECT_EQ(0, reporter.num_logs());
}

class logging_test : public leaf {
public:
	logging_test() : leaf{"Logging"} {}
private:
	void do_run(reporter & reporter) {
		reporter.record(log{__FILE__, __LINE__, "logging"});
	}
};

TEST(Log) {
	composite test_suite{"test_suite"};
	composite test_case{"test_case"};
	installer test_case_installer{test_suite, test_case};
	logging_test logging_test;
	installer test_installer{test_case, logging_test};
	EXPECT_EQ(1, test_suite.children().size());
	EXPECT_EQ(1, test_case.children().size());

	simple_reporter reporter;
	test_suite.run(reporter);
	EXPECT_EQ(0, reporter.num_pass_results());
	EXPECT_EQ(0, reporter.num_fail_results());
	EXPECT_EQ(0, reporter.num_errors());
	EXPECT_EQ(1, reporter.num_logs());
}

TEST(All) {
	composite test_suite{"test_suite"};
	composite test_case{"test_case"};
	installer test_case_installer{test_suite, test_case};
	passing_test passing_test;
	installer passing_test_installer{test_case, passing_test};
	failing_test failing_test;
	installer failing_test_installer{test_case, failing_test};
	erring_test erring_test;
	installer erring_test_installer{test_case, erring_test};
	logging_test logging_test;
	installer logging_test_installer{test_case, logging_test};
	EXPECT_EQ(1, test_suite.children().size());
	EXPECT_EQ(4, test_case.children().size());

	simple_reporter reporter;
	test_suite.run(reporter);
	EXPECT_EQ(1, reporter.num_pass_results());
	EXPECT_EQ(1, reporter.num_fail_results());
	EXPECT_EQ(1, reporter.num_errors());
	EXPECT_EQ(1, reporter.num_logs());
}

END_TEST_SET(test_leaf)

}
