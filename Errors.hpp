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
            virtual const char* show() const noexcept;
    };

    class SyntaxError: public Error
    {
        public:
            SyntaxError(const std::string& n = "Syntax error") : s{n} {};
            ~SyntaxError() {}
            virtual const char* show() const noexcept { return s.c_str(); };
        private:
            std::string s;
    };

    class ComponentError: public Error
    {
        public:
            ComponentError(const std::string& n = "Component error") : s{n} {};
            ~ComponentError() {}
            virtual const char* show() const noexcept { return s.c_str(); };
        private:
            std::string s;
    };

    class PinError: public Error
    {
        public:
            PinError(const std::string& n = "Pin error") : s{n} {};
            ~PinError() {}
            virtual const char* show() const noexcept { return s.c_str(); };
        private:
            std::string s;
    };

    class LinkError: public Error
    {
        public:
            LinkError(const std::string& n = "Link error") : s{n} {};
            ~LinkError() {}
            virtual const char* show() const noexcept { return s.c_str(); };
        private:
            std::string s;
    };

    class NameError: public Error
    {
        public:
            NameError(const std::string& n = "Name error") : s{n} {};
            ~NameError() {}
            virtual const char* show() const noexcept { return s.c_str(); };
        private:
            std::string s;
    };
}

#endif
