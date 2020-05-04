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
        auto f = std::find_if(CPTS.begin(), CPTS.end(),
                [&t] (ctPair a) { return a.first == t; });
        if (f->first == "")
            throw ComponentError("Cannot add component of type " + t);
        return f->second;
    }
}
