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
#include "Components/Components.hpp"

extern const std::vector<nts::ctPair> nts::CPTS;

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

    ctls Parser::parseChipsets(std::ifstream& fs)
    {
        ctls cs{};

        for (std::string tmp; ; tmp.clear()) {
            if (getCleanTok(fs, tmp))
                continue;
            if (tmp != ".chipsets:")
                throw SyntaxError("Expected `.chipsets`, found: " + tmp);
            else
                break;
            if (fs.eof())
                break;
        }
        for (std::string tmp; ; tmp.clear()) {
            if (getCleanTok(fs, tmp))
                continue;
            if (tmp == ".links:")
                break;
            if (std::find_if(CPTS.begin(), CPTS.end(),
                    [&tmp] (ctPair a) { return a.first == tmp; })
                    != CPTS.end())
                throw ComponentError("Component does not exist: " + tmp);
            auto cur = createComponent(tmp);
                // throw SyntaxError("Expected `ctName`, found nothing");
            cs.push_back(cur);
            if (fs.eof() || tmp == ".links:")
                break;
        }
        return cs;
    }

    void Parser::parseLinks(const ctls& cs, std::ifstream& fs, int, const char**)
    {
        for (std::string tmp; ; tmp.clear())
            loadLink(cs, fs, tmp);
    }

    void Parser::checkLast(const ctls& cs, int c, const char **v)
    {
        for (const auto& i : cs) {
            if (i->Type() == "output" && dynamic_cast<Output&>(*i).getLinks().size() == 0)
                throw PinError("Output has no links: " + i->Name());
        }
        checkInputs(cs, c, v);
        std::function<std::string()> pAllDups = [&cs] {
            ctls dups{};
            for (auto i = cs.begin(); i != cs.end(); ++i)
                std::copy_if(cs.begin(), cs.end(), dups.begin()
                        , [i] (ct a) { return (*i)->Name() == a->Name(); });

            std::string all{""};
            for (auto i = dups.begin(); i != dups.end();
                    all += (*i)->Name() + ":", ++i);
            return all;
        };
        std::string err = pAllDups();
        if (err != "")
            throw NameError("Multiple components with identical names: " + err);
    }

    void Parser::checkInputs(const ctls& cs, int c, const char** v)
    {
        ctls ins;
        std::copy_if(cs.begin(), cs.end(), ins.begin(),
                [] (ct a) { return a->Type() == "input"; });
        if (ins.size() == 0)
            return;

        for (auto& i : ins)
            for (int ac = 0; ac < c; ++ac)
                if (i->Name() == v[ac])
                    i->_setIn(toState(std::stoi(v[ac])));
        ins.erase(std::remove_if(ins.begin(), ins.end(),
                    [] (ct a) { return a->compute() != UNDEFINED; }),
                ins.end());
        if (ins.size() != 0)
            throw ComponentError(std::string("Input") + ins[0]->Name() + " has no value");
    }

    bool Parser::getCleanTok(std::ifstream& fs, std::string& tmp)
    {
        if (fs.bad())
            throw std::ifstream::failure("Error reading file.");
        tmp.clear();
        if (!getline(fs, tmp))
            return true;
        // trim comments
        tmp = tmp.substr(0, tmp.find("#"));
        // trim spaces
        tmp = std::regex_replace(std::regex_replace(tmp,
                std::regex("^\\s+") , ""),
                std::regex("\\s+$"), "");
        return tmp == "";
    }

    void Parser::loadLink(const ctls& cs, std::ifstream& fs, std::string tmp)
    {
        if (getCleanTok(fs, tmp) || fs.eof())
            return;

        auto parseWord = [&fs] () {
            std::string tmp;
            fs >> tmp;

            std::pair<std::string, std::size_t> cpt{
                tmp.substr(0, tmp.find(':'))
              , std::stoi(tmp.substr(tmp.find(':') + 1))
            };
            return cpt;
        };

        std::pair<std::string, std::size_t> from = parseWord();
        std::pair<std::string, std::size_t> to = parseWord();
        auto froms = std::find_if(cs.begin(), cs.end(),
                [from] (ct a) { return a->Name() == from.first; });
        auto tos   = std::find_if(cs.begin(), cs.end(),
                [to]   (ct a) { return a->Name() == to.first; });
        if (froms == cs.end())
            throw NameError(std::string("No components with name ") + from.first);
        if (tos == cs.end())
            throw NameError(std::string("No components with name ") + to.first);
        (*froms)->setLink(from.second, *tos, to.second);
    }

    ct Parser::createComponent(const std::string& tmp)
    {
        auto type = tmp.substr(0, tmp.find('\t'));
        auto name = std::regex_replace(std::regex_replace(
                    tmp.substr(tmp.find('\t')),
                        std::regex("^\\s+") , ""),
                        std::regex("\\s+$"), "");
        auto i = mkComponent(type)(name);
        return i;
    }
}
