#include <math.h>

#include "dod.h"
#include "sum.h"
#include "var.h"

using namespace nsDod;
using namespace nsVar;


void nsSum::sum()
{
	n = 1;
	a = (x * x * x) / 6;
	S = a;
	do {
		n++;
		R = ((2.0 * n - 1) * (2.0 * n - 1)) / (2.0 * n * (2.0 * n + 1)) * (x * x);
		dod();
		S += a;

	} while (fabs(a) >= eps);
}