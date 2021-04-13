#include "Fwoosh.hpp"

Fwoosh::Fwoosh(void)
	: ASpell("Fwoosh", "Fwooshed")
{
}

Fwoosh::Fwoosh(const Fwoosh& other)
	: ASpell(other.getName(), other.getEffects())
{
	*this = other;
}

Fwoosh::~Fwoosh(void)
{
}


Fwoosh&	Fwoosh::operator=(const Fwoosh& other)
{
	(void)other;
	return (*this);
}

ASpell*	Fwoosh::clone(void) const
{
	return (new Fwoosh());
}