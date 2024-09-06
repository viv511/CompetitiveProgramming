// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

class Solution {
public:
    int findNumberOfLIS(vector<int>& v) {
        int finalSize = v.size();
        ll maxVal = 0;
        ll numLens = 0;

        vi endingSeq(finalSize, 1);
        vi count(finalSize, 1);

        for(int i=0; i<finalSize; i++) {
            for(int j=0; j<i; j++) {
                if(v[j] < v[i]) {
                    if(endingSeq[j] + 1 > endingSeq[i]) {
                        endingSeq[i] = endingSeq[j] + 1;
                        count[i] = count[j];
                    }
                    else if(endingSeq[j] + 1 == endingSeq[i]) {
                        count[i] = (count[i] + count[j]);
                    }
                }
            }

            //Find the max ending sequence
            if(maxVal < endingSeq[i]) {
                maxVal = endingSeq[i];
                numLens = count[i];
            }
            else if(maxVal == endingSeq[i]) {
                numLens = (numLens + count[i]);
            }

        }

        //Loop through the ending sequence and count array to find the number of sequences
        //Add it all up to find ans
        return numLens;
    }
};