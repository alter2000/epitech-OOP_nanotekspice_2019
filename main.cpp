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
        std::cout << "> ";
        if (in.find("=") != std::string::npos)
            setInput(cs, in);
        if (in == "display")
            nts::display(cs);
        if (in == "dump")
            for (auto i = cs.begin(); i < cs.end(); ++i)
                (*i)->dump();
        if (in == "loop") {
            // TODO: register for SIGINT
        }
        if (in == "exit")
            break;
    }
}

int main(int c, const char **v)
{
    nts::Parser p(c, v);
    try {
        loop(p.get());
    } catch (const nts::Error& e) {
        std::cerr << e.show() << std::endl;
        return 84;
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
