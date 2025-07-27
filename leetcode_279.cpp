#include <cmath>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        while (n%4==0) n/=4;
        if (n%8==7) return 4;
        int sq=(int)sqrt(n);
        for (int i=0;i<=sq;i++) {
            int y = n-i*i;
            int ysq = (int)sqrt(y);
            if (i*i+ysq*ysq==n) return (i==0||ysq==0?1:2);
        }
        for (int i=1;i*i<n;i++)
            if ((int)sqrt(n-i*i)*(int)sqrt(n-i*i)==n-i*i) return 2;
        return 3;
    }
};
