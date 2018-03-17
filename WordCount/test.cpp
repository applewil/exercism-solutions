// clang-format off
#include <algorithm>
#include <locale>
#include <string>
#include <unordered_map>
#include "WordCount.hpp"

#define BOOST_TEST_MODULE WordCount
#include <boost/test/included/unit_test.hpp>
// clang-format on

using namespace std;

BOOST_AUTO_TEST_CASE(counts_one_word) {
    WordCount word_count("word");
    const unordered_map<string, int> expected{{"word", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(counts_one_of_each) {
    WordCount word_count("one of each");
    const unordered_map<string, int> expected{{"one", 1}, {"of", 1}, {"each", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(counts_multiple_occurrences) {
    WordCount word_count("one fish two fish red fish blue fish");
    const unordered_map<string, int> expected{{"one", 1}, {"fish", 4}, {"two", 1}, {"red", 1}, {"blue", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(ignores_punctuation) {
    WordCount word_count("car : carpet as java : javascript!!&@$%^&");
    const unordered_map<string, int> expected{{"car", 1}, {"carpet", 1}, {"as", 1}, {"java", 1}, {"javascript", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(includes_numbers) {
    WordCount word_count("testing, 1, 2 testing");
    const unordered_map<string, int> expected{{"testing", 2}, {"1", 1}, {"2", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(normalizes_case) {
    WordCount word_count("go Go GO");
    const unordered_map<string, int> expected{{"go", 3}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(counts_constructor) {
    WordCount word_count("constructor Constructor");
    const unordered_map<string, int> expected{{"constructor", 2}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(counts_multiline) {

    WordCount word_count("hello\nworld");
    const unordered_map<string, int> expected{{"hello", 1}, {"world", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(count_everything_just_once) {
    WordCount word_count("all the kings horses and all the kings men");
    const unordered_map<string, int> expected{{"all", 2},    {"the", 2}, {"kings", 2},
                                              {"horses", 1}, {"and", 1}, {"men", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(handles_cramped_list) {

    WordCount word_count("one,two,three");
    const unordered_map<string, int> expected{{"one", 1}, {"two", 1}, {"three", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(with_apostrophes) {

    WordCount word_count("First: don't laugh. Then: don't cry.");
    const unordered_map<string, int> expected{{"first", 1}, {"don't", 2}, {"laugh", 1}, {"then", 1}, {"cry", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(with_free_standing_apostrophes) {

    WordCount word_count("go ' Go '' GO");
    const unordered_map<string, int> expected{{"go", 3}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(with_apostrophes_as_quotes) {
    WordCount word_count("She said, 'let's meet at twelve o'clock'");
    const unordered_map<string, int> expected{{"she", 1}, {"said", 1},   {"let's", 1},  {"meet", 1},
                                              {"at", 1},  {"twelve", 1}, {"o'clock", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(starts_with_symbol) {
    WordCount word_count("!hello world");
    const unordered_map<string, int> expected{{"hello", 1}, {"world", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(ends_with_symbol) {
    WordCount word_count("hello world!");
    const unordered_map<string, int> expected{{"hello", 1}, {"world", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(handles_hyphens) {
    WordCount word_count("A fox-trot above my head is a gold-moon-shot- or a g-m-s-");
    const unordered_map<string, int> expected{{"a", 3},  {"fox-trot", 1},       {"above", 1}, {"my", 1},   {"head", 1},
                                              {"is", 1}, {"gold-moon-shot", 1}, {"or", 1},    {"g-m-s", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}

BOOST_AUTO_TEST_CASE(handles_symbols) {
    WordCount word_count("I am will.i.am!");
    const unordered_map<string, int> expected{{"i", 1}, {"am", 1}, {"will.i.am", 1}};
    const unordered_map<string, int>& actual = word_count.count();
    BOOST_TEST(expected == actual);
}
