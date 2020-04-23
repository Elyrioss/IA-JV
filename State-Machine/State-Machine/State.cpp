#include "State.h"

State::State(std::string Name, int NbTransitions)
{
	name = Name;
	Transitions = std::vector<Transition>(NbTransitions);
}

State::State()
{
	name = "Default";
	Transitions = std::vector<Transition>(0);
}

void State::AddTransition(Transition Transition)
{
	Transitions.push_back(Transition);
}

void State::AddTransition(State* S)
{
	Transition A(S);
	Transitions.push_back(A);
}
