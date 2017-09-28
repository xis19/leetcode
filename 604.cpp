class StringIterator {
    std::stringstream m_SS;

    char currChar;
    int currCount;

    char nextChar;
    int nextCount;
public:
    StringIterator(const std::string compressedString) : currChar(0), currCount(0), nextChar(0), nextCount(0) {
        m_SS << compressedString;

        if (!m_SS.eof()) {
            m_SS >> currChar >> currCount;
        }
        if (!m_SS.eof()) {
            m_SS >> nextChar >> nextCount;
        }
    }

    char next() {
        if (currCount == 0) {
            currChar = nextChar;
            currCount = nextCount;

            if (!m_SS.eof()) {
                m_SS >> nextChar >> nextCount;
            } else {
                nextChar = 0;
                nextCount = 0;
            }
        }

        if (currChar == 0) {
            return ' ';
        }
        --currCount;
        return currChar;
    }

    bool hasNext() const {
        return !(currCount == 0 && nextChar == 0);
    }
};
