#include "grid.hpp"

#include <iostream>

namespace luanics::grid {

constexpr char grid::empty_value;

void grid::write_to(std::ostream & out) const {
	for (std::size_t y = height() - 1; y < height(); --y) {
		for (std::size_t x = 0; x < width(); ++x) {
			out << operator()(x, y);
		}
		out << std::endl;
	}
}

void grid::read_from(std::istream & in) {
	// Don't resize to fit input. Just set failbit and quit if input doesn't match width.
	std::string line;
	std::size_t y = height() - 1;
	while ((y < height()) and std::getline(in, line)) {
		auto const width = line.size();
		if (width != this->width()) {
			in.setstate(std::ios::failbit);
			return;
		}
		for (std::size_t x = 0; x < this->width(); ++x) {
			operator()(x,y) = line[x];
		}
		--y;
	}
	bool const is_complete = y == height();
	if (not is_complete) {
		in.setstate(std::ios::failbit);
	}
}

bool operator==(grid const & lhs, grid const & rhs) {
	bool const have_same_dimensions =
		(lhs.width() == rhs.width())
		and (lhs.height() == rhs.height())
	;
	if (not have_same_dimensions)
		return false;
	for (std::size_t y = 0; y < lhs.height(); ++y) {
		for (std::size_t x = 0; x < lhs.width(); ++x) {
			if (lhs(x,y) != rhs(x,y))
				return false;
		}
	}
	return true;
}

bool operator!=(grid const & lhs, grid const & rhs) {
	return not operator==(lhs, rhs);
}

std::ostream & operator<<(std::ostream & out, grid const & grid) {
	grid.write_to(out);
	return out;
}

std::istream & operator>>(std::istream & in, grid & grid) {
	grid.read_from(in);
	return in;
}

} // namespace luanics::grid
