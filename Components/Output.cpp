//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// output cpp file
//

#include <iostream>
#include "../Primitives.hpp"
#include "../Errors.hpp"
#include "Output.hpp"
#include "SimpleLinks.hpp"

namespace nts
{
    Output::Output(const std::string &name)
	: _link(NULL), _name(name)
    {
    }
    
    Tristate Output::Compute(size_t cur)
    {
	if (this->_link && cur == 1)
	    return (this->_lin1k->compute());
	return (UNDEFINED);
    }
    
    void    Output::SetLink(size_t pin, IComponent &component, size_t target)
    {
	if (pin == 1)
	    this->_link = new SimpleLink(&component, target);
    }
    
    void    Output::Dump() const
    {
	std::cout << "Output: " << this->_name << std::endl;
    }
}
