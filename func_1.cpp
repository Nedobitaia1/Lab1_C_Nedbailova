#include <iostream>
#include <type_traits>
using namespace std;
int f(void) {
	long int var1 = 1;
	long long int var2 = 0;
	using res_type = common_type_t<decltype(var1), decltype(var2)>;
	res_type result;
	result = var1 + var2;
	result = result + var1;
	result = result + var2;
	cout << result << endl;
	return 0;
}
