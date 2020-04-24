#include "Transition.h"


Transition::Transition(State* S, Trigger* TransTrigg) {
	End = S;
	Trig = *TransTrigg;
}

Transition::Transition()
{
}
