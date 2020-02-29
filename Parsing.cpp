/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <fstream>
#include <regex>
#include "Errors.hpp"
#include "Builders.hpp"
#include "Parsing.hpp"

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

        parseLinks(cs, fs, c, v);
        checkLast(cs, c, v);
        return cs;
    }

    bool Parser::getCleanTok(std::ifstream& fs, std::string& tmp)
    {
        if (fs.bad())
            throw std::ifstream::failure("Error reading file.");
        tmp.clear();
        fs >> tmp;
        tmp = tmp.substr(0, tmp.find("#"));
        // trim spaces
        std::regex_replace(std::regex_replace(tmp,
                           std::regex("^\\s+") , ""),
                           std::regex("\\s+$"), "");
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
        // unlinked element#
        // unknown input#
        // name error#
        for (const auto& i : cs) {
            nts::ctType it = i->Type();
            if (it == "out")
                checkOutput(*i.get());
        }
        checkInputs(cs, c, v);
        std::function<std::string()> pAllDups = [&cs] {
            ctls dups{};
            for (auto i = cs.begin(); i != cs.end(); ++i) {
                std::copy_if(cs.begin()
                        , cs.end()
                        , dups.begin()
                        , [i] (ct a) { return (*i)->Name() == a->Name(); });
            }

            std::string all{""};
            for (auto i = dups.begin(); i != dups.end(); ++i) {
                all += (*i)->Name() + ":";
            }
            return all;
        };
        std::string err = pAllDups();
        if (err != "")
            throw NameError("Multiple components with identical names: " + err);
    }

    void Parser::parseLinks(const nts::ctls& cs, std::ifstream& fs, int c, const char** v)
    {
    }

    nts::ctls Parser::parseChipsets(std::ifstream& fs)
    {
        nts::ctls cs{};

        for (std::string tmp; ; tmp.clear()) {
            if (getCleanTok(fs, tmp))
                continue;
            if (tmp != ".chipsets")
                throw SyntaxError("Expected `.chipsets`, found: " + tmp);
            auto cur = mkComponent(tmp);
            if (getCleanTok(fs, tmp))
                throw SyntaxError("Expected `ctName`, found nothing");
            cs.push_back(cur(tmp));
        }
        return cs;
    }
}
