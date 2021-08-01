#include <algorithm>
#include "DoublyLinkedList.h"
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <random>

void generateList(DoublyLinkedList<int>& list) {

    std::random_device device;
    std::mt19937 generator{device()};
    std::uniform_int_distribution<> distr{0, 9};

    std::generate(list.begin(), list.end(), [&]{
        return distr(generator);
    });

}

double calculateArithmeticMean(DoublyLinkedList<int>& list) {
    return std::accumulate(list.begin(), list.end(), 0.0) / list.getSize();
}

void printCountedDigits(DoublyLinkedList<int>& list) {

    std::map<int, std::size_t> counter;
    for(auto&& e : list) {
        ++counter[e];
    }

    std::cout << "ilosci wystapien roznych cyfr:\n";
    for(auto&& e : counter) {
        std::cout << e.first << " -> " << e.second << '\n';
    }

}

template <class ForwardIt>
void quicksort(ForwardIt first, ForwardIt last) {

    if(first == last) {
        return;
    }

    auto pivot = *std::next(first, std::distance(first,last)/2);

    const ForwardIt middle1 = std::partition(first, last, [pivot](const auto& em) {
        return em < pivot;
    });

    const ForwardIt middle2 = std::partition(middle1, last, [pivot](const auto& em) {
        return !(pivot < em);
    });

    quicksort(first, middle1);
    quicksort(middle2, last);

}

bool hasAnyValueGreaterThan10(DoublyLinkedList<int>& list) {

    return std::any_of(list.begin(), list.end(), [](int value) {
        return value > 10;
    });

}

int main() {

    DoublyLinkedList<int> list(100);

    generateList(list);
    std::cout << "lista: " << list << '\n';

    std::cout << "srednia: " << calculateArithmeticMean(list) << '\n';

    printCountedDigits(list);

    quicksort(list.begin(), list.end());
    std::cout << "posortowana lista: " << list << '\n';

    std::cout << "czy wystapila wartosc wieksza niz 10: ";
    std::cout << std::boolalpha << hasAnyValueGreaterThan10(list)  << '\n';


}
