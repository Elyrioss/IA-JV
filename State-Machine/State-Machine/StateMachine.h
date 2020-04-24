#pragma once
#include <vector>
#include <string>

#include "State.h"
#include "Transition.h"

class StateMachine
{
	public:
		State Current;
		std::vector<State> States;
		std::string CheckStates();
		StateMachine();
		StateMachine(std::vector<State> states);
};

