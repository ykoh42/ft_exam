#include "Warlock.hpp"

Warlock::Warlock(const std::string& name, const std::string& title)
	: name(name)
	, title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock(void)
{
	std::cout << name << ": My job here is done!" << std::endl;
	for (std::list<ASpell*>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		delete *it;
		lst.erase(it);
	}
}

const std::string&	Warlock::getName(void) const
{
	return (name);
}

const std::string&	Warlock::getTitle(void) const
{
	return (title);
}

void				Warlock::setName(const std::string& name)
{
	this->name = name;
}

void				Warlock::setTitle(const std::string& title)
{
	this->title = title;
}

void				Warlock::introduce(void) const
{
	std::cout << name << ": I am " << name << ", " << title << "!" << std::endl;
}

void				Warlock::learnSpell(ASpell* spell)
{
	if (spell)
	{
		for (std::list<ASpell*>::iterator it = lst.begin(); it != lst.end(); ++it)
		{
			if ((*it)->getName().compare(spell->getName()) == 0)
			{
				return ;
			}
		}
		lst.push_back(spell->clone());
	}
}

void				Warlock::forgetSpell(const std::string name)
{
	for (std::list<ASpell*>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		if ((*it)->getName().compare(name) == 0)
		{
			delete *it;
			lst.erase(it);
			return ;
		}
	}
}

void				Warlock::launchSpell(const std::string name, const ATarget& target)
{
	for (std::list<ASpell*>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		if ((*it)->getName().compare(name) == 0)
		{
			(*it)->launch(target);
			return ;
		}
	}
}
