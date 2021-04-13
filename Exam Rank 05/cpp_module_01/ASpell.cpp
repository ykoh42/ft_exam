#include "ASpell.hpp"

ASpell::ASpell(void)
{
}

ASpell::ASpell(const std::string& name, const std::string& effects)
	: name(name)
	, effects(effects)
{
}

ASpell::ASpell(const ASpell& other)
{
	*this = other;
}

ASpell::~ASpell(void)
{
}

ASpell&				ASpell::operator=(const ASpell& other)
{
	name = other.name;
	effects = other.effects;
	return (*this);
}

const std::string&	ASpell::getName(void) const
{
	return (name);
}

const std::string&	ASpell::getEffects(void) const
{
	return (effects);
}

void				ASpell::launch(const ATarget& target) const
{
	target.getHitBySpell(*this);
}
