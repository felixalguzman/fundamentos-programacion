#include <stdio.h>
#include <stdlib.h>

int nub(int x, int y)
{
    int mod=0, ec2=0;
    mod=x%y;


        while (mod==0 || ec2==0)
        {
             if(mod==0)
        return y;

            if(mod!=0)
            {
                ec2=y%mod;
                if(ec2==0)
                {
                    return mod;
                }

            }

        }




}

int mcm(int nub(int x, int y),int c, int d)
{
  int m, modulo;
  m=c*d;
  modulo=m%nub(c,d);
  if (modulo == 0)
  {
      return modulo;
  }



}

int main()
{
    int a=0, b=0;
    scanf("%d", &a);
    scanf("%d", &b);
    printf("%d", mcm(nub(a,b), a,b));

}
