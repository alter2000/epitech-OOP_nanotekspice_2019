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
    auto mkComponent(ctType t, ctName n) -> decltype([](){ return ct{nullptr}; });
}

#endif
