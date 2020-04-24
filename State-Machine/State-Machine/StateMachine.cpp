#include "StateMachine.h"


std::string StateMachine::CheckStates()
{
	for (Transition T : Current.Transitions) {
		if (T.Trig.Check()) {
			Current = *T.End;			
		}
	}
	if (Current.Sub != nullptr){
		return Current.Name +" ,SubState "+ Current.Sub->CheckStates();
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
