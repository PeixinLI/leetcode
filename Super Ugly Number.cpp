//This problem is based on Ugly NumberII
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
      if(n == 1)
        return 1;
      int size = primes.size();
      vector<int> lastIndex(size, 0);
      vector<int> uglyNumber(n+1, INFINITY);

      uglyNumber[0] = 1;

      for(int i = 1; i < n; i++){ // for kth Ugly Number
        for(int j = 0; j < size; j++)
          uglyNumber[i] = min(uglyNumber[i], uglyNumber[lastIndex[j]] * primes[j]);

        for(int j = 0; j < size; j++)
          if(uglyNumber[i] == uglyNumber[lastIndex[j]] * primes[j])
            lastIndex[j]++;
      }

      return uglyNumber[n-1];
    }
};
