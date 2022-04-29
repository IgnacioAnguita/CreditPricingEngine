#ifndef N_TO_DEFAULT_SWAP_H
#define N_TO_DEFAULT_SWAP_H
#include <vector>
#include "CreditProduct.h"
#include <iostream>


class NtoDefault: public CreditProduct
{
	public:
		NtoDefault(vector<double>& PaymentTimes_, 
			double& coupon_, vector<double>& discounts_,const double& recoveryRate_,
			const int& NumbertoDefault_);					
		double PayOff(const vector<double>& DefaultTimes);	
	private:
		double recoveryRate;
		int NumbertoDefault;
};

#endif
