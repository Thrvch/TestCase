#include <limits>
#include <algorithm>
#include "bit_edit.h"

using namespace std;

pair<uint32_t, uint32_t> getMinMax(uint32_t value){
	uint32_t setBits = __builtin_popcount(value);
	if (setBits == 32) {
	    return make_pair(value, value);
	  }

	uint32_t minVal = 0, maxVal = 0;

	for (uint32_t i = 0; i < setBits; ++i) {
		minVal |= (1 << i);
	}

	for (uint32_t i = 31; i >= 32 - setBits; --i) {
		maxVal |= (1 << i);
	}

	return make_pair(minVal, maxVal);
}
