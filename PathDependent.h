#ifndef PATH_DEPENDENT_H
#define PATH_DEPENDENT_H
#include <vector>

using namespace std;


class CashFlow
{
	public:
		double Amount;
		unsigned long TimeIndex;
		
		CashFlow(unsigned long TimeIndex_ = 0UL, double Amount_ = 0.0):
			TimeIndex(TimeIndex_), Amount(Amount_) {};
};

class PathDependent
{
	public:
		PathDependent(const vector<double>& LookAtTimes);
		const vector<double> GetLookAtTimes() const;
		
		virtual unsigned long MaxNumberOfCashFlows() const;
		virtual vector<double> PosibleCashFlowTimes() const;
		virtual unsigned long CashFlows(const vector<double>& DefaultTimes,
										vector<CashFlow>& GeneratedFlows) const=0;
		virtual PathDependent* clone() const ;
		virtual ~PathDependent() {};
		
	private:
		vector<double> LookAtTimes;
	
};

#endif
