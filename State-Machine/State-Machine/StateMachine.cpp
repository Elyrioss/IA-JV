#include "StateMachine.h"


std::string StateMachine::CheckStates()
{
	for (Transition T : Current.Transitions) {
		if (T.Trig.Check()) {
			Current = *T.End;
			return Current.Name;
		}
	}
	return Current.Name;
}

StateMachine::StateMachine()
{
	
}

StateMachine::StateMachine(std::vector<State> states)
{
	States = states;
	Current = states[0];
}
