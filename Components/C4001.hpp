//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4001 hpp file
//

#ifndef C4001_H_
#define C4001_H_

#include "ILinks.hpp"
#include "IComponent.hpp"
#include <string>
#include <vector>

class C4001 : public nts::IComponent
{
public:
    C4001(const std::string &name);
    ~C4001() {};
    virtual nts::Tristate Compute(size_t pin_num_this = 1);
    virtual void SetLink(size_t pin_num_this, nts::IComponent &component, size_t pin_num_target);
    virtual void Dump(void) const;
private:
    std::string _name;
    std::vector<ILinks *> _link;
};

#endif /* C4001_H_ */
