// File: a1.cpp
// Amanda 
// La
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

int main(int argc, char* argv[]){

	std::string dna_s = "";
	std::ifstream dna_f(argv[1]);

	char ascii_k = *argv[2];
	int k_param = int(ascii_k) - 48;
	int t_param = atoi(argv[3]);
	
	//nucleotide base counts
	int a = 0;
	int c = 0;
	int g = 0;
	int t = 0;

	if (k_param == 1){
		k_param = 10;
	}
	
	if(dna_f.is_open()){
		std::getline(dna_f, dna_s);
		dna_f.close();
	}

	//A1 line 1
	std::cout<< 0 << " " << k_param << " " << dna_s.length() << '\n';

	for(int i = 0; i!= dna_s.length(); ++i){
		char ascii_nuc = dna_s[i];
		int nuc_num = int(ascii_nuc);
		if(nuc_num == 65){
			++a;
		}else if(nuc_num == 67){
			++c;
		}else if (nuc_num == 71){
			++g;		
		}else{
			++t;
		}
	}
	
	//A1 line 2
	std::cout<< 1 << " " << a << " " << c << " " << g << " " << t << std::endl;	

	//working on pt2
	int stopper = dna_s.length() - k_param + 1;	
	std::vector<std::string> all_kmers(2*stopper, "");
    std::vector<int> count(1048577, 0);
    std::vector<std::string> unique_kmers(1048577, "");
   // all_kmers.reserve(2*stopper);
   

    if(dna_s.length() < k_param){
    	std::cout<< "error"<< std::endl;
    }else{
	    for(int current = 0; current != stopper; ++current){
	       all_kmers[current] = dna_s.substr(current,k_param);
	       //all_kmers.push_back(dna_s.substr(current, k_param));
	    }
	  	for(int i = 0; i< all_kmers.size(); ++i){
	      	int sum = 0;
	      	for(int m = 0, n = 1; m < k_param; ++m, ++n){
	          	char s = all_kmers[i][m];
	            int num = int(s);
	            if(num == 65){
	                sum += (pow(4, k_param-n) * 0);
	            }else if (num == 67){
	                sum += (pow(4, k_param-n) * 1);
	            }else if(num ==71){
	                sum += (pow(4, k_param-n) * 2);
	            }else if(num == 84){
	                sum += (pow(4, k_param-n) * 3);
	            }
	      	}
		    ++(count[sum]);
		    unique_kmers[sum] = all_kmers[i];
	    }
	   

	   for(int m = 0; m < count.size(); m++){
	       if(count[m] >= t_param){
	       	std::cout<< unique_kmers[m] << " " << count[m] << std::endl;
	       }
	   }
	}

	//A1 pt 1
	
	// if(dna_s.length() < k_param){
	// 	std::cout<< "error"<< std::endl;
	// }else{
	// 	for(int current = 0; current != stopper; ++current){
	// 		std::cout<< dna_s.substr(current, k_param) << '\n';
	// 	}
	// }

	return 0;
}
