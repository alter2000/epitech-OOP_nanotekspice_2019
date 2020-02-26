/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef ENTRYPOINT_HPP_
#define ENTRYPOINT_HPP_

#include <vector>
#include "IComponent.hpp"
#include "Errors.hpp"

namespace nts
{
    ctls parse(int c, const char** v);
    void display(const ctls& cs);
    void setInput(const ctls& cs, const std::string& in);
    TriState toState(const std::string& v);
    TriState toState(std::size_t v);
}

#endif
