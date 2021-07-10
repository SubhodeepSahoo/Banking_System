The project aims to implement banking service. There are 2 types of account that we are creating <br/>
For both Single Account and Joint Account which have following functionalities, <br/>
For Customer, He can <br/>
a. create account <br/>
b. login in to his account <br/>
c. view details <br/>
d. deposit <br/>
e. withdraw <br/>
f. change password <br/>
For Admin, He can <br/>
a. Add Account <br/>
b. Delete Account <br/>
c. Search Account <br/>
d. Add Joint Account <br/>
e. Delete Joint Account <br/>
f. Search Joint Account <br/>
The difference between Single Account and Joint Account is joint account can be shared by 2 customers. <br/>
We are using Shared Locking to prevent the updation in any account by another user while one user is using it. <br/>
We are also using socket programing so that server maintains the data base and service multiple clients <br/>
concurrently. Client program can connect to the server and access their specific account details. <br/>
Used system calls instead of Library functions wherever it is possible in the project: <br/>
Process Management, File Management, File Locking, Multithreading and Inter Process Communication Mechanisms. <br/>
