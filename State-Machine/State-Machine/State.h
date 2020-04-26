#pragma once
#include <vector>
#include <string>
#include "Transition.h"

class StateMachine;

class State
{
private:
	
public:

	std::vector<Transition> Transitions;
	std::string Name;
	bool IsFinal;
	State(std::string Name, int NbTransitions,bool final);
	State(std::string Name, int NbTransitions, bool final,StateMachine* sub);
	State();
	void AddTransition(Transition* transition,int index);
	void AddTransition(State* S,Trigger* TransTrig,int index);
	void AddSubStateMachine(StateMachine* sub,Transition toSub1);

	StateMachine* Sub;
	Transition ToSub1;
};


