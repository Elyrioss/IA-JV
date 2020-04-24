#pragma once
class Trigger
{
	public:
		enum Type
		{
			Bool,Int,Float
		};

		Type type;

		bool* B;
		int* I;
		float* F;

		int i;
		float f;



		Trigger() {
			type = Bool;
		};

		Trigger(bool* val) {
			type = Bool;
			B = val;
		};

		Trigger(float* val,float compare) {
			type = Float;
			F = val;
			f = compare;
		};

		Trigger(int* val, int compare) {
			type = Int;
			I = val;
			i = compare;
		}

		bool Check() {
			switch (type)
			{
				case Trigger::Bool:
					return *B;
					break;
				case Trigger::Int:
					if (*I > i) {
						return true;
					}
					else {
						return false;
					}			
					break;
				case Trigger::Float:
					if (*F > f) {
						return true;
					}
					else {
						return false;
					}
					break;
			}
		}

};

