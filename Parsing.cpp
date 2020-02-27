/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <fstream>
#include "Entrypoint.hpp"
#include "Errors.hpp"
#include "Components/Components.hpp"

static void checkOutput(const nts::IComponent& i)
{
    if (std::static_cast<nts::Output*>(i).getLinks().length() == 0)
        throw nts::PinError("Output has no links: " + i.Name());
}

static void checkInputs(const nts::ctls& cs, int c, const char** v)
{
    for (auto& i : cs) {
        if (std::static_cast<nts::Input*>(i)->getLinks().length() == 0) {
            throw nts::PinError("Input has no links: " + i->Name());
        }
    }
}

static void checkLast(const nts::ctls& cs, int c, const char **v)
{
    // TODO:
    // find `any`:
    // unlinked element
    // unknown input
    // name error
    for (auto&& i : cs) {
        nts::ctType it = i->Type();
        if (it == "out")
            checkOutput(*i.get());
    }
    checkInputs(cs, c, v);
}

static bool getCleanLine(std::ifstream& fs, std::string& tmp)
{
    if (fs.bad())
        throw std::ifstream::failure("Error reading file.");
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
        // TODO: find `any`:
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
        checkLast(cs, c, v);
        return cs;
    }
}
