#include "StateMachine.h"


std::string StateMachine::CheckStates()
{


	for (Transition T : Current.Transitions) {
		if (T.Trig.Check()) {
			Current = *T.End;			
		}
	}
	/*
	if (Current.Sub != nullptr){
		if (Current.ToSub1.Trig.Check()) {
			Current = Current.Sub->Current;
		}		
		//return Current.Name +" ,SubState "+ Current.Sub->CheckStates();
	}
	*/
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

StateMachine::StateMachine(std::vector<State> states, State* any, Transition* toAny)
{
	States = states;
	Current = states[0];
	AnyState = *any;
	ToAnyState = *toAny;
}
