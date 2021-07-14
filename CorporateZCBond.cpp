#include "CorporateZCBond.h"

CorporateZCBond::CorporateZCBond(vector<double>& PaymentTimes_, 
			double& coupon_, vector<double>& discounts_, const double& recoveryRate_):
			CreditProduct(PaymentTimes_, coupon_, discounts_), recoveryRate(recoveryRate_)
{}

double CorporateZCBond::PayOff(const vector<double>& DefaultTimes)
{
	double maturity = getPaymentTimes()[0];
	double discount = getDiscounts()[0];
	if (DefaultTimes[0]> maturity){
		return 1 * discount;		
	}
	else
	{
		return discount * recoveryRate;
	}
}
