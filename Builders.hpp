/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef BUILDERS_HPP
#define BUILDERS_HPP

#include "IComponent.hpp"
#include "Primitives.hpp"

namespace nts
{
    std::function<ct(ctName)> mkComponent(ctType t);
}

#endif
