#pragma once

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
public:
	Fwoosh(void);
	Fwoosh(const Fwoosh& other);
	virtual ~Fwoosh(void);

	Fwoosh&				operator=(const Fwoosh& other);

	virtual ASpell*		clone(void) const;
};