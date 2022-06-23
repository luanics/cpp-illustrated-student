#include "luanics/grid/sub_grid.hpp"

#include "luanics/logging/contract.hpp"

namespace luanics::grid {

sub_grid::sub_grid(
	std::size_t const width,
	std::size_t const height,
	std::size_t const x_offset,
	std::size_t const y_offset,
	grid * parent
) :
	_width{width},
	_height{height},
	_x_offset{x_offset},
	_y_offset{y_offset},
	_parent{parent}
{
	EXPECTS(width + x_offset <= parent->width());
	EXPECTS(height + y_offset <= parent->height());
}

std::size_t sub_grid::x_offset() const {
	return _x_offset;
}

std::size_t sub_grid::y_offset() const {
	return _y_offset;
}

std::size_t sub_grid::width() const {
	return _width;
}

std::size_t sub_grid::height() const {
	return _height;
}

grid::value_type & sub_grid::operator()(std::size_t const x, std::size_t const y) {
	return const_cast<char&>(const_cast<sub_grid const &>(*this).operator()(x,y));
}

grid::value_type const & sub_grid::operator()(std::size_t const x, std::size_t const y) const {
	EXPECTS(x < _width and y < _height);
	return _parent->operator()(x + _x_offset, y + _y_offset);
}

void sub_grid::clear() {
	fill_with(empty_value);
}

void sub_grid::fill_with(value_type const value) {
	for (std::size_t x = 0; x < _width; ++x) {
		for (std::size_t y = 0; y < _height; ++y) {
			operator()(x,y) = value;
		}
	}
}

void sub_grid::write_to(std::ostream & out) const {
	grid::write_to(out);
}

void sub_grid::read_from(std::istream & in) {
	grid::read_from(in);
}

} // namespace luanics::grid
