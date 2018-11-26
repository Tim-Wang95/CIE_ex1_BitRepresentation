#include <iostream>
#include <vector>


std::vector<int> convert(int x) {
	std::vector<int> ret;
	for (int j = 0; j < sizeof(x)*8-1; ++j) {
		if (x&1) { ret.push_back(1); }
		else { ret.push_back(0);}
		x >>= 1;
	}

	reverse(ret.begin(), ret.end());
	return ret;
}

int main() {
	int num;
	std::cout << "Input an integer number in [" 
		<< std::pow(2,8*sizeof(num)-1) << " " << -std::pow(2,8*sizeof(num)+1) << "]: ";
	std::cin >> num; 
	std::vector<int> ans = convert(std::abs(num));
	std::cout << std::endl;
	
	std::cout << "the bit representation is ";
	
	for (int i = ans.size()-1; i >=0; --i) {
		if ((i + 2) % 8 == 0 && i!=30) { std::cout << " "; }
		std::cout << ans [i];
	}
	if (num > 0) { std::cout << "0"; }
	else { std::cout << "1"; }
	
	return 0;
}

