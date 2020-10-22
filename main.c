#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct worker      /*usedtodefineinformationofeachworker */
{
  int id_no;
  char pwd[20];
  char name[20];
  int amount;
  char sector[20];
  char month[20];
  struct worker *link;
};
struct worker *root = NULL;
void insert ()
{
  struct worker *temp;    /*temporaryvariablecreatedtoallocatethelocationofeachworker */
  temp = (struct worker *) malloc (sizeof (struct worker));
  printf ("enter the idnumber: ");  /*idorregistrationnumberofeachworker */
  scanf("%d",&temp->id_no);
  printf ("\n");
  printf("Create a Password: ");
   scanf("%s",temp->pwd);
     printf ("\n");
  printf ("enter the name: ");
  scanf("%s",temp->name);
  printf ("\n");
  printf ("enter the amountreceivedforwork: ");
    scanf("%d",&temp->amount); /*amountearnedbyworkerafterworking */
  printf ("\n");
  printf ("enter the sector in which the person is working: ");
    scanf("%s",temp->sector);
  printf ("\n");
  printf ("enter the joining date: ");
    scanf("%s",temp->month);
  printf ("\n");

  if(temp->id_no<0){
    printf("Enter valid data");
  }



  temp->link = NULL;

  if (root == NULL)
    root = temp;
  else
    {
      struct worker *t;
      t = root;
      while (t->link != NULL)
  {
    t = t->link;
  }
      t->link = temp;
    }
}

int number_of_workers()    /*countingnumberofworkers */
{
  struct worker *p;
  p = root;
  int count = 0;
  while (p->link != NULL)
    {
      p = p->link;
      count = count + 1;
    }
  return (count + 1);
}


void delete1 ()
{
  struct worker *temp;
  temp = root;
  int len = number_of_workers ();
  int loc, i = 0;
  printf ("enter the worker location to be removed:");
  scanf ("%d", &loc);
  if (root == NULL)
    {
      printf ("the list is empty");
    }
  else if (loc > len)
    {
      printf ("invalid input");
    }
  else if (loc == 1)
    {
      root = temp->link;
      temp->link = NULL;
      free (temp);
    }

  else
    {
      struct worker *p, *q;
      p = root;
      while (i < loc - 2)
  {
    p = p->link;
    i++;
  }
      p->link = (p->link)->link;
    }
}


void display ()
{
    printf("---------------------------------------------------------------------------------\n");
    printf("********** Details************\n");
    printf("ID.no    Name     Wage        Dept.     Date Joined\n");
    printf("---------------------------------------------------------------------------------\n");
  struct worker *temp;
  temp = root;
  while (temp->link != NULL)
    {
      printf ("%d\t%s\t%d\t%s\t%s\t\n", temp->id_no, temp->name, temp->amount,temp->sector, temp->month);
      temp = temp->link;
    }
  printf ("%d\t%s\t%d\t%s\t%s\t\n", temp->id_no, temp->name, temp->amount,temp->sector, temp->month);
  printf("\n\n\n");
}






void update ()
{
  int n, ch;
  printf ("Enter the  ID of the employee whose details are to be updated: ");
  scanf ("%d", &n);
  struct worker *temp;
  temp = root;
  while (temp->id_no != n)
    temp = temp->link;
  printf
    ("Following are the details that can be updated:-\n1. name\n2. amount\n3. sector\n4. month\n5.Password\n Enter your choice(1-5): ");
  scanf ("%d", &ch);
  switch (ch)
    {
    case 1:
      {
  char nam[20];
  printf ("Enter the new name: ");
  scanf ("%s", nam);
  strcpy (temp->name, nam);
  break;
      }
    case 2:
      {
  int a;
  printf ("Enter the new amount: ");
  scanf ("%d", &a);
  temp->amount = a;
  break;
      }
    case 3:
      {
  char nam[20];
  printf ("Enter the new sector: ");
  scanf ("%s", nam);
  strcpy (temp->sector, nam);
  break;
      }
    case 4:
      {
  char nam[20];
  printf ("Enter the new date: ");
  scanf ("%s", nam);
  strcpy (temp->month, nam);
  break;
      }
    case 5:
      {
  char nam[20];
  printf ("Enter the new Password: ");
  scanf ("%s", nam);
  strcpy (temp->pwd, nam);
  break;
      }
  break;

    default:
      printf ("Wrong choice!\n");
      break;
    }
}


void search ()
{
  struct worker *temp;
  char person[20];
  printf ("Enter the name to be searched: ");
  scanf ("%s", person);
  temp = root;
  while (strcmp (person, temp->name) != 0)
    {
      temp = temp->link;
    }
    printf("---------------------------------------------------------------------------------\n");
    printf("********** Details************\n");
    printf("ID.no   Name    Wage        Dept.     Date Joined\n");
    printf("---------------------------------------------------------------------------------\n");
  printf ("%d\t%s\t%d\t%s\t%s\t\n", temp->id_no, temp->name, temp->amount,
    temp->sector,temp->pwd, temp->month);
}
void search2 ()
{
  struct worker *temp;
  char person[20];
  printf ("Enter your name again to confirm: ");
  scanf ("%s", person);
  temp = root;
  while (strcmp (person, temp->name) != 0)
    {
      temp = temp->link;
    }
    printf("---------------------------------------------------------------------------------\n");
    printf("********** Details************\n");
    printf("ID.no   Name    Wage        Dept.     Password\n");
    printf("---------------------------------------------------------------------------------\n");
  printf ("%d\t%s\t%d\t%s\t%s\t\n", temp->id_no, temp->name, temp->amount,
    temp->sector,temp->pwd, temp->month);
}

int pass(void)
{
   int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";
    do
{
	system("cls");

    printf("\n  **************************  LOGIN AS ADMIN  **************************  ");
    printf(" \n                       ENTER USERNAME:-");
	scanf("%s", &uname);
	printf(" \n                       ENTER PASSWORD:-");
	while(i<10)
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	//char code=pword;
	i=0;
	//scanf("%s",&pword);
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL\n");
	system("PAUSE");
	break;
	}
	else
	{
		printf("\n        SORRY !!!!  LOGIN IS UNSUCESSFUL\n");
		system("PAUSE");
		a++;

		getch();

	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");

		getch();

		}
		system("cls");
}



void admin_login()
{
    pass();
   int ch, len;
  do
    {
      printf("[1]Enter the staff details\n[2]Delete the staff details\n[3]Display Staff details\n[4]number of workers\n[5]search\n[6]update details\n[7]Exit\n");
      printf ("enter your choice between (1-7):");
      scanf ("%d", &ch);

      switch (ch)
  {
  case 1:
      system("cls");
      insert ();
      system("cls");
    break;
  case 2:
      system("cls");
      delete1 ();
      system("cls");
    break;
  case 3:
      system("cls");
    display ();
    break;
  case 4:
      system("cls");
      len = number_of_workers ();
      printf ("the no of workers is %d\n", len);
    break;
  case 5:
      search ();
      system("PAUSE");
      system("cls");
      main();
  case 6:
      update();

    break;
  case 7:
      system("cls");
      main();
      return 0;
    break;
  default:
      system("cls");
      printf ("****************Give a Valid Input*******************\n\n\n");

    break;
  }
    }
  while (ch != 7);

}

void user_login(){
 struct worker *temp;
  char person[20];
  char password[10];



   printf("Enter Your user name: ");
 printf("(use your name)\n ");
    scanf ("%s", person);
  printf("Enter Your Password:\n");

int    i=0;
char c=' ';
  while(i<10)
	{
	    password[i]=getch();
	    c=password[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	password[i]='\0';
	//char code=pword;
printf("\n\n\n");

  temp = root;
  while (strcmp (person, temp->name) != 0)
    {
      temp = temp->link;
    }
  if(strcmp(password,temp->pwd)==0 && strcmp (person, temp->name) == 0 )
       {
        printf("Login Successful\n");
        system("PAUSE");
        system("cls");

         int ch, len;
  do
    {
      printf("[1]Display Your details\n[2]update your details\n[3]Exit\n");
      printf ("enter your choice between (1-3):");
      scanf ("%d", &ch);
      switch (ch)
  {

  case 1:
    system("cls");
    search2();
     system("PAUSE");
    system("cls");
    break;

  case 2:
    update();
    break;
  case 3:
    system("cls");
    main();
    break;
  default:
      system("cls");
      printf ("****************Give a Valid Input*******************\n\n\n");
      system("PAUSE");
      system("cls");
    main();


    break;
  }
    }
  while (ch != 3);

}
else
{
    system("cls");
    printf("\t\t\t\tCould not login \n\t\t\t\tPlease Try Again\n\n\n");
     system("PAUSE");
        system("cls");
    main();
}

    }

int main ()
{
  printf("\n\n\t\t\t       EMPLOYEE MANAGEMENT SYSTEM");
    printf("\n\n\n\t\t\t\xB2\xB2\xB2\xB2\xB2\xB2\xB2 WELCOME TO THE MAIN MENU \xB2\xB2\xB2\xB2\xB2\xB2\xB2\n\n");
    printf("\n\t\t\t----Please choose one of the options below----\n");
int p;
 printf("[1]Admin Login\n[2]User Login \n");
 scanf ("%d", &p);
      switch (p)
  {
  case 1:

admin_login();
    break;

  case 2:
user_login();
    break;

  default:
    printf ("\n\n\n****************Give a Valid Input*******************\n\n\n");
    system("PAUSE");
    system("cls");
    main();
    }

}
