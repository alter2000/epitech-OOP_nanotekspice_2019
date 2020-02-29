/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include "Primitives.hpp"

namespace nts
{
    TriState Not::operator()() const
    {
        switch (a) {
            case UNDEFINED: return UNDEFINED;
            case TRUE:      return FALSE;
            case FALSE:     return TRUE;
        }
        return UNDEFINED;
    }

    TriState Clock::operator()()
    {
        TriState r;

        switch (a) {
            case TRUE:
                r = a;
                a = FALSE;
            case FALSE:
                r = a;
                a = TRUE;
            case UNDEFINED:
                return a;
        }
        return r;
    }

    TriState And::operator()(TriState a, TriState b) const
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return (a == b) ? TRUE : FALSE;
    }

    TriState NAnd::operator()(TriState a, TriState b) const
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return Not(And(a, b)).get();
    }

    TriState Or::operator()(TriState a, TriState b) const
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return (a == TRUE || b == TRUE) ? TRUE : FALSE;
    }

    TriState NOr::operator()(TriState a, TriState b) const
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return Not(Or(a, b)).get();
    }

    TriState XOr::operator()(TriState a, TriState b) const
    {
        if (a == UNDEFINED || b == UNDEFINED)
            return UNDEFINED;
        return (a == b) ? FALSE : TRUE;
    }
}
