//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// simple link hpp file
//

#ifndef SIMPLELINK_H_
#define SIMPLELINK_H_H

#include <utility>
#include "ILinks.hpp"

class SimpleLink : public ILinks
{
public:
    SimpleLink(nts::IComponent *component, size_t pin);
    virtual ~SimpleLink() {};
    virtual nts::Tristate compute();
private:
    std::pair<nts::IComponent *, size_t> in;
};

#endif /* SIMPLELINK_H_ */
