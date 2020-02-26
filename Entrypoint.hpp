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
    using ctls = std::vector<ct>;

    ctls parse(const char** path);
    void display(const ctls& cs);
    void setInput(const ctls& cs, const std::string& in);
    TriState toState(const std::string& v);
    TriState toState(std::size_t v);
}

#endif
