#include<cstdio>
int n,len,le;
int a[100111],x[100111],c[101111];
int main()
{
	while(scanf("%d",&a[++n])!=EOF)
	{
		
	}n--;
	for(int i=1;i<=n;i++)
	{
		if(len==0||a[i]<=x[len])
		{
			x[++len]=a[i];
		}
		else
		{
			int l=1;
			int r=len;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(a[i]>x[mid])
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			x[l]=a[i];
		}
	}
	printf("%d ",len);
	
	for(int i=1;i<=n;i++)
	{
		if(le==0||a[i]>c[le])
		{
			c[++le]=a[i];
		}
		else
		{
			int l=1;
			int r=le;
			while(l<r)
			{
				int mid=(l+r)/2;
				if(a[i]<=c[mid])
				{
					r=mid;
				}
				else
				{
					l=mid+1;
				}
			}
			c[l]=a[i];
		}
	}
	printf("%d ",le);
}