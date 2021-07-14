#ifndef CREDIT_ENGINE_H
#define CREDIT_ENGINE_H

#include<vector>
#include "PathDependent.h"

using namespace std;

class CreditEngine
{
	public:
		CreditEngine(const PathDependent& TheProduct_, vector<double>& Discounts_);
		virtual void GetOnePath(vector<double>& DefaultTimes)=0;
		void DoSimulation(vector<double>& MeanGatherer, unsigned long NumberOfPaths);
		virtual ~CreditEngine(){};
		double DoOnePath(const vector<double>& DefaultTimes) const;		
		
	private:
		
		PathDependent TheProduct;				
		vector<double> Discounts;
		mutable vector<CashFlow> TheseCashFlows;	
	
};

#endif
