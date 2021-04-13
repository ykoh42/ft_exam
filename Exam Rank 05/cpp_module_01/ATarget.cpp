#include "ATarget.hpp"

ATarget::ATarget(void)
{
}

ATarget::ATarget(const std::string& type)
	: type(type)
{
}

ATarget::ATarget(const ATarget& other)
{
	*this = other;
}

ATarget::~ATarget(void)
{
}


ATarget&			ATarget::operator=(const ATarget& other)
{
	type = other.type;
	return (*this);
}

const std::string&	ATarget::getType(void) const
{
	return (type);
}

void				ATarget::getHitBySpell(const ASpell& spell) const
{
	std::cout << type << " has been " << spell.getEffects() << "!" << std::endl;
}
