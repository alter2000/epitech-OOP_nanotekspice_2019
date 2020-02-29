//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// ILinks hpp file
//

#ifndef ILINKS_H_
#define ILINKS_H_

#include "IComponent.hpp"

class ILinks
{
public:
    virtual ~ILinks() {}
    virtual nts::Tristate compute() = 0;
};

#endif /* ILINKS_H_ */
