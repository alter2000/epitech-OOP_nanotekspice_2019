/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include "Primitives.hpp"

namespace nts
{
    TriState Clock::operator()()
    {
        TriState r{UNDEFINED};

        switch (a) {
            case TRUE:
                r = a;
                a = FALSE;
                return r;
            case FALSE:
                r = a;
                a = TRUE;
                return r;
            case UNDEFINED:
                return r;
        }
        return r;
    }
}
