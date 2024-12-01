#include "pch.h"

//parse function
template <typename T>
void parse(T data, std::vector<std::string>* input){
    int sum = 0;
    
    std::vector<int> list1;
    std::vector<int> list2;
    
    for(int i = 0; i < input->size(); i++){
        int list1Num = std::stoi(input->at(i).substr(0, 5));
        int list2Num = std::stoi(input->at(i).substr(8, 5));
        list1.push_back(list1Num);
        list2.push_back(list2Num);
    }
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    for(int i = 0; i < list1.size(); i++) {
        sum += abs(list1[i] - list2[i]);
    }
    std::cout << sum << std::endl;
    
    //similarity stuff
    int similarity = 0;
    std::unordered_map<int, int> list2Frequency;
    for(int i = 0; i < list2.size(); i++) {
        auto ret = list2Frequency.emplace(list2.at(i), 1);
        if(!ret.second) {
            ret.first->second++; 
        }
    }

    for(int i = 0; i < list1.size(); i++) {
        try {
            similarity += list1[i] * list2Frequency.at(list1[i]);
        } catch(std::out_of_range) {
            //then the value doesn't appear so don't do anything.
        }
        
    }
    std::cout << similarity << std::endl;
    return;
}


//read function
template<typename T>
int read(T data){
    std::ifstream fajl("input.txt");
    if (!fajl){
        fmt::print("Error opening input.txt: {}\n", strerror(errno));
        return 1;
    }

    std::vector<std::string> input;
    std::string trsh;
    while(getline(fajl, trsh)){
        //here you can also do some work on the input strings
        input.emplace_back(trsh);
    }

    fajl.close();

    parse(data, &input);
    return 0;
}


//write function
template<typename T>
int write(T data){
    std::ofstream fajl("output.txt", std::fstream::trunc);
    if (!fajl){
        fmt::print("Error opening output.txt: {}\n", strerror(errno));
        return 1;
    }


    //insert the way you want the data to be outputed

    fajl.close();
    return 0;
}