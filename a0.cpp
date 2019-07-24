// File: a0.cpp
// Amanda
// La
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#include <iostream>
#include <string>

int main(){
	std::string name = "Amanda La";

	bool has_tested = true;

	int num_tests = 2;

	std::cout << name;

	if(has_tested){
		std::cout << " performed " << num_tests << " test(s)" <<std::endl;
	}else{
	std::cout << " was lazy" << std::endl;
	}

	return 0;
}
