/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <algorithm>
#include "Builders.hpp"
#include "Components/Components.hpp"
#include "Errors.hpp"

namespace nts
{
    std::function<ct(std::string)> mkComponent(ctType t)
    {
        auto f = std::find(CPTS.begin(), CPTS.end(), t);
        if (*f == "")
            throw ComponentError("Unknown component type: " + t);
        if (*f == std::string("input"))
            return [](ctName n) { return ct(new Input(n)); };
        if (*f == std::string("output"))
            return [](ctName n) { return ct(new Output(n)); };
        if (*f == std::string("true"))
            return [](ctName n) { return ct(new True(n)); };
        if (*f == std::string("false"))
            return [](ctName n) { return ct(new False(n)); };
        if (*f == std::string("clock"))
            return [](ctName n) { return ct(new Clock(n)); };
        if (*f == std::string("4001"))
            return [](ctName n) { return ct(new C4001(n)); };
        // if (*f == std::string("4008"))
        //     return [](ctName n) { return ct(new C4008(n)); };
        // if (*f == std::string("4011"))
        //     return [](ctName n) { return ct(new C4011(n)); };
        // if (*f == std::string("4013"))
        //     return [](ctName n) { return ct(new C4013(n)); };
        // if (*f == std::string("4017"))
        //     return [](ctName n) { return ct(new C4017(n)); };
        // if (*f == std::string("4030"))
        //     return [](ctName n) { return ct(new C4030(n)); };
        // if (*f == std::string("4040"))
        //     return [](ctName n) { return ct(new C4040(n)); };
        // if (*f == std::string("4069"))
        //     return [](ctName n) { return ct(new C4069(n)); };
        // if (*f == std::string("4071"))
        //     return [](ctName n) { return ct(new C4071(n)); };
        // if (*f == std::string("4081"))
        //     return [](ctName n) { return ct(new C4081(n)); };
        // if (*f == std::string("4094"))
        //     return [](ctName n) { return ct(new C4094(n)); };
        // if (*f == std::string("4514"))
        //     return [](ctName n) { return ct(new C4514(n)); };
        // if (*f == std::string("4801"))
        //     return [](ctName n) { return ct(new C4801(n)); };
        // if (*f == std::string("2716")) {
        //     // TODO: add rom?
        //     return [](ctName n) { return ct(new C2716(n)); };
        // }
        return [] (ctName) { return ct(); };
    }
}
