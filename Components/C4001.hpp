//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4001 hpp file
//

#ifndef C4001_H_
#define C4001_H_

#include <string>
#include <vector>
#include "../Primitives/Primitives.hpp"
#include "../IComponent.hpp"

namespace nts
{
    class C4001 : public IComponent
    {
        public:
            C4001(const std::string &name);
            ~C4001() {};
            nts::TriState compute(size_t pin = 1);
            void setLink(std::size_t pin, ct component, std::size_t target);
            ctls getLinks() const;
            void dump(void) const;
            ctName Name() const;
            ctType Type() const;
        private:
            const std::string _type = "C4001";
            const std::string _name;
            /* std::vector<std::shared_ptr<Primitive>> _link; */
    };
}

#endif /* C4001_H_ */
