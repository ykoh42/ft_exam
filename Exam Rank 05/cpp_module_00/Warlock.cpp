#include "Warlock.hpp"

Warlock::Warlock(void)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const std::string& name, const std::string& title)
	: name(name)
	, title(title)
{
	std::cout << name << ": This looks like another boring day." << std::endl;
}

Warlock::Warlock(const Warlock& other)
{
	*this = other;
}

Warlock::~Warlock(void)
{
	std::cout << name << ": My job here is done!" << std::endl;
}

Warlock&			Warlock::operator=(const Warlock& other)
{
	name = other.name;
	title = other.title;
	return (*this);
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