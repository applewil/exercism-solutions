// clang-format off
#include <stdexcept>
#include <string>
#include "Hamming.hpp"

#define BOOST_TEST_MODULE Hamming
#include <boost/test/included/unit_test.hpp>
// clang-format on

BOOST_AUTO_TEST_CASE(no_difference_between_identical_strands) {
    BOOST_REQUIRE_EQUAL(0, Hamming::compute("A", "A"));
}

BOOST_AUTO_TEST_CASE(complete_hamming_distance_for_single_nucleotide_strand) {
    BOOST_REQUIRE_EQUAL(1, Hamming::compute("A", "G"));
}

BOOST_AUTO_TEST_CASE(complete_hamming_distance_for_small_strand) {
    BOOST_REQUIRE_EQUAL(2, Hamming::compute("AG", "CT"));
}

BOOST_AUTO_TEST_CASE(small_hamming_distance) {
    BOOST_REQUIRE_EQUAL(1, Hamming::compute("AT", "CT"));
}

BOOST_AUTO_TEST_CASE(small_hamming_distance_in_longer_strand) {
    BOOST_REQUIRE_EQUAL(1, Hamming::compute("GGACG", "GGTCG"));
}

BOOST_AUTO_TEST_CASE(domain_error_when_first_string_is_longer) {
    BOOST_REQUIRE_THROW(Hamming::compute("AAAG", "AAA"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(domain_error_when_second_string_is_longer) {
    BOOST_REQUIRE_THROW(Hamming::compute("AAA", "AAAG"), std::domain_error);
}

BOOST_AUTO_TEST_CASE(large_hamming_distance) {
    BOOST_REQUIRE_EQUAL(4, Hamming::compute("GATACA", "GCATAA"));
}

BOOST_AUTO_TEST_CASE(hamming_distance_in_very_long_strand) {
    BOOST_REQUIRE_EQUAL(9, Hamming::compute("GGACGGATTCTG", "AGGACGGATTCT"));
}
