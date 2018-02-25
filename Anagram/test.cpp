// clang-format off
#include <climits>
#include <stdexcept>
#include <string>
#include <vector>
#include "Anagram.hpp"

#define BOOST_TEST_MODULE Anagram
#include <boost/test/included/unit_test.hpp>
// clang-format on

BOOST_AUTO_TEST_CASE(no_matches) {
    Anagram anagram("diaper");
    auto& matches = anagram.matches({"hello", "world", "zombies", "pants"});
    std::vector<std::string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_simple_anagram) {
    Anagram anagram("ant");
    auto& matches = anagram.matches({"tan", "stand", "at"});
    std::vector<std::string> expected{"tan"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(does_not_detect_false_positives) {
    Anagram anagram("galea");
    auto& matches = anagram.matches({"eagle"});
    std::vector<std::string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_multiple_anagrams) {
    Anagram anagram("master");
    auto& matches = anagram.matches({"stream", "pigeon", "maters"});
    std::vector<std::string> expected{"stream", "maters"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(does_not_detect_anagram_subsets) {
    Anagram anagram("good");
    auto& matches = anagram.matches({"dog", "goody"});
    std::vector<std::string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_anagram) {
    Anagram anagram("listen");
    auto& matches = anagram.matches({"enlists", "google", "inlets", "banana"});
    std::vector<std::string> expected{"inlets"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_multiple_anagrams2) {
    Anagram anagram("allergy");
    auto& matches = anagram.matches({"gallery", "ballerina", "regally", "clergy", "largely", "leading"});
    std::vector<std::string> expected{"gallery", "regally", "largely"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(detects_anagrams_case_insensitively) {
    Anagram anagram("Orchestra");
    auto& matches = anagram.matches({"cashregister", "Carthorse", "radishes"});
    std::vector<std::string> expected{"Carthorse"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(does_not_detect_a_word_as_its_own_anagram) {
    Anagram anagram("banana");
    auto& matches = anagram.matches({"Banana"});
    std::vector<std::string> expected;

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}

BOOST_AUTO_TEST_CASE(matches_accepts_std_string_arguments) {
    Anagram anagram("ant");
    auto& matches = anagram.matches({"stand", "tan", "at"});
    std::vector<std::string> expected{"tan"};

    BOOST_REQUIRE_EQUAL_COLLECTIONS(expected.begin(), expected.end(), matches.begin(), matches.end());
}
