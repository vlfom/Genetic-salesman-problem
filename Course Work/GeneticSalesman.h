//
// GeneticSalesman.h
//

#ifndef GENETIC_SALESMAN
#define GENETIC_SALESMAN

#include <vector>
#include <set>

using namespace std;

struct EvolutionIt{
	bool gotBetter;
	vector < int > child;
	vector < int > par1, par2;
	set < pair < int, int > > diff1, diff2;
};

class GeneticSalesman {
public:
	vector < pair < float, float > > nodes;
	set < long long > individualsHash;
	vector < pair < double, vector < int > > > individuals;

public:
	GeneticSalesman();
	void addNode(float, float);
	void generateStartPopulation(int);
	EvolutionIt evolutionIteration(double *, double, double *);
	double pathLength(vector < int >);
	
	void loadFromFile(const char *);
	void saveToFile(const char*);

private:
	vector <int> headToZeroNode(vector<int>);
	double dist(int, int);
	int pick_new_parent(int);
	pair < int, int > pick_new_parents();
	pair < double, vector < int > > __breeding1(int, int);
	pair < double, vector < int > > breeding1(int, int);
	pair < double, vector < int > > breeding2(int, int);
	pair < double, vector < int > > breeding3(int, int);
	void mutation1();
	void mutation2();
	void mutation3();
	void mutation4();

private:
	double MUTATION_RESISTANT = 0.05;
	int POPULATION_SIZE = 100;
};

#endif