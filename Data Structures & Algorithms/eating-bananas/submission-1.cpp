class Solution {
private:
    bool good (vector<int> &piles, int k, int h) {
        for (int pile: piles) {
            h -= ceil(pile * 1.0 / k);
            if (h < 0) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0; int r = 1e9 + 1;
        while (l + 1 < r) {
            int mid = (l + r) / 2;
            if (good(piles, mid, h)) 
                r = mid;
            else l = mid;
        }
        return r;
    }
};
