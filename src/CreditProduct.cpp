#include "CreditProduct.h"	
	

CreditProduct::CreditProduct(vector<double>& PaymentTimes_, 
			double& coupon_, vector<double>& discounts_):
				PaymentTimes(PaymentTimes_), coupon(coupon_),
				discounts(discounts_)
{
}

CreditProduct::CreditProduct(const CreditProduct& CreditProduct)
{
	PaymentTimes = CreditProduct.PaymentTimes;
	coupon = CreditProduct.coupon;
	discounts = CreditProduct.discounts;
}

double CreditProduct::PayOff(const vector<double>& DefaultTimes)
{
	return 2.0 ;
}
