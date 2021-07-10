The project aims to implement banking service. There are 2 types of account that we are creating
For both Single Account and Joint Account which have following functionalities,
For Customer, He can
a. create account 
b. login in to his account
c. view details
d. deposit
e. withdraw
f. change password
 For Admin, He can
a. Add Account
b. Delete Account
c. Search Account
d. Add Joint Account
e. Delete Joint Account
f. Search Joint Account
The difference between Single Account and Joint Account is joint account can be shared by 2 customers.
We are using Shared Locking to prevent the updation in any account by another user while one user is using it.
We are also using socket programing so that server maintains the data base and service multiple clients
concurrently. Client program can connect to the server and access their specific account details.
Used system calls instead of Library functions wherever it is possible in the project:
Process Management, File Management, File Locking, Multithreading and Inter Process Communication Mechanisms.
