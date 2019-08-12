class StringIterator {
public:
    StringIterator(string compressedString) {
        str = compressedString;
        index = 0;
        count = 0;
        cur = 0;
        while (index < str.size()) {
            if (isalpha(str[index])) {
                if (cur == 0) cur = str[index];
                else break;
            } else {
                count = count*10+str[index]-'0';
            }
            index++;
        }
    }
    
    char next() {
        if (count) {
            count--;
            return cur;
        }
        if (index>=str.size()) return ' ';
        cur = str[index++];
        while (index<str.size()) {
            if (isdigit(str[index])) count = count*10+str[index++]-'0';
            else break;
        }
        count--;
        return cur;
    }
    
    bool hasNext() {
        return count || index<str.size();
    }
private:
    string str;
    int index;
    char cur;
    int count;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */