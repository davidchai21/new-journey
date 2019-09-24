// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        if (reader.get(0)==bound) return -1;
        int base = 1;
        while (1) {
            int cur = reader.get(base-1);
            if (cur == target) return base-1;
            else if (cur<target) base<<=1;
            else break;
        }
        base>>=1;
        cout<<base<<endl;
        int left = base;
        int right = base*2-1;
        while (left+1<right) {
            int mid = left + (right - left)/2;
            int t = reader.get(mid);
            if (t==target) return mid;
            else if (t<target) left = mid+1;
            else right = mid - 1;
        }
        if (reader.get(left)==target) return left;
        if (reader.get(right)==target) return right;
        return -1;
    }
private:
    const int bound = 2147483647;
};

// Solution based on range:
// Forward declaration of ArrayReader class.
class ArrayReader;

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = 20000;
        while (left + 1 < right) {
            int mid = left + (right - left);
            int cur = reader.get(mid);
            if (cur == target) return mid;
            else if (cur<target) left = mid+1;
            else right = mid-1;
        }
        if (reader.get(left)==target) return left;
        if (reader.get(right)==target) return right;
        return -1;
    }
};