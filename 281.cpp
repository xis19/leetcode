#include <list>
#include <vector>

class ZigzagIterator {
    std::list<std::pair<size_t, size_t>> m_List;
    std::list<std::pair<size_t, size_t>>::iterator m_Iter;
    std::vector<std::vector<int>*> m_pV;
public:
    ZigzagIterator(std::vector<int>& v1, std::vector<int>& v2) {
        if (v1.size() > 0) {
            m_pV.push_back(&v1);
            m_List.push_back(std::make_pair(m_pV.size() - 1, 0));
        }

        if (v2.size() > 0) {
            m_pV.push_back(&v2);
            m_List.push_back(std::make_pair(m_pV.size() - 1, 0));
        }
        m_Iter = m_List.begin();
    }

    int next() {
        auto value = m_pV[m_Iter->first]->at(m_Iter->second);
        if ((++m_Iter->second) >= m_pV[m_Iter->first]->size()) {
            m_Iter = m_List.erase(m_Iter);
        } else {
            m_Iter = std::next(m_Iter);
        }
        if (m_Iter == m_List.end())
            m_Iter = m_List.begin();
        return value;
    }

    bool hasNext() {
        return m_List.size() != 0;
    }
};
