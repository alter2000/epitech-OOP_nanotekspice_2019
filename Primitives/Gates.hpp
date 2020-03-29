/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef GATES_HPP_
#define GATES_HPP_

#include "Primitives.hpp"

namespace nts
{
    class Not : public Primitive
    {
        public:
            Not(TriState a) : a{a} {}
            Not(Primitive a) : a{a.get()} {}
            ~Not() {}
            TriState operator()() const;
            TriState get() const { return a; }
        private:
            TriState a;
    };

    class And : public Primitive
    {
        public:
            And(TriState a, TriState b) : a{a}, b{b} {}
            And(TriState a, Primitive b) : a{a}, b{b.get()} {}
            And(Primitive a, TriState b) : a{a.get()}, b{b} {}
            And(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            ~And() {}
            TriState operator()(TriState a, TriState b) const;
            TriState get() const { return this->operator()(a, b); }
        private:
            TriState a;
            TriState b;
    };

    class NAnd : public Primitive
    {
        public:
            NAnd(TriState a, TriState b) : a{a}, b{b} {}
            NAnd(TriState a, Primitive b) : a{a}, b{b.get()} {}
            NAnd(Primitive a, TriState b) : a{a.get()}, b{b} {}
            NAnd(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            ~NAnd() {}
            TriState get() const { return this->operator()(a, b); }
            TriState operator()(TriState a, TriState b) const;
        private:
            TriState a;
            TriState b;
    };

    class Or : public Primitive
    {
        public:
            Or(TriState a, TriState b) : a{a}, b{b} {}
            Or(TriState a, Primitive b) : a{a}, b{b.get()} {}
            Or(Primitive a, TriState b) : a{a.get()}, b{b} {}
            Or(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            ~Or() {}
            TriState get() const { return this->operator()(a, b); }
            TriState operator()(TriState a, TriState b) const;
        private:
            TriState a;
            TriState b;
    };

    class NOr : public Primitive
    {
        public:
            NOr(TriState a, TriState b) : a{a}, b{b} {}
            NOr(TriState a, Primitive b) : a{a}, b{b.get()} {}
            NOr(Primitive a, TriState b) : a{a.get()}, b{b} {}
            NOr(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            ~NOr() {}
            TriState get() const { return this->operator()(a, b); }
            TriState operator()(TriState a, TriState b) const;
        private:
            TriState a;
            TriState b;
    };

    class XOr : public Primitive
    {
        public:
            XOr(TriState a, TriState b) : a{a}, b{b} {}
            XOr(TriState a, Primitive b) : a{a}, b{b.get()} {}
            XOr(Primitive a, TriState b) : a{a.get()}, b{b} {}
            XOr(Primitive a, Primitive b) : a{a.get()}, b{b.get()} {}
            ~XOr() {}
            TriState get() const { return this->operator()(a, b); }
            TriState operator()(TriState a, TriState b) const;
        private:
            TriState a;
            TriState b;
    };

}

#endif
