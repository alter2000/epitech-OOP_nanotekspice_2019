/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef BOOLS_HPP_
#define BOOLS_HPP_

#include "Primitives.hpp"

namespace nts
{
    class True : public Primitive, public IComponent
    {
        public:
            True(ctName n) : n{n} {}
            ~True() {}
            TriState get() const { return this->operator()(); }
            TriState operator()() const { return TRUE; }

            TriState compute(std::size_t) { return this->operator()(); };
            void setLink(std::size_t, ct, std::size_t) {}
            void dump() const
            { std::cout << n << "=" << this->operator()() << std::endl; }
            ctName Name() const { return n; }
            ctType Type() const { return _t; }
        private:
            const std::string _t = "true";
            const std::string n;
    };

    class False : public Primitive, public IComponent
    {
        public:
            False(ctName n) : n{n} {}
            ~False() {}
            TriState get() const { return this->operator()(); }
            TriState operator()() const { return FALSE; }

            TriState compute(std::size_t) { return this->operator()(); }
            void setLink(std::size_t, ct, std::size_t) {}
            void dump() const
            { std::cout << n << "=" << this->operator()() << std::endl; }
            ctName Name() const { return n; }
            ctType Type() const { return _t; }
        private:
            const std::string _t = "false";
            const std::string n;
    };

}

#endif
