void del(char *file2,char name[])
{
	int a;
	FILE *fp;
	FILE *fp2;
	fp = fopen(file2,"rb");
	fp2 = fopen("temp.bin","w+");
	
	struct customer_info c;
	while(fread(&c,sizeof(struct customer_info),1,fp))
	{
		if(strcmpi(name,c.customerName)==0)
		{
			continue;
		}
		fwrite(&c,sizeof(struct customer_info),1,fp2);
	}

    
	remove(file2);
	rename("temp.bin",file2);
	fclose(fp);
	fclose(fp2);
}

void cancel(char bus_no[],char *filename)
{	
    struct node *p= head1;
	struct customer_info c;
	char name[50],email[50];
	int s;
	fflush(stdin);
	Colour(252);
    printf("\n\nEnter Email Id:");
    Colour(240);
    gets(email);
	FILE *fil2;
	char file2[20];
	strcpy(file2,email);
	strcat(file2,".bin");
	fil2 = fopen(file2,"rb");
	Colour(252);
	printf("\nEnter the name:");
	Colour(240);
	gets(name);
	Colour(252);
	printf("\nEnter the seat number:");
	Colour(240);
	scanf("%d",&s);
	while(fread(&c,sizeof(customer_info),1,fil2))
	{
	    insert_linked2(c);
	}
		struct node2 *p1=head2;
	
	while(p1!=NULL)
		{
			if(strcmpi(name,p1->c.customerName)==0)
			{
		while(p!=NULL)
		{
			if(strcmpi(bus_no,p->a1.b_no)==0)
			{
				
				for(int j=0;j<40;j++)
				{
					if(s-1==j)
					{
		
						int w=1;
						Colour(252);
						    printf("\nAre you sure for cancelling the ticket?");
						    Colour(240);
	          		        printf("\n\t\t1).Yes");
	          	          	printf("\n\t\t2).No\n");
	          	          	
	          	          	
						while(w==1)
						{
		                    scanf("%d",&w);
	          	          	switch(w)
	          	          	{
	          	          		case 1:strcpy(p->a1.seats[j],"Empty");
				                       replace(p->a1,bus_no,filename);
				                       fclose(fil2);
				                       del(file2,p1->c.customerName);
				                       printf("\n\nThe seat has been cancelled!!!....");
				                       printf("\n\nThe amount will be refunded to your account within a week");
				                       return;
				                case 2:
				                       break;
							}
							
						}
			        }
			    }
			}
			
			p=p->next;
		}
	   }
	   p1=p1->next;
    }
        
        
    }
    
    
void CancelBus(char *filename,char fr[],char To[])
{
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
    	CancelBus(filename,fr,To);
	}
	fclose(fp);    
}

int Cancel()
{

	int ch,choice;
	int found = 0;
	char fr[50],To[50],bus_no[50];
	char departure[10];
	start1:
	system("cls");
	printf("\n\n\n\n\t\t\t\t\t\t\t\t");
	Colour(245);
	printf("CANCEL BOOKING");
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
			CancelBus("day1.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day1.bin");
		                         goto k;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day1.bin");
		                         goto k;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day1.bin");
		                        goto k;
		                        break;
		                case 4:
		                	   goto k;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
	    case 2:
	    	free_linked();
		    CancelBus("day2.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k1:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h1:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day2.bin");
		                         goto k1;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day2.bin");
		                         goto k1;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day2.bin");
		                        goto k1;
		                        break;
		                case 4:
		                	   goto k1;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h1;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
	    case 3:
	    	free_linked();
	    	CancelBus("day3.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k2:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h2:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day3.bin");
		                         goto k2;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day3.bin");
		                         goto k2;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day3.bin");
		                        goto k2;
		                        break;
		                case 4:
		                	   goto k2;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h2;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
		case 4:
			free_linked();
		    CancelBus("day4bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k3:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h3:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day4.bin");
		                         goto k3;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day4.bin");
		                         goto k3;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day4.bin");
		                        goto k3;
		                        break;
		                case 4:
		                	   goto k3;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h3;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
		case 5:
			free_linked();
			CancelBus("day5.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k4:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h4:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day5.bin");
		                         goto k4;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day5.bin");
		                         goto k4;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day5.bin");
		                        goto k4;
		                        break;
		                case 4:
		                	   goto k4;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h4;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
		case 6:
			free_linked();
			CancelBus("day6.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k5:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h5:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day6.bin");
		                         goto k5;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day6.bin");
		                         goto k5;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day6.bin");
		                        goto k5;
		                        break;
		                case 4:
		                	   goto k5;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h5;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
		case 7:
			free_linked();
		   CancelBus("day7.bin",fr,To);
		    fflush(stdin);
		    print(bus_no,departure);
		    k6:
		    printf("\n\n1) Cancel \t\t\t\t2) Back\t");
            scanf("%d",&choice);
	        switch(choice)
	        {
	          case 1:
	          	int w;
	          	while(1)
	          	{
	          		Colour(244);
	          		printf("\nReason for cancelling your ticket!!!");
	          		printf("\n\t\t1).Personal reasons");
	          		printf("\n\t\t2).I am not comfortable with your service");
	          		printf("\n\t\t3).No reasons");
	          		printf("\n\t\t4).Back");
	          		Colour(240);
	          		h6:
	          		scanf("%d",&w);
	          		switch(w)
	          		{
	          			case 1:
		                         cancel(bus_no,"day7.bin");
		                         goto k6;
		                         break;
		                case 2:	 
		                         cancel(bus_no,"day7.bin");
		                         goto k6;
		                         break;
		                case 3:	 
		                        cancel(bus_no,"day7.bin");
		                        goto k6;
		                        break;
		                case 4:
		                	   goto k6;
		                	   break;
		                default:printf("\nSelect the correct one:");
		                        goto h6;
		            }
				}
		        break;
	          case 2:
	   	         Cancel();
	   	         break;
	          default:	
	             printf("\n\nInvalid choice");
          	}    
		    break;
		case 8:
			 Contents();
			 break;
	} 
}
