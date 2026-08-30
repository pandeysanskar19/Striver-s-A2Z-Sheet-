class Solution {
public:
// TIME COMPLEXITY : O(N) , SPACE COMPLEXITY : O(1).
    string removeOuterParentheses(string s) {
        string result ="";
        int level =0;

        for(char ch : s){
            if(ch =='('){
                if(level > 0){
                    result += '(';
                }
                level++;
            }
            else if(ch == ')'){
                level --;
                if(level>0){
                    result +=')';
                }
            }
        }
        return result;
    }
};
