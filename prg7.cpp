#include <stdio.h>
#include<stdlib.h>

int c=0;
int w[20];
int v[20];

int brute(int, int);
int TD_DP(int ,int, int[][100]);
void BU_DP(int, int);

int main ()
{
  int n,W,res,i,j,ch,s[10],k;
  printf("***Knapsack Problem***\n");
  printf("\nEnter the number of elements: ");
  scanf("%d",&n);
  printf("Enter %d weights - \n",n);
  w[0]=0;
  for(i=1;i<=n;i++)
  {
      scanf("%d",&w[i]);
  }
  printf("Enter %d corresponding values - \n",n);
  v[0]=0;
  for(i=1;i<=n;i++)
  {
      scanf("%d",&v[i]);
  }
  printf("Enter the weight of knapsack: ");
  scanf("%d",&W);
  printf("Enter method choice: 1.Bruteforce recursive , 2.Recurive DP (top down) , 3.Non-recursive DP (bottom up)\n");
  scanf("%d",&ch);
  while(1)
  {
    switch(ch)
    {
        case 1:
        {
            c=0;
            res=brute(n, W);
            printf ("\nB(%d,%d)=%d and DP_Recursive_Top_Down_Count=%d\n\n",n,W,res,c);
            break;
        }
        case 2:
        {
                c=0;
                int B[100][100];
                for(i=0;i<=n;i++)
                    for(j=0;j<=W;j++)
                        if(i==0||j==0)
                            B[i][j]=0;
                        else
                            B[i][j]=-1;
                /*printf("\n");
                for(i=0;i<=n;i++)
                {
                    for(j=0;j<=W;j++)
                        printf("%d\t",B[i][j]);
                    printf("\n");
                }*/
                TD_DP(n, W, B);
                for(i=0;i<=n;i++)
                {
                    for(j=0;j<=W;j++)
                        printf("%d\t",B[i][j]);
                    printf("\n");
                }
                printf ("\nB(%d,%d)=%d and DP_Recursive_Top_Down_Count=%d\n\n",n,W,B[n][W],c);
                i=n;
                j=W;
                k=0;
                while(i>=0 && j>=0)
                {
                    if((i-1)>=0 && B[i][j]==B[i-1][j])
                    {
                        i--;
                    }
                    else
                    {
                        //printf("n=%d, w=%d\n",i,j);
                        s[k]=v[i];
                        j-=w[i];
                        i--;
                        k++;
                    }
                }
                printf("Selected items: ");
                for(i=0;i<k-1;i++)
                    printf("%d  ",s[i]);
                printf("\n");
                break;
        }
        case 3:
        {
            BU_DP(n, W);
            break;
        }
        default:
        {
            printf("Exiting . . .\n");
            exit(0);
        }
    }
    printf("Enter method choice: 1.Bruteforce recursive, 2.Recurive DP (top down), 3.Non-recursive DP (bottom up)\n");
    scanf("%d",&ch);
  }
  return 0;
}

int brute(int n,int W)
{
    int c1,c2,res;
    if(n==0 || W==0)
        return 0;
    if(W<w[n])
        res=brute(n-1,W);
    else
    {
        c1=brute(n-1,W);
        c2=v[n]+brute(n-1,W-w[n]);
        res=(c1>c2)?c1:c2;
        c++;
    }
    return res;
}

int TD_DP(int n,int W, int B[100][100])
{
    //printf("TD(%d,%d)\n",n,W);
    int c1,c2;
    c++;
    if(B[n][W]<0)
    {
        if(W<w[n])
            B[n][W]=TD_DP(n-1,W,B);
        else
        {
            c1=TD_DP(n-1,W,B);
            c2=v[n]+TD_DP(n-1,W-w[n],B);
            B[n][W]=(c1>c2)?c1:c2;
        }
    }
    return B[n][W];
}

void BU_DP(int n,int W)
{
  int i,j,c1,c2,flag=0,s[10],k;
  c=0;
  int B[n+1][W+1];
  for(i=0;i<=n;i++)
    for(j=0;j<=W;j++)
        if(i==0||j==0)
            B[i][j]=0;
        else
            B[i][j]=-1;
  for(i=1;i<=n;i++)
  {
    for(j=1;j<=W;j++)
    {
        if(B[i][j]<0)
        {
            if(j<w[i])
                B[i][j]=B[i-1][j];
            else
            {
                c1=B[i-1][j];
                c2=v[i]+B[i-1][j-w[i]];
                B[i][j]=(c1>c2)?c1:c2;
            }
            c++;
        }
    }
  }
  for(i=0;i<=n;i++)
  {
    for(j=0;j<=W;j++)
        printf("%d\t",B[i][j]);
    printf("\n");
  }
  printf ("\nB(%d,%d)=%d and DP_NonRecursive_Bottom_Up_Count=%d\n\n",n,W,B[n][W],c);
  i=n;
  j=W;
  k=0;
  while(i>=0 && j>=0)
  {
      if((i-1)>=0 && B[i][j]==B[i-1][j])
      {
          //printf("not n=%d, w=%d, w[i]=%d\n",i,j,w[i]);
          i--;
      }
      else
      {
          //printf("1. n=%d, w=%d, w[i]=%d\n",i,j,w[i]);
          s[k]=v[i];
          j=j-w[i];
          i--;
          k++;
          //printf("2. n=%d, w=%d, w[i]=%d\n",i,j,w[i]);
      }
  }
  printf("Selected items: ");

  for(i=0;i<k-1;i++)
    printf("%d  ",s[i]);
  printf("No of items selected %d",k);
  printf("\n");
}

