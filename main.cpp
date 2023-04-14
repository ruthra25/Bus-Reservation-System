#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
#include<stdlib.h>
int Contents();
void empty_stdin (void);
#include"login.cpp"
#include"booking.cpp"
#include"buslist.cpp"
#include"cancel.cpp"
void empty_stdin (void)
{
    int c = getchar();
    while (c != '\n' && c != EOF)
    c = getchar();
}

int Contents()
{
	char fr[50],To[50];
	int ch;
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 112);
	printf("CONTENTS");
	printf("\n");
	Colour(240);
	printf("\n\n\t\t\t\t\t\t\t");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("1)Buslist");
	printf("\n\n\t\t\t\t\t");
	Colour(112);
	printf("\t\t2)Booking");
	printf("\n\n\t\t\t\t\t\t");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("\t3)Cancel");
	printf("\n\n\t\t\t\t\t\t");
	Colour(112);
	printf("\t4)Display Tickets");
	printf("\n\n\t\t\t\t\t");
	SetConsoleTextAttribute( GetStdHandle(STD_OUTPUT_HANDLE), 240);
	printf("\t\t5)Quit");
	printf("\n\n\t\t\t\t\t");
	Colour(112);
	printf("Choose Your Option...");
	Colour(240);
	int rtn = 0;
	for (;;) {
        rtn = scanf("\n\n\t\t\t\t\t\t%d",&ch);
        if (rtn == EOF) {
            fputs ("(user canceled input.)\n", stderr);
            return 1;
        }
        else if (rtn == 0) {
            fputs ("Invalid Option,please choose valid one...\n", stderr);
            empty_stdin();
        }
        else if (ch<1 || 5<ch) {
            fputs (" Option out of range [1-5]\n", stderr);
            empty_stdin();
        }
        else {
            empty_stdin();
            break;
        }
        system("pause");
    }
	switch(ch)
	{
		case 1:
		    Buslist();
			break;
		case 2:
			booking();
			break;
		case 3:
			Cancel();
			break;
		case 4:
			 display(fr,To);
			 
			 break;
		case 5:
			exit(0);
	}

}

int main()
{
	int ch;
	Colour(241);
	printf("\n\n\n\n\n\n\t\t\t\t\t\t\t\tCITY TRAVELS");
	Colour(240);
	printf("\n\n\n\n\t\t\t\t\tCity Travels providing travel solutions to their passengers with best in class \n\t\t\t\t\tquality by operating brand new fleets with well experienced professionals. \n\t\t\t\t\tSome of the Important routes of City Travels include Chennai to Coimbatore Book \n\t\t\t\t\tCity Travels bus tickets online in website and from your mobile with few easy steps.");
    int count =0;
    do
    {
       int c = 0;
       count = 0;
       Colour(252);
       printf("\n\n\n\n\t\t\t\t\t\t\tPress ENTER to continue");
       Colour(240);
       fflush(stdout);
       while((c = getchar()) != '\n' )
       {
          ++count;
       }
       if(count)
       {
          puts("\n\n\n\n\t\t\t\t\t\t\tENTER only, I say!");
       }
    } while(count);
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t1) Register now");
    printf("\n\n\n\n\n\t\t\t\t\t\t\t\t2) Login");
     Colour(252);
    printf("\n\n\n\n\t\t\t\t\t\t\tEnter your choice......");
     Colour(240);
	int rtn = 0;
	for (;;) {
        rtn = scanf("\n%d",&ch);
        if (rtn == EOF) {
            fputs ("(user canceled input.)\n", stderr);
            return 1;
        }
        else if (rtn == 0) {
            fputs ("Invalid Option,please choose valid one...\n", stderr);
            empty_stdin();
        }
        else if (ch<1 || 2<ch) {
            fputs (" Option out of range [1-2]\n", stderr);
            empty_stdin();
        }
        else {
            empty_stdin();
            break;
        }
        system("pause");
    }
	switch(ch)
	{
		case 1:
			getchar();
			sign_up();
			char a;
			do
			{
				Colour(252);
				printf("\n\n\n\t\t\tPress L for login: ");
				Colour(240);
			    scanf("%c",&a);
			    if(a=='L'||a=='l')
			    {
			    	getchar();
			    	sign_in();
			    	break;
				}
				else
					continue;
			}while(true);
			break;
		case 2:
			getchar();
			system("cls");
			sign_in();
			break;
	}    
}
