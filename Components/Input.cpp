//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// input cpp file
//

#include <iostream>
#include "Input.hpp"
#include "../Primitives.hpp"
#include "../Errors.hpp"

namespace nts
{
    Input::Input(const std::string &name)
	: _name(name)
    {
    }
    
    Tristate Input::Compute(size_t cur)
    {
	if (cur == 1)
	    return (this->_state);
	return (UNDEFINED);
    }
    
    void	Input::SetLink(size_t pin, IComponent &component, size_t target)
    {
	component.SetLink(target, *this, pin);
    }
    
    void	Input::Dump() const
    {
	std::cout << "Input: " << this->_name << " is " << this->_state << std::endl;
    }
}
