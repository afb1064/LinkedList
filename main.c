////Linked List Practices and Some Functions
//Author afb1064
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
typedef struct list{
	char name[20];
	char surname[20];
	char number[11];
	int age;
	list*next;
}List;
List *first=NULL,*last=NULL,*newp,*temp,*iter;

 void add(List*);
 void print();
 void del(int);
 void writeFile();
 void readFile();

 FILE *fp;
 FILE *fc;

int main(){

     int choice=0;

         while(choice!=6)
	 {
	 puts("1-ADD\n2-LIST\n3-DELETE\n4-WRITE TO FIKE\n5-ADD FROM FILE\n6-EXIT");

	 scanf("%d",&choice);
	 system("CLS");

	 switch(choice)
	 {

		case 1:
	        newp=(List*)malloc(sizeof(List));

		puts("Please Enter The Name:\n");
	        scanf("%s",&newp->name);

	        puts("Please Enter The Surname");
	        scanf("%s",&newp->surname);

	        puts("Plase Enter The Phone Number");
	        scanf("%s",&newp->number);

	        puts("Please Enter The Age");
	        scanf("%d",&newp->age);

		newp->next=NULL;
	        add(newp);
	        puts("Press any key for go back...\n");
                getch();
	        break;

		case 2:
		print();
		puts("Press any key for go back...\n");
                getch();
		break;

		case 3:
		int num;
		puts("Please Enter The Record Number for Delete");
		scanf("%d",&num);
		del(num);
		puts("Press any key for go back...\n");
		getch();
		break;

		case 4:
		fp=fopen("List.txt","w");
		writeFile();
		fclose(fp);
		puts("Records successfully written. Press any key for go back...\n");
	        getch();
	        break;

		case 5:
		fc=fopen("List.txt","r");
		if(fc!=NULL)
		{
                readFile();
	        fclose(fc);
	        puts("Records successfully added. Press any key for go back...\n");
                }
                else
		{
                puts("There is no file, please create one.");	
		}
		getch();
	        break;
	    
	        case 6:
	        puts("Goodbye");
	        return 0;
	    
	        default:
	        puts("Wrong choice, press any key for go back... ");
	        getch();
	        break;
	}
      system("CLS");
 }
 return 0;
}
void add(List*newp)
{
	if(first==NULL)
	{
	first=newp;
	last=newp;
	}
	else
	{
	last->next=newp;
	last=last->next;
	}
}

void print()
{
    temp=first;
    if(temp!=NULL)
    {

    while(temp!=NULL)
{

	printf("Name: %s\n",temp->name);
	printf("Surname: %s\n",temp->surname);
	printf("Phone Number: %s\n",temp->number);
	printf("Age: %d\n",temp->age);
	printf("\n");
        temp=temp->next;

    }
}
    else
     {
	puts("There is nothing to list");
    }
}
void del(int number)
{
	int i=0;
	temp=first;

	while(temp!=NULL)
	{
	temp=temp->next;
	i++;
        }

	if(number==1)
	{
    	temp=first;
    	first=first->next;
    	free(temp);
	}

    else if(number==i)
    {
	temp=first;

	for(int j=0;j<(i-2);j++)
	{
        temp=temp->next;
	}

       iter=temp->next;
       last=temp;
       last->next=NULL;
       free(iter);
    }

    else {
    temp=first;

	for(int s=0;s<(number-2);s++)
        {
        temp=temp->next;
	}

	iter=temp->next;
	temp->next=iter->next;
	free(iter);
	}

}

void writeFile(){

  temp=first;
  while(temp!=NULL)
  {
    fprintf(fp,"%s\t%s\t%s\t%d\n",temp->name,temp->surname,temp->number,temp->age);
    temp=temp->next;
  }
}

void readFile(){

  while(!feof(fc))
    {
    newp=(List*)malloc(sizeof(List));
    fscanf(fc,"%s\t%s\t%s\t%d\n",&newp->name,&newp->surname,&newp->number,&newp->age);
    newp->next=NULL;
    add(newp);
    }
}
