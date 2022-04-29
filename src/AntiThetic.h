#ifndef ANTITHETIC_H
#define ANTITHETIC_H

#include "Random2.h"
#include "Wrapper.h"
#include<vector>


class AntiThetic: public RandomBase
{
	public:
		AntiThetic(const Wrapper<RandomBase>& InnerGenerator_);
		virtual RandomBase* clone() const;
		virtual void GetUniforms(std::vector<double>& variates);
		virtual void Skip(unsigned long numberOfPaths);
		virtual void SetSeed(unsigned long Seed);
		virtual void ResetDimensionality(unsigned long NewDimensionality);
		virtual void Reset();
		
	private:
		Wrapper<RandomBase> InnerGenerator;
		bool OddEven;
		std::vector<double> NextVariates;
};

#endif
