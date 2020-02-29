/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <fstream>
#include "Parsing.hpp"
#include "Errors.hpp"
#include "Components/Components.hpp"

namespace nts
{
    // TODO: find `any`:
    // SyntaxError
    // PinError (from ::setLink)
    // NameError (from ::setLink)
    ctls Parser::get()
    {
        if (c == 1) {
            std::cerr << "need a circuit file" << std::endl;
            exit(84);
        }
        std::ifstream fs{std::string{v[1]}};
        if (!fs.is_open())
            throw std::ifstream::failure("can't open" + std::string(v[1]));
        ctls cs{parseChipsets(fs)};

        parseLinks(cs);
        checkLast(cs, c, v);
        return cs;
    }

    bool Parser::getCleanLine(std::ifstream& fs, std::string& tmp)
    {
        if (fs.bad())
            throw std::ifstream::failure("Error reading file.");
        fs >> tmp;
        tmp = tmp.substr(0, tmp.find("#"));
        return tmp == "";
    }

    void Parser::checkOutput(const nts::IComponent& i)
    {
        if (i.getLinks().size() == 0)
            throw nts::PinError("Output has no links: " + i.Name());
    }

    void Parser::checkInputs(const nts::ctls& cs, int c, const char** v)
    {
        for (auto& i : cs) {
            if (i->getLinks().size() == 0) {
                throw nts::PinError("Input has no links: " + i->Name());
            }
        }
    }

    void Parser::checkLast(const nts::ctls& cs, int c, const char **v)
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

    void Parser::parseLinks(nts::ctls cs)
    {
    }

    nts::ctls Parser::parseChipsets(std::ifstream& fs)
    {
        nts::ctls cs{};
        return cs;
    }
}
