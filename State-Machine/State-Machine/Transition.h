#pragma once
#include <vector>
#include <string>
#include "Trigger.h"

class State;

class Transition
{
	public:
		State* End;
		Trigger Trig;
		Transition(State* S);
		Transition();
		
};

