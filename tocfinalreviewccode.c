#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <Windows.h>
void loading(){
	int i, loading = 175;
	for(i=1;i<=2;++i)
	{
		system("COLOR 4B");
		printf("\n\n\n\n\n\t\t\t\t\t\t    WELCOME TO\n\n\n\n\n\n");
		printf("\t\t\t\t\t-----------------------------------\n");
		printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t\t\t\t||                               ||\n");
		printf("\t\t\t\t\t||              DNA              ||\n");
		printf("\t\t\t\t\t||           HYBRIDIZER          ||\n");
		printf("\t\t\t\t\t||                               ||\n");
		printf("\t\t\t\t\t~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\t\t\t\t\t-----------------------------------\n");
		printf("\n\n\n\n\n\n\t\t\t\t\t\t       %c", loading);
		Sleep(500);
		printf("%c", loading);
		Sleep(500);
		printf("%c", loading);
		Sleep(500);
		printf("%c", loading);
		Sleep(500);
		printf("%c", loading);
		Sleep(500);
		system("cls");
	}	
}
char final1[100],final2[100],sub_string[100];
void substring(char string[], char sub[], int start, int end)
{
   int c = start;
   int i=0;
   while (c <= end)
   {
      sub[i] = string[c];
      i++;
	  c++;
   }
   sub[c]='\0';
   strcpy(sub_string,sub);
}
void lexical_analyser(char input[200])
{
	if (strlen(input)==0)
	{
		printf("No input entered");
		exit(-1);
	}
	int j=0;
	input=strupr(input);
	char i=input[j];
	while (i!=NULL)
	{
		printf("%c --> ",i);
		switch (i)
		{
			case 'A':
				printf("Protein Adenine\n");
				if (input[j+1]=='T' && ((input[j+2]==',') || (input[j+2]=='$')))
				{
					printf("%c --> ",input[j+1]);
					printf("Protein Thyamine\n");
					printf("Correct pair\n");
					if (input[j+2]==',')
					{
						printf("%c --> ",input[j+2]);
						printf("One set over. Waiting for the other set\n");
						if (input[j+3]==NULL)
						{
							printf("Not the correct way to end the string. Does not belong to the language");
							exit(-1);
						}
					}
				}
				else
				{
					if (input[j+1]==NULL)
					{
						printf("Protein cannot exist without its other complementary part. ");
					}
					else
					{
						printf("Wrong combination as A can make pair with T only.\n");
					}
					printf("Does not belong to the language.\n");
					exit(-1);
				}
				j=j+2;
				break;
			case 'T':
				printf("Protein Thyamine\n");
				if (input[j+1]=='A' && ((input[j+2]==',') || (input[j+2]=='$')))
				{
					printf("%c --> ",input[j+1]);
					printf("Protein Adenine\n");
					printf("Correct pair\n");
					if (input[j+2]==',')
					{
						printf("%c --> ",input[j+2]);
						printf("One set over. Waiting for the other set\n");
						if (input[j+3]==NULL)
						{
							printf("Not the correct way to end the string. Does not belong to the language");
							exit(-1);
						}
					}
				}
				else
				{
					if (input[j+1]==NULL)
					{
						printf("Protein cannot exist without its other complementary part. ");
					}
					else
					{
						printf("Wrong combination as T can make pair with A only.\n");
					}
					printf("Does not belong to the language.\n");
					exit(-1);
				}
				j=j+2;
				break;
			case 'G':
				printf("Protein Guanine\n");
				if (input[j+1]=='C' && ((input[j+2]==',') || (input[j+2]=='$')))
				{
					printf("%c --> ",input[j+1]);
					printf("Protein Cytosine\n");
					printf("Correct pair\n");
					if (input[j+2]==',')
					{
						printf("%c --> ",input[j+2]);
						printf("One set over. Waiting for the other set\n");
						if (input[j+3]==NULL)
						{
							printf("Not the correct way to end the string. Does not belong to the language");
							exit(-1);
						}
					}
				}
				else
				{
					if (input[j+1]==NULL)
					{
						printf("Protein cannot exist without its other complementary part. ");
					}
					else
					{
						printf("Wrong combination as G can make pair with C only.\n");
					}
					printf("Does not belong to the language.\n");
					exit(-1);
				}
				j=j+2;
				break;
			case 'C':
				printf("Protein Cytosine\n");
				if (input[j+1]=='G' && ((input[j+2]==',') || (input[j+2]=='$')))
				{
					printf("%c --> ",input[j+1]);
					printf("Protein Guanine\n");
					printf("Correct pair\n");
					if (input[j+2]==',')
					{
						printf("%c --> ",input[j+2]);
						printf("One set over. Waiting for the other set\n");
						if (input[j+3]==NULL)
						{
							printf("Not the correct way to end the string. Does not belong to the language");
							exit(-1);
						}
					}
				}
				else
				{
					if (input[j+1]==NULL)
					{
						printf("Protein cannot exist without its other complementary part. ");
					}
					else
					{
						printf("Wrong combination as C can make pair with G only.\n");
					}
					printf("Does not belong to the language.\n");
					exit(-1);
				}
				j=j+2;
				break;
			case '$':
				if(i=='$' && input[strlen(input)-1]=='$' && input[j+1]==NULL)
				{
					printf("String termination\n");
				}
				else
				{
					printf("Inappropriate use of '$'\n");
					exit(-1);
				}
				break;
			default:
				printf("Not a valid character. Does not belong to the alphabet set of the language. Hence does not belong to the language.\n");
				exit(-1);
		}
		i=input[++j];
	}
	printf("\nTHE INPUT ENTERED IS LEICALLY CORRECT\n\n");
}
void hybridization(char input1[200],char input2[200])
{
int k=0,l=0,s=0;
printf("\nEnter no. of pairs to check the suitability for hybridization: ");
scanf("%d\n",&s);
char temp[100];
int same=0,flag=0;
char sub1[100],sub2[100];
if (strlen(input1)==strlen(input2))
{
	for(k=0;k+1+(s-1)*3<strlen(input1);k=k+3)
	{
		for(l=0;l+1+(s-1)*3<strlen(input2);l=l+3)
		{
			substring(input1,sub1,k,k+1+(s-1)*3);
			strcpy(sub1,sub_string);
			substring(input2,sub2,l,l+1+(s-1)*3);
			strcpy(sub2,sub_string);
            if(strcmpi(sub1,sub2)==0)
			{
				same=1;
				printf("Hybridization possible as at least %d pairs are same\n",s);
				if (k!=0)
				{
					substring(input1,temp,0,k-1);
					strcat(final1,sub_string);
				}
				strcat(final1,sub1);
				substring(input2,temp,l+2+(s-1)*3,strlen(input2));
				strcat(final1,sub_string);
				if (l!=0)
				{
					substring(input2,temp,0,l-1);
					strcat(final2,sub_string);
				}
				strcat(final2,sub2);
				substring(input1,temp,k+2+(s-1)*3,strlen(input1));
				strcat(final2,sub_string);
				printf("1st Hybridization result-----------%s\n",final1);
    		    printf("2nd Hybridization result-----------%s\n",final2);
    		    flag=1;
    		    break;
            }
		}
		if (flag==1)
		{
			break;
		}
	}
	if (same==0)
	{
		printf("Hybridization not possible as at least %d pairs are not same\n",s);
		exit(-1);
	}
}
else
{
	printf("DNA strands are not of same size. Hence hybridization not possible");
	exit(1);
}
}
void main()
{
	loading();
	int i=0;
	char a1[200],b1[200];
	char line[100],a[100],b[100],temp[100];
	FILE *input=fopen("text.txt","r");
	while ( fgets ( line, 25, input ) != NULL )
    	{
        	if(i==0)
        	{
         		strcpy(a,line);
         		i++;
        	}
         	else
         	{
         		strcpy(b,line);
         	}
    	}
	printf("DNA 1----------------------------------------------------------------\n");
	printf("%s\n",a);
	lexical_analyser(a);
	printf("DNA 2----------------------------------------------------------------\n");
	printf("%s\n",b);
	lexical_analyser(b);
	printf("Checking for hybridization\n");
	substring(a,temp,0,strlen(a)-2);
	strcpy(a,sub_string);
	printf("%s\n",a);
	substring(b,temp,0,strlen(b)-2);
	strcpy(b,sub_string);
	printf("%s\n",b);
	hybridization(a,b);
	fclose(input);
}
