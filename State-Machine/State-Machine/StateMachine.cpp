#include "StateMachine.h"


std::string StateMachine::CheckStates()
{
	for (Transition T : Current.Transitions) {
		if (T.Trig.Check()) {
			Current = *T.End;
			return Current.name;
		}
	}
	return Current.name;
}

StateMachine::StateMachine()
{
	
}

StateMachine::StateMachine(std::vector<State> states)
{
	States = states;
	Current = states[0];
}
