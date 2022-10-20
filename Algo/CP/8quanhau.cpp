#include<bits/stdc++.h>
using namespace std;
int a[100][100],n,d=0;
void showresult()
{
	for (int i=1;i<=n;i++)
		{
			for (int j=1;j<=n;j++)
			     {
			     	cout<<a[i][j]<<" ";
				 }
				    cout<<endl;
		}
		cout<<endl;
		d++;
}
bool kiemtra(int row , int col)
{
	
	for (int i=1;i<col;i++)
		{
			if (a[row][i]==1) return false;
		}
		
	int  i=row;
	int  j=col;
	while (i>=1 && j>=1)
		{
			if (a[i][j]==1) return false;
			i--;
			j--;
		}
		
	 i=row;
	 j=col;	
				while (i<=n && j>=1)
					{
						if (a[i][j]==1)	return false;
						i++;
						j--;
					}
	
	return true;
}

void setqueen(int col)
{
//	if (col >n) return;
	for (int i=1;i<=n;i++)
		{
			if (kiemtra(i,col)==true)
				{
					a[i][col]==1;
					if (col==n) showresult();
					    else setqueen(col+1);
					a[i][col]==0;
				}
				
		}
}
int main()
{
//	freopen(".INP", "r", stdin);
//	freopen(".OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
 	n=8;
    for (int i=1;i<=n;i++)
    	{
    		for ( int j=1 ; j <=n; j++)
    			{
    				a[i][j]=0;
				}
		}
 setqueen(1) ;
 //	if (d==0) cout<<"NO solution";
}
