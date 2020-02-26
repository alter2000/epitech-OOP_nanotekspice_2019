/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <fstream>
#include "Entrypoint.hpp"

static void checkLast(const nts::ctls& cs)
{
    // TODO:
    // find `any`:
    // unlinked element
    // unknown input
    // name error
}

static bool getCleanLine(std::ifstream& fs, std::string& tmp)
{
    if (fs.bad())
        throw std::ifstream::failure("Error reading");
    fs >> tmp;
    tmp = tmp.substr(0, tmp.find("#"));
    return tmp == "";
}

static void parseLinks(nts::ctls cs)
{
}

static nts::ctls parseChipsets(std::ifstream& fs)
{
    nts::ctls cs{};
    return cs;
}

namespace nts {
        // TODO:
        // find `any`:
        // SyntaxError
        // PinError (from ::setLink)
        // NameError (from ::setLink)
    ctls parse(int c, const char** v)
    {
        if (c == 1) {
            std::cerr << "need a circuit file" << std::endl;
            exit(84);
        }
        ctls cs;
        std::ifstream fs{std::string{v[1]}};
        bool chipsets = false;
        bool links = false;

        if (!fs.is_open())
            throw std::ifstream::failure("can't open" + std::string(v[1]));

        for (std::string cur; ; cur.clear()) {
            if (getCleanLine(fs, cur))
                continue;
            if (cur == ".chipsets") {
                cs = parseChipsets(fs);
                chipsets = true;
            }
            if (cur == ".links") {
                parseLinks(cs);
                links = true;
            }
        }
        if (!chipsets)
            throw SyntaxError("No `.chipsets` section.");
        if (!links)
            throw SyntaxError("No `.links` section.");
        checkLast(cs);
        return cs;
    }
}
