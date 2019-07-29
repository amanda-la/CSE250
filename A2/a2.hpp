// File: a2.hpp
// Amanda 
// La
// I AFFIRM THAT WHEN WORKING ON THIS ASSIGNMENT
// I WILL FOLLOW UB STUDENT CODE OF CONDUCT, AND
// I WILL NOT VIOLATE ACADEMIC INTEGRITY RULES

#ifndef A2_HPP
#define A2_HPP

// MAKE SURE TO UPDATE YOUR INFORMATION IN THE HEADER OF THIS FILE
// IMPLEMENT MISSING FUNCTIONALITY OF key_value_sequences IN THIS FILE
// YOU ARE NOT ALLOWED TO INCLUDE ANY OTHER HEADERS THAN
// <algorithm>, <list>, <vector>
// YOU CAN CHANGE/EDIT ANY CODE IN THIS FILE AS LONG AS SEMANTICS IS UNCHANGED
// AND MATCHES SPECIFICATION PROVIDED IN THE ASSIGNMENT TEXT

#include <algorithm>
#include <list>
#include <vector>

class key_value_sequences {
public:
    // YOU SHOULD USE C++ CONTAINERS TO AVOID RAW POINTERS
    // IF YOU DECIDE TO USE POINTERS, MAKE SURE THAT YOU MANAGE MEMORY PROPERLY

    // IMPLEMENT ME: SHOULD RETURN SIZE OF A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN 0

    int size(int key) const{
        int num_el = 0;
        for(int m = 0; m < this->keys_.size(); ++m){
            if(this->keys_[m].front() == key){
                num_el = this->keys_[m].size()-1;
                break;
            }
        }
        return num_el;
    }

    // IMPLEMENT ME: SHOULD RETURN POINTER TO A SEQUENCE FOR GIVEN KEY
    // IF NO SEQUENCE EXISTS FOR A GIVEN KEY RETURN nullptr
    const int* data(int key) const{
        const int* ptr = nullptr;
       
        for(int m = 0; m < this->keys_.size(); ++m){
            if(this->keys_[m].front() == key){
                ptr = this->keys_[m].data();
                ++ptr;
                break;
            }
        }
        return ptr;
    }

    // IMPLEMENT ME: INSERT VALUE INTO A SEQUENCE IDENTIFIED BY GIVEN KEY
    void insert(int key, int value) {
        int i = 0;
        for(int m = 0; m < this->keys_.size(); ++m){
            if(this->keys_[m].front() == key){
                this->keys_[m].push_back(value);
                ++i;
                break;
            }
        }
        if(i == 0){
            this->keys_.push_back(sequence_);
            this->keys_.back().push_back(key);
            this->keys_.back().push_back(value);
        }
        else{
            --i;
        }
    }

private: 
     std::vector<int> sequence_;
     std::vector< std::vector<int> > keys_;
    // int key;
    // int value;
    //int* ptr;

}; // class key_value_sequences



#endif // A2_HPP
