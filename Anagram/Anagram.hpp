#ifndef ANAGRAM_HPP
#define ANAGRAM_HPP

class Anagram {
private:
    static const size_t CHAR_SET_LENGTH = CHAR_MAX - CHAR_MIN + 1;
    static const char TO_LOWERCASE_BIT_PATTERN = 0x20;
    std::string subject;
    std::vector<std::string> _matches;
    static bool match(std::string a, std::string b) {
        int a_map[CHAR_SET_LENGTH]{0};
        int b_map[CHAR_SET_LENGTH]{0};
        char a_char;
        char b_char;
        bool equal(true);
        size_t i;

        if (a.length() != b.length()) return false;
        for (i = 0; i < a.length(); i++) {
            a_char = a[i] | TO_LOWERCASE_BIT_PATTERN;
            b_char = b[i] | TO_LOWERCASE_BIT_PATTERN;
            a_map[(int) a_char]++;
            b_map[(int) b_char]++;
            if (a_char != b_char) equal = false;
        }
        if (equal) return false;
        for (i = 0; i < CHAR_SET_LENGTH; i++) {
            if (a_map[i] != b_map[i]) return false;
        }
        return true;
    }

public:
    Anagram(std::string subject) : subject(subject) {}
    std::vector<std::string>& matches(std::vector<std::string> candidates) {
        std::vector<std::string>::iterator it;

        for (it = candidates.begin(); it != candidates.end(); it++) {
            if (match(subject, *it)) _matches.push_back(*it);
        }
        return _matches;
    }
};

#endif
