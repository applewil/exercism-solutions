#ifndef LEAPYEAR_HPP
#define LEAPYEAR_HPP

class Hamming {
public:
    static unsigned int compute(std::string s, std::string t) {
        unsigned int distance;
        size_t i;

        if (s.length() != t.length()) throw std::domain_error("Strings not equal length");
        for (i = 0, distance = 0; i < s.length(); i++) {
            if (s.at(i) != t.at(i)) {
                distance++;
            }
        }
        return distance;
    }
};

#endif