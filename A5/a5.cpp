#include<iostream>
#include <map>
#include<string>
#include<fstream>
#include <vector>
#include<queue>

int main(int argc, char* argv[]){

	std::ifstream input_dict(argv[1]);

	std::map<std::string, bool> maps;
	std::map<std::string, int> main_dict;
	std::vector<std::map<std::string, bool> > checker(50, maps);
	std::map<std::string, int>::iterator search;
	std::vector<std::string> listo;
	std::queue<std::string> Q;	


	std::string name = "";
	int freq;
	std::string hold;


	while(input_dict >> name >> freq){
		main_dict[name] = freq;
		checker[name.size()][name] = false;
	}

	input_dict.close();

	while(std::cin >> hold){
		std::string name_input = hold;
		search = main_dict.find(name_input);
		if(search != main_dict.end()){
			std::cout << search->first << " " << search->second << std::endl;
			search->second++;
		}
		else{
			//check substitution
			for(std::map<std::string, bool>::iterator it = checker[hold.size()].begin(); 
				it != checker[hold.size()].end(); ++it){
				for(int j = 0; j< hold.size(); ++j){
					for(int i = 65; i<91; ++i){
						std::string a;
						a = (char) i;

						if(name_input.replace(j,1,a) == it->first){
							listo.push_back(name_input);
						}
						name_input = hold;
					}
				}
			}//sub check

			//insertion check
			for(std::map<std::string, bool>::iterator it = checker[hold.size()+1].begin();
				it != checker[hold.size()+1].end(); ++it){
				
				for(int j = 0; j< hold.size() + 1; ++j){
					for(int i = 65; i < 91; ++i){
						std::string a;
						a = (char) i;
						name_input.insert(j, a);
						if(name_input == it->first){
							listo.push_back(name_input);
						}
						name_input = hold;
					}
				}
			}//insertion

			//deletion check
			for(std::map<std::string, bool>::iterator it = checker[hold.size()-1].begin();
				it !=checker[hold.size()-1].end(); ++it){
				for(int i = 0; i< hold.size(); ++i){
					if(name_input.erase(i,1) == it->first){
						listo.push_back(name_input);
					}
					name_input = hold;
				}
			}//deletion check

			//no matches
			if(listo.empty()){
				main_dict[hold] = 1;
				checker[hold.size()][hold] = false;
				std::cout<< "-"<< '\n';
			}
			//matches
			else{
				Q.push(listo[0]);
				for(int i = 1; i < listo.size(); ++i){
					if(main_dict[Q.front()] < main_dict[listo[i]]){
						Q.pop();
						Q.push(listo[i]);
					}else if(main_dict[Q.front()] == main_dict[listo[i]]){
						if(listo[i] < Q.front()){
							Q.pop();
							Q.push(listo[i]);
						}
					}
				}
				std::cout<< Q.front()<< " " << main_dict[Q.front()]<< std::endl; 
				
				while(!Q.empty()){
					Q.pop();
				}
			}//found match
			while(!listo.empty()){
				listo.pop_back();
			}
		}
	}

	std::cout<< "-----" <<'\n';
	for (std::map<std::string, int>::iterator it = main_dict.begin(); it!=main_dict.end(); ++it){
    	std::cout << it->first << " " << it->second << '\n';
	}

}