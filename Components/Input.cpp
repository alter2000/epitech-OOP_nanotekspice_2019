/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include "Input.hpp"

namespace nts {
    Input::Input(const std::string &name) : _n{name}, _val{UNDEFINED} {}
    void Input::_setIn(TriState a) { _val = a; }

    void Input::setLink(std::size_t, ct, std::size_t) {}

    void Input::dump(void) const { std::cout << _n << "=" << _val << std::endl; };
    TriState Input::compute(size_t) { return _val; };
    ctName Input::Name() const { return _n; };
    ctType Input::Type() const { return _t; };
}
