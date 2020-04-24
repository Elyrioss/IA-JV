#pragma once
class Trigger
{
	private: 

		enum Type
		{
			Bool, Int, Float
		};

		Type type;

		bool* B;
		int* I;
		float* F;

		int i;
		float f;

		int Comparaison; // -1 < ; 0 = ; 1 >

	public:		

		Trigger() {
			type = Bool;
		};

		Trigger(bool* val) {
			type = Bool;
			B = val;
		};

		Trigger(float* val,float compare,int comparaison) {
			type = Float;
			F = val;
			f = compare;
			Comparaison = comparaison;
		};

		Trigger(int* val, int compare, int comparaison) {
			type = Int;
			I = val;
			i = compare;
			Comparaison = comparaison;
		}

		bool Check() {
			switch (type)
			{
				case Trigger::Bool:
					return *B;
					break;
				case Trigger::Int:
					if (Comparaison==1) {
						if (*I > i) {
							return true;
						}
						else {
							return false;
						}
					}
					else if (Comparaison == -1) {
						if (*I < i) {
							return true;
						}
						else {
							return false;
						}
					}
					else{
						if (*I == i) {
							return true;
						}
						else {
							return false;
						}
					}
						
					break;
				case Trigger::Float:
					if (Comparaison == 1) {
						if (*F > f) {
							return true;
						}
						else {
							return false;
						}
					}
					else if (Comparaison == -1) {
						if (*F < f) {
							return true;
						}
						else {
							return false;
						}
					}
					else {
						if (*F == f) {
							return true;
						}
						else {
							return false;
						}
					}
			}
		}

};

