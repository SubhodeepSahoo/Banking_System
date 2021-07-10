#include <sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<stdlib.h>

void mainMenu(int);
void displayMenu(int);
void admin_functions(int);
void jointAccountLogin(int);
void jointDisplayMenu(int);


void deleteAccount(int sd)
{
	char uname[20],buffer[35];

	printf("\nEnter the username to be deleted: ");
	scanf(" %s", uname);

	write(sd, uname, sizeof(uname));
	read(sd, buffer, sizeof(buffer));

	printf("%s",buffer);
	admin_functions(sd);
}

void deleteJointAccount(int sd)
{
	char uname1[20], uname2[20], buffer[35];

	printf("ENTER FIRST ACCOUNT HOLDER NAME TO DELETE  ACCOUNT : ");
	scanf(" %s",uname1);
	printf("ENTER SECOND ACCOUNT HOLDER NAME TO DELETE  ACCOUNT : ");
	scanf(" %s",uname2);

	write(sd, uname1, sizeof(uname1));
	write(sd, uname2, sizeof(uname2));

	read(sd, buffer, sizeof(buffer));

	printf("%s",buffer);
	admin_functions(sd);
}

void newJointAccount(int sd, int flag)
{
	char uname1[20], pass1[20], uname2[20], pass2[20], buffer[30];
	printf("ENTER FIRST ACCOUNT HOLDER NAME : ");
	scanf(" %s", uname1);
	printf("Enter password: ");
	scanf(" %s", pass1);
	printf("ENTER SECOND ACCOUNT HOLDER NAME : ");
	scanf(" %s", uname2);
	printf("ENTER PASSWORD : ");
	scanf(" %s", pass2);

	write(sd, uname1, sizeof(uname1));
	write(sd, pass1, sizeof(pass1));
	write(sd, uname2, sizeof(uname2));
	write(sd, pass2, sizeof(pass2));

	read(sd, buffer, sizeof(buffer));
	printf("%s", buffer);
	if(flag==1)
		mainMenu(sd);
	else
		admin_functions(sd);
}

void signUp(int sd, int flag)
{
	int account_id;
	char uname[20],pass[20], buffer[30];

	printf("ENTER ACCOUNT HOLDER NAME : ");
	scanf(" %s",uname);
	printf("ENTER PASSWORD : ");
	scanf(" %s",pass);

	write(sd, uname,sizeof(uname));
	write(sd, pass, sizeof(pass));

	read(sd, buffer, sizeof(buffer));
	printf("%s", buffer);
	if(flag==1)
		mainMenu(sd);
	else
		admin_functions(sd);
}

void login(int sd)
{
	char buffer[30];
	char uname[20],pass[20];
	int flag;

	printf("ENTER ACCOUNT HOLDER NAME : ");
	scanf(" %s",uname);
	printf("ENTER PASSWORD : ");
	scanf(" %s",pass);

	write(sd, uname,sizeof(uname));
	write(sd, pass, sizeof(pass));

	read(sd, &flag, sizeof(flag));
	read(sd, buffer, sizeof(buffer));
	printf("%s",buffer);

	if(flag==1)
		displayMenu(sd);
	else
		mainMenu(sd);


}

void jointAccountLogin(int sd)
{
	char buffer[30];
	char uname1[20],pass[20],uname2[20];
	int flag;

	printf("ENTER FIRST ACCOUNT HOLDER NAME : ");
	scanf(" %s",uname1);

	printf("ENTER SECOND ACCOUNT HOLDER NAME : ");
	scanf(" %s",uname2);

	printf("ENTER PASSWORD FOR THE JOINT ACCOUNT : ");
	scanf(" %s",pass);

	write(sd, uname1,sizeof(uname1));
	write(sd, uname2,sizeof(uname2));
	write(sd, pass, sizeof(pass));

	read(sd, &flag, sizeof(flag));
	read(sd, buffer, sizeof(buffer));
	printf("%s",buffer);

	if(flag==1)
	{
		jointDisplayMenu(sd);
	}
	else
		mainMenu(sd);

}

void viewDetails(int sd)
{
	char uname[20];
	int acc_id, balance;

	read(sd,uname, sizeof(uname));
	read(sd,&acc_id, sizeof(acc_id));
	read(sd,&balance, sizeof(balance));

	printf("ACCOUNT HOLDER NAME : %s\n ACCOUNT ID : %d\n BALANCE : %d\n",uname,acc_id,balance);
	displayMenu(sd);
}

void viewJointDetails(int sd)
{
	char uname1[20], uname2[20];
	int acc_id, balance;

	read(sd,uname1, sizeof(uname1));
	read(sd,uname2, sizeof(uname2));
	read(sd,&acc_id, sizeof(acc_id));
	read(sd,&balance, sizeof(balance));

	printf("FIRST JOINT ACCOUNT HOLDER NAME : %s\nSECOND JOINT ACCOUNT HOLDER NAME : %s\n ACCOUNT ID : %d\n BALANCE : %d\n",uname1,uname2,acc_id,balance);
	jointDisplayMenu(sd);
}

void deposit(int sd)
{
	int amount;
	printf("\nENTER AMOUNT TO DEPOSIT : ");
	scanf("%d",&amount);

	write(sd, &amount, sizeof(amount));
	read(sd, &amount, sizeof(amount));
	printf("NEW BALANCE : %d",amount);

	displayMenu(sd);
}

void jointDeposit(int sd)
{
	int amount;
	printf("\nENTER AMOUNT TO DEPOSIT: ");
	scanf("%d",&amount);

	write(sd, &amount, sizeof(amount));
	read(sd, &amount, sizeof(amount));
	printf("NEW BALANCE : %d",amount);

	jointDisplayMenu(sd);
}

void jointWithdraw(int sd)
{
	int amount,flag;
	printf("\nENTER AMOUNT TO WITHDRAW : ");
	scanf("%d",&amount);

	write(sd, &amount, sizeof(amount));
	read(sd, &flag, sizeof(flag));

	if(flag==0)
	{
		printf("INSUFFICIENT BALANCE\n");
		read(sd, &amount, sizeof(amount));
		printf("BALANCE : %d",amount);
	}
	else
	{
		read(sd, &amount, sizeof(amount));
		printf(" NEWBALANCE : %d",amount);

	}

	jointDisplayMenu(sd);
}





void withdraw(int sd)
{
	int amount,flag;
	printf("\nENTER AMOUNT TO WITHDRAW : ");
	scanf("%d",&amount);

	write(sd, &amount, sizeof(amount));
	read(sd, &flag, sizeof(flag));

	if(flag==0)
	{
		printf("INSUFFICIENT BALANCE\n");
		read(sd, &amount, sizeof(amount));
		printf("BALANCE: %d",amount);
	}
	else
	{
		read(sd, &amount, sizeof(amount));
		printf(" NEWBALANCE: %d",amount);

	}

	displayMenu(sd);
}

void jointPassChange(int sd)
{
	char pass[20];

	printf("\nENTER THE NEW PASSWORD : ");
	scanf(" %s",pass);


	write(sd,pass,sizeof(pass));
	mainMenu(sd);

}



void passChange(int sd)
{
	char pass[20];

	printf("\nENTER THE NEW PASSWORD : ");
	scanf(" %s",pass);

	write(sd,pass,sizeof(pass));
	mainMenu(sd);

}

void displayMenu(int sd)
{
	int choice;
	printf("\n1.VIEW DETAILS\n2.DEPOSIT\n3.WITHDRAW\n4.PASSWORD CHANGE\n5.EXIT\n");
	printf("ENTER YOUR CHOICE : ");
	scanf("%d",&choice);

	write(sd, &choice, sizeof(choice));

	switch(choice)
	{
		case 1: viewDetails(sd);
				break;
		case 2: deposit(sd);
				break;
		case 3: withdraw(sd);
				break;
		case 4: passChange(sd);
				break;
		case 5: mainMenu(sd);
				break;
		default: printf("Enter proper choice");
				break;

	}
}

void jointDisplayMenu(int sd)
{
	int choice;
	printf("\n1.VIEW DETAILS\n2.DEPOSIT\n3.WITHDRAW\n4.PASSWORD CHANGE\n5.EXIT\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d",&choice);

	write(sd, &choice, sizeof(choice));

	switch(choice)
	{
		case 1: viewJointDetails(sd);
				break;
		case 2: jointDeposit(sd);
				break;
		case 3: jointWithdraw(sd);
				break;
		case 4: jointPassChange(sd);
				break;
		case 5: mainMenu(sd);
				break;


	}

}

void admin_functions(int sd)
{
	int choice;

	printf("\n1.ADD ACCOUNT\n2.DELETE ACCOUNT\n3.SEARCH ACCOUNT\n4.ADD JOINT ACCOUNT\n5.DELETE JOINT ACCOUNT\n6.SEARCH JOINT ACCOUNT\n7.EXIT\nENTER YOUR CHOICE: ");
	scanf("%d", &choice);

	char buffer[46], uname[20], pass[20], uname1[20], uname2[20];
	write(sd, &choice, sizeof(choice));

	switch(choice)
	{
		case 1:signUp(sd,0);
			break;
		case 2:deleteAccount(sd);
			break;
		case 3:printf("\nENTER ACCOUNT HOLDER NAME TO SEARCH: ");
			scanf(" %s", uname);
			write(sd, uname, sizeof(uname));
			read(sd, &buffer, sizeof(buffer));
			printf(" %s", buffer);
			admin_functions(sd);
			break;
		case 4:newJointAccount(sd,0);
			break;
		case 5:deleteJointAccount(sd);
			break;
		case 6:printf("\nENTER FIRST ACCOUNT HOLDER NAME TO SEARCH: ");
			scanf(" %s", uname1);
			printf("\nENTER SECOND ACCOUNT HOLDER NAME TO SEARCH : ");
			scanf(" %s", uname2);
			write(sd, uname1, sizeof(uname1));
			write(sd, uname2, sizeof(uname2));
			read(sd, &buffer, sizeof(buffer));
			printf("%s", buffer);
			admin_functions(sd);
			break;
		case 7:mainMenu(sd);
	}
}

void adminLogin(int sd)
{
	char uname[20], pass[20], buffer[20];
	int flag;

	printf("\nENTER THE ADMIN USERNAME: ");
	scanf(" %s",uname);
	printf("\nENTER ADMIN PASSWORD: ");
	scanf(" %s",pass);

	write(sd, uname, sizeof(uname));
	write(sd, pass, sizeof(pass));
	read(sd, &flag, sizeof(flag));
	read(sd, buffer, sizeof(buffer));

	printf("%s",buffer);
	if(flag == 1)
		admin_functions(sd);
	else
		mainMenu(sd);
}

void mainMenu(int sd)
{
	int choice;

	printf("\n1.SIGNUP\n2.LOGIN\n3.ADMIN LOGIN\n4.NEW JOINT ACCOUNT\n5.JOINT ACCOUNT LOGIN\n6.EXIT\n");
	printf("ENTER YOUR CHOICE: ");
	scanf("%d",&choice);

	write(sd, &choice, sizeof(choice));

	switch(choice)
	{
		case 1: signUp(sd,1);
				break;
		case 2: login(sd);
				break;
		case 3: adminLogin(sd);
				break;
		case 4: newJointAccount(sd,1);
				break;
		case 5: jointAccountLogin(sd);
				break;
		case 6: exit(0);
				break;

	}
}

int main(int argc,char *argv[])
{
	printf("======== WELCOME TO DBS BANK ========\n");
	int send_num;
	char buffer[80];
  int socket_fd = socket(AF_INET,SOCK_STREAM,0);                                     //Get the file descriptor
  struct sockaddr_in socket_client_element;
  socket_client_element.sin_family = AF_INET;
  socket_client_element.sin_port = htons(12400);
  socket_client_element.sin_addr.s_addr = INADDR_ANY;
	int size_of_client = sizeof(socket_client_element);
 	connect(socket_fd,(struct sockaddr *)&socket_client_element,size_of_client);
 	perror("accept");
	mainMenu(socket_fd);
	close(socket_fd);
 	return 0;
}
