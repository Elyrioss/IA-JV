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

void State::AddTransition(Transition Transition,int index)
{
	Transitions[index] =Transition;
}

void State::AddTransition(State* S,Trigger* TransTrig,int index)
{
	Transition A(S,TransTrig);
	Transitions[index] = A;
}


