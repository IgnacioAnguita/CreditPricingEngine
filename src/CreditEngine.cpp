#include "CreditEngine.h"
#include <cmath>
#include <math.h>
#include "PathDependent.h"

using namespace std;

CreditEngine::CreditEngine(const PathDependent& TheProduct_, 
	vector<double>& Discounts_):
	Discounts(Discounts_), TheProduct(TheProduct_)
{}

void CreditEngine::DoSimulation(vector<double>& MeanGatherer, 
	unsigned long NumberOfPaths)
{
	vector<double> DefaultTimes (0.0, TheProduct.GetLookAtTimes().size());
	TheseCashFlows.resize(TheProduct.MaxNumberOfCashFlows());
	double thisValue = 0.0;
	int counter = 0;
	
	for(unsigned long i = 0; i < NumberOfPaths; ++i)
	{
		GetOnePath(DefaultTimes);
		thisValue += DoOnePath(DefaultTimes);
		if(i==pow(2,counter)){
			MeanGatherer.push_back(thisValue/(counter+1));
			counter+=1;
		}	
	}
	
	MeanGatherer.push_back(thisValue/NumberOfPaths);	
}

double CreditEngine::DoOnePath(const vector<double>& DefaultTimes) const
{
	unsigned long NumberFlows = TheProduct.CashFlows(DefaultTimes, TheseCashFlows);
	double Value = 0.0;
	
	for(unsigned i = 0; i < NumberFlows; ++i)
	{
		Value += TheseCashFlows[i].Amount * Discounts[i];
	}
	return Value;
}
