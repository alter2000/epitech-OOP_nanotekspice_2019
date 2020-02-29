/*
** EPITECH PROJECT, 2020
** OOP_nanotekspice_2019
** File description:
** automated desc ftw
*/

#ifndef ICOOMPONENT_HPP_
#define ICOOMPONENT_HPP_

#include <iostream>
#include <memory>
#include <vector>

namespace nts
{
    enum TriState {
        UNDEFINED = (-true),
        TRUE = true,
        FALSE = false,
    };

    class IComponent;
    using ctName = const std::string&;
    using ctType = const std::string&;
    using ct = std::shared_ptr<IComponent>;
    using ctls = std::vector<ct>;

    class IComponent
    {
        public:
            virtual ~IComponent() = default;

            virtual nts::TriState compute(std::size_t pin = 1) = 0;
            virtual void setLink(std::size_t pin, IComponent& other, std::size_t otherPin) = 0;
            virtual void dump() const = 0;
            virtual void _setIn(nts::TriState a) = 0;
            virtual ctName Name() const = 0;
            virtual ctType Type() const = 0;
            virtual ctls getLinks() const = 0;
    };
}

#endif
