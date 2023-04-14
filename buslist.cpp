
struct busList1
{
	char b_no[10];
	char b_brd[50];
	char type[20];
	char from[50];
	char to[50];
	char dist[10];
	char dep[10];
	float ticketRsAdult;
	float ticketRsChild;
	char d_name[100];
	char d_mob[20];
	char v_no[20];
	char v_name[20];
	char seats[40][20];
};

struct node1
{
   struct busList1 a1;
   struct node1 *next;
   struct node1 *prev;
};

struct node1 *newNode_bl;
struct node1  *head1_bl,*temp1_bl,*tail_bl;

void free_linked_bl()
{
    struct node1* tem=head1_bl;
	while(tem!=NULL)
	{
        struct node1* tem1 = tem;
        tem=tem->next;
        free(tem1);
	}
	head1_bl = NULL;
}

void cpyBuslist1(busList1 *dest,busList1 *src)
{
	strcpy(dest->b_no,src->b_no);
	strcpy(dest->b_brd,src->b_brd);
	strcpy(dest->dep,src->dep);
	strcpy(dest->dist,src->dist);
	strcpy(dest->from,src->from);
	strcpy(dest->to,src->to);
	strcpy(dest->type,src->type);
	dest->ticketRsAdult = src->ticketRsAdult;
	dest->ticketRsChild = src->ticketRsChild;
	strcpy(dest->d_name,src->d_name);
	strcpy(dest->d_mob,src->d_mob);
	strcpy(dest->v_name,src->v_name);
	strcpy(dest->v_no,src->v_no);
	for(int i=0;i<40;i++)
	{
		strcpy(dest->seats[i],src->seats[i]);
	}
}

void insert_linked_a(struct busList1 q)
{
   newNode_bl = (struct node1*)malloc(sizeof(struct node1));
   cpyBuslist1(&newNode_bl->a1,&q);
   newNode_bl->prev = NULL;
   newNode_bl->next = NULL;
   if(head1_bl==NULL)
    {
        head1_bl = newNode_bl;
        tail_bl = newNode_bl;
    }
    else
    {
        tail_bl->next=newNode_bl;
        newNode_bl->prev=tail_bl;
        tail_bl = newNode_bl;
    }
}


void Read_Bus_bl(char *filename)
{
	FILE *fp;
	fp = fopen(filename,"rb");   
	struct busList1 q;
	int ch,choice,n_tic;
	int size=0;
	while(fread(&q,sizeof(busList1),1,fp))
	{
	   		size++;
	   		insert_linked_a(q);	
	}
	fclose(fp);    
}

//----------------------------------------------------------------------------------------------------------//
// BUS INFORMATION
//----------------------------------------------------------------------------------------------------------//
void print_bl(char bus_no[])
{
    struct node1 *ptr = head1_bl;
    system("cls");
    Colour(15);
    printf("\n\n\n\n\t\t\t\t\t\t\t\t\t\tBUS LIST");
    Colour(244);
    printf("\n\n\n\n\t\t\t\t\tBus no\t\tDistance\t\tFrom\t\tTo\t\tTicket cost\t\tDepature Time\n");
    Colour(240);
    while(ptr != NULL)
    {
    	Colour(248);
   	    printf("\n\n\t\t\t\t\t%s%20s%20s%15s%25f%20s",ptr->a1.b_no,ptr->a1.dist,ptr->a1.from,ptr->a1.to,ptr->a1.ticketRsAdult,ptr->a1.dep);
   	    ptr = ptr->next;
    }
    Colour(244);
	printf("\n\n\n\t\t\t\t\tEnter Bus No.:");
	Colour(240);
    gets(bus_no);
    struct node1 *p=head1_bl;
    while(p!=NULL)
    {
    if(strcmp(bus_no,p->a1.b_no)==0)
    {
    	system("cls");
    	Colour(143);
    	printf("\n\t\t\t\t\t\t\t\tBUS DETAILS");
    	Colour(240);
    	printf("\n\t\t\t\t ================================================================================");
    	printf("\n\t\t\t\t| Bus Number                  : %-20s \t\t\t\t|",p->a1.b_no);
		printf("\n\t\t\t\t| Bus Type                    : %-20s \t\t\t\t|",p->a1.type);
		printf("\n\t\t\t\t| Bus Brand                   : %-20s \t\t\t\t|",p->a1.b_brd);
		printf("\n\t\t\t\t| From place                  : %-20s \t\t\t\t|",p->a1.from);
		printf("\n\t\t\t\t| To place                    : %-20s \t\t\t\t|",p->a1.to);
		printf("\n\t\t\t\t| Distance                    : %-20s \t\t\t\t|",p->a1.dist);
		printf("\n\t\t\t\t| Departure Time              : %-20s \t\t\t\t|",p->a1.dep);
		printf("\n\t\t\t\t| Driver name                 : %-20s \t\t\t\t|",p->a1.d_name);
		printf("\n\t\t\t\t| Driver mobile number        : %-20s \t\t\t\t|",p->a1.d_mob);
		printf("\n\t\t\t\t| Vaccine Name                : %-20s \t\t\t\t|",p->a1.v_name);
		printf("\n\t\t\t\t| Vaccine number              : %-20s \t\t\t\t|",p->a1.v_no);
		fflush(stdin);
		printf("\n\t\t\t\t| Ticket Cost[Adult]          : %-20f \t\t\t\t|",p->a1.ticketRsAdult);
		printf("\n\t\t\t\t| Ticket Cost[Child(>12yrs)]  : %-20f \t\t\t\t|",p->a1.ticketRsChild);
		fflush(stdin);
		printf("\n \t\t\t\t================================================================================");
		int index = 0;
		printf("\n\n\n");
		for(int j=0;j<40;j++)
		{
		   printf("%d->%s\t",index+1,p->a1.seats[j]);
		   index++;
		   printf("\t\t\t\t");
			if(j%4==0)
			{
			 printf("\n");
		    }
		}  
		int count =0;
		for(int i=0;i<40;i++)
		{
			if(strcmp(p->a1.seats[i],"Empty")==0)
			{
				count++;
			}
		}
		Colour(15);
		printf("\n\n\nAvailable seats are: %d",count);
		Colour(240);
		 
	}
     p=p->next;
    }
   
}

int Buslist()
{
	int ch,choice;
	int n_tic;
	int found = 0;
	char fr[50],To[50],bus_no[50];
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	Colour(245);
	printf("BUSLIST");
	printf("\n\n\n\n\t\t\t\t\t\t");
	Colour(252);
	printf("CHOOSE THE DAY IN WHICH YOU PLANNED TO TRAVEL");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	Colour(240);
	printf("1)Monday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("2)Tuesday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("3)Wednesday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("4)Thursday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("5)Friday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("6)Saturday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("7)Sunday");
	printf("\n\n\t\t\t\t\t\t\t\t");
	printf("8)Back");
	printf("\n\n\n\t\t\t\t\t\t");
	Colour(252);
	printf("Give your choice:");
	Colour(240);
	int rtn = 0;
	for (;;) {
        rtn = scanf("%d",&ch);
        if (rtn == EOF) {
            fputs ("(user canceled input.)\n", stderr);
            return 1;
        }
        else if (rtn == 0) {
            fputs ("Invalid Option,please choose valid one...\n", stderr);
            empty_stdin();
        }
        else if (ch<1 || 8<ch) {
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
			free_linked_bl();
		    Read_Bus_bl("day1.bin");
		    start1:
		    fflush(stdin);
		    print_bl(bus_no);
		    Colour(252);
		    printf("\n\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		        goto start1;	
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}
		    break;
	    case 2:
	    	free_linked_bl();
		    Read_Bus_bl("day2.bin");
		    start2:
		    fflush(stdin);
		    print_bl(bus_no);
		    Colour(252);
		    printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    	Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start2;
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}
		    break;
	    case 3:
	    	free_linked_bl();
	    	Read_Bus_bl("day3.bin");
	    	start3:
	    	fflush(stdin);
			print_bl(bus_no);
			Colour(252);
			printf("\n\nWould you like to see other buses?(Yes-'Y'/No-'N')");
				Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start3;
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}
		    break;
		case 4:
			free_linked_bl();
			Read_Bus_bl("day4.bin");
			start4:
			fflush(stdin);
			print_bl(bus_no);
			Colour(252);
			printf("\n\nWould you like to see other buses?(Yes-'Y'/No-'N')");
				Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start4;
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}    
		    break;
		case 5:
			free_linked_bl();
			Read_Bus_bl("day5.bin");
			start5:
			fflush(stdin);
			print_bl(bus_no);
			Colour(252);
			printf("\n\nWould you like to see other buses?(Yes-'Y'/No-'N')");
				Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start5;
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}
		    break;
		case 6:
			free_linked_bl();
			Read_Bus_bl("day6.bin");
			start6:
			fflush(stdin);
			print_bl(bus_no);
			Colour(252);
			printf("\n\nWould you like to see other buses?(Yes-'Y'/No-'N')");
				Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		        goto start6;
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}
		    break;
		case 7:
			free_linked_bl();
		   Read_Bus_bl("day7.bin");
		    start7:
		    fflush(stdin);
			print_bl(bus_no);
			Colour(252);
			printf("\n\nWould you like to see other buses?(Yes-'Y'/No-'N')");
			Colour(240);
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start7;
			}
			else if(ch == 'N'||ch =='n')
			{
				Buslist();
			}
		    break;
		case 8:
			Contents();
	}   
}