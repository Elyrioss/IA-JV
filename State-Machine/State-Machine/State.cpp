#include "State.h"

State::State(std::string name, int NbTransitions,bool final)
{
	Name = name;
	Transitions = std::vector<Transition>(NbTransitions);
	IsFinal = final;
}

State::State()
{
	Name = "Default";
	Transitions = std::vector<Transition>(0);
	IsFinal = false;
}

void State::AddTransition(Transition* Transition,int index)
{
	Transitions[index] =*Transition;
}

void State::AddTransition(State* S,Trigger* TransTrig,int index)
{
	Transition A(S,TransTrig);
	Transitions[index] = A;
}


