#include "State.h"

State::State(bool Loop, std::string Name, int NbTransitions)
{
	loop = Loop;
	name = Name;
	_transitions = std::vector<Transitions>(NbTransitions);
}

State::State()
{
	loop = false;
	name = "Default";
	_transitions = std::vector<Transitions>(0);
}

void State::AddTransition(Transitions Transition)
{
	_transitions.push_back(Transition);
}
