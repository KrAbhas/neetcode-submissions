class Solution {
public:
    vector<string> ans;

    void genBrackets(string &s, vector<int> &choice, int n) {
        for (int i = 0; i < 2; i++) {
            if (choice[i] < 0 || (i == 1 && choice[1] <= choice[0])) continue;
            s += i == 0? "(" : ")";
            choice[i]--;
            if (choice[1] == 0 && choice[0] == 0) ans.push_back(s);
            else genBrackets(s, choice, n);
            s.pop_back();
            choice[i]++;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<int> choice;
        choice = {n, n};
        string s = "";
        genBrackets(s, choice, n);
        return ans;
    }
};
