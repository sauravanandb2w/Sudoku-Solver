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
/*Question**********************************************************
Some Help:
memset(array,v,sizeof(array[0][0])*m*n);  v can be 0 or -1
memset(a,r,sizeof(a));  a=saurav =>   rrrrrr
pii p;  p=mp(3,5);

for(auto u:ma)
  cout<<u.fi<<" "<<u.se<<"\n";
map<ll,ll>::iterator it;
for(it=ma.begin();it!=ma.end();it++)
  cout<<(it->fi)<<" "<<(it->se)<<"\n";
********************************************************************/
int grid[9][9];

pii nozero()
{
  pii p;
  for(int i=0;i<9;i++)
  {
    for(int j=0;j<9;j++)
    {
      if(!grid[i][j])
      {
        p=mp(i,j);
        return p;
      }
    }
  }
  p=mp(-1,-1);
  return p;
}

bool issafe(int r,int c,int option)
{
  int i,j;
  for(i=0;i<9;i++)
  {
    if(grid[i][c]==option)
      return false;
  }

  for(i=0;i<9;i++)
  {
    if(grid[r][i]==option)
      return false;
  }

  int sr=(r/3)*3;
  int sc=(c/3)*3;
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      int ra=sr+i;
      int ca=sc+j;
      if(grid[ra][ca]==option)
        return false;
    }
  }

  return true;
}

bool fillgrid()
{
  pii p;
  p=nozero();
  if(p.fi==-1&&p.se==-1)
    return true;

  int r=p.fi;
  int c=p.se;
  for(int option=1;option<=9;option++)
  {
    if(issafe(r,c,option))
    {
      //cout<<3<<endl;
      //debug2(r,c);
      grid[r][c]=option;
      bool ans1=fillgrid();
      if(ans1)
        return ans1;
      //cout<<2<<endl;
      //debug2(r,c);
      grid[r][c]=0;
    }
  }
  //cout<<1<<endl;
  //debug2(r,c);
  return false;
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

    bool ans=fillgrid();

    if(!ans)
      cout<<"No solution"<<endl;
    else
      {
        for(i=0;i<9;i++)
        {
          for(j=0;j<9;j++)
            cout<<grid[i][j]<<" ";
          cout<<endl;
        }
      }
  }
return 0;
}
