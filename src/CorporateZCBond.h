#ifndef CORPORATE_ZC_H
#define CORPORATE_ZC_H
#include <vector>
#include "CreditProduct.h"

using namespace std;

class CorporateZCBond: public CreditProduct
{
	public:
		CorporateZCBond(vector<double>& PaymentTimes_, 
			double& coupon_, vector<double>& discounts_,const double& recoveryRate_);					
		double PayOff(const vector<double>& DefaultTimes);	
	private:
		double recoveryRate;
};

#endif
