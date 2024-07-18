#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int word1 = s1.size();
        int word2 = s2.size();

        if (word1 > word2)
            return false;

        unordered_map<char, int> mp1, mp2;

        for (auto it : s1)
            mp1[it]++;

        // Initialize mp2 with the first word1 characters of s2
        for (int i = 0; i < word1; ++i)
            mp2[s2[i]]++;

        if (mp1 == mp2)
            return true;

        for (int i = word1; i < word2; ++i) {
            mp2[s2[i]]++; // Add the new character
            mp2[s2[i - word1]]--; // Remove the old character
            if (mp2[s2[i - word1]] == 0) {
                mp2.erase(s2[i - word1]); // Clean up the map
            }
            if (mp1 == mp2) {
                return true; // Found a permutation
            }
        }
        
        return false; // No permutation found
    }
};
