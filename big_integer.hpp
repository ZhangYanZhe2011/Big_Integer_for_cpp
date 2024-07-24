#include<vector>
#include<iostream>
#include<string>
using namespace std;
struct big_int
{
    vector<int>num;
    bool negative;
    size_t size(void){return num.size();}
    int& operator[](unsigned a){return num[a];}
    big_int()
    {
        negative=false;
        num.emplace_back(0);
    }
    #define def(type) \
    big_int(type a) \
    { \
        if(a<0) \
        { \
            negative=true; \
            a=-a; \
        } \
        else negative=false; \
        while(a!=0) \
        { \
            this->num.emplace_back(a%10); \
            a/=10; \
        } \
    }
    def(short)
    def(unsigned short)
    def(int)
    def(unsigned int)
    def(long)
    def(unsigned long)
    def(long long)
    def(unsigned long long)
    #undef def
    big_int operator=(big_int o)
    {
        negative=o.negative;
        num=o.num;
        return *this;
    }
    big_int operator=(string &s)
    {
        int beg=0;
        if(s[0]=='-')
        {
            negative=true;
            ++beg;
        }
        num.resize(s.size());
        for(int i=beg;i<s.size();++i)
            num[s.size()-i-1]=s[i]-48;
        return *this;
    }
    bool operator==(big_int o)
    {
        if(negative!=o.negative||num.size()!=o.num.size())return false;
        for(int i=0;i<num.size();++i)
            if(num[i]!=o.num[i])return false;
        return true;
    }
    bool operator!=(big_int o){return !(*this!=o);}
    bool operator>(big_int o)
    {
        if(negative!=o.negative)return negative<o.negative;
        if(negative)
        {
                if(size()>o.size())return false;
                if(size()<o.size())return true;
                for(int i=0;i<size();++i)
                {
                    if(num[i]>o.num[i])return false;
                    if(num[i]<o.num[i])return true;
                }
                return false;
        }
        else
        {
            if(size()>o.size())return true;
            if(size()<o.size())return false;
            for(int i=0;i<size();++i)
            {
                if(num[i]>o.num[i])return true;
                if(num[i]<o.num[i])return false;
            }
            return false;
        }
    }
    bool operator<(big_int o){return o>*this;}
    bool operator>=(big_int o){return !(*this<o);}
    bool operator<=(big_int o){return !(*this>o);}
    big_int operator+(big_int o)
    {
        big_int ans;
        ans.num.clear();
        ans.num.resize((size()>o.size()?size():o.size())+1);
        if(negative==o.negative)ans.negative=negative;
        else abs()>o.abs()?negative:o.negative;
        for(int i=0;i<ans.size()-1;++i)
        {
            if(i<size())ans.num[i]+=(ans.negative==negative?1:-1)*num[i];
            if(i<o.size())ans.num[i]+=(ans.negative==o.negative?1:-1)*o.num[i];
            while(ans.num[i]<0)
            {
                ans.num[i]+=10;
                --ans.num[i+1];
            }
            ans.num[i+1]+=ans.num[i]/10;
            ans.num[i]%=10;
        }
        while(ans.num.back()==0)ans.num.pop_back();
        return ans;
    }
    big_int operator+=(big_int o){return *this=*this+o;}
    big_int operator-(big_int o)
    {
        o.negative=!o.negative;
        return *this+o;
    }
    big_int operator-=(big_int o){return *this=*this-o;}
    big_int operator*(big_int o)
    {
        big_int ans;
        ans.negative=!(negative==o.negative);
        ans.num.clear();
        ans.num.resize(num.size()*o.num.size());
        for(int i=0;i<size();++i)
            for(int j=0;j<o.size();++j)
                ans.num[i+j]+=num[i]*o.num[j];
        for(int i=0;i<ans.num.size();++i)
        {
            ans[i+1]+=ans[i]/10;
            ans[i]%=10;
        }
        while(ans.num.back()==0)ans.num.pop_back();
        return ans;
    }
    big_int operator*=(big_int o){return *this=(*this)*o;}
    big_int operator/(big_int o)
    {
        if(o==big_int(0))throw "The divisor cannot be 0.";
        big_int ans;
        return ans;
    }
    big_int operator/=(big_int o){return *this=*this/o;}
    big_int abs(void)
    {
        big_int a=*this;
        a.negative=false;
        return a;
    }
};
istream& operator>>(istream &in,big_int &a)
{
    string s;
    cin>>s;
    a=s;
    return in;
}
ostream& operator<<(ostream &out,big_int a)
{
    if(a.negative)out<<'-';
    for(int i=a.num.size()-1;i>=0;--i)
        out<<a.num[i];
    return out;
}
big_int to_big_int(const char *num)
{
    big_int ans;
    while(num)
        ans.num.push_back(int(*num)-48);
    return ans;
}
string to_string(big_int &a)
{
    string s;
    s.resize(a.num.size());
    for(int i=0;i<s.size();++i)
        s[i]=a.num[i]+48;
    return s;
}
