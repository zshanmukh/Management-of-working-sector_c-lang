#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct worker/*usedtodefineinformationofeachworker*/
{
int id_no;
char name[20];
int amount;
char sector[20];
char month[20];
struct worker* link;};
struct worker*root=NULL;
void insert()
{
/*intialisationforinsertioninlinkedlist*/
struct
worker*temp;/*temporaryvariablecreatedtoallocatethelocationofea
chworker*/
temp=(struct worker*)malloc(sizeof(struct worker));
printf("enter the idnumber:");/*idorregistrationnumberofeachworker*/
printf("\n");
printf("enter the name:");
printf("\n");
printf("enter the amountreceivedforwork:");/*amountearnedbyworkerafterworking*/
printf("\n");
printf("enter the sector in which the person is working:");
printf("\n");
printf("enter the joining month:");
printf("\n");
scanf("%d%s%d%s%s",&temp->id_no,&temp->name,&temp->amount,temp->sector,temp->month);
temp->link=NULL;
/*nodeconnectionbymakinguseofa*/
/*while(temp!=NULL)
{
printf("%d\t%s\t%d\t%s\t%s\t\n",temp->id_no,temp->name,temp-
>amount,temp
->sector,temp->month);temp=temp->link;
}*/
if (root==NULL)
root=temp;
else
{
struct worker *t;
t=root;
while (t->link!=NULL)
{
t=t->link;
}
t->link=temp;
}
}
int number_of_workers()/*countingnumberofworkers*/
{
struct worker*p;
p=root;
int count=0;
while(p->link!=NULL)
{
p=p->link;count=count+1;
}
return (count+1);
}
void delete1()
{
struct worker*temp;temp=root;
int len=number_of_workers();
int loc,i=0;
printf("enter the worker location to be removed:");
scanf("%d",&loc);
if(root==NULL)
{
printf("the list is empty");
}
else if(loc>len)
{
printf("invalid input");
}
else if(loc==1)
{
root=temp->link;
temp->link=NULL;
free(temp);
}
else
{
struct worker*p,*q;p=root;
while(i<loc-2)
{
p=p->link;
i++;
}
p->link=(p->link)->link;
}}
void display()
{
struct worker *temp;
temp=root;
while(temp->link!=NULL)
{
printf("%d\t%s\t%d\t%s\t%s\t\n",temp->id_no,temp->name,temp->amount,temp->sector,temp->month);
temp=temp->link;
}
printf("%d\t%s\t%d\t%s\t%s\t\n",temp->id_no,temp->name,temp->amount,temp->sector,temp->month);
}
void update()
{
int n,ch;
printf("Enter the id of the employee whose details are to beupdated: ");
scanf("%d",&n);
struct worker *temp;
temp=root;
while(temp->id_no!=n)
temp=temp->link;
printf("Following are the details that can be updated:-\n1. name\n2. amount\n3. sector\n4. month\n Enter your choice(1-4): ");
scanf("%d",&ch);
switch(ch)
{case 1: {
char nam[20];
printf("Enter the new name: ");
scanf("%s",nam);
strcpy(temp->name,nam);
break;}
case 2:{
int a;
printf("Enter the new amount: ");
scanf("%d",&a);
temp->amount=a;
break;}
case 3:{
char nam[20];
printf("Enter the new sector: ");
scanf("%s",nam);
strcpy(temp->sector,nam);
break;}
case 4:{
char nam[20];
printf("Enter the new month: ");
scanf("%s",nam);
strcpy(temp->month,nam);
break;}
default: printf("Wrong choice!\n");
break;
}
}
void search()/*searchingabouttheworkerinthelistthroughhisname*/{
struct worker *temp;
char person[20];
printf("Enter the name to be searched: ");
scanf("%s",person);
temp=root;
while(strcmp(person,temp->name)!=0)
{
temp=temp->link;
}
printf("%d\t%s\t%d\t%s\t%s\t\n",temp->id_no,temp->name,temp->amount,temp->sector,temp->month);
}
int main()
{
int ch,len;
do
{
printf("1.insert\n2.delete\n3.display\n4.number_of_workers\n5.search\n7. update details\n6.Exit\n");
printf("enter your choice between (1-6):");
scanf("%d",&ch);
switch(ch)
{
case 1:
insert();
break;
case 2:
delete1();break;
case 3:
display();
break;
case 4:
len=number_of_workers();
printf("the no of workers is %d\n",len);
break;
case 5:
search();
case 6: return 0;
break;
case 7:
update();
break;
default:
printf("give valid input\n");
break;
}
}while(ch!=6);
}
