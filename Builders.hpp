/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef BUILDERS_HPP
#define BUILDERS_HPP

#include <functional>
#include "IComponent.hpp"
#include "Primitives/Primitives.hpp"

namespace nts
{
    std::function<ct(std::string)> mkComponent(ctType t);
    static const std::vector<std::string> CPTS = {
        "input" , "output" , "true" , "false" , "clock" , "4001" , "4008" ,
        "4011"  , "4013"   , "4017" , "4030"  , "4040"  , "4069" , "4071" ,
        "4081"  , "4094"   , "4514" , "4801"  , "2716"  , ""
};

}

#endif
