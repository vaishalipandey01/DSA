//Approach-1 (Using simple conversion)
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        
        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        
        string result= "";
        
        for(int number = 0; number <= 65536; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }
        
        return result.substr(16-n);
        
    }
};


//Approach-2 (Improving above code)
//We no need to check from 0 to 65536. Only need to check from 0 to n
//T.C : O(n^2) - Iterating on each string and converting each character to integer
//S.C : O(n) - Using set
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> st;
        
        for(string &num : nums) {
            st.insert(stoi(num, 0, 2));
        }
        
        int n = nums.size();
        
        string result= "";
        
        for(int number = 0; number <= n; number++) {
            if(st.find(number) == st.end()) {
                result = bitset<16>(number).to_string();
                break;
            }
        }
        
        return result.substr(16-n);
        
    }
};


//Approach-3 (By discarding matching characters in each position)
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
       string sol = "";
       int n = nums.size();
       for(int i=0 ; i<n ; i++){
        nums[i][i]=='0'? sol+='1':sol+='0';
       }    
       return sol;
    }
};