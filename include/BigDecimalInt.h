#ifndef BIGDECIMALINT_H
#define BIGDECIMALINT_H
#include <bits/stdc++.h>
#include<ostream>
using namespace std;


class BigDecimalInt
{
        friend ostream& operator << (std::ostream& out, BigDecimalInt b);

    public:
        BigDecimalInt();
        BigDecimalInt(std::string);
        BigDecimalInt(int);
        BigDecimalInt operator+( BigDecimalInt& b);
        BigDecimalInt operator-( BigDecimalInt& b);
        BigDecimalInt operator=( BigDecimalInt& b);
        int Size();
    protected:
    private:
          std::vector<int> num;
};

#endif // BIGDECIMALINT_H3
