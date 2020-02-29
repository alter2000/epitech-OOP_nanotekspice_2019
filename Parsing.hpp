/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef PARSING_HPP_
#define PARSING_HPP_

#include "Entrypoint.hpp"

namespace nts
{
    class Parser
    {
        public:
            Parser(int c, const char **v) : c{c}, v{v} {}
            ~Parser() {};
            ctls get();
        private:
            const int c;
            const char **v;
            nts::ctls parseChipsets(std::ifstream& fs);
            void parseLinks(nts::ctls cs);
            bool getCleanLine(std::ifstream& fs, std::string& tmp);
            void checkLast(const nts::ctls& cs, int c, const char **v);
            void checkInputs(const nts::ctls& cs, int c, const char** v);
            void checkOutput(const nts::IComponent& i);
    };
}

#endif
