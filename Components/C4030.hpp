//
// EPITECH PROJECT, 2020
// EPITECH 2020
// File description:
// C4030 hpp file
//

#ifndef C4030_H_
#define C4030_H_

namespace nts
{
    class C4030 : public IComponent
    {
    public:
	C4030(const std::string &name);
	~C4030() {};
	nts::TriState compute(size_t pin = 1);
	void setLink(std::size_t pin, IComponent &component, std::size_t target);
	void dump(void) const;
	void _setIn(nts::TriState a);
	ctName Name() const;
	ctType Type() const;
    private:
	const std::string _type;
	ctName _name;
	ctls _link;
    };
}

#endif /* C4030_H_ */
