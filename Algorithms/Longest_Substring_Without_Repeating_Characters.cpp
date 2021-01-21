// Copyright 2020 AmberBhardwaj
// Licensed under MIT License or any later version

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 1) return 1;
     
        int cnt = 0;
        
        unordered_set<char> lookup;
        int start=0, move =0;
        /*
         Algorithm:
         ----------
         I took two pointers i.e. one for pointing to the start of an array and another
         for pointing to the start of the array but that pointer will move foward whenever
         there is no duplication (checking with the help of set ) between "start & move".
         
         If there is a duplicate then increment the start(Remove the value pointing by start 
         from the set don't increament move) and again check the string between "startd & move".
         
        */
        while(start < s.length() && move < s.length())
        {
            // If not found in lookup table
            //cout << "trying to find = " << s[move] <<"\n";
    
            if  ( ( lookup.find(s[move]) == lookup.end()) )
            {
                //cout << "adding Not Found = " << s[move] <<"\n";
                lookup.insert(s[move]);        
                cnt = std::max(cnt, move- start +1);
                //cout << "F = " << cnt << "\n";
                move++;
            }
            else
            {
                //cout << "Found = " << s[move] <<"\n";
                lookup.erase(s[start]);
                //cout << "removed = " << s[start] <<  " NF = " << cnt << "\n";
                start++;
            }
        }
        
        return cnt;
    }
};
