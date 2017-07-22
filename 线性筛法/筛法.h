/**
* 
* 筛法，找出小与MAXN的所有素数
*/
const int MAXN=15000010;
int primes;
bool isnotprime[MAXN];
int prime[N];
vector<int> p[153];
void init()
{
        MEM(isnotprime,false);
        isnotprime[1]=1;
        for(int i=2;i*i<=MAXN-1;i++){
                if(isnotprime[i]==1)
                        continue;
                for(int j=i*2;j<=MAXN-1;j+=i)
                {
                        isnotprime[j]=1;
                }
        }
        int k=0;
        for(int kt=2;kt<=MAXN-1;kt++){
                if(isnotprime[kt]==0)
                {
                        prime[k++]=kt;
                }
        }
        //printf("%d\n",max1);
        primes=k;
}