#include "Random2.h"
#include "normal.h"
#include <cstdlib>

using namespace std;

void RandomBase::GetGaussian(vector<double>& variates)
{
	GetUniforms(variates);
	
	for(unsigned long i = 0; i < Dimensionality; i++){
		double x = variates[i];
		double temp = InverseCumulativeNormal(x);
		variates[i] = temp;
	}
}

void RandomBase::ResetDimensionality(unsigned long NewDimensionality){
	Dimensionality = NewDimensionality;	
}

RandomBase::RandomBase(unsigned long Dimensionality_):
	Dimensionality(Dimensionality_){}
	
unsigned long RandomBase::GetDimensionality() const {
	return Dimensionality;
}
