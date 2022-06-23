#pragma once

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @file tutorial/structural_macros.hpp
///
/// @brief Macros for setting up tutorial hierarchy.
///
/// Note that all names are decorated (minimally) with "LUANICS_" prefix to avoid name clashes.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

#include "luanics/testing/core/composite.hpp"
#include "luanics/testing/core/installer.hpp"
#include "luanics/testing/core/leaf.hpp"
#include "luanics/testing/core/reporter.hpp"
#include "luanics/testing/unit/structural_macros.hpp"

#define LUANICS_ADD_TUTORIAL(tutorial_name) \
	luanics::testing::core::composite tutorial{#tutorial_name};

#define LUANICS_ADD_PART(part_name, is_enabled) \
	luanics::testing::core::composite part_##part_name{#part_name}; \
	luanics::testing::core::installer part_##part_name##_installer{tutorial, part_##part_name}; \

#define LUANICS_ADD_CHAPTER(part_name, chapter_name, is_enabled) \
	extern luanics::testing::core::composite luanics_chapter_##chapter_name##_instance; \
	luanics::testing::core::installer chapter_##chapter_name##_installer{part_##part_name, luanics_chapter_##chapter_name##_instance};

#define LUANICS_ADD_PROJECT(part_name, project_namespace, project_name, is_enabled) \
	namespace luanics { \
	namespace project_namespace { \
	extern luanics::testing::core::composite LUANICS_TEST_SET_INSTANCE_EXTERNAL(project_name); \
	luanics::testing::core::installer project_##project_name_##installer{part_##part_name, LUANICS_TEST_SET_INSTANCE_EXTERNAL(project_name)}; \
	} }

#define LUANICS_CHAPTER_INSTANCE(name) luanics_##chapter_##name##_instance

#define LUANICS_BEGIN_CHAPTER(name)\
	luanics::testing::core::composite LUANICS_CHAPTER_INSTANCE(name){#name};\
	namespace {\
		luanics::testing::core::composite & chapter_reference = LUANICS_CHAPTER_INSTANCE(name);

#define LUANICS_END_CHAPTER(name) \
	}

#define LUANICS_SECTION_CLASS_NAME(name) luanics_##name##_section
#define LUANICS_SECTION_INSTANCE_NAME(name) luanics_##name##_section_instance
#define LUANICS_SECTION_INSTALLER_INSTANCE_NAME(name) luanics_##name##_section_installer_instance
#define LUANICS_REPORTER_NAME luanics_reporter

#define LUANICS_SECTION(name)\
	class LUANICS_SECTION_CLASS_NAME(name) : public luanics::testing::core::leaf {\
	public: \
		LUANICS_SECTION_CLASS_NAME(name)() : leaf{#name} {} \
		virtual void do_run(luanics::testing::core::reporter &) override final;\
	}; \
	LUANICS_SECTION_CLASS_NAME(name) LUANICS_SECTION_INSTANCE_NAME(name); \
	luanics::testing::core::installer LUANICS_SECTION_INSTALLER_INSTANCE_NAME(name){chapter_reference, LUANICS_SECTION_INSTANCE_NAME(name)};\
	void LUANICS_SECTION_CLASS_NAME(name)::do_run(luanics::testing::core::reporter & LUANICS_REPORTER_NAME)

#define LUANICS_SUBPROJECT_INSTANCE(name) luanics_subproject_##name##_instance

#define LUANICS_BEGIN_SUBPROJECT(name)\
	luanics::testing::core::composite LUANICS_SUBPROJECT_INSTANCE(name){#name};\
	namespace {\
		luanics::testing::core::composite & subproject_reference = LUANICS_SUBPROJECT_INSTANCE(name);

#define LUANICS_END_SUBPROJECT(name) \
	}

#define LUANICS_SUBPROJECT_TEST_CLASS(name) luanics_##name##_subproject_test
#define LUANICS_SUBPROJECT_TEST_INSTANCE(name) luanics_##name##_subproject_test_instance
#define LUANICS_SUBPROJECT_TEST_INSTALLER_INSTANCE(name) luanics_##name##_subproject_test_installer_instance
#define LUANICS_REPORTER luanics_reporter

#define LUANICS_SUBPROJECT_TEST(name) \
	class LUANICS_SUBPROJECT_TEST_CLASS(name) : public luanics::testing::core::leaf { \
	public: \
		LUANICS_SUBPROJECT_TEST_CLASS(name)() : leaf{#name} {} \
		virtual void do_run(luanics::testing::core::reporter &) override final; \
	}; \
	LUANICS_SUBPROJECT_TEST_CLASS(name) LUANICS_SUBPROJECT_TEST_INSTANCE(name); \
	luanics::testing::core::installer LUANICS_SUBPROJECT_TEST_INSTALLER_INSTANCE(name){subproject_reference, LUANICS_SUBPROJECT_TEST_INSTANCE(name)}; \
	void LUANICS_SUBPROJECT_TEST_CLASS(name)::do_run(luanics::testing::core::reporter & LUANICS_REPORTER_NAME)
