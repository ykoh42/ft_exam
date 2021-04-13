#include "Dummy.hpp"

Dummy::Dummy(void)
	: ATarget("Target Practice Dummy")
{
}

Dummy::Dummy(const Dummy& other)
	: ATarget(other.getType())
{
	*this = other;
}

Dummy::~Dummy(void)
{
}


Dummy&	Dummy::operator=(const Dummy& other)
{
	(void)other;
	return (*this);
}

ATarget*	Dummy::clone(void) const
{
	return (new Dummy());
}