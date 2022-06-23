#pragma once

#include "luanics/logging/contract.hpp"

namespace luanics {

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class value_category
///
/// @brief Enumeration for the terminal categories of value category.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
enum class value_category {
	LVALUE,
	XVALUE,
	PRVALUE
};

inline std::ostream & operator<<(std::ostream & out, value_category const value) {
	switch (value) {
		case value_category::LVALUE: out << "LVALUE"; break;
		case value_category::XVALUE: out << "XVALUE"; break;
		case value_category::PRVALUE: out << "PRVALUE"; break;
		default: UNREACHABLE(static_cast<int>(value));
	}
	return out;
}

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class expression_analysis
///
/// @brief Contains the *type* and *value category* of an expression.
///
/// Remember that the type of expressions is always *object* type.
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <typename T, value_category V>
struct expression_analysis {
	static constexpr value_category value = V;
	using type = T;

	static void write_to(std::ostream & out) {
		out << "(";
		write_type_to(out);
		out << ",";
		write_value_category_to(out);
		out << ")";
	}
	static void write_value_category_to(std::ostream & out) {
		out << value;
	}
	static void write_type_to(std::ostream & out) {
		// typeid doesn't include cv-ness ...
		out << typeid(T).name();
		// ... so we include it ourselves.
		if constexpr (std::is_const_v<T>) {
			out << " const";
		}
		if constexpr (std::is_volatile_v<T>) {
			out << " volatile";
		}
	}

};

/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
///
/// @class analyze_expression
///
/// @brief Type metafunction that returns expression_analysis
///
/// Value category analysis based on idea presented by Luc Danton:
///  https://stackoverflow.com/questions/16637945/empirically-determine-value-category-of-c11-expression
///
/////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////
template <typename T>
struct analyze_expression;

/// Primary template matches all types.
template <typename T>
struct analyze_expression {
	///  Since decltype(e) is non-ref for prvalue expression e,
	///   the value category is PRVALUE.
	using type = expression_analysis<T, value_category::PRVALUE>;
};

/// Universal reference specialization, matches all reference types.
template <typename T>
struct analyze_expression<T &&> {
	/// Since decltype(e) is an rvalue ref for xvalue expression e,
	///  the value category is XVALUE.
	using type = expression_analysis<T, value_category::XVALUE>;
};

/// Lvalue reference specialization, matches *only* lvalue refs.
template <typename T>
struct analyze_expression<T &> {
	///  Since decltype(e) is an lvalue ref for lvalue expression e,
	///  the value category is LVALUE
	using type = expression_analysis<T, value_category::LVALUE>;
};

} // namespace luanics

#define VALUE_CATEGORY_OF(x) luanics::analyze_expression<decltype((x))>::type::value
#define TYPE_OF(x) typename luanics::analyze_expression<decltype((x))>::type::type
#define ANALYSIS_OF(x) luanics::analyze_expression<decltype((x))>::type
#define PRINT_ANALYSIS_OF(x) std::cout << "(" << #x << ") -> "; luanics::analyze_expression<decltype((x))>::type::writeTo(std::cout); std::cout << std::endl
