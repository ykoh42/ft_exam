#pragma once

#include "ATarget.hpp"

class Dummy : public ATarget
{
public:
	Dummy(void);
	Dummy(const Dummy& other);
	virtual ~Dummy(void);

	Dummy&					operator=(const Dummy& other);

	virtual ATarget*		clone(void) const;
};