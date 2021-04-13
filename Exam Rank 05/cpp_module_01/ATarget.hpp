#pragma once

#include <iostream>

#include "ASpell.hpp"
class ASpell;

class ATarget
{
public:
	ATarget(const std::string& type);
	ATarget(const ATarget& other);
	virtual ~ATarget(void);

	ATarget&			operator=(const ATarget& other);

	const std::string&	getType(void) const;
	virtual ATarget*	clone(void) const = 0;
	void				getHitBySpell(const ASpell& spell) const;

private:
	ATarget(void);
	
	std::string			type;
};