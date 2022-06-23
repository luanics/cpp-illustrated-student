#include "luanics/testing/tutorial.hpp"

#include <cassert>
#include <type_traits>

BEGIN_CHAPTER(References)

// * References must bind to an object exactly once, at initialization.
// * After binding, reference variables are no different than object variables --- both provide names which can be used to \emph{view} the object.
// * Different views of an object may have different types.
// * lvalue references are introduced with &, rvalue references are introduced with &&.
// * Rules for binding:
//   * lvalue references bind to objects, rvalue references to unobjects.
//   * references to non-const bind only to non-const objects, references to const bind to both const and non-const objects.
//   * As a special case, lvalue reference to const binds to everything.
// * Reference collapsing occurs when declaring a reference to a type that is aliased to a reference type.
// * Rules for reference collapsing:
//   * If either reference is lvalue, the result is lvalue.
//   * Only if both references are rvalue is the result rvalue.
//   * The resulting object type is const only if the alias is a ref-to-const.

SECTION(Basics) {
// * lvalue references are introduced with &, rvalue references are introduced with &&.
	int object_variable = 1;
	FIX(int lvalue_ref_variable) = object_variable;
	FIX(int rvalue_ref_variable) = 1;

	EXPECT_TRUE(std::is_lvalue_reference_v<decltype(lvalue_ref_variable)>);
	EXPECT_TRUE(std::is_rvalue_reference_v<decltype(rvalue_ref_variable)>);
}

SECTION(Binding) {
// * Rules for binding:
//   * lvalue references bind to objects, rvalue references to unobjects.
//   * references to non-const bind only to non-const objects, references to const bind to both const and non-const objects.
//   * As a special case, lvalue reference to const binds to everything.

	// Give "a" a non-const reference type that will bind to an unobject
	FIX(int a) = 1;
	EXPECT_FALSE(std::is_const_v<std::remove_reference_t<decltype(a)>>);
	EXPECT_TRUE(std::is_reference_v<decltype(a)>);

	// Give "b" a non-const reference type that will bind to an object but not an unobject
	FIX(int b) = a;
	EXPECT_FALSE(std::is_const_v<decltype(b)>);
	EXPECT_TRUE(std::is_reference_v<decltype(b)>);

	// Give "c" a const reference type that will bind to an unobject
	FIX(int c) = 1;
	EXPECT_TRUE(std::is_const_v<std::remove_reference_t<decltype(c)>>);
	EXPECT_TRUE(std::is_reference_v<decltype(c)>);

	// Give "d" a const reference type that will bind to an object
	FIX(int d) = c;
	EXPECT_TRUE(std::is_const_v<std::remove_reference_t<decltype(d)>>);
	EXPECT_TRUE(std::is_reference_v<decltype(d)>);

	// Find a common reference type for "e" and "f" that will bind to both objects and unobjects
	FIX(int e) = 1; // binding to unobject
	FIX(int f) = e; // binding to object
	EXPECT_TRUE(std::is_reference_v<decltype(e)>);
	EXPECT_TRUE(std::is_reference_v<decltype(f)>);
	EXPECT_TRUE((std::is_same_v<decltype(e), decltype(f)>));

}

SECTION(Constness) {
	//   * references to non-const bind only to non-const objects, references to const bind to both const and non-const objects.
	int const a = 1;
	// Give "b" a reference type
	FIX(int b) = a;
	EXPECT_TRUE(std::is_reference_v<decltype(b)>);
}


// We'll use this enumeration for the next section
enum class type_category {
	OTHER, ///< not a reference type
	LVALUE_REF,
	LVALUE_REF_TO_CONST,
	RVALUE_REF,
	RVALUE_REF_TO_CONST
};

std::string to_string(type_category value) {
	using tc = type_category;
	switch (value) {
		case tc::OTHER: return "OTHER";
		case tc::LVALUE_REF: return "LVALUE_REF";
		case tc::LVALUE_REF_TO_CONST: return "LVALUE_REF_TO_CONST";
		case tc::RVALUE_REF: return "RVALUE_REF";
		case tc::RVALUE_REF_TO_CONST: return "RVALUE_REF_TO_CONST";
		default: return "INVALID";
	}
}

// Here's a function to identify which category a type is.
// Don't worry about how this works at this point - it will be a while before we've covered that material.
template <typename T>
constexpr type_category type_of() {
	if constexpr (std::is_lvalue_reference_v<T>) {
		if constexpr (std::is_const_v<std::remove_reference_t<T>>) {
			return type_category::LVALUE_REF_TO_CONST;
		}
		else {
			return type_category::LVALUE_REF;
		}
	}
	else if constexpr (std::is_rvalue_reference_v<T>) {
		if constexpr (std::is_const_v<std::remove_reference_t<T>>) {
			return type_category::RVALUE_REF_TO_CONST;
		}
		else {
			return type_category::RVALUE_REF;
		}
	}
	else {
		return type_category::OTHER;
	}
}

// And here is a macro to make it easier to use the function
#define REFERENCE_TYPE_OF(x) type_of<decltype(x)>()

SECTION(ReferenceCollapsing) {
// * Reference collapsing occurs when declaring a reference to a type that is aliased to a reference type.
// * Rules for reference collapsing:
//   * If either reference is lvalue, the result is lvalue.
//   * Only if both references are rvalue is the result rvalue.
//   * The resulting object type is const only if the alias is a ref-to-const.

	using int_lvalue_ref = int &;
	using int_const_lvalue_ref = int const &;
	using int_rvalue_ref = int &&;

	// For each of the types, choose the correct type_category using the
	//  reference collapsing rules.

	int a = 1;

	int_lvalue_ref b = a;
	EXPECT_EQ(REFERENCE_TYPE_OF(b), FIX(type_category::OTHER));

	int_rvalue_ref c = 1;
	EXPECT_EQ(REFERENCE_TYPE_OF(c), FIX(type_category::OTHER));

	int_const_lvalue_ref d = a;
	EXPECT_EQ(REFERENCE_TYPE_OF(d), FIX(type_category::OTHER));

	int_lvalue_ref & e = a;
	EXPECT_EQ(REFERENCE_TYPE_OF(e), FIX(type_category::OTHER));

	int_lvalue_ref const & f = a;
	EXPECT_EQ(REFERENCE_TYPE_OF(f), FIX(type_category::OTHER));

	int_const_lvalue_ref & g = a;
	EXPECT_EQ(REFERENCE_TYPE_OF(g), FIX(type_category::OTHER));

	int_rvalue_ref && h = 1;
	EXPECT_EQ(REFERENCE_TYPE_OF(h), FIX(type_category::OTHER));
}

END_CHAPTER(References)
