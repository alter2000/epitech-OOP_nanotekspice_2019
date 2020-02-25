/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <exception>
#include "IComponent.hpp"

namespace nts
{
    class Error : public std::exception
    {
        public:
            virtual ~Error() {}
            virtual std::string show() = 0;
    };

    class SyntaxError: public Error
    {
        public:
            SyntaxError(const std::string& n = "syntax error") : s{n} {};
        private:
            std::string s;
    };

    class ComponentError: public Error
    {
        public:
            ComponentError(const std::string& n = "component error") : s{n} {};
        private:
            std::string s;
    };

    class PinError: public Error
    {
        public:
            PinError(const std::string& n = "pin error") : s{n} {};
        private:
            std::string s;
    };

    class LinkError: public Error
    {
        public:
            LinkError(const std::string& n = "link error") : s{n} {};
        private:
            std::string s;
    };

    class NameError: public Error
    {
        public:
            NameError(const std::string& n = "name error") : s{n} {};
        private:
            std::string s;
    };
}

#endif
