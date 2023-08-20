#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct election 
{
char name[20];
char id[20];
int vote;
char pass[10];
	
};
struct candidates
{
	int CaptainA;
	int CaptainB;
	int CaptainC;
}B;
struct voted_member
{
	char id[10];
};
void details_enter();
void welcome();
void voting();
int check(char a[]);
void results(int,int,int);

void main()
{int n;
	struct election A[n];
	struct candidates B;
	B.CaptainA=0;
	B.CaptainB=0;
	B.CaptainC=0;
	
details_enter();
details_enter();
welcome();welcome();
};

void results(int x,int y,int z)
{
	if (x>y)
	{
		if (x>z)
		{ printf("CaptainA");
		}
		else if(z>x)
		{printf("CaptainC");
		}
		
	}
	else if(y>x)
	{if (y>z)
	printf("CaptainB");
	else if(z>y)
	printf("CaptainC");
		
	}

};
void voting() //
{ int n;
printf("The eligible candidates for the ongoing election is:\nCaptainA (1)\t\tCaptainB (2)\t\tCaptainC (3)\n");
scanf("%d",&n);

if (n==1)
{B.CaptainA+=1;
printf("\n%d",B.CaptainA);
}
else if (n==2)
{B.CaptainB+=1;
}
else if (n==3)
{B.CaptainC+=1;
}	

};
//Before election day.......this has to be done.
void details_enter()  
{
FILE *fp;struct election voter;
fp=fopen("proj.txt","ab"); //ab is append binary
		printf("Enter name:\n");
	    fflush(stdin);
		gets(voter.name);
		fflush(stdin);
		voter.vote=0;
		printf("What is the password to be assigned?\n");
		gets(voter.pass);
		fflush(stdin);
		printf("Enter voter ID:\n");
		gets(voter.id); 
		fflush(stdin);
		fwrite(&voter,sizeof(struct election),1,fp);		
	
	fclose(fp);
	
};
int check(char a[20])
{
	FILE *fp;struct voted_member A;
	fread(&A,sizeof(struct voted_member),1,fp);
	while (1)
	{
		if (feof(fp))
		return 0;
		else if(strcmp(a,A.id)==0)
		return 1;
		else
		return 0;
	}
};

void welcome() //
{
char s[20];int i;struct election p;struct voted_member VM;
	printf("Welcome to Voting Booth\n\n Enter your voter ID :\n");
	gets(s);int n=1;
	FILE *fp;
	fp=fopen("proj.txt","rb");
	FILE *a;
	a=fopen("voted_m.txt","ab");
	
	while(1)
	{
		fread(&p,sizeof(struct election),1,fp);
		if (feof(fp))
		{
			break;
	    }
		else if(strcmp(s,"1234567890")==0)
		{
			results(B.CaptainA,B.CaptainB,B.CaptainC);	
		}
		else if(strcmp(s,p.id)==0)
		{
			printf("Enter password:\n");
			char x[20];
			gets(x);
			if (strcmp(p.pass,x)==0 && check(x)==0)
			{
				printf("Password matched.You may vote now!\n");
				strcpy(VM.id,p.id);
				fwrite(&VM,sizeof(struct voted_member),1,a);
				fclose(a);
		    	voting();
				break;
			}
			else if(strcmp(p.pass,x)==0 && check(x)!=0)
			{
				printf("You have aldready voted.\n");
				break;
			}
			
		}
		else if (strcmp(p.id,s)!=0)
		{
			printf("You have not registered.\n");
			break;
			n=0;
		}
		fclose(fp);
}
};
