/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef PRIMITIVES_HPP_
#define PRIMITIVES_HPP_

#include "../IComponent.hpp"

namespace nts
{
    class Primitive
    {
        public:
            virtual ~Primitive() {}
            virtual TriState get() const { return UNDEFINED; };
    };

    class Clock : public Primitive, public IComponent
    {
        public:
            Clock(ctName n) : n{n}, a{FALSE} {}
            ~Clock() {}
            TriState get() const { return a; }
            TriState operator()();

            TriState compute(std::size_t) { return this->operator()(); };
            void setLink(std::size_t, ct, std::size_t) {};
            void dump() const
            { std::cout << n << "=" << a << std::endl; }
            ctName Name() const { return n; }
            ctType Type() const { return _t; };
        private:
            const std::string _t = "clock";
            const std::string n;
            TriState a;
    };
}

#endif
