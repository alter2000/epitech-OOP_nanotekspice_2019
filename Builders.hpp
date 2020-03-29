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
#include "Components/Components.hpp"
#include "Primitives/Primitives.hpp"

namespace nts
{
    using ctPair = std::pair<std::string, std::function<ct(std::string)>>;

    std::function<ct(std::string)> mkComponent(ctType t);
    static const std::vector<ctPair>
        CPTS = {
            ctPair("input",  [] (ctName n) { return ct(new Input(n)); }),
            ctPair("output", [] (ctName n) { return ct(new Output(n)); }),
            ctPair("true",   [] (ctName n) { return ct(new True(n)); }),
            ctPair("false",  [] (ctName n) { return ct(new False(n)); }),
            ctPair("clock",  [] (ctName n) { return ct(new Clock(n)); }),
            ctPair("4001",   [] (ctName n) { return ct(new C4001(n)); }),
            // ctPair("4008",   [] (ctName n) { return ct(new C4008(n)); }),
            // ctPair("4011",   [] (ctName n) { return ct(new C4011(n)); }),
            // ctPair("4013",   [] (ctName n) { return ct(new C4013(n)); }),
            // ctPair("4017",   [] (ctName n) { return ct(new C4017(n)); }),
            // ctPair("4030",   [] (ctName n) { return ct(new C4030(n)); }),
            // ctPair("4040",   [] (ctName n) { return ct(new C4040(n)); }),
            // ctPair("4069",   [] (ctName n) { return ct(new C4069(n)); }),
            // ctPair("4071",   [] (ctName n) { return ct(new C4071(n)); }),
            // ctPair("4081",   [] (ctName n) { return ct(new C4081(n)); }),
            // ctPair("4094",   [] (ctName n) { return ct(new C4094(n)); }),
            // ctPair("4514",   [] (ctName n) { return ct(new C4514(n)); }),
            // ctPair("4801",   [] (ctName n) { return ct(new C4801(n)); }),
            // ctPair("2716",   [] (ctName n) { return ct(new C2716(n)); }),
            ctPair("", [] (ctName) { return nullptr; }),
};

}

#endif
