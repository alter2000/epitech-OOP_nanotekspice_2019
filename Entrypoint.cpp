/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <algorithm>
#include "Entrypoint.hpp"

namespace nts
{
    void display(ctls& cs)
    {
        ctls os;
        for (auto i = cs.begin(); i < cs.end(); ++i)
            if ((*i)->Type() == "output") {
                os.push_back(std::move(*i));
            }
        std::sort(os.begin(), os.end(), [](const ct& a, const ct& b)
            { return a->Name() < b->Name(); });
        for (auto& i : os)
            i->dump();
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

    std::string fromState(TriState a)
    {
        switch (a) {
            case TRUE:      return "T";
            case FALSE:     return "F";
            case UNDEFINED: return "U";
        }
        return "U";
    }
}
