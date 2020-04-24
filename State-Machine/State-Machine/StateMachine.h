#pragma once
#include <vector>
#include <string>

#include "State.h"
#include "Transition.h"

class StateMachine
{
	public:
		State Current;
		State AnyState;
		Transition ToAnyState;
		std::vector<State> States;
		std::string CheckStates();
		StateMachine();
		StateMachine(std::vector<State> states);
		StateMachine(std::vector<State> states,State* any,Transition* toAny);
};

