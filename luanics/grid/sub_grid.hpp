#pragma once

#include "luanics/grid/grid.hpp"

namespace luanics::grid {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class sub_grid
///
/// @brief grid that refers to a region in a "parent" grid.
///
/// Though the sub_grid constructor takes a pointer to a non-const grid,
///  sub_grid is designed to allow "const" views of a grid through the following
///  procedure:
///   grid const * const_grid = ...;
///   sub_grid const const_grid_view{w,h,x,y,const_cast<grid*>(const_grid)};
///  This is guaranteed to avoid undefined behavior because the constructor
///  avoids calling any non-const methods on the input grid.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class sub_grid : public grid {
public:
	sub_grid(
		std::size_t const width,
		std::size_t const height,
		std::size_t const x_offset,
		std::size_t const y_offset,
		grid * parent
	);
	sub_grid(sub_grid const & other) = default;
	sub_grid & operator=(sub_grid const & other) = default;

	std::size_t x_offset() const;
	std::size_t y_offset() const;

	virtual std::size_t width() const final;
	virtual std::size_t height() const final;
	/// @pre x < width and y < height
	virtual value_type & operator()(std::size_t const x, std::size_t const y) final;
	/// @pre x < width and y < height
	virtual value_type const & operator()(std::size_t const x, std::size_t const y) const final;
	virtual void clear() final;
	virtual void fill_with(value_type const value) final;
	virtual void write_to(std::ostream & out) const final;
	virtual void read_from(std::istream & in) final;

private:
	std::size_t _width;
	std::size_t _height;
	std::size_t _x_offset;
	std::size_t _y_offset;
	grid * _parent;
};
// class sub_grid

} // namespace luanics::grid
