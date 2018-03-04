#ifndef ETL_HPP
#define ETL_HPP

template <class K, class V>
class Etl {
private:
    const std::unordered_map<K, std::vector<V>> subject;
    std::unordered_map<V, K> transformed;

public:
    Etl(const std::unordered_map<K, std::vector<V>> subject) : subject(subject) {}
    const std::unordered_map<V, K>& transform() {
        typename std::unordered_map<K, std::vector<V>>::const_iterator i;
        typename std::vector<V>::const_iterator j;

        for (i = subject.cbegin(); i != subject.cend(); i++) {
            for (j = i->second.cbegin(); j != i->second.cend(); j++) {
                transformed.insert({tolower(*j), i->first});
            }
        }
        return transformed;
    }
};

#endif
