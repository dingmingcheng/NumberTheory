/*
*
* 用来高效地计算矩阵的高次方
* 时间复杂度降为O(logn)
*
*
*
*/


/*
q矩阵(main（）res)
a0 a1 ... a9
1 ..........
0 1 ........
...
0 .......1 0
*/
/*初始矩阵
f9
f8
..
.
.
f0
*/
#define MAXN 10
struct Matrix
{
    ll m[MAXN][MAXN];
};
int SMod;
Matrix Mul(Matrix a,Matrix b)
{
    Matrix c;
    memset(c.m,0,sizeof(c.m));
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            for(int k=0;k<MAXN;k++)
                c.m[i][j] += ((a.m[i][k]*b.m[k][j])%SMod + SMod)%SMod;
    return c;
}

Matrix fastm(Matrix a,ll n)
{
    Matrix res;
    memset(res.m,0,sizeof(res.m));
     for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(j==0)
                res.m[i][j]=9-i;
        }
    }
    while(n)
    {
        if(n&1)
            res = Mul(a,res);//注意顺序
        n>>=1;
        a = Mul(a,a);
    }
    return res;
}
ll a[10];
int main()
{
    int n;
    Matrix res;
    while(scanf("%d",&n)!=EOF)
    {
        scanf("%d",&SMod);
        memset(res.m,0,sizeof(res.m));//qjuzheng
        for(int i=0;i<10;i++)
            scanf("%I64d",&a[i]);
        for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(i==0)
                res.m[i][j]=a[j];
            else if(i==j+1)
                res.m[i][j]=1;
        }
        }
        Matrix ans;
        if(n<10)
            printf("%d\n",((1+n)*n/2)%SMod);
        else{
        ans=fastm(res,n-9);
        printf("%I64d\n",ans.m[0][0]%SMod);
        }
    }
    return 0;
}

