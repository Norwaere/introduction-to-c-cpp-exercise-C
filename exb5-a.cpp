#include <iostream>
#include <random>
#include <set>

std::set<int>::iterator func (std::set<int>::iterator lbound, std::set<int>::iterator ubound) {
    std::set<int>::iterator next_val = std::next(lbound);
    while (next_val != ubound) {
        if (*lbound +1 != *next_val){
            return next_val;
        }
        lbound = next_val;
        next_val = std::next(lbound);
    }
    return ubound;
}

int main() { 
    // lower and upper bound of rng and numbers to be generated
    int min = 0, max = 9, len = 8;
    std::cout << "set input lenght:" << std::endl;
    std::cin >> len;

    std::random_device seed;
    std::mt19937 mt(seed());
    std::uniform_int_distribution<int> dist(min,max);
    std::set <int> arr;
    std::cout << "The set {";

    //create set... not sure if I should have saved the original order as well or
    //  if just the set is ok
    for (int i = 0; i<len; ++i){
        int temp = dist(mt); 
        arr.insert(temp);
        std::cout << temp;
        if (i<len-1) {std::cout << ", ";}
    }
    std::cout << "} is decomposed as " << std::endl;
    std::set<int>::iterator start = arr.begin(), stop = arr.end();
    int i = 0;

    //main loop
    while (start != stop) {
        if (i!=0)  std::cout << " U ";
        std::cout << "[" << *start;

        //function
        std::set<int>::iterator new_start = func(start, stop);

        std::cout << ", " << *std::prev(new_start) << "]";
        start = new_start;
        i++;
        //emergency break
        if (i > len) {
            std::cout << "\n endless loop? something broke again?" <<std::endl;
            break;
        }
    }

    std::cout << "." << std::endl;
    std::cout << "Full set: [";
    for(auto val: arr)  std::cout << val << " ";
    std::cout << "]" << std::endl;

    return 0;
}