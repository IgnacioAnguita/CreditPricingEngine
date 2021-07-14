#ifndef PARK_MILLER_H
#define PARK_MILLER_H
#include "Random2.h"
#include <vector>

using namespace std;

class ParkMiller
{
	public:
		ParkMiller(long Seed_ = 1);
		long GetOneRandomInteger();
		void SetSeed(long Seed_);
		
		static unsigned long Max();
		static unsigned long Min();
		
	private:
		long Seed;
};


class RandomParkMiller : public RandomBase
{
	public:
		RandomParkMiller(unsigned long Dimensionality_,
			unsigned long Seed_ = 1);
		virtual RandomBase* clone() const;
		virtual void GetUniforms(vector<double>& variates);
		virtual void Skip(unsigned long numberOfPaths);
		virtual void SetSeed(unsigned long Seed);
		virtual void Reset();
		virtual void ResetDimensionality(unsigned long NewDimensionality);
		
	private:
		ParkMiller InnerGenerator;
		unsigned long InitialSeed;
		double Reciprocal;
		
};


#endif
