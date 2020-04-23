#pragma once
#include <vector>
#include <string>
#include "Transitions.h"

class State
{
private:
	bool loop;
	std::vector<Transitions> _transitions;
	std::string name;
public:
	State(bool Loop, std::string Name, int NbTransitions);
	State();
	void AddTransition(Transitions Transition);
};


