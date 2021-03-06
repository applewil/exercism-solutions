// clang-format off
#include <cctype>
#include <unordered_map>
#include <vector>
#include "Etl.hpp"

#define BOOST_TEST_MODULE Etl
#include <boost/test/included/unit_test.hpp>
// clang-format on

using namespace std;

BOOST_AUTO_TEST_CASE(transforms_one_value) {
    const unordered_map<int, vector<char>> old{{1, {'A'}}};
    const Etl etl(old);
    const auto& actual(etl.transform());
    const unordered_map<char, int> expected{{'a', 1}};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(transforms_more_values) {
    const unordered_map<int, vector<char>> old{{1, {'A', 'E', 'I', 'O', 'U'}}};
    const Etl etl(old);
    const auto& actual(etl.transform());
    const unordered_map<char, int> expected{{'a', 1}, {'e', 1}, {'i', 1}, {'o', 1}, {'u', 1}};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(transforms_more_keys) {
    const unordered_map<int, vector<char>> old{{1, {'A', 'E'}}, {2, {'D', 'G'}}};
    const Etl etl(old);
    const auto& actual(etl.transform());
    const unordered_map<char, int> expected{{'a', 1}, {'e', 1}, {'d', 2}, {'g', 2}};

    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(transforms_a_full_dataset) {
    const unordered_map<int, vector<char>> old{{1, {'A', 'E', 'I', 'O', 'U', 'L', 'N', 'R', 'S', 'T'}},
                                               {2, {'D', 'G'}},
                                               {3, {'B', 'C', 'M', 'P'}},
                                               {4, {'F', 'H', 'V', 'W', 'Y'}},
                                               {5, {'K'}},
                                               {8, {'J', 'X'}},
                                               {10, {'Q', 'Z'}}};
    const Etl etl(old);
    const auto& actual(etl.transform());
    const unordered_map<char, int> expected{{'a', 1}, {'b', 3}, {'c', 3},  {'d', 2}, {'e', 1}, {'f', 4}, {'g', 2},
                                            {'h', 4}, {'i', 1}, {'j', 8},  {'k', 5}, {'l', 1}, {'m', 3}, {'n', 1},
                                            {'o', 1}, {'p', 3}, {'q', 10}, {'r', 1}, {'s', 1}, {'t', 1}, {'u', 1},
                                            {'v', 4}, {'w', 4}, {'x', 8},  {'y', 4}, {'z', 10}};

    BOOST_TEST(expected == actual);
}
