// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     */
    int read(char *buf, int n) {
        int index = 0;
        char* ptr = new char[4];
        for (int i=0;i<n/4;i++) {
            int num = read4(ptr);
            for (int j=0;j<num;j++) buf[index++]=ptr[j];
        }
        int residue = n%4;
        if (residue) {
            int num = read4(ptr);
            int size = min(num, residue);
            for (int i=0;i<size;i++) buf[index++]=ptr[i];
        }
        return index;
    }
};