/*    problrm statement
print all the circular primes below n;

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

 */
#include <bits/stdc++.h>

using namespace std;
int rev (int c,int n)   /*  it take a number and rotate its digit by one and return that number for eg 123 -> 231 */
{
    int arr[n];
    for(int i=0;i<n;i++)    /* store number digit by digit in an array*/
    {
        arr[i]=c%10;
        c/=10;
    }
    int kx=0;
    int p=0;
    for(int i =n-1;i>0;i--)    /* restore that number while ignoring last digit*/
    {
        kx+=arr[i]*pow(10,p);
        
        
        p++;
        
    }
    kx+=arr[0]*pow(10,p);    /* now add remaining digit */
    //cout<<kx<<" ";
    return kx;
    
    
    
    
}
/* Driver code */
int main()
{
  int n;

 cin>>n;   /* take input from user */
    int nn=n;
    n*=10;
  int arr[n];
   unordered_map<int, int> map;
  for(int i=1;i<=n;i++)   /*  fill the array from 1 to n */
  {
      arr[i]=i;
  }
   for(int i=2;i<=n;i++)   /* sieve code that mark all non prime number as 1  and store all prime numbers in a hash map*/
  {
      
      if(arr[i]!=1)
      {
           map.insert(make_pair(arr[i],1));
          for(int j=i+i;j<=n;j+=i)
          {
              arr[j]=1;
          }
      }
     
  }

 
   for(int i=1;i<=nn;i++)
  {
     if(arr[i]!=1)     /* if the number is prime*/
     {
         int flag2=0;
         int c=arr[i];
         int k=0;
          while(c)      /* number of digits in that number =k*/
          {
              k++;
              c/=10;
          }
          
          int kk=k;
          c=arr[i];
          int cc=c;
          if(k>1)
          {int arr1[kk-1];
          int p=0;
          while(k>1)
          {
             c= rev(c,kk);    /* function that rotate the digits of number by 1*/
             arr1[p]=c;
             if (map.find(c) == map.end())   /* if the new number is not a prime number then it is not a circular prime*/
             {
                 
                 flag2=1;
                 break;
             }
             p++;
             k--;
          }
          
          }
          if(flag2==0)     /* if all its rotations are prime then print that number */
          {
              cout<<cc<<" ";

          }
         
         
          
       }
        
  }
   return 0;
}
