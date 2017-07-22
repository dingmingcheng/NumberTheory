/**
*
* C(m,n)%p,p可以不为素数
*
*
**/

ll POW(ll a,ll b,ll mod)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

ll POW(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b&1) ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}


ll exGcd(ll a,ll b,ll &x,ll &y)
{
    ll t,d;
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    d=exGcd(b,a%b,x,y);
    t=x;
    x=y;
    y=t-a/b*y;
    return d;
}

bool modular(ll a[],ll m[],ll k)
{
    ll d,t,c,x,y,i;

    for(i=2;i<=k;i++)
    {
        d=exGcd(m[1],m[i],x,y);
        c=a[i]-a[1];
        if(c%d) return false;
        t=m[i]/d;
        x=(c/d*x%t+t)%t;
        a[1]=m[1]*x+a[1];
        m[1]=m[1]*m[i]/d;
    }
    return true;
}



ll reverse1(ll a,ll b)
{
    ll x,y;
    exGcd(a,b,x,y);
    return (x%b+b)%b;
}

ll C(ll n,ll m,ll mod)
{
    if(m>n) return 0;
    ll ans=1,i,a,b;
    for(i=1;i<=m;i++)
    {
        a=(n+1-i)%mod;
        b=reverse1(i%mod,mod);
        ans=ans*a%mod*b%mod;
    }
    return ans;
}

ll C1(ll n,ll m,ll mod)
{
    if(m==0) return 1;
    return C(n%mod,m%mod,mod)*C1(n/mod,m/mod,mod)%mod;
}

ll cal(ll n,ll p,ll t)
{
    if(!n) return 1;
    ll x=POW(p,t),i,y=n/x,temp=1;
    for(i=1;i<=x;i++) if(i%p) temp=temp*i%x;
    ll ans=POW(temp,y,x);
    for(i=y*x+1;i<=n;i++) if(i%p) ans=ans*i%x;
    return ans*cal(n/p,p,t)%x;
}

ll C2(ll n,ll m,ll p,ll t)
{
    ll x=POW(p,t);
    ll a,b,c,ap=0,bp=0,cp=0,temp;
    for(temp=n;temp;temp/=p) ap+=temp/p;
    for(temp=m;temp;temp/=p) bp+=temp/p;
    for(temp=n-m;temp;temp/=p) cp+=temp/p;
    ap=ap-bp-cp;
    ll ans=POW(p,ap,x);
    a=cal(n,p,t);
    b=cal(m,p,t);
    c=cal(n-m,p,t);
    ans=ans*a%x*reverse1(b,x)%x*reverse1(c,x)%x;
    return ans;
}

//计算C(n,m)%mod
ll Lucas(ll n,ll m,ll mod)
{
    ll i,t,cnt=0;
    ll A[100],M[100];
    for(i=2;i*i<=mod;i++) if(mod%i==0)
    {
        t=0;
        while(mod%i==0)
        {
            t++;
            mod/=i;
        }
        M[++cnt]=POW(i,t);
        if(t==1) A[cnt]=C1(n,m,i);
        else A[cnt]=C2(n,m,i,t);
    }
    if(mod>1)
    {
        M[++cnt]=mod;
        A[cnt]=C1(n,m,mod);
    }
    modular(A,M,cnt);
    return A[1];
}