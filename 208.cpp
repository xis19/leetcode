#include <array>
#include <string>
#include <unordered_map>

class Trie {
    struct Node {
        Node(char ch, bool end=false) : character(ch), hasEndHere(end), children() {}

        char character;
        bool hasEndHere;
        std::unordered_map<char, Node*> children;

        void append(char ch, bool end=false) {
            if (!getChild(ch)) {
                children[ch - 'a'] = new Node(ch, end);
            }
        }

        Node* getChild(char ch) {
            auto item = children.find(ch - 'a');
            if (item == children.end())
                return nullptr;
            return item->second;
        }
    };

    Node startNode;
public:
    Trie() : startNode('a', false) {}

    void insert(const std::string& word) {
        if (word.length() == 0) return;

        auto nodeIter = &startNode;
        for(auto ch: word) {
            nodeIter->append(ch);
            nodeIter = nodeIter->getChild(ch);
        }
        nodeIter->hasEndHere = true;
    }

    bool search(const std::string& word) {
        auto nodeIter = &startNode;
        for(auto ch: word) {
            auto next = nodeIter->getChild(ch);
            if (!next) return false;
            nodeIter = next;
        }
        return nodeIter->hasEndHere;
    }

    bool startsWith(const std::string& prefix) {
        auto nodeIter = &startNode;
        for(auto ch: prefix) {
            auto next = nodeIter->getChild(ch);
            if (!next) return false;
            nodeIter = next;
        }
        return true;
    }

    // FIXME Need destructor to free the memory
};
