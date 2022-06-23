#pragma once

#include "luanics/grid/grid.hpp"

#include <memory>

namespace luanics::grid {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class flipped_grid
///
/// @brief A Grid that reverses the direction of Y axis.
///
/// Flipped grid has origin (0,0) at top left.
///
/// *----> x
/// |
/// |
/// V y
///
/// Implemented as a Grid Decorator. When it wraps a regular grid
///   (origin at bottom left), the result is origin at top left.
///   Note that the orientation of the axes is not observable until
///   IO is used.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class flipped_grid : public grid {
public:
	flipped_grid(grid * decorated);

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
	grid * _decorated;
}; // class flipped_grid

} // namespace luanics::grid
