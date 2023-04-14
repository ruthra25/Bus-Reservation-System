int booking();
struct busList
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

struct customer_info
{
	char customerName[100];
	char customerLastName[100];
	int age;
	int seat;
	float calcTic;
	float totalTic;
	char bus[10];
	char depart[10];
	char from_place[50];
	char to_place[50];
	char status[20];
	char day[10];
	char date[15];
};

struct node
{
   struct busList a1;
   struct node *next;
   struct node *prev;
};

struct node2
{
	struct customer_info c;
	struct node2 *next;
	struct node2 *prev;
};

struct node *newNode;
struct node  *head1,*temp1,*tail;

struct node2 *newNode2;
struct node2  *head2,*temp2,*tail2;

bool isChar1(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

bool isDigit1(const char c)
{
	return (c >= '0' && c <= '9');
}

bool Validity1(char *t_mail)
{
	int i;
   if(!isChar(t_mail[0]))
   {
   	 return 0;
   }
   
   int at=-1,dot=-1;
   
 
   for(i=0;i<strlen(t_mail);i++)
   {
   	    if(t_mail[i] == '@')
   	    {
   	  	   at = i;
		}
		else if(t_mail[i]== '.')
		{
			dot = i;
		}
	
   }
   
   if (at == -1 || dot == -1)
		{
		  return 0;
        }
        
	    if (at > dot)
	    {
		  return 0;
	    }
	    
   return 1;
}


void free_linked()
{
    struct node* tem=head1;
	while(tem!=NULL)
	{
        struct node* tem1 = tem;
        tem=tem->next;
        free(tem1);
	}
	head1 = NULL;
}

void free_linked1()
{
	struct node2 *tem2 = head2;
	while(tem2!=NULL)
	{
		struct node2* tem3 = tem2;
		tem2 = tem2->next;
		free(tem3);
	}
	head2 = NULL;
}

//----------------------------------------------------------------------------------------------------------//
// PRINTING THE SEATS
//----------------------------------------------------------------------------------------------------------//
void seats(char bus_no[])
{
	struct node *p=head1;
	int index=0;
	while(p!=NULL)
	{
		if(strcmpi(bus_no,p->a1.b_no)==0)
		{
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
   }
    p=p->next;	
   } 
}


void replace(busList b,char bus_no[],char *filename)
{
	FILE *fp2;
	fp2 = fopen(filename,"r+");
	rewind(fp2);
	busList temp;
	while(fread(&temp, sizeof(temp), 1, fp2))
    {
        if(strcmpi(temp.b_no,bus_no)==0)
        {
        	fseek(fp2,-sizeof(b),SEEK_CUR);
        	fflush(fp2);
        	fwrite(&b,sizeof(b),1,fp2);
        	fflush(fp2);
		}
    }
    fclose(fp2);
}


void cpyBuslist(busList *dest,busList *src)
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

void insert_linked(struct busList q)
{
   newNode = (struct node*)malloc(sizeof(struct node));
   cpyBuslist(&newNode->a1,&q);
   newNode->prev = NULL;
   newNode->next = NULL;
   if(head1==NULL)
    {
        head1 = newNode;
        tail = newNode;
    }
    else
    {
        tail->next=newNode;
        newNode->prev=tail;
        tail = newNode;
    }
}

//----------------------------------------------------------------------------------------------------------//
// STORING CUSTOMER INFORMATION INFORMATION IN LINKED LIST
//----------------------------------------------------------------------------------------------------------//
void cpyCustomer(customer_info *dest,customer_info *src)
{
	strcpy(dest->customerName,src->customerName);
	strcpy(dest->customerLastName,src->customerLastName);
	dest->age = src->age;
	dest->seat = src->seat;
}

void insert_linked2(struct customer_info s)
{
   newNode2 = (struct node2*)malloc(sizeof(struct node));
   cpyCustomer(&newNode2->c,&s);
   newNode2->prev = NULL;
   newNode2->next = NULL;
   if(head2==NULL)
    {
        head2 = newNode2;
        tail2 = newNode2;
    }
    else
    {
        tail2->next=newNode2;
        newNode2->prev=tail2;
        tail2 = newNode2;
    }
}


void display(char fr[],char To[])
{
	char ch;
	char email_id[100];
	struct node *p= head1;
	struct customer_info c;
	fflush(stdin);
	printf("\n\nEnter E-mail ID : ");
	gets(email_id);
	FILE *fil2;
	char file2[20];
	strcpy(file2,email_id);
	strcat(file2,".bin");
	fil2 = fopen(file2,"rb");
	if(fread(&c,sizeof(customer_info),1,fil2))
	{
	    printf("\n\n|-------------------------------------------------------------------------------|");
	    printf("\n|\t\t\t-----TICKET-----                                        |");
	    printf("\n|-------------------------------------------------------------------------------|");
	    printf("\n| Name           : %-s %s \t\t\t\t\t\t\t|",c.customerName, c.customerLastName);
		printf("\n| Age            : %-20d \t\t\t\t\t|",c.age);
		printf("\n| Bus no         : %-20s \t\t\t\t\t|",c.bus);
		printf("\n| Seat           : %-20d \t\t\t\t\t|",c.seat);
		printf("\n| Departure Time : %-20s \t\t\t\t\t|",c.depart);
		printf("\n| Day            : %-20s \t\t\t\t\t|",c.day);
		printf("\n| Date           : %-20s \t\t\t\t\t|",c.date);
		printf("\n| From           : %-20s \t\t\t\t\t|",c.from_place);
		printf("\n| To             : %-20s \t\t\t\t\t|",c.to_place);
		printf("\n| Status         : %-20s \t\t\t\t\t|",c.status);
		printf("\n ================================================================================");	
	}
	else
	{
		printf("\n\nTicket is not booked");
		getchar();
	    Contents();
	}
	
	while(fread(&c,sizeof(customer_info),1,fil2))
	{
	    printf("\n| Name           : %-s %s \t\t\t\t\t\t\t|",c.customerName, c.customerLastName);
		printf("\n| Age            : %-20d \t\t\t\t\t|",c.age);
		printf("\n| Bus no         : %-20s \t\t\t\t\t|",c.bus);
		printf("\n| Seat           : %-20d \t\t\t\t\t|",c.seat);
		printf("\n| Departure Time : %-20s \t\t\t\t\t|",c.depart);
		printf("\n| Day            : %-20s \t\t\t\t\t|",c.day);
		printf("\n| Date           : %-20s \t\t\t\t\t|",c.date);
		printf("\n| From           : %-20s \t\t\t\t\t|",c.from_place);
		printf("\n| To             : %-20s \t\t\t\t\t|",c.to_place);
		printf("\n| Status         : %-20s \t\t\t\t\t|",c.status);
		printf("\n ================================================================================");
	}
	printf("\n-------------------------------------------------------------------------------");
	printf("\n\nPress B to return to main menu");
	scanf("%c",&ch);
	if(ch == 'B'||ch == 'b')
	{
		Contents();
	}
	fclose(fil2);
}

//----------------------------------------------------------------------------------------------------------//
// DISPLAY TICKET
//----------------------------------------------------------------------------------------------------------//
void displayTic(int n_tic,char *c_email,char fr[],char To[],float total)
{
    getchar();
   	system("cls");
	struct node *p= head1;
	struct customer_info c;
	FILE *fil1;
	char file1[20];
	strcpy(file1,c_email);
	strcat(file1,".bin");
	fil1 = fopen(file1,"rb");
	printf("\n\n|-------------------------------------------------------------------------------|");
	printf("\n|\t\t\t-----TICKET-----                                        |");
	printf("\n|-------------------------------------------------------------------------------|");
	while(fread(&c,sizeof(customer_info),1,fil1))
	{
	    printf("\n| Name           : %-s %s\t\t\t\t|",c.customerName, c.customerLastName);
		printf("\n| Age            : %-20d \t\t\t\t\t|",c.age);
		printf("\n| Bus no         : %-20s \t\t\t\t\t|",c.bus);
		printf("\n| Seat           : %-20d \t\t\t\t\t|",c.seat);
		printf("\n| Departure Time : %-20s \t\t\t\t\t|",c.depart);
		printf("\n| Day            : %-20s \t\t\t\t\t|",c.day);
		printf("\n| Date           : %-20s \t\t\t\t\t|",c.date);
		printf("\n| From           : %-20s \t\t\t\t\t|",c.from_place);
		printf("\n| To             : %-20s \t\t\t\t\t|",c.to_place);
		printf("\n| Status         : %-20s \t\t\t\t\t|",c.status);
		printf("\n ================================================================================");
	}
	printf("\n| Amount: %f                                                          |",c.totalTic); 
	printf("\n-------------------------------------------------------------------------------");
	fclose(fil1);
}

//----------------------------------------------------------------------------------------------------------//
// CREDIT CARD PAYMENT
//----------------------------------------------------------------------------------------------------------//
void creditPay(int n_tic,float total)
{
	char cardNo[10],cardName[50],exp_date[10];
	int cvv;
	struct customer_info c;
	c.totalTic=total;
	char op;
	fflush(stdin);
	Colour(252);
	printf("\n\nCard number :");
	Colour(240);
   	gets(cardNo);
   	fflush(stdin);
   	Colour(252);
   	printf("\nName on card  :");
   	Colour(240);
   	gets(cardName);
   	fflush(stdin);
   	Colour(252);
   	printf("\nExpiry date   :");
   	Colour(240);
   	gets(exp_date);
   	fflush(stdin);
   	Colour(252);
    printf("\nCVV           :");
    Colour(240);
   	scanf("%d",&cvv);
   	Colour(244);
   	printf("\n\nTotal amount: %f",c.totalTic);
   	printf("\n\nPress P to complete payment: ");
   	Colour(240);
   	fflush(stdin);
   	scanf("%c",&op);
   	if(op == 'P'||op == 'p')
   	{
   		Colour(242);
   		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tIN PROGRESS...");
	    Sleep (1500);
	    printf(".....");
	    Sleep (2000);
	    printf(".....");
	    Sleep (2000);
	    printf(".....");
   	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPAYMENT IS SUCCESSFUL");		
   	    Colour(240);
    }
}
void debitPay(int n_tic,float total)
{	
	char cardNo[10],cardName[50],exp_date[10];
	int cvv;
	struct customer_info c;
	c.totalTic=total;
	char op;
    fflush(stdin);
    Colour(252);
	printf("\n\nCard number :");
	Colour(240);
   	gets(cardNo);
   	fflush(stdin);
   	Colour(252);
   	printf("\nName on card  :");
   	Colour(240);
   	gets(cardName);
   	fflush(stdin);
   	Colour(252);
   	printf("\nExpiry date   :");
   	Colour(240);
   	gets(exp_date);
   	fflush(stdin);
   	Colour(252);
   	printf("\nCVV           :");
   		Colour(240);
   	scanf("%d",&cvv);
   	printf("\n\nTotal amount: %f",c.totalTic);
   	Colour(252);
   	printf("\n\nPress P to complete payment: ");
   		Colour(240);
   	fflush(stdin);
   	scanf("%c",&op);
   	if(op == 'P'||op == 'p')
   	{
   			Colour(242);
   		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tIN PROGRESS...");
	    Sleep (1500);
	    printf(".....");
	    Sleep (2000);
	    printf(".....");
	    Sleep (2000);
	    printf(".....");
   	    printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tPAYMENT IS SUCCESSFUL");
		   Colour(240);	
    }
}

//----------------------------------------------------------------------------------------------------------//
// PAYMENT
//----------------------------------------------------------------------------------------------------------//
void payNow(int n_tic,char c_email[],char fr[],char To[],float total)
{
	getchar();
	system("cls");
	int ch;
	Colour(244);
   	printf("\n\nPAYMENT GATEWAY");
   	Colour(240);
   	printf("\n\n1)Credit card");
   	printf("\n\n2)Debit card");
   	Colour(252);
   	printf("\n\nChoose your mode of payment: ");
   	Colour(240);
   	scanf("\n%d",&ch);
   	switch(ch)
   	{
   	    case 1:
   	    	creditPay(n_tic,total);
   	    	break;
	    case 2:
	    	debitPay(n_tic,total);
	    	break;
		default:	
		    printf("\n\n\n\t\t\t\t\t\t\t\tINVALID CHOICE, PLEASE CHOOSE VALID OPTION");
	}
   	displayTic(n_tic,c_email,fr,To,total);
   	
}


//----------------------------------------------------------------------------------------------------------//
// SEAT BOOK
//----------------------------------------------------------------------------------------------------------//
void seatBook(int n,char bus_no[],char file[],int seat,char custo_name[],char *filename)
{
	int i,j;
	struct busList b;
	struct customer_info c;
	for(i=0;i<n;i++)
	{
		struct node *p=head1;
	    while(p!=NULL)
	    {
	        if(strcmpi(bus_no,p->a1.b_no)==0)
	        {
		        for(j=0;j<40;j++)
		        {
		   	        if(seat-1 == j)
		         	{
		                   strcpy(p->a1.seats[j],custo_name);
		                   replace(p->a1,bus_no,filename);
                    }
		        }
            }
	        p=p->next;
        }
	}
}

//----------------------------------------------------------------------------------------------------------//
// CUSTOMER INFORMATION
//----------------------------------------------------------------------------------------------------------//
void customer(int n,char bus_no[],char *filename,char fr[],char To[],char departure[],char days[],char dates[])
{
	int i,j,k;
	char c_email[100],p_no[11];
	struct busList b;
	struct customer_info c;
	Colour(112);
	printf("\n\n\n\nCUSTOMER INFORMATION\n\n");
	Colour(240);
	jump:
	fflush(stdin);
	Colour(252);
	printf("\n\nEnter Email ID :");
	Colour(240);
	gets(c_email);
	bool check = Validity(c_email);
	if(!check)
	{
		printf("\n\n\tEmail is not valid");
		goto jump;
	}
	fflush(stdin);
	do{
	Colour(252);
	printf("\nEnter Customer p.no:");
	gets(p_no);
	Colour(240);
	k=strlen(p_no);
	if(k>9&&k<=10)
	  break;
	else
	printf("\nInvalid phone number,please eneter the correct one!......\n");
	 continue;
}while(true);
	char file[20];
	FILE *fp3;
	strcpy(file,c_email);
	strcat(file,".bin");
	fp3 = fopen(file,"ab");
	for(i=1;i<=n;i++)
	{
		Colour(244);
	   printf("\n\nCustomer %d",i);
	   Colour(240);
	   fflush(stdin);
	   Colour(252);
	   printf("\n\nEnter Customer first name   :");
	   Colour(240);
	   gets(c.customerName);
	   fflush(stdin);
	   Colour(252);
	   printf("\nEnter Customer last name    :");
	   Colour(240);
	   gets(c.customerLastName);
	   fflush(stdin);
	   Colour(252);
	   printf("\nEnter Customer age          :");
	   Colour(240);
	   scanf("%d",&c.age);
	   strcpy(c.bus,bus_no);
	   printf("\nBus No.                     :%s",c.bus);
	   strcpy(c.depart,departure);
	   printf("\n\nDeparture Time              :%s",c.depart);
	   strcpy(c.day,days);
	   strcpy(c.date,dates);
	   printf("\n\nDay                         :%s",c.day);
	   printf("\n\nDate                        :%s",c.date);
	   strcpy(c.from_place,fr);
	   strcpy(c.to_place,To);
	   printf("\n\nFrom Place                  :%s",c.from_place);
	   fflush(stdin);
	   printf("\n\nTo Place                    :%s",c.to_place);
	   struct node *ptr=head1;
	   while(ptr!=NULL)
	   {
	   	    if(strcmpi(bus_no,ptr->a1.b_no)==0)
	   	    {
	   	        if(c.age >= 12)
			    {
			        c.calcTic = c.calcTic + ptr->a1.ticketRsAdult;
			    }
			    else if(c.age < 12 && c.age > 0)
			    {
			        c.calcTic = c.calcTic + ptr->a1.ticketRsChild;  
			    }	
		    }
		    ptr =ptr->next;  
	    }
	   
	    c.totalTic = c.calcTic;	
	   strcpy(c.status,"Paid");
	    f:
	    	Colour(252);
	    printf("\n\nEnter seat number           :");
	    Colour(240);
	    scanf("%d",&c.seat);
	    fflush(stdin);
	    if(c.seat>40)
        {
           printf("\nThere is only 40 seats in this bus");
           goto f;
	    }
	    
		   struct node *p=head1;
	        while(p!=NULL)
	        {
	           if(strcmpi(bus_no,p->a1.b_no)==0)
	           {
		            for(j=0;j<40;j++)
		            {
		   	            if(c.seat-1 == j)
		         	    {
		                    if(strcmp(p->a1.seats[j],"Empty")==0)
		                    {
		                    	printf("\n\nSeat is available !!!! Continue with your process");
		                    	seatBook(n,bus_no,file,c.seat,c.customerName,filename); 
							}
							else
							{
								printf("\n\nSeat is already booked... please choose another seat");
		                    	goto f;
							}
                        }
		            }
                }
	            p=p->next;
            }
	    
       fwrite(&c,sizeof(c),1,fp3);
	 }
	fclose(fp3);
	Colour(244);
	printf("\n\nTicket Cost : %f\n\n",c.totalTic);
	Colour(240);
	payNow(n,c_email,fr,To,c.totalTic);
	free_linked();
	free_linked1(); 
}


//----------------------------------------------------------------------------------------------------------//
// SELECT BUS
//----------------------------------------------------------------------------------------------------------//
void SelectBus(char *filename,char fr[],char To[])
{
	getchar();
	FILE *fp;
	fp = fopen(filename,"rb");   
	struct busList q;
	int ch,choice,n_tic;
	int size=0;
	system("cls");
	Colour(244);
	printf("\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tChoose your destination:");
	Colour(240);
	fflush(stdin);
	Colour(248);
	printf("\n\n\n\n\t\t\t\t\t\t\t\tFrom:");
	Colour(240);
	gets(fr);
	Colour(248);
	printf("\n\n\n\t\t\t\t\t\t\t\tTO:");
	Colour(240);
	gets(To);
	free_linked();
	while(fread(&q,sizeof(busList),1,fp))
	{
	
	   	if(strcmpi(q.from,fr)==0 && strcmpi(q.to,To)==0 )
	   	{
	   		size++;
	   		insert_linked(q);
		}	
	}
	struct node *ptr = head1;
	if(ptr == NULL)
    {
    	printf("\n\nBuses is not available");
    	SelectBus(filename,fr,To);
	}
	fclose(fp);    
}


//----------------------------------------------------------------------------------------------------------//
// BUS INFORMATION
//----------------------------------------------------------------------------------------------------------//
void print(char bus_no[],char departure[])
{
    struct node *ptr = head1;
    Colour(244);
    printf("\n\n\n\t\t\t\t\t\n\nBus no\t\tDistance\t\tTicket cost\tDepature Time\n");
    Colour(240);
    while(ptr != NULL)
    {
    	Colour(248);
   	    printf("\t\t\t\t\t\n%s%20s%27f%20s",ptr->a1.b_no,ptr->a1.dist,ptr->a1.ticketRsAdult,ptr->a1.dep);
   	    ptr = ptr->next;
    }
    Colour(112);
	printf("\n\n\t\t\t\t\tEnter Bus No.:");
	Colour(240);
    gets(bus_no);    
    struct node *p=head1;
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
		strcpy(departure,p->a1.dep);
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

/*void start_booking(char *filename,char fr[],char To[],char departure[])
{
	int choice;
	int n_tic;
	char bus_no[50];
	Colour(249);
	printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
	Colour(240);
    scanf("%d",&choice);
	switch(choice)
	{
	    case 1:
	    	char ch;
	   	    printf("\n\nEnter no. of tickets");
		    scanf("%d",&n_tic);
		    customer(n_tic,bus_no,filename,fr,To,departure);
		    printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    if(ch == 'Y'||ch == 'y')
		    {
		    	start_booking(filename,fr,To,departure);
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		    break;
	    case 2:
	   	    booking();
	    default:	
	        printf("\n\nInvalid choice");
	        start_booking(filename,fr,To,departure);
    }    
}*/


int booking()
{
    char days[10];
    char date[15];
	int ch,choice;
	int n_tic;
	int found = 0;
	char fr[50],To[50],bus_no[50];
	char departure[10];
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	Colour(245);
	printf("TICKET BOOKING");
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
            fputs (" Option out of range [1-8]\n", stderr);
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
			free_linked();
			strcpy(days,"Monday");
			strcpy(date,"27/9/2021");
			start1:
		    SelectBus("day1.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
        	{
	        case 1:
	        system("cls");
	        Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	        seats(bus_no);
	    	char ch;
	    	Colour(15);
	   	    printf("\n\n\n\nEnter no. of tickets");
	   	    Colour(240);
		    scanf("%d",&n_tic);
		    customer(n_tic,bus_no,"day1.bin",fr,To,departure,days,date);
		    fflush(stdin);
		    printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    scanf("%c",&ch);
			if(ch == 'Y'||ch == 'y')
		    {
		    	goto start1;
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		    break;
	    case 2:
	   	    booking();
	    default:	
	        printf("\n\nInvalid choice");
	        booking();
          }    
			//start_booking("day1.bin",fr,To);
		    break;
	    case 2:
	    	free_linked();
	    	strcpy(days,"Tuseday");
			strcpy(date,"28/9/2021");
	    	start2:
		    SelectBus("day2.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	system("cls");
	          	Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	   	        seats(bus_no);
	   	        Colour(15);
	   	        printf("\n\n\n\nEnter no. of tickets");
	   	         Colour(240);
		        scanf("%d",&n_tic);
		        customer(n_tic,bus_no,"day2.bin",fr,To,departure,days,date);
		        fflush(stdin);
		        char ch;
		       printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		       scanf("%c",&ch);
		       if(ch == 'Y'||ch == 'y')
		       {
		    	 goto start2;
			   }
			   else if(ch == 'N'||ch =='n')
			   {
				booking();
		    	}
		        break;
	          case 2:
	   	          booking();
	         default:	
	        printf("\n\nInvalid choice");
	        booking();
          	}    
		    break;
	    case 3:
	    	free_linked();
	    	strcpy(days,"Wednesday");
			strcpy(date,"29/9/2021");
	    	start3:
	    	SelectBus("day3.bin",fr,To);
	    	fflush(stdin);
			print(bus_no,departure);
	    	printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	system("cls");
	          	Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	   	        seats(bus_no);
	   	         Colour(15);
	   	        printf("\n\n\n\nEnter no. of tickets");
	   	        Colour(240);
		        scanf("%d",&n_tic);
		        customer(n_tic,bus_no,"day3.bin",fr,To,departure,days,date);
		        fflush(stdin);
		        char ch;
		    printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start3;
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		        break;
	          case 2:
	   	          booking();
	           default:	
	        printf("\n\nInvalid choice");
	        booking();
          	}    
		    break;
		case 4:
			free_linked();
			strcpy(days,"Thursday");
			strcpy(date,"30/9/2021");
			start4:
			SelectBus("day4.bin",fr,To);
			fflush(stdin);
			print(bus_no,departure);
			printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	system("cls");
	          	Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	   	        seats(bus_no);
	   	         Colour(15);
	   	        printf("\n\n\n\nEnter no. of tickets");
	   	        Colour(240);
		        scanf("%d",&n_tic);
		        customer(n_tic,bus_no,"day4.bin",fr,To,departure,days,date);
		        char ch;
		        printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		       scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start4;
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		        break;
	          case 2:
	   	          booking();
	    default:	
	        printf("\n\nInvalid choice");
	        booking();
          	}    
		        break;
		case 5:
			free_linked();
			strcpy(days,"Friday");
			strcpy(date,"01/10/2021");
			start5:
			SelectBus("day5.bin",fr,To);
			fflush(stdin);
			print(bus_no,departure);
			printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	system("cls");
	          	Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	   	        seats(bus_no);
	   	         Colour(15);
	   	        printf("\n\n\n\nEnter no. of tickets");
	   	        Colour(240);
		        scanf("%d",&n_tic);
		        customer(n_tic,bus_no,"day5.bin",fr,To,departure,days,date);
		        char ch;
		        printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		       scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start5;
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		        break;
	          case 2:
	   	          booking();
	    default:	
	        printf("\n\nInvalid choice");
	        booking();
          	}    
		    break;
		case 6:
			free_linked();
			strcpy(days,"Saturday");
			strcpy(date,"02/10/2021");
			start6:
			SelectBus("day6.bin",fr,To);
			fflush(stdin);
			print(bus_no,departure);
			printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	system("cls");
	          	Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	   	        seats(bus_no);
	   	         Colour(15);
	   	        printf("\n\n\n\nEnter no. of tickets");
	   	        Colour(240);
		        scanf("%d",&n_tic);
		        customer(n_tic,bus_no,"day6.bin",fr,To,departure,days,date);
		        char ch;
		        printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start6;
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		    break;
	        case 2:
	   	          booking();
	       default:	
	        printf("\n\nInvalid choice");
	        booking();
          	}    
		    break;
		case 7:
			free_linked();
			strcpy(days,"Sunday");
			strcpy(date,"03/10/2021");
			 start7:
		    SelectBus("day7.bin",fr,To);
		    fflush(stdin);
			print(bus_no,departure);
		    printf("\n\n1) Start Booking\t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	system("cls");
	          	Colour(112);
	          	printf("\n\n\n\t\t\t\t\t\t\t\tSEAT BOOKING\n\n\n");
	          	Colour(240);
	   	        seats(bus_no);
	   	         Colour(15);
	   	        printf("\n\n\n\nEnter no. of tickets");
	   	         Colour(240);
		        scanf("%d",&n_tic);
		        customer(n_tic,bus_no,"day7.bin",fr,To,departure,days,date);
		        char ch;
		        printf("\n\nWould you like to continue booking?(Yes-'Y'/No-'N')");
		    scanf("%c",&ch);
		    if(ch == 'Y'||ch == 'y')
		    {
		    	goto start7;
			}
			else if(ch == 'N'||ch =='n')
			{
				booking();
			}
		        break;
	        
	          case 2:
	   	         booking();
	          default:	
	             printf("\n\nInvalid choice");
	             booking();
          	}    
		    break;
		case 8:
			Contents();
		   
	} 
}
