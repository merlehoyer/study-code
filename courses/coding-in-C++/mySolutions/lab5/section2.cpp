#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

int main(){

    //------------------------- sort + inspect ------------------------------//
    std::vector<int> v_record_samples ={42,17,42,5,99,17,63,12};

    // printing original vector
    for(int x : v_record_samples){
        std::cout << x << " ";
    }
    std::cout<<std::endl;

    std::sort(v_record_samples.begin(), v_record_samples.end());

    //printing sorted vector
    for(int x : v_record_samples){
        std::cout << x << " ";
    }
    std::cout<<std::endl;
    //searching for number
    std::vector<int>::iterator it;
    it= std::find(v_record_samples.begin(), v_record_samples.end(), 63);

    if(it != v_record_samples.end()){
        std::cout<< *it << " found"<< std::endl;
    }else{
        std::cout<<"not found"<<std::endl;
    }

    //--------- noise cleanup ------------//

    std::vector<int> v_dirty_records={7,-1,13,-1,21,21,8,-1,8};
    
    std::vector<int>::iterator it_cleanup;
    
    std::replace(v_dirty_records.begin(), v_dirty_records.end(), -1, 0);
    for(int x : v_dirty_records){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;
/*
    while(it_cleanup!=v_dirty_records.end()){
        it_cleanup = std::find(v_dirty_records.begin(), v_dirty_records.end(), -1);
        *it_cleanup= 0;
        
        for(int x : v_dirty_records){
            std::cout<<x<<" ";
        }
        std::cout<<std::endl;

    }
*/

    int number_elem=0;

    number_elem= std::count(v_dirty_records.begin(), v_dirty_records.end(), 8);
    
    std::cout <<number_elem<<std::endl;

    std::reverse(v_dirty_records.begin(),v_dirty_records.end());

    for(int x : v_dirty_records){
            std::cout<<x<<" ";
    }
        
    std::cout<<std::endl;

    //--------- manual iterator -----------//

    for(it= v_record_samples.begin(); it != v_record_samples.end(); it++){
        std::cout << *it << " ";
    }


    return 0;
}
