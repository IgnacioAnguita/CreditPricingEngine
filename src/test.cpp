#include "test.h"
#include <iostream>
#include "ParkMiller.h"
#include "HoLiCreditEngine.h"
#include "CreditProduct.h"
#include "AntiThetic.h"
#include "CorporateZCBond.h"
#include "NtoDefault.h"
#include <math.h>


void test_1()
{
	cout<<"Test 1 Checking that the average default time equals 1 / hazard rate: ";
	vector<double> hazards, PaymentTimes, discounts;
	hazards.push_back(1/10.0);
	PaymentTimes.push_back(1.0);
	discounts.push_back(1.0);
	double correlation = 1.0, coupon = 1.0;
	
	RandomParkMiller generator(2);
	AntiThetic RandomGenerator(generator);
	CreditProduct TheProduct(PaymentTimes, coupon, discounts);
	HoLiCreditEngine<RandomParkMiller,CreditProduct> Engine(hazards, correlation,
			generator, TheProduct);
	
	vector<double> DefaultTimes(1,1.0);
	vector<double> variates(2,1.0);	

	double total = 0.0;
	for(int i = 0; i<1000000; i++){
		RandomGenerator.GetGaussian(variates);	
		Engine.GetDefaultTimes(DefaultTimes, variates);
		total+=DefaultTimes[0];		
	}
	if((total/1000000-10.0)/10.0<0.001)
	{
		std::cout<<" passed!"<<endl;
	}
	else
	{
		std::cout<<" failed!"<<endl;
	}	
}

void test_2()
{
	std::cout<<"Test 2 Checking the implementation of a ZC Bond: ";
	vector<double> hazards, PaymentTimes, discounts;
	hazards.push_back(1/10.0);
	PaymentTimes.push_back(1.0);
	discounts.push_back(1.0);
	double correlation = 1.0, coupon = 1.0;
	
	RandomParkMiller generator(2);
	AntiThetic RandomGenerator(generator);
	
	double recoveryRate = 0.4;
	CorporateZCBond TheProduct(PaymentTimes, coupon, discounts, recoveryRate);
	HoLiCreditEngine<AntiThetic,CorporateZCBond> Engine(hazards, correlation,
			RandomGenerator, TheProduct);
	
	vector<double> DefaultTimes(1,1.0);
	vector<double> MeanGatherer;
	unsigned long NumberOfPaths = 100000;
	
	Engine.DoSimulation(MeanGatherer, NumberOfPaths);	

	double ZCAnalytical = recoveryRate + (1-recoveryRate)*exp(-hazards[0]*PaymentTimes[0]);
	if((MeanGatherer.back()/ZCAnalytical -1)<0.001)
	{
		std::cout<<" passed!"<<endl;
	}
	else
	{
		std::cout<<" failed!"<<endl;
	}	
}

void test_3()
{
	cout<<"Test 3 Checking the basic implementation of a N to Default: ";
	vector<double> hazards, PaymentTimes, discounts;
	hazards.push_back(1/10.0);
	PaymentTimes.push_back(1.0);
	discounts.push_back(1.0);
	double correlation = 1.0, coupon = 1.0;
	
	RandomParkMiller generator(2);
	AntiThetic RandomGenerator(generator);
	
	double recoveryRate = 0.4;
	int NumbertoDefault = 1;
	NtoDefault TheProduct(PaymentTimes, coupon, discounts, recoveryRate, NumbertoDefault);
	HoLiCreditEngine<AntiThetic,NtoDefault> Engine(hazards, correlation,
			RandomGenerator, TheProduct);
	
	vector<double> DefaultTimes(1,1.0);
	vector<double> MeanGatherer;
	unsigned long NumberOfPaths = 1000000;
	
	Engine.DoSimulation(MeanGatherer, NumberOfPaths);
	
	for(int i = 0; i <MeanGatherer.size(); i++)
	{
		std::cout<<MeanGatherer[i]<<endl;
	}
	double ZC1toDefault = 1 - (recoveryRate + (1-recoveryRate)*exp(-hazards[0]*PaymentTimes[0]));

	if((MeanGatherer.back()/ZC1toDefault -1)<0.001)
	{
		std::cout<<" passed!"<<endl;
	}
	else
	{
		std::cout<<" failed!"<<endl;
	}	
}
