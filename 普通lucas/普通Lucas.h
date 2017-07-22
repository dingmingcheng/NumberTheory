/**
*
* 普通lucas，求解C(m,n)%p;
*
*
**/
一个定理：A^x % m = A^(x%phi(m)+phi(m)) % m (x >= phi(m))(公式证明)
int Pow(ll a,ll n,ll p)
{
    ll x = a;
    ll res = 1;
    while(n)
    {
        if(n & 1)
        {
            res = ((ll)res * (ll)x) % p;
        }
        n >>= 1;
        x = ((ll)x*(ll)x) % p;
    }
    return res;
}

int Cm(ll n,ll m,ll p)
{
    ll a = 1,b = 1;
    if(m > n) return 0;
    //实现(a!/(a-b)!) * (b!)^(p-2)) mod p,由于n比较大，所以，此处不知道有什么好的优化
    while(m)
    {
        a = (a * n) % p;
        b = (b * m) % p;
        m--;
        n--;
    }
    return ((ll)a * (ll)Pow(b,p-2,p))%p;
}
ll Lucas(ll n,ll m,ll p)
{
    if(m==0)
        return 1;
    return((ll)Cm(n%p,m%p,p)*(ll)Lucas(n/p,m/p,p))%p;
}
///yuchuli版本当N,M不大时
ll mod=1e9+7;

//扩展欧几里德
void ExEuclid(ll a,ll b,ll &x,ll &y,ll &q){
    if(b==0){
        x=1;y=0;q=a;
        return;
    }
    ExEuclid(b,a%b,y,x,q);
    y-=x*(a/b);
}
//乘法逆元
ll inv(ll num){
    ll x,y,q;
    ExEuclid(num,mod,x,y,q);
    return (x+mod)%mod;
}
ll fab[1000010];
//组合数
ll C(ll n,ll k){
    ll res=fab[n]*inv(fab[k]);
    res%=mod;
    res*=inv(fab[n-k]);
    res%=mod;
    return res;
}
void init()
{
        fab[0]=1;
        for(int i=1;i<=1000000;i++){
                fab[i]=fab[i-1]*i;
                fab[i]%=mod;
        }
}