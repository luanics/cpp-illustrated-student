#include "luanics/utility/tuples.hpp"

namespace luanics::utility {

namespace detail {

template <typename TupleT, std::size_t IndexV>
struct writer {
	static void write(TupleT const & values, std::ostream & out, std::string_view const & delimiter) {
		out << std::get<std::tuple_size<TupleT>::value - IndexV>(values) << delimiter;
		writer<TupleT, IndexV - 1>::write(values, out, delimiter);
	}
};

template <typename TupleT>
struct writer<TupleT, 0> {
	static void write(TupleT const & values, std::ostream & out, std::string_view const & delimiter) {}
};

}

template <typename ... ParamsT>
void write_tuple(std::tuple<ParamsT...> const & values, std::ostream & out, std::string_view delimiter) {
	using TupleType = std::tuple<ParamsT...>;
	detail::writer<TupleType, std::tuple_size<TupleType>::value>::write(values, out, delimiter);
}

}

namespace std {

template <typename ... ParamsT>
ostream & operator<<(ostream & out, tuple<ParamsT...> const & values) {
	luanics::utility::write_tuple(values, out, ",");
	return out;
}

}
