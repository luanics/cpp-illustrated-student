#include "luanics/grid/dynamic_grid.hpp"

#include "luanics/logging/contract.hpp"
#include "luanics/utility/iterators.hpp"

#include <algorithm>
#include <iostream>

namespace luanics::grid {

dynamic_grid::dynamic_grid() :
	_width{0},
	_height{0},
	_data{}
{}

dynamic_grid::dynamic_grid(std::size_t const width, std::size_t const height) :
	_width{width},
	_height{height},
	_data(height, std::vector<char>(width, empty_value))
{}

std::size_t dynamic_grid::width() const {
	return _width;
}

std::size_t dynamic_grid::height() const {
	return _height;
}

dynamic_grid::value_type & dynamic_grid::operator()(std::size_t const x, std::size_t const y) {
	return const_cast<char&>(const_cast<dynamic_grid const &>(*this).operator()(x,y));
}

dynamic_grid::value_type const & dynamic_grid::operator()(std::size_t const x, std::size_t const y) const {
	EXPECTS(x < _width and y < _height, x, _width, y, _height);
	return _data[y][x];
}

void dynamic_grid::clear() {
	fill_with(empty_value);
}

void dynamic_grid::fill_with(value_type const value) {
	for (auto & row: _data) {
		row.assign(_width, value);
	}
}

void dynamic_grid::write_to(std::ostream & out) const {
	for (auto const & row : utility::reverse(_data)) {
		for (auto const & value: row) {
			out << value;
		}
		out << std::endl;
	}
}

void dynamic_grid::read_from(std::istream & in) {
	_data.clear();
	std::string line;
	std::size_t max_width = 0;
	while (std::getline(in, line)) {
		max_width = std::max(line.size(), max_width);
		_data.push_back(std::vector<char>(line.begin(), line.end()));
	}
	_width = max_width;
	_height = _data.size();
	for (auto & row: _data) {
		row.resize(_width, empty_value);
	}
	std::reverse(_data.begin(), _data.end());
}

} // namespace luanics::grid
