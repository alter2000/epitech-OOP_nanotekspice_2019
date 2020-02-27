/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <array>
#include <algorithm>
#include "IComponent.hpp"
#include "Errors.hpp"

static const std::array<std::string, 14> CPTS = {
    "4001",
    "4008",
    "4011",
    "4013",
    "4017",
    "4030",
    "4040",
    "4069",
    "4071",
    "4081",
    "4094",
    "4514",
    "4801",
    "2716",
};

namespace nts
{
    auto mkComponent(ctType t, ctName n)
    {
        auto f = std::find(CPTS.begin(), CPTS.end(), t);
        if (f == nullptr)
            throw ComponentError("Unknown component type: " + t);
        if (*f == std::string("4001"))
            return [n]() { return C_x(n); }
        if (*f == std::string("4008"))
            return [n]() { return C_y(n); }
        if (*f == std::string("4011"))
            return [n]() { return C_z(n); }
        if (*f == std::string("4013"))
        if (*f == std::string("4017"))
        if (*f == std::string("4030"))
        if (*f == std::string("4040"))
        if (*f == std::string("4069"))
        if (*f == std::string("4071"))
        if (*f == std::string("4081"))
        if (*f == std::string("4094"))
        if (*f == std::string("4514"))
        if (*f == std::string("4801"))
        if (*f == std::string("2716")) {
            // TODO: add rom?
        }
    }
}
