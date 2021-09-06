#include <iostream>
#include"Vector.h"
#include"Vector.cpp"

#include <vector>

int main() {
    Vector<int> vector;
    vector.push_back(2);
    vector.print();

    vector.push_back(3);
    vector.print();

    vector.push_back(4);
    vector.print();
    std::cout << "At index 0:" << " ";
    std::cout << vector.at(0) << std::endl;


    std::cout <<"reserve:"<<" ";
    vector.reserve(1);
    vector.print();

    std::cout << "Front: ";
    vector.front();
    std::cout << vector.front() << std::endl;

    std::cout << "back: " ;
    vector.back();
    std::cout << vector.back() << std::endl;


    std::cout <<"resize:"<<" ";
vector.resize(5);
vector.print();


Vector<int>vec2;
vec2.push_back(5);
    vec2.push_back(6);
    vec2.push_back(8);
    vec2.push_back(7);
    std::cout << "swap: ";
vector.swap(vec2);
vector.print();
vec2.print();//insert erase (cppreference)(03.09 !!!!!!!!!!!)




//проверка insert and erase,пожалуйста работай
std::vector<int>valiko{0,1,2,3,4,5,6,7,8,9};
    std::cout << "my vector contains:";
    for (unsigned i=0; i<valiko.size(); ++i)
        std::cout << ' ' << valiko[i];
    std::cout << '\n';
valiko.erase(valiko.begin());
    std::cout << "now my vector contains:";
    for (unsigned i=0; i<valiko.size(); ++i)
        std::cout << ' ' << valiko[i];
    std::cout << '\n';


    valiko.insert(valiko.begin(),3);
    std::cout << "after insert my vector contains:";
    for (unsigned i=0; i<valiko.size(); ++i)
        std::cout << ' ' << valiko[i];
    std::cout << '\n';

}