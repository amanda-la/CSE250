// File: a4.hpp
// Amanda
// La
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A4_HPP
#define A4_HPP

#include <ostream>
#include "symbol.hpp"
#include <queue>
#include <vector>

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT ALL REQUIRED FUNCTIONS BELOW
// YOU ARE NOT ALLOWED TO ALTER ANY INTERFACE
// INSIDE A FUNCTION YOU CAN DO WHATEVER YOU LIKE

// IMPLEMENT YOUR FUNCTION huffman_tree
struct compare_bnodes {
	bool operator()(const bnode<symbol>& b, const bnode<symbol>& a){
		return((a.value.count< b.value.count) || (!(b.value.count < a.value.count) && (a.value.value < b.value.value)));
	}
};

std::priority_queue< bnode<symbol>, std::vector< bnode<symbol> >, compare_bnodes> Q; 
std::vector<bnode<symbol> > sims(256*256);
std::string stringer = "";

template <typename Iter>
bnode<symbol>* huffman_tree(Iter first, Iter last){
	int i = 0;
	int j = 1;
	bnode<symbol>* ptr;
	
	while(first != last){
		Q.push(bnode<symbol>(*first));
		++first;
	}

	while(Q.size()>1){
		sims[i] = Q.top();
		Q.pop();
		sims[j] = Q.top();
		Q.pop();

		int total = sims[i].value.count + sims[j].value.count;
		char sym;

		if(sims[i].value.value < sims[j].value.value){
			sym = sims[i].value.value;
		}else{
			sym = sims[j].value.value;
		}

		Q.push(bnode<symbol>(symbol(sym, total), &sims[i], &sims[j]));

		i+=2;
		j+=2;
	}

	ptr = const_cast<bnode<symbol> *>(&Q.top());
	return ptr;
}
	

// IMPLEMENT YOUR FUNCTION print_dictionary
void print_dictionary(std::ostream& os, bnode<symbol>* root){

	if(root->left != nullptr){
        stringer+="0";
        print_dictionary(os, root->left);
    }
    
    if(root->left == nullptr && root->right== nullptr){
        os<< root->value.value<< " "<< stringer<< std::endl;
        stringer.pop_back();
        return;
    }
    
    if(root->right != nullptr){
        stringer+="1";
        print_dictionary(os,root->right);
    }
    stringer.pop_back();
}

// IMPLEMENT YOUR FUNCTION release_tree
void release_tree(bnode<symbol>* root){
	while(!Q.empty()){
		Q.pop();
	}
	//delete root;
}

#endif // A6_HPP
