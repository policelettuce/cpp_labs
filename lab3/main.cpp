#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <random>
#include "CustomClass.hpp"

using namespace std;

int main() {
    // 1
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> size_dist(500, 1000);
    size_t N = size_dist(gen);

    std::vector<CustomClass> v1(N);
    std::uniform_int_distribution<> value_dist(1, 1000);
    std::generate(v1.begin(), v1.end(), [&](){
        return CustomClass(value_dist(gen), "random_string");
    });

    // 2
    size_t b = N >= 200 ? N - 200 : 0;
    size_t e = N - 1;
    std::vector<CustomClass> v2(v1.begin() + b, v1.begin() + e + 1);

    // 3
    std::uniform_int_distribution<size_t> distrib(20, 50);
    size_t n = distrib(gen);
    std::nth_element(v1.begin(), v1.end() - n, v1.end());
    std::sort(v1.end() - n, v1.end());
    std::list<CustomClass> list1;
    std::move(v1.end() - n, v1.end(), std::back_inserter(list1));
    v1.erase(v1.end() - n, v1.end());

    // 4
    std::nth_element(v2.begin(), v2.begin() + n, v2.end());
    std::sort(v2.end() - n, v2.end());
    std::list<CustomClass> list2;
    std::move(v2.begin(), v2.begin() + n, std::back_inserter(list2));
    v2.erase(v2.begin(), v2.begin() + n);

    // 5 - done in 3 and 4

    // 6
    double sum = std::accumulate(list1.begin(), list1.end(), 0.0, [](double acc, const CustomClass& obj){
        return acc + obj.value;
    });
    double avg = sum / list1.size();
    std::stable_partition(list1.begin(), list1.end(), [avg](const CustomClass& obj){
        return obj.value > avg;
    });

    // 7
    list2.remove_if([](const CustomClass& obj){
        return obj.isOdd();
    });

    // 8
    std::sort(v2.begin(), v2.end());
    std::vector<CustomClass> v3;
    std::set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), std::back_inserter(v3));

    // 9
    auto size1 = list1.size();
    auto size2 = list2.size();
    if (size1 > size2) {
        auto it = list1.begin();
        std::advance(it, size1 - size2);
        list1.erase(list1.begin(), it);
    } else if (size2 > size1) {
        auto it = list2.begin();
        std::advance(it, size2 - size1);
        list2.erase(list2.begin(), it);
    }
    std::list<std::pair<CustomClass, CustomClass>> list3;
    std::transform(list1.begin(), list1.end(), list2.begin(), std::back_inserter(list3),
                   [](const CustomClass& a, const CustomClass& b){
                       return std::make_pair(a, b);
                   });

    // 10
    size_t min_size = std::min(v1.size(), v2.size());
    std::vector<std::pair<CustomClass, CustomClass>> v_pairs;
    v_pairs.reserve(min_size);
    std::transform(v1.begin(), v1.begin() + min_size, v2.begin(), std::back_inserter(v_pairs),
                   [](const CustomClass& a, const CustomClass& b){
                       return std::make_pair(a, b);
                   });

    return 0;
}