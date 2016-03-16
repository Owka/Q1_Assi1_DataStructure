#include "BigDecimalInt.h"
#include <bits/stdc++.h>
using namespace std;


///////////////////////////////////////////////////
BigDecimalInt::BigDecimalInt()
{

}
//////////////////////////////////////////////////
BigDecimalInt::BigDecimalInt(std::string s)
{
    // check if the input is bad
        bool bad_char=false;
        if (s[0]!='-'&&(48>s[0]||s[0]>57))
            bad_char=true;
        for(int i=1;i<s.size();i++)
        {
            if(48>s[i]||s[i]>57)
                bad_char=true;
        }
    // if bad input out a message to user
        if(bad_char)
        {
            cout<<"bad input - invalid number"<<endl;
            this->num.clear();
        }

        else
        {

            if(s[0]=='-')
            {
                for(int i=1;i<s.size();i++)
                {
                    this->num.push_back(-1*(s[i]-48));
                }
            }
            else
            {

                for(int i=0;i<s.size();i++)
                {
                    this->num.push_back(s[i]-48);
                }
            }
        }
}
//////////////////////////////////////////
BigDecimalInt::BigDecimalInt(int s)
{

        std::vector<int> reversed;
        while(s)
        {
            reversed.push_back(s%10);
            s/=10;
        }

        for(int i=reversed.size()-1;i>=0;i--)
            this->num.push_back(reversed[i]);
}


////////////////////////////////////////////

BigDecimalInt BigDecimalInt::operator+( BigDecimalInt& b)
{
        BigDecimalInt c;

        //
        if(this->num.size()<b.num.size())
        {

            int original_size=this->num.size();
            for(int i=0;i<b.num.size()-original_size;i++)
                this->num.push_back(0);
            for(int i=0;i<original_size/2;i++)
            {
                int temp=this->num[i];
                this->num[i]=this->num[original_size-1-i];
                this->num[original_size-1-i]=temp;
            }
            for(int i=0;i<this->num.size()/2;i++)
            {
                int temp=this->num[i];
                this->num[i]=this->num[this->num.size()-1-i];
                this->num[this->num.size()-1-i]=temp;
            }
        }
        else if(this->num.size()>b.num.size())
        {
            int original_size=b.num.size();
            for(int i=0;i<this->num.size()-original_size;i++)
                b.num.push_back(0);
            for(int i=0;i<original_size/2;i++)
            {
                int temp=b.num[i];
                b.num[i]=b.num[original_size-1-i];
                b.num[original_size-1-i]=temp;
            }
            for(int i=0;i<b.num.size()/2;i++)
            {
                int temp=b.num[i];
                b.num[i]=b.num[b.num.size()-1-i];
                b.num[b.num.size()-1-i]=temp;
            }
//            for(int i=0;i<b.num.size();i++)cout<<b.num[i]<<endl;
//
//            for(int i=0;i<this->num.size();i++)cout<<this->num[i]<<endl;
      }
//        /*******/
        int reminder=0;
            for(int i=this->num.size()-1;i>=0;i--)
            {
                if((this->num[i]+b.num[i]+reminder>=0&&this->num[i]+b.num[i]+reminder<10)||(this->num[i]+b.num[i]+reminder<=0&&this->num[i]+b.num[i]+reminder>-10))
                {
                    c.num.push_back(this->num[i]+b.num[i]+reminder);
                    reminder=0;
                }
                else
                {
                    if(this->num[i]+b.num[i]+reminder<-9)
                    {
                        c.num.push_back((this->num[i]+b.num[i]+reminder)%10);
                        reminder=-1;
                    }
                    else
                    {
                        c.num.push_back((this->num[i]+b.num[i]+reminder)%10);
                        reminder=1;
                    }
                }
            }
            if(reminder!=0)
                c.num.push_back(reminder);
            for(int i=0;i<c.num.size()/2;i++)
            {
                int temp=c.num[i];
                c.num[i]=c.num[c.num.size()-1-i];
                c.num[c.num.size()-1-i]=temp;
            }
            //for(int i=0;i<c.num.size();i++)cout<<c.num[i]<<endl;
        return c;
}
/////////////////////////////////////

BigDecimalInt BigDecimalInt::operator=( BigDecimalInt& b)
{
        BigDecimalInt c;
        for(int i=0;i<b.num.size();i++)
        {
            c.num[i]=b.num[i];
        }
        return c;
}





/////////////////////////////////////

ostream &operator<<(ostream &out, BigDecimalInt b)     //output
{
    string result ="";
    bool negative = false;
    for(int i=0;i<b.num.size();i++)
        if(b.num[i]<0)negative=true;
    if (negative)
    {
        result+="-";
    for(int i=0;i<b.num.size();i++)
        result+=(char)(-1*b.num[i])+48;
    }
    else
    {
            for(int i=0;i<b.num.size();i++)
                result+=(char)(b.num[i])+48;
    }
    out<<result<<endl;
    return out;
}
///////////////////////////////
int BigDecimalInt::Size()
{

    return this->num.size();

}
