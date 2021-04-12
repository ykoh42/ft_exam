#pragma once

#include <iostream>

class Warlock
{
public:
	Warlock(const std::string& name, const std::string& title);
	~Warlock(void);

	const std::string&	getName(void) const;
	const std::string&	getTitle(void) const;
	void				setName(const std::string& name);
	void				setTitle(const std::string& title);
	void				introduce(void) const;

private:
	Warlock(void);
	Warlock(const Warlock& other);

	Warlock&			operator=(const Warlock& other);

	std::string			name;
	std::string			title;
};