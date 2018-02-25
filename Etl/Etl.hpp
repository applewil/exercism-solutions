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
        return transformed;
    }
};

#endif
