#include <bits/stdc++.h>
#include <BigDecimalInt.h>

using namespace std;

int main()
{
    BigDecimalInt b("123456789012345678901234567890");
//    BigDecimalInt b("123K*$%#@45");
    BigDecimalInt c("113456789011345678901134567890");
    BigDecimalInt f=c+b;
//     BigDecimalInt k("-14");
//      BigDecimalInt o("11");
//      cout<<o+k;
//        BigDecimalInt kk("-999994");
//        BigDecimalInt oo("-454511");
//        cout<<oo+kk;
//        BigDecimalInt kkk("0");
//        BigDecimalInt ooo("0");
//        cout<<ooo+kkk;
//          BigDecimalInt k(421564);
//          BigDecimalInt o(112345);
//          cout<<o+k;
    cout<<"size is : "<<b.Size()<<endl;
    cout<<"size is : "<<c.Size()<<endl;
    cout<<"f size is : "<<f.Size()<<endl;
    cout<<f;
//    cout<<b;
//    cout<<c;


    return 0;
}
