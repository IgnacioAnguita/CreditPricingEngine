#ifndef HO_LI_ENGINE_H
#define HO_LI_ENGINE_H

#include <cmath>
#include <math.h>
#include "CreditProduct.h"
#include "Random2.h"
#include "Wrapper.h"
#include "normal.h"

template<class T1, class T2>
class HoLiCreditEngine
{
	public:
		HoLiCreditEngine(vector<double>& hazards_, double& correlation_, 
			T1 RandomGenerator_,const T2& TheProduct_);
		void GetDefaultTimes(vector<double>& DefaultTimes, vector<double>& variates);
		void DoSimulation(vector<double>& MeanGatherer, unsigned long& NumberOfPaths);		
		
	private:
		T2 TheProduct;
		vector<double> hazards;
		double correlation;
		T1 RandomGenerator;
	
};

template <class T1,class T2>		
HoLiCreditEngine<T1,T2>::HoLiCreditEngine(vector<double>& hazards_, 
	double& correlation_, T1 RandomGenerator_, const T2& TheProduct_):
		hazards(hazards_), correlation(correlation_),
		TheProduct(TheProduct_), RandomGenerator(RandomGenerator_)
{
}

template <class T1, class T2>
void HoLiCreditEngine<T1,T2>::GetDefaultTimes(vector<double>& DefaultTimes, vector<double>& variates)
{		

	RandomGenerator.GetGaussian(variates);

	double p = 0.0;	
	
	for(int i = 0; i<variates.size()-1; i++)
	{
		p = correlation * variates[0] + 
			sqrt(1-correlation*correlation)*variates[i+1];
		
		p = CumulativeNormal(p);	
		DefaultTimes[i] = log((1-p))/-hazards[i];
	}	
	
}

template <class T1, class T2>
void HoLiCreditEngine<T1,T2>::DoSimulation(vector<double>& MeanGatherer, unsigned long& NumberOfPaths)
{
	
	vector<double> variates(hazards.size()+1,0.0);
	vector<double> DefaultTimes(hazards.size(), 0.0);

	double thisValue = 0.0;
	int counter = 0;
	
	for(int i = 0; i<NumberOfPaths; i++){
		
		GetDefaultTimes(DefaultTimes,variates);				
		thisValue += TheProduct.PayOff(DefaultTimes);
	
		if(i==pow(2,counter)){
			MeanGatherer.push_back(thisValue/(i+1));
			counter+=1;
		}
	}	
	MeanGatherer.push_back(thisValue/NumberOfPaths);
}



#endif
