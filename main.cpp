/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#include <iostream>
#include <algorithm>
#include "Entrypoint.hpp"

void loop(nts::ctls cs)
{
    std::string in;
    std::cin >> in;

    while (true) {
        if (in.find("=") != std::string::npos)
            setInput(cs, in);
        if (in == "display")
            display(cs);
        if (in == "dump")
            for (auto i = cs.begin(); i < cs.end(); ++i)
                (*i)->dump();
        if (in == "loop") {
            // register for SIGINT
        }
        if (in == "exit")
            break;
    }
}

int main(int c, const char **v)
{
    if (c == 1) {
        std::cerr << "need a circuit file" << std::endl;
        return 84;
    }
    nts::ctls cs = nts::parse(v);
    try {
        loop(cs);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
