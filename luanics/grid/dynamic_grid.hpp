#pragma once

#include "luanics/grid/grid.hpp"

#include <vector>

namespace luanics::grid {

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///
/// @class dynamic_grid
///
/// @brief Grid implemented using 2d vector of vectors.
///
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
class dynamic_grid : public grid {
public:
	//////////////////////////////////////////////////////////////////
	/// @name Management
	//////////////////////////////////////////////////////////////////
	//@{
	dynamic_grid(); ///< 0 by 0 grid
	dynamic_grid(std::size_t const width, std::size_t const height);
	dynamic_grid(dynamic_grid const & other) = default;
	dynamic_grid & operator=(dynamic_grid const & other) = default;
	dynamic_grid(dynamic_grid && other) = default;
	dynamic_grid & operator=(dynamic_grid && other) = default;
	//@}

	//////////////////////////////////////////////////////////////////
	/// @name Attributes
	//////////////////////////////////////////////////////////////////
	//@{
	virtual std::size_t width() const override final;
	virtual std::size_t height() const override final;
	//@}

	//////////////////////////////////////////////////////////////////
	/// @name Access
	//////////////////////////////////////////////////////////////////
	//@{
	/// @pre x < width and y < height
	virtual value_type & operator()(std::size_t const x, std::size_t const y) override final;
	/// @pre x < width and y < height
	virtual value_type const & operator()(std::size_t const x, std::size_t const y) const override final;
	//@}

	//////////////////////////////////////////////////////////////////
	/// @name Modification
	//////////////////////////////////////////////////////////////////
	//@{
	/// Fills with EmptyValue
	virtual void clear() override final;
	virtual void fill_with(value_type const value) override final;
	//@}

	//////////////////////////////////////////////////////////////////
	/// @name Io
	//////////////////////////////////////////////////////////////////
	//@{
	virtual void write_to(std::ostream & out) const final;
	/// Grid::readFrom(), this will dynamically resize.
	virtual void read_from(std::istream & in) final;
	//@}

private:
	std::size_t _width;
	std::size_t _height;
	std::vector<std::vector<value_type>> _data;
}; // class dynamic_grid

} // namespace luanics::grid