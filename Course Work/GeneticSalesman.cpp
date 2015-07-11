//
// GeneticSalesman.cpp
//

#include "GeneticSalesman.h"
#include "path_hash.h"
#include "my_random.h"

#include <fstream>
#include <algorithm>
#include <vector>
#include <set>

#include <iostream>
#include <sstream>

using namespace std;

GeneticSalesman::GeneticSalesman() {
}

void GeneticSalesman::addNode(float x, float y) {
	nodes.push_back(make_pair(x, y));
}

void GeneticSalesman::generateStartPopulation(int populationSize) {
	int populationSizeTemp = populationSize;
	while (populationSizeTemp--) {
		vector<int> seq;
		for (int i = 0; i < (int)nodes.size(); ++i)
			seq.push_back(i);
		random_shuffle(seq.begin(), seq.end());
		seq = headToZeroNode(seq);
		long long seqHash = path_hash(seq);
		if (individualsHash.count(seqHash))
			populationSizeTemp++;
		else {
			individualsHash.insert(seqHash);
			individuals.push_back(make_pair(pathLength(seq), seq));
		}
	}
}

void GeneticSalesman::mutation1() {
	sort(individuals.begin(), individuals.end());
	int mutationResistant = int(MUTATION_RESISTANT * (int)individuals.size() + 1 - 1e-9);
	int mutationIndividual = mutationResistant + rand() % ((int)individuals.size() - mutationResistant);
	int a = rand() % (int)nodes.size();
	int b = rand() % (int)nodes.size();
	swap(individuals[mutationIndividual].second[a],
		individuals[mutationIndividual].second[b]);
	individuals[mutationIndividual].first =
		pathLength(individuals[mutationIndividual].second);
}

void GeneticSalesman::mutation2() {
	sort(individuals.begin(), individuals.end());
	int mutationResistant = int(MUTATION_RESISTANT * (int)individuals.size() + 1 - 1e-9);
	int mutationIndividual = mutationResistant + rand() % ((int)individuals.size() - mutationResistant);
	int maxlen1 = -1, maxlen2 = -1, ind1, ind2;
	for (int i = 0; i < (int)nodes.size(); ++i) {
		int j = (i + 1) % (int)nodes.size();
		double d = dist(
			individuals[mutationIndividual].second[i],
			individuals[mutationIndividual].second[j]
			);
		if (d > maxlen1) {
			maxlen2 = maxlen1;
			ind2 = ind1;
			maxlen1 = d;
			ind1 = j;
		}
		else if (d > maxlen2) {
			maxlen2 = d;
			ind2 = j;
		}
	}
	swap(individuals[mutationIndividual].second[ind1],
		individuals[mutationIndividual].second[ind2]);
	individuals[mutationIndividual].first =
		pathLength(individuals[mutationIndividual].second);
}

void GeneticSalesman::mutation3() {
	sort(individuals.begin(), individuals.end());
	int mutationResistant = int(MUTATION_RESISTANT * (int)individuals.size() + 1 - 1e-9);
	int mutationIndividual = mutationResistant + rand() % ((int)individuals.size() - mutationResistant);
	int a = rand() % (int)nodes.size();
	double best = 1e9; int ind;
	for (int i = 0; i < (int)nodes.size(); ++i) {
		swap(individuals[mutationIndividual].second[a],
			individuals[mutationIndividual].second[i]);
		if (pathLength(individuals[mutationIndividual].second) < best) {
			best = pathLength(individuals[mutationIndividual].second);
			ind = i;
		}
		swap(individuals[mutationIndividual].second[a],
			individuals[mutationIndividual].second[i]);
	}
	swap(individuals[mutationIndividual].second[a],
		individuals[mutationIndividual].second[ind]);
	individuals[mutationIndividual].first =
		pathLength(individuals[mutationIndividual].second);
}

void GeneticSalesman::mutation4() {
	sort(individuals.begin(), individuals.end());
	int mutationResistant = int(MUTATION_RESISTANT * (int)individuals.size() + 1 - 1e-9);
	int mutationIndividual = mutationResistant + rand() % ((int)individuals.size() - mutationResistant);
	int a = rand() % (int)nodes.size(), b;
	do {
		b = rand() % (int)nodes.size();
	} while (b == a);
	int l = b - a + 1;
	for (int i = a; i < a + l / 2; ++i)
		swap(individuals[mutationIndividual].second[i],
			individuals[mutationIndividual].second[b - (i - a)]);
	individuals[mutationIndividual].first =
		pathLength(individuals[mutationIndividual].second);
}

EvolutionIt GeneticSalesman::evolutionIteration(double *breedingPriority, double mutationProbability, double *mutationPriority) {
	EvolutionIt ret;
	ret.gotBetter = false;

	/* Mutation */
	if (flip_coin(mutationProbability)) {
		if (flip_coin(mutationPriority[0] ))
			mutation1();
		else if (flip_coin(mutationPriority[1]))
			mutation2();
		else if (flip_coin(mutationPriority[2]))
			mutation3();
		else if (flip_coin(mutationPriority[3]))
			mutation4();
	}

	/* Breeding */
	pair<int, int> parents = pick_new_parents();
	int a = parents.first, b = parents.second;
	pair<double, vector<int> > child;
	if( flip_coin(breedingPriority[0]) )
		child = breeding1(a, b);
	else if (flip_coin(breedingPriority[1]))
		child = breeding2(a, b);
	else if (flip_coin(breedingPriority[2]))
		child = breeding3(a, b);

	/* Deciding whether new child will survive */
	long long childHash = path_hash(child.second);
	double parentLen = min(individuals[a].first, individuals[b].first);
	double growthPercent = child.first / parentLen;
	if (!individualsHash.count(childHash)
		&& (growthPercent < 1 || (rand() % 20 == 0 && growthPercent < 1.1))) {

		if (individuals[0].first > child.first) {
			ret.gotBetter = true;
			ret.child = child.second;
			ret.par1 = individuals[a].second;
			ret.par2 = individuals[b].second;

			set < pair < int, int > > childEdges;

			for (int i = 0; i < nodes.size(); ++i) {
				int next = (i + 1) % (int)nodes.size();

				childEdges.insert(make_pair(child.second[i], child.second[next]));
				childEdges.insert(make_pair(child.second[next], child.second[i]));
			}

			for (int i = 0; i < nodes.size(); ++i) {
				int next = (i + 1) % (int)nodes.size();

				if (!childEdges.count(make_pair(ret.par1[i], ret.par1[next])))
					ret.diff1.insert(make_pair(i, next));

				if (!childEdges.count(make_pair(ret.par2[i], ret.par2[next])))
					ret.diff2.insert(make_pair(i, next));
			}
		}

		individualsHash.erase(path_hash(individuals.back().second));
		individuals.erase(--individuals.end());

		individualsHash.insert(childHash);
		individuals.push_back(child);
	}

	sort(individuals.begin(), individuals.end());

	return ret;
}

vector <int> GeneticSalesman::headToZeroNode(vector<int> v) {
	vector<int> res;
	int i, j;
	for (i = 0; i < (int)v.size(); ++i)
		if (v[i] == 0)
			break;
	for (j = 0; j < (int)v.size(); ++j)
		res.push_back(v[(i + j) % (int)v.size()]);
	return res;
}

double GeneticSalesman::dist(int a, int b) {
	double dx = nodes[a].first - nodes[b].first;
	double dy = nodes[a].second - nodes[b].second;
	return sqrt((double)(dx * dx + dy * dy));
}

double GeneticSalesman::pathLength(vector < int > v) {
	double cost = 0;
	int cur, next;
	for (int i = 0; i < (int)v.size(); ++i) {
		cur = v[i];
		next = v[(i + 1) % (int)v.size()];
		cost += dist(cur, next);
	}
	return cost;
}

int GeneticSalesman::pick_new_parent(int size) {
	int a = rand() % size;
	if (a >= size / 2)
		a = rand() % size;
	return a;
}

pair < int, int > GeneticSalesman::pick_new_parents() {
	sort(individuals.begin(), individuals.end());
	int x, y;
	x = pick_new_parent((int)individuals.size());
	do {
		y = pick_new_parent((int)individuals.size());
	} while (x == y);
	return make_pair(x, y);
}

pair < double, vector < int > > GeneticSalesman::__breeding1(int a, int b) {
	int l = rand() % (int)nodes.size(), r;
	do {
		r = rand() % (int)nodes.size();
	} while (r == l);
	if (l > r)
		swap(l, r);
	vector < int > path;
	vector < int > next((int)nodes.size());
	set < int > allfree;
	for (int i = 0; i < (int)nodes.size(); ++i) {
		allfree.insert(i);
		next[individuals[b].second[i]] = individuals[b].second[(i + 1) % (int)nodes.size()];
	}
	for (int i = l; i < r; ++i) {
		path.push_back(individuals[a].second[i]);
		allfree.erase(individuals[a].second[i]);
	}
	while ((int)path.size() < (int)nodes.size()) {
		int v = path.back();
		if (allfree.count(next[v])) {
			path.push_back(next[v]);
			allfree.erase(next[v]);
			v = next[v];
		}
		else {
			v = rand() % (int)allfree.size();
			set < int > ::iterator it;
			for (it = allfree.begin(); v > 0; ++it, --v);
			v = *it;
			path.push_back(v);
			allfree.erase(v);
		}
	}
	return make_pair(pathLength(path), path);
}

pair < double, vector < int > > GeneticSalesman::breeding1(int a, int b) {
	pair < double, vector < int > > first = __breeding1(a, b), second = __breeding1(b, a);
	if (first.first < second.first)
		return first;
	return second;
}

pair < double, vector < int > > GeneticSalesman::breeding2(int a, int b) {
	int cur = rand() % (int)nodes.size(),
		childPathLength = 1;
	vector<int> childPath;
	vector<bool> visited((int)nodes.size(), 0);
	childPath.push_back(cur);
	visited[cur] = true;
	while (childPathLength < (int)nodes.size()) {
		++childPathLength;

		vector<pair<double, int> > d; //candidates
		int pos;
		for (pos = 0; pos < (int)individuals[a].second.size(); ++pos)
			if (individuals[a].second[pos] == cur)
				break;
		for (int k = 0;; ++k) {
			int next = pos - k;
			if (next < 0)
				next += (int)individuals[a].second.size();
			next = individuals[a].second[next];
			if (!visited[next]) {
				d.push_back(make_pair(dist(cur, next),
					next));
				break;
			}
		}
		for (int k = 0;; ++k) {
			int next = (pos + k) % (int)individuals[a].second.size();
			next = individuals[a].second[next];
			if (!visited[next]) {
				d.push_back(make_pair(dist(cur, next),
					next));
				break;
			}
		}
		for (pos = 0; pos < (int)individuals[b].second.size(); ++pos)
			if (individuals[b].second[pos] == cur)
				break;
		for (int k = 0;; ++k) {
			int next = pos - k;
			if (next < 0)
				next += (int)individuals[b].second.size();
			next = individuals[b].second[next];
			if (!visited[next]) {
				d.push_back(make_pair(dist(cur, next),
					next));
				break;
			}
		}
		for (int k = 0;; ++k) {
			int next = (pos + k) % (int)individuals[b].second.size();
			next = individuals[b].second[next];
			if (!visited[next]) {
				d.push_back(make_pair(dist(cur, next),
					next));
				break;
			}
		}
		sort(d.begin(), d.end());
		cur = d[0].second;
		visited[cur] = true;
		childPath.push_back(cur);
	}

	childPath = headToZeroNode(childPath);

	return make_pair(pathLength(childPath), childPath);
}

pair < double, vector < int > > GeneticSalesman::breeding3(int a, int b) {
	set < pair < int, int > > temp;
	vector < vector < int > > e((int)nodes.size());
	set < int > e0, e1, any;

	for (int i = 0; i < (int)nodes.size(); ++i) {
		e0.insert(i);
		any.insert(i);
	}

	for (int i = 0; i < (int)nodes.size(); ++i) {
		int next = (i + 1) % (int)nodes.size();
		int x = individuals[a].second[i];
		int y = individuals[a].second[next];
		if (x > y)
			swap(x, y);
		temp.insert(make_pair(x, y));
	}

	for (int i = 0; i < (int)nodes.size(); ++i) {
		int next = (i + 1) % (int)nodes.size();
		int x = individuals[b].second[i];
		int y = individuals[b].second[next];
		if (x > y)
			swap(x, y);
		if (temp.count(make_pair(x, y))) {
			if (e0.count(x)) {
				e0.erase(x);
				e1.insert(x);
			}
			else if (e1.count(x)) {
				e1.erase(x);
				any.erase(x);
			}

			if (e0.count(y)) {
				e0.erase(y);
				e1.insert(y);
			}
			else if (e1.count(y)) {
				e1.erase(y);
				any.erase(y);
			}

			e[x].push_back(y);
			e[y].push_back(x);
		}
	}

	if (any.empty())
		return individuals[a];

	vector < int > vis((int)nodes.size());
	int v = 0, cnt = 0, left, total, next;
	vector < int > allv;
	vector < int > allfree;
	vector < vector < int > > components;
	set < int > ::iterator it;

	for (it = e1.begin(); it != e1.end(); ++it)
		if (!vis[*it]) {
			++cnt;
			vector < int > component;
			v = *it;
			allv.push_back(v);
			do {
				component.push_back(v);
				vis[v] = cnt;
				if (!vis[e[v][0]])
					next = e[v][0];
				else if ((int)e[v].size() > 1 && !vis[e[v][1]])
					next = e[v][1];
				else
					break;
				v = next;
			} while (true);
			components.push_back(component);
		}

	for (it = e0.begin(); it != e0.end(); ++it) {
		allv.push_back(*it);
		allfree.push_back(*it);
	}

	vector < int > path;
	int n;
	v = 0;
	do {
		if (vis[allv[v]]) {
			for (int i = 0; i < (int)components[vis[allv[v]] - 1].size(); ++i)
				path.push_back(components[vis[allv[v]] - 1][i]);
			n = components[vis[allv[v]] - 1].back();
		}
		else {
			path.push_back(allv[v]);
			n = allv[v];
		}
		allv.erase(allv.begin() + v);
		if (allv.empty())
			break;
		int minind; double mind = 1e9;
		for (int i = 0; i < (int)allv.size(); ++i)
			if (dist(n, allv[i]) < mind) {
				mind = dist(n, allv[i]);
				minind = i;
			}
		v = minind;
	} while (true);

	path = headToZeroNode(path);

	return make_pair(pathLength(path), path);
}

void GeneticSalesman::loadFromFile(const char *fileName) {
	FILE *F = fopen(fileName, "r");
	int num;
	float fi, se;
	fscanf(F, "%d", &num);
	for (int i = 0; i < num; ++i) {
		fscanf(F, "%f %f", &fi, &se);
		nodes.push_back(make_pair(fi, se));
	}
	fclose(F);
}

void GeneticSalesman::saveToFile(const char *fileName) {
	ofstream write(fileName);
	int num = nodes.size();
	float fi, se;
	write << num << endl;
	for (int i = 0; i < num; ++i)
		write << nodes[i].first << nodes[i].second << endl;
	write.close();
}