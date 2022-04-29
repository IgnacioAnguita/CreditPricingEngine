#ifndef CREDIT_PRODUCT_H
#define CREDIT_PRODUCT_H
#include <vector>


class CreditProduct
{
	public:
		CreditProduct(vector<double>& PaymentTimes_, 
			double& coupon_, vector<double>& discounts_);
			
		CreditProduct(const CreditProduct& Product);
		double getCoupon() {return coupon;	}
		const vector<double> getDiscounts() {return discounts;}		
		const vector<double> getPaymentTimes() {return PaymentTimes;}
		virtual double PayOff(const vector<double>& DefaultTimes);	
		
	private:
		vector<double> PaymentTimes;
		double coupon;
		vector<double> discounts;
};

#endif
