#include "NtoDefault.h"

using namespace std;


NtoDefault::NtoDefault(vector<double>& PaymentTimes_, 
			double& coupon_, vector<double>& discounts_, const double& recoveryRate_,
			const int& NumbertoDefault_):
			CreditProduct(PaymentTimes_, coupon_, discounts_), recoveryRate(recoveryRate_), 
			NumbertoDefault(NumbertoDefault_)
{}

double NtoDefault::PayOff(const vector<double>& DefaultTimes)
{
	int defaulted = 0;
	double maturity = 0;
	
	for (int i = 0; i < getPaymentTimes().size(); i++)
	{
		defaulted = 0;
		maturity = getPaymentTimes()[i];
		for(int j = 0; j < DefaultTimes.size(); j++){
			if (DefaultTimes[j] <= maturity)
			{
				defaulted++;
			}
		}
		if (defaulted>= NumbertoDefault)
		{
			return (1 - recoveryRate) * getDiscounts()[i];
		}		
	}
	return 0.0;
}
