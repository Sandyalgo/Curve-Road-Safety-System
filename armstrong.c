int main()
{
	int n,r,i,count=0,m=0,t;
	printf("Enter number: ");
	scanf("%d",&n);
	t=n;
	while(n!=0){
	n=n/10;
	count++;
	}
	printf("%d\n",count);
	n=t;
	for(i=1;i<=count;i++)
	{
		m+=pow(t%10,count);
		t=t/10;
	}
	printf("%d\n",m);
	if(n==m)
	printf("Armstrong\n");
	else
	printf("Not Armstrong\n");
}  