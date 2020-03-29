/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include "Output.hpp"

namespace nts {
    Output::Output(const std::string &name) : _n{name}, _link{} {}

    void Output::setLink(std::size_t, ct component, std::size_t) { _link = component; }
    TriState Output::compute(size_t) { return _link->compute(); };
    void Output::dump(void) const
    { std::cout << _n << "=" << _link->compute() << std::endl; };
    ctName Output::Name() const { return _n; };
    ctType Output::Type() const { return _t; };
}
