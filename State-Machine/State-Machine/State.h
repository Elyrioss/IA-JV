#pragma once
#include <vector>
#include <string>
#include "Transition.h"

class State
{
private:
	
public:
	std::vector<Transition> Transitions;
	std::string name;
	State(std::string Name, int NbTransitions);
	State();
	void AddTransition(Transition transition);
	void AddTransition(State* S);
};


