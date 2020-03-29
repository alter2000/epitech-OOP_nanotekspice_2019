/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <algorithm>
#include "Builders.hpp"
#include "Errors.hpp"

namespace nts
{
    std::function<ct(std::string)> mkComponent(ctType t)
    {
        // TODO: loop std::pairs (str, cons)
        auto f = std::find(CPTS.begin(), CPTS.end(), t);
        if (f->first == "")
            throw ComponentError("Cannot add component of type " + t);
        return f->second;
    }
}
