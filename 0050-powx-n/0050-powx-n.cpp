class Solution {
public:

    double powRec(double x, int n)
    {
        if(n == 0)
            return 1;

        if(n == 1)
            return x;

       

        if(n % 2 != 0)
        {
            return x * powRec(x*x, n/2);
        }

        return powRec(x*x, n/2);
    }
    
    double myPow(double x, int n) {
        if(n < 0)
        {
            return 1/powRec(x, n);
        }
        return powRec(x,n);
    }
};