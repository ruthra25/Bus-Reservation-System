void Colour(WORD Attributes)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), Attributes);
}
struct login
{
	char name[50];
	char email[100];
	char p_no[11];
	char passwor[20];
};


bool isChar(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z'));
}

bool isDigit(const char c)
{
	return (c >= '0' && c <= '9');
}

bool Validity(char *t_mail)
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


void sign_up()
{
	getchar();
	char t_mail[100];
	char t_ph[11];
	char u_pass[20];
	int i,k;
	int flag=0;
	struct login l;
	struct login c;
	FILE *ln;
	FILE *lo;
	lo = fopen("login.bin","ab+");
	system("cls");
	Colour(241);
	printf("\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tSIGN IN");
	Colour(240);
	fflush(stdin);
	Colour(248);
	printf("\n\n\n\n\t\t\tUsername  :");
	Colour(240);
	gets(l.name);
	fflush(stdin);
	jump:
		Colour(248);
	printf("\n\t\t\tEmail     :");
	Colour(240);
	gets(l.email);
	strcpy(t_mail,l.email);
	bool check = Validity(t_mail);
	if(!check)
	{
		printf("\n\n\n\tEmail is not valid");
		goto jump;
	}
	fflush(stdin);
	do
	{
	Colour(248);
	printf("\n\t\t\tPhone No. :");
	Colour(240);
	gets(l.p_no);
	strcpy(t_ph,l.p_no);
	k=strlen(t_ph);
	if(k>9&&k<=10)
	  break;
	else
	printf("\nInvalid phone number,please eneter the correct one!......\n");
	 continue;
}while(true);
	fflush(stdin);
	Colour(248);
	printf("\n\t\t\tPassword  :");
	Colour(240);
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			l.passwor[i] = u_pass[i];
			++i;
			u_pass[i]='*';
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			l.passwor[i] = '\0';
			break;
		}
	}
	
	while(fread(&c,sizeof(login),1,lo))
    {
    	if(strcmpi(t_mail,c.email)==0 && strcmpi(t_ph,c.p_no)==0)
    	{
    		flag=1;
    		
		}
	}
	if(flag==1)
	{
	    printf("\n\nEmail/Phone number is already registered...");
    	sign_up();	
	}
	else
	{
	char filename[20];
	strcpy(filename,l.email);
	strcat(filename,".bin");
	ln = fopen(filename,"ab");
	//fwrite(&l, sizeof(login), 1, ln);
	fclose(ln);
	fwrite(&l, sizeof(login),1,lo);
	fclose(lo);
   }
}

void sign_in()
{
	int flag=0;
	char u_pass[20],pass[20];
	int i;
	char username[50];
	struct login l;
	FILE *lo;
	system("cls");
	Colour(241);
	printf("\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n\t\t\t\t\t\t\t\tLOGIN\t\t\t\t\t\t\t\t\t\t\t\t\t\n\t\t\t");
	Colour(240);
	fflush(stdin);
	Colour(248);
	printf("\n\n\n\t\t\t\n\t\tUsername  :");
	Colour(240);
	gets(username);
	fflush(stdin);
	Colour(248);
	printf("\n\n\n\t\t\t\n\t\tPassword  :");
	Colour(240);
	for( i=0 ; ; )
	{
		u_pass[i] = getch();
		if((u_pass[i]>='a'&&u_pass[i]<='z')||(u_pass[i]>='A'&&u_pass[i]<='Z')||(u_pass[i]>='!'&&u_pass[i]<='@'))
		{
			pass[i] = u_pass[i];
			++i;
			u_pass[i]='*';
			printf("%c",u_pass[i]);
		}
		if(u_pass[i] == '\b' && i>=1)
		{
		    printf("\b \b");
		    --i;
		}
		if(u_pass[i] == '\r')
		{
			pass[i] = '\0';
			break;
		}
	}
	lo = fopen("login.bin","rb");
	
	while(fread(&l,sizeof(login),1,lo))
	{
		if(strcmpi(username,l.name)==0 && strcmpi(pass,l.passwor)==0)
		{
			flag = 1;
			Colour(243);
			printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tLogged in Successfully!!!");
			Colour(240);
			Sleep(1500);
			Contents();
		}
	}
	if(flag == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\tInvalid Username/Password..."); 
		sign_in();
	}
}
  
