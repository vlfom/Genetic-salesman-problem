#include "path_hash.h"
#include <vector>

const long long PRIME[] = {
	179424419LL,
	20667293LL
};

const long long MOD = 237082639LL;

long long path_hash(std::vector<int> v) {
	long long res[] = {
		0,
		0
	};
	for (int j = 0; j < 2; ++j)
		for (int i = 0; i < (int)v.size(); ++i)
			res[j] = (res[j] * PRIME[j] + v[i]) % MOD;
	long long final = 0;
	for (int j = 0; j < 2; ++j)
		final = (final * PRIME[j] + res[j]) % MOD;
	return final;
}