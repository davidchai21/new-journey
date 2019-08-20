class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dic(wordList.begin(), wordList.end());
        unordered_set<string> head, tail, *phead, *ptail;
        if (dic.find(endWord)==dic.end()) return 0;
        head.insert(beginWord);
        tail.insert(endWord);
        int res = 2;
        while (!head.empty() && !tail.empty()) {
            if (head.size()<tail.size()) {
                phead = &head;
                ptail = &tail;
            } else {
                phead = &tail;
                ptail = &head;
            }
            unordered_set<string> t;
            for (auto it = phead->begin();it!=phead->end();it++) {
                string str = *it;
                for (int i=0;i<str.size();i++) {
                    char c = str[i];
                    for (int j=0;j<26;j++) {
                        str[i]='a'+j;
                        if (ptail->find(str)!=ptail->end()) return res;
                        if (dic.find(str)!=dic.end()) {
                            t.insert(str);
                            dic.erase(str);
                        }
                    }
                    str[i]=c;
                }
            }
            phead->swap(t);
            res++;
        }
        return 0;
    }
};