class MedianFinder {
public:
    multiset<int> ms;

    MedianFinder() {
    }

    void addNum(int num) {
        ms.insert(num);
    }

    double findMedian() {
        int sz = ms.size();
        auto it = ms.begin();
        for (int i = 0; i < (sz - 1) / 2; ++i)
            ++it;
        double ret = *it;
        if (sz % 2 == 0) {
            ++it;
            ret = (ret + *it) / 2;
        }
        return ret;
    }
};