#include "luanics/grid/flipped_grid.hpp"

#include "luanics/logging/contract.hpp"
#include "luanics/testing/tutorial/macros.hpp"

namespace luanics::grid {

flipped_grid::flipped_grid(grid * decorated) :
	_decorated{decorated}
{}

std::size_t flipped_grid::width() const {
	FIX(return _decorated->width();)
}

std::size_t flipped_grid::height() const {
	FIX(return _decorated->height();)
}

flipped_grid::value_type & flipped_grid::operator()(std::size_t const x, std::size_t const y) {
	FIX(
//		static ValueType temp;
//		return temp;
		return const_cast<value_type&>(const_cast<flipped_grid const *>(this)->operator()(x,y));
	)
}

flipped_grid::value_type const & flipped_grid::operator()(std::size_t const x, std::size_t const y) const {
	FIX(
//		static ValueType temp;
//		return temp;
		return _decorated->operator()(x, height() - 1 - y);
	)
}

void flipped_grid::clear() {
	CREATE
	_decorated->clear();
}

void flipped_grid::fill_with(value_type const value) {
	CREATE
	_decorated->fill_with(value);
}

void flipped_grid::write_to(std::ostream & out) const {
	CREATE
	_decorated->write_to(out);
}

void flipped_grid::read_from(std::istream & in) {
	CREATE
	_decorated->read_from(in);
}

} // namespace luanics::grid
