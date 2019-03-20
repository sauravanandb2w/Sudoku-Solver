/**************************SAURAV ANAND******************************/
/*************************MNNIT 2nd YEAR*****************************/

#include <bits/stdc++.h>

using namespace std;
#define pb(x)               push_back(x)
#define mp(x,y)             make_pair(x,y)
#define pii                 pair<int,int>
#define vi                  vector<int>
#define vii                 vector<pii>
#define mi                  map<int,int>
#define mii                 map<pii,int>
#define all(a)              (a).begin(),(a).end()
#define fi                  first
#define se                  second
#define sz(x)               (int)x.size()
#define endl                '\n'
#define md                  1000000007
#define rep(i,a,b)          for(int i=a;i<b;i++)
#define pcout(x)	          cout<<fixed<<setprecision(x)
#define debug(x)            cout<<#x<<"::"<<x<<endl;
#define debug2(x,y)         cout<<#x<<"::"<<x<<"\t"<<#y<<"::"<<y<<endl;
#define boost               ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)

typedef long long ll;
typedef double ld;

inline ll prodm(ll a,ll b)  {return ((a%md)*(b%md))%md;}
inline ll summ(ll a,ll b)   {return ((a%md)+(b%md))%md;}
inline bool ispow2(ll x)    {return  x && (!(x&(x-1)));}

const int NN = 1e6 + 5;
const int N = 1e9 + 9;

int grid[9][9];


bool issafe(int r,int c,int option)
{
  int i,j;
  for(i=0;i<9;i++)
  {
    if(i!=r)
    if(grid[i][c]==option)
    {
      //debug2(i,c);
      return false;
    }
  }

  for(i=0;i<9;i++)
  {
    if(i!=c)
    if(grid[r][i]==option)
      {
        //debug2(r,i);
        return false;
      }
  }

  int sr=(r/3)*3;
  int sc=(c/3)*3;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      int ra=sr+i;
      int ca=sc+j;
      if(r!=ra&&c!=ra)
      if(grid[ra][ca]==option)
      {
        //debug2(ra,ca);
        return false;
      }
    }
  }

  return true;
}

int main()
{
  boost;
  int T,i,j;
  cin>>T;
  while(T--)
  {
    memset(grid,0,sizeof(grid));
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
        {
          cin>>grid[i][j];
        }
    }
    int flag=0;
    for(i=0;i<9;i++)
    {
      for(j=0;j<9;j++)
      {
        if(!issafe(i,j,grid[i][j]))
          {
            //debug2(i,j);
            cout<<"Not A Sudoku"<<endl;
            flag=1;
            break;
          }
      }
      if(flag==1)
        break;
    }
    //debug(flag);

    if(flag==0)
      cout<<"Its A Sudoku"<<endl;

  }
return 0;
}
