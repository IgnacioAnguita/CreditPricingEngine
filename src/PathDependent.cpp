#include "PathDependent.h"

PathDependent::PathDependent(const vector<double>& LookAtTimes_):
	LookAtTimes(LookAtTimes_){	}
	
const vector<double> PathDependent::GetLookAtTimes() const
{
	return LookAtTimes;
}

