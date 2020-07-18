class Solution {
public:
    
    bool checkForValidity(const string & str)
    {
        stack<char> stk;
        for (auto itr : str)
        {
            switch(itr)
            {
                case '(':
                    stk.push(itr);            
                    break;
                case ')':
                    if (stk.empty()) 
			            return false; 
                    if (stk.top() == '(')
                        stk.pop();
                    break;
            }
        }  
        return stk.empty();
    }
    bool shouldSwap(string str, int start, int curr) 
    { 
        for (int i = start; i < curr; i++)  
            if (str[i] == str[curr]) 
                return 0; 
        return 1; 
    } 
    void helper (string str, int l, int r)
    {
        if (l == r)
        {
            if (checkForValidity(str))
            {
                combinations.push_back(str);
            }
            //return;
        }
        for (int i = l; i < r; i++ )
        {
            if (shouldSwap(str, l, i))
            {
                swap(str[i], str[l]);    
                helper(str, l+1, r);//0,1,
                swap(str[i], str[l]);
            }

        }
    }
    vector<string> generateParenthesis(int n) {
        brackets.clear();
        
        for (int i = 0; i < n; i++)
        {
            brackets +="()";    
        }
        helper (brackets, 0, brackets.length());
        return combinations;
    }
    vector <string> combinations;
    set<int> s;
    string brackets;
};
