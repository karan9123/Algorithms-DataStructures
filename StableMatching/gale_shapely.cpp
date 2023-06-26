#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>




int main(){
    size_t size;
    std::cout<< "Enter the number of elements: ";
    std::cin >> size;
    // set to keep a track of all unique hospitals
    std::unordered_set <std::string> hospitals;
    // false means the resident hasn't been asked yet
    std::unordered_map <std::string, bool> residents;
    // false means hospitals without a resident and true means the hospitals which have taken a resident
    std::unordered_map <bool, std::vector<std::string>> hospitals_status_map;
    // a map with hospital as key and residents as vector with the order of preference from hospital
    std::unordered_map <std::string, std::vector<std::string>> hospital_map;
    // a map with resident as the key and value is a map with the rank of hospital as key and hospital's name as value
    std::unordered_map <std::string, std::unordered_map<int, std::string>> resident_map;
    // one-to-one map of matched hospital and its resident
    std::unordered_map <std::string, std::string> hospital_resident_map;


    std::string str_input;
    std::cout<<"Enter hospitals:" << std::endl;
    for(size_t i = 0; i< size; i++){
        std::cin >> str_input;
        hospitals.insert(str_input);
        hospital_map[str_input] = std::vector<std::string>(size);
    }

    std::cout<< std::endl <<"Enter Residents:" << std::endl;
    for(size_t i = 0; i< size; i++){
        std::cin >> str_input;
        residents[str_input] = false;
    }

    int rank = 0;
    std::cout << "Enter the rank for residents for Hospitals:" << std::endl;
    for (std::string hospital: hospitals){
        hospitals_status_map[false].push_back(hospital);
        std::cout << hospital << ": " << std::endl;
        std::unordered_set <int> rank_set ;
        for (auto resident : residents){
            std::cout << "Rank for " << resident.first << ": ";
            std::cin >> rank;
            while (rank_set.count(rank) > 0){
                std::cout << "This rank has already been assigned to " << hospital_map[hospital][rank-1] << ". Please enter another rank under "<< size << std::endl;
                std::cout << "Rank for " << resident.first << ": ";
                std::cin >> rank; 
            }
            rank_set.insert(rank);
            (hospital_map[hospital])[rank-1] = resident.first;
        }
    }


    std::cout<< "Enter the rank for hospitals for residents"<< std::endl;
    for (auto resident: residents){
        std::cout << resident.first<< ": " << std::endl;
        for(std::string hospital: hospitals){
            std::cout << "Rank for "<< hospital << ": ";
            std::cin >> rank;
            while((resident_map[resident.first]).count(rank-1) > 0){
                std::cout << "This rank has already been assigned to " << resident_map[resident.first][rank-1] << ". Please enter another rank under "<< size << std::endl;
                std::cout << "Rank for " << hospital << ": ";
                std::cin >> rank; 
            }
            resident_map[resident.first][rank-1] = hospital;
        }
    }


    for (auto& vector: hospital_map){
        std::cout << vector.first <<": " << std::endl;
        rank = 1;
        for (std::string resident: vector.second){
            std::cout << rank << ": " << resident << "   ";
            rank ++;
        }
        std::cout << std::endl;
    }

    for (auto& mmap: resident_map){
        std::cout << mmap.first << std::endl;
        for (auto& map: mmap.second){
            std::cout<< map.first << ": "<< map.second << "  ";
        }
         std::cout << std::endl;
    }

    
    while(hospitals_status_map[false].size()){
        std::string current_hospital = (hospitals_status_map[false]).back();
        rank = 0;
        for(int i = 0; i < size; i ++){
            std::string current_resident = hospital_map[current_hospital][i];
            if (!residents[current_resident]){
                hospital_resident_map[current_hospital] = current_resident;
                (hospitals_status_map[false]).pop_back();
                hospitals_status_map[true].push_back(current_hospital);
                break;
            }else if(residents[current_resident] && resident_map[current_resident]){}
        }


    }
    
        
    return 0;
}