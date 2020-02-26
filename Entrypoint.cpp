/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <algorithm>
#include "Entrypoint.hpp"

static void checkLast(const nts::ctls& cs)
{
    // TODO:
    // find `any`:
    // unlinked element
    // unknown input
    // name error
}

namespace nts
{
    ctls parse(const char** path)
    {
        ctls cs;
        // TODO: all
        checkLast(cs);
        return cs;
    }

    void display(const ctls& cs)
    {
        // TODO: find all outputs and make sorted linear<uptr> out of them
    }

    void setInput(const ctls& cs, const std::string& in)
    {
        std::size_t idx = in.find("=");
        std::string k = in.substr(0, idx);
        std::string v = in.substr(idx + 1);

        auto cur = std::find_if(cs.begin(), cs.end(),
                [&k] (const ct& a) { return a->Name() == k; });
        if (*cur == nullptr)
            throw ComponentError("Unknown input: " + k);
        (*cur)->_setIn(toState(v));
    }

    TriState toState(const std::string& v)
    {
        if (v == "0")
            return FALSE;
        else if (v == "1")
            return TRUE;
        else
            throw ComponentError("Input value is unknown: " + v);
    }

    TriState toState(std::size_t v)
    {
        switch (v) {
            case 0: return FALSE;
            case 1: return TRUE;
            default:
                    throw ComponentError(std::string("Input value is unknown: " ) + std::to_string(v));
        }
    }
}
