#ifndef WORDCOUNT_HPP
#define WORDCOUNT_HPP

class WordCount {
private:
    std::string subject;
    std::unordered_map<std::string, int> wc;
    bool is_word_end(const char current, const char next) {
        return (std::isspace(current) || current == ',') || (!std::isalnum(current) && !std::isalnum(next));
    }

public:
    WordCount(const std::string subject) : subject(subject) {}
    const std::unordered_map<std::string, int>& count() {
        std::string::iterator left;
        std::string::iterator right;

        for (left = subject.begin(); left != subject.cend(); left++) {
            if (std::isalnum(*left)) {
                for (right = left; right != subject.cend(); right++) {
                    if (is_word_end(*right, *(right + 1))) break;
                    *right = std::tolower(*right);
                }
                wc[std::string(left, right)]++;
                left = right - 1;
            }
        }
        return wc;
    }
};

#endif
