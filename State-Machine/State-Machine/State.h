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
	void AddTransition(Transition transition,int index);
	void AddTransition(State* S,Trigger* TransTrig,int index);
};


