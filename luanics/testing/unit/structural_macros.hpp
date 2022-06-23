#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file unit/structural_macros.hpp
///
/// @brief Macros for setting up unit test hierarchy.
///
/// Note that all names are decorated (minimally) with "LUANICS_" prefix to avoid name clashes.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "luanics/testing/core/composite.hpp"
#include "luanics/testing/core/installer.hpp"
#include "luanics/testing/core/leaf.hpp"
#include "luanics/testing/core/reporter.hpp"
#include "luanics/testing/unit/instance.hpp"

#define LUANICS_DOUBLE_COMPARISON_PRECISION 1e-6

#define LUANICS_TEST_SET_INSTANCE luanics_test_set_instance
#define LUANICS_TEST_SET_INSTALLER_INSTANCE luanics_test_set_installler_instance
#define LUANICS_TEST_SET_INSTANCE_EXTERNAL(name) luanics_test_set_instance_##name

#define LUANICS_BEGIN_TEST_SET(name)\
	luanics::testing::core::composite LUANICS_TEST_SET_INSTANCE_EXTERNAL(name){#name};\
	namespace {\
		luanics::testing::core::composite & LUANICS_TEST_SET_INSTANCE = LUANICS_TEST_SET_INSTANCE_EXTERNAL(name);\
		luanics::testing::core::installer LUANICS_TEST_SET_INSTALLER_INSTANCE{luanics::testing::unit::suite_instance(), LUANICS_TEST_SET_INSTANCE};\

#define LUANICS_END_TEST_SET()\
	}

#define LUANICS_TEST_CLASS(name) luanics_##name##_test
#define LUANICS_TEST_INSTANCE(name) luanics_##name##_test_instance
#define LUANICS_TEST_INSTALLER_INSTANCE(name) luanics_##name##_test_installer_instance
#define LUANICS_REPORTER luanics_reporter

#define LUANICS_TEST_IMPL(name, is_slow)\
	class LUANICS_TEST_CLASS(name) : public luanics::testing::core::leaf {\
	public: \
		LUANICS_TEST_CLASS(name)() : leaf{#name, is_slow} {} \
		virtual void do_run(luanics::testing::core::reporter &) override final;\
	}\
	LUANICS_TEST_INSTANCE(name);\
	luanics::testing::core::installer LUANICS_TEST_INSTALLER_INSTANCE(name){LUANICS_TEST_SET_INSTANCE, LUANICS_TEST_INSTANCE(name)};\
	void LUANICS_TEST_CLASS(name)::do_run(luanics::testing::core::reporter & LUANICS_REPORTER)

#define LUANICS_TEST(name) LUANICS_TEST_IMPL(name, false)
#define LUANICS_TEST_SLOW(name) LUANICS_TEST_IMPL(name, true)

