class big_int
{
public:
    vector<int>num;
    bool negative;
    size_t size(void){return num.size();}
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
        while(a!=0) \
        { \
            num.emplace_back(a%10); \
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
                    if(num[i]<o.num[i])reurn true;
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
                if(num[i]<o.num[i])reurn false;
            }
            return false;
        }
    }
    bool operator<(big_int o){return o>*this;}
    bool operator>=(big_int o){return !(*this<o);}
    bool operator<=(big_int o){return !(*this>o);}
    big_int operator+(big_int o)
    {
        
    }
    big_int operator+=(big_int o){return *this=*this+o;}
    big_int operator-(big_int o)
    {
        
    }
    big_int operator-=(big_int o){return *this=*this-o;}
    big_int operator*(big_int o)
    {
        
    }
    big_int operator*=(big_int o){return *this=*this*o;}
    big_int operator/(big_int o)
    {
        
    }
    big_int operator/=(big_int o){return *this=*this/o;}
};
