#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<unistd.h>
#include<conio.h>

struct Book {
    int id;
    char bookName[30];
    char authorName[30];
    char studentName[30];
    char date[15];
    char returnDate[15];
    struct Book *ptrb;
}b;

FILE *ptr;
FILE *fp;

void project();
void welcome();
void login();
void main_menu();
int takeIntegerInput();

void add();
void search_Book();
void view();
void delete_Book();
void edit();

void welcome() {

    puts("\t\t\t\t===========================================================");
    puts("\t\t\t\t|-------------                                 -----------|");
    puts("\t\t\t\t|-------------            WEL COME             -----------|");
    puts("\t\t\t\t|-------------               TO                -----------|");
    puts("\t\t\t\t|-------------       LIBRARY MANAGEMENT        -----------|");
    puts("\t\t\t\t|-------------             SYSTEM              -----------|");
    puts("\t\t\t\t===========================================================");

}

void project() {

    //show project name

    puts("\t\t\t\t------------------------------------------------------------------------");
    puts("\t\t\t\t|------------                                              ------------|");
    puts("\t\t\t\t|------------    Library Management System  Project        ------------|");
    puts("\t\t\t\t|------------                                              ------------|");
    puts("\t\t\t\t------------------------------------------------------------------------");

}

void login() {

    //Enter Password and User name Otherwise it will not work , you may change this password

    const char user_name[15] = "Siddhanta@";
    const char password[15] = "Siddhanta@";

    char user[15];
    char pass[15];

    puts("\n\n\t\t\t\t========================================================================");
        puts("\t\t\t\t----------------                 LOGIN                  ----------------");
        puts("\t\t\t\t========================================================================");


    //enter your user name and password

    printf("\n\n\n\t\t\t\tUsername: ");
    scanf("%[^\n]%*c",user);

    printf("\t\t\t\tPassword: ");
    scanf("%[^\n]%*c",pass);

    //check it's correct or not

    if ( strcmp(user,user_name) == 0  && (strcmp(pass , password)) == 0 ) {

        usleep(2000000);
        printf("\n\n\t\t\t\tPress enter to continue.....");
        getch();
        main_menu();
    } else {
        printf("\n\n\t\t\t\tIncorrect Password.Please enter the correct Password.");
        exit(0);
    }
}

int takeIntegerInput() {
    int n;
    while (!scanf("%d",&n)) {
        printf("\n\t\t\t\tPlease Enter a valid integer Input!\n");
        usleep(1000000);
        printf("\t\t\t\tTry Again....\n");
        printf("\n\t\t\t\tEnter your Choice: ");
        //clear buffer input
        while(getchar() != '\n');
    }
    return n;
}

void main_menu() {

    system("cls");

    //display project name

    printf("\n\n");

    project();

    usleep(1000000);

puts("\n\n\t\t\t\t========================================================================");
    puts("\t\t\t\t----------------              MAIN MENU                  ---------------");
    puts("\t\t\t\t========================================================================");

    //enter your choice

    usleep(1000000);

    puts("\n\t\t\t\t1. Add Books");
    puts("\t\t\t\t2. Search Books");
    puts("\t\t\t\t3. View Books");
    puts("\t\t\t\t4. Delete Books");
    puts("\t\t\t\t5. Edit Books");
    puts("\t\t\t\t6. Exit");

    start:
    printf("\n\n\t\t\t\tEnter your choice: ");
    int choice;
    choice = takeIntegerInput();

    system("cls");

    project();


    switch (choice)
    {
    case 1:
        {
            add();
            break;
        }
    case 2:
        {
            search_Book();
            break;
        }
    case 3:
        {
            view();
            break;
        }
    case 6:
        {
            exit(2);
        }
    case 4:
        {
            delete_Book();
            break;
        }
    case 5:
        {
            edit();
            break;
        }
    default:
        {
                printf("\n\t\t\t\tEnter a valid integer between 1 to 6 !....\n");
                usleep(1000000);
                printf("\t\t\t\tPlease Try Again.....");

                main_menu();
        }
    }
}

void add() {

        char ch;

        ptr = fopen("addBookDetails.txt","a+");
        if ( ptr == NULL ) {
            exit(1);
        }

    puts("\n\n\t\t\t\t========================================================================");
        puts("\t\t\t\t----------------            ADD NEW BOOKS                ---------------");
        puts("\t\t\t\t========================================================================");


        //enter your details

    puts("\n\t\t\t\t========================================================================");
        puts("\t\t\t\tEnter Your Details");
        puts("\t\t\t\t========================================================================");


    do {

    printf("\n\t\t\t\tBook ID NO: ");
    scanf("%d",&b.id);

    while(getchar() != '\n');

    printf("\t\t\t\tBook Name: ");
    scanf("%[^\n]%*c",b.bookName);

    printf("\t\t\t\tAuthor Name: ");
    scanf("%[^\n]%*c",b.authorName);

    fflush(stdin);

    printf("\t\t\t\tIssuer Student Name: ");
    scanf("%[^\n]%*c",b.studentName);

    printf("\t\t\t\tDate of Issue: ");
    scanf("%[^\n]%*c",b.date);

    fflush(stdin);

    printf("\t\t\t\tDate of return: ");
    scanf("%[^\n]%*c",b.returnDate);

    fwrite(&b,sizeof(b),1,ptr);

    printf("\n\t\t\t\tDo you want to add another data(y/n): ");
    ch = getchar();

    } while ( ch == 'y' || ch == 'Y');

       usleep(1000000);
       printf("\n\t\t\t\tYour Data is Successfully Saved.");

    fclose(ptr);

    usleep(1000000);

    printf("\n\n\n\t\t\t\tPress Enter to go to Main Menu Page........");
    getch();

    main_menu();
}

void search_Book() {

    system("cls");
    project();

    usleep(2000000);

    puts("\n\n\t\t\t\t========================================================================");
        puts("\t\t\t\t----------------              SEARCH BOOKS               ---------------");
        puts("\t\t\t\t========================================================================");

        int id,f=0;
        struct Book *ptrb;
        ptrb = &b;



        printf("\n\n\t\t\t\tSearch Books by Id: ");
        scanf("%d",&id);

        ptr = fopen("addBookDetails.txt","r");

        while(fread(&b,sizeof(b),1,ptr) == 1)
        {
            if ( id == ptrb->id){
                printf("\n\t\t\t\tBook Name: %s\n",ptrb->bookName);
                printf("\t\t\t\tBook Author Name: %s\n",ptrb->authorName);
                printf("\t\t\t\tIssuer Student Name: %s",ptrb->studentName);
                printf("\n\t\t\t\tDate of Issue: %s",ptrb->date);
                printf("\n\t\t\t\tDate of Return: %s",ptrb->returnDate);
                f++;
            }
        }

          if ( f == 0)
            {
                printf("\n\n\t\t\t\tResult not Found.");
            }
        fclose(ptr);

        usleep(2000000);
        printf("\n\n\n\t\t\t\tPress Enter to continue......");
        getch();

        main_menu();
}

void view() {


     puts("\n\n\t\t\t\t========================================================================");
        puts("\t\t\t\t----------------            VIEW ALL DETAILS              ---------------");
        puts("\t\t\t\t=========================================================================");


        ptr = fopen("addBookDetails.txt","r");

        if( ptr == NULL)
        {
            exit(1);
        }

        while(fread(&b,sizeof(b),1,ptr) == 1)
        {
            printf("\n\n\t\t\t\tBook Id: %d",b.id);
            printf("\n\t\t\t\tBook Name: %s",b.bookName);
            printf("\n\t\t\t\tAuthor Name: %s",b.authorName);
            printf("\n\t\t\t\tIssuer Student Name: %s",b.studentName);
            printf("\n\t\t\t\tDate of Issue: %s",b.date);
            printf("\n\t\t\t\tDate of Return: %s",b.returnDate);
        }


        fclose(ptr);

        usleep(2000000);

        printf("\n\n\t\t\t\tPress enter to continue.....");
        getch();

        main_menu();

}

void delete_Book() {

    int id,f=0;
    struct Book *ptrb;
    ptrb = &b;

     puts("\n\n\t\t\t\t========================================================================");
        puts("\t\t\t\t----------------             DELETE DETAILS               ---------------");
        puts("\t\t\t\t=========================================================================");


        ptr = fopen("addBookDetails.txt","r"); //open existing file
        fp = fopen("temp.dat","w"); //open a temporary file

        if( ptr == NULL)
        {
            exit(1);
        }

        if( fp == NULL)
        {
            exit(1);
        }

        printf("\n\n\t\t\t\tEnter the book Id No: ");
        scanf("%d",&id);  //enter the book id name

        while(fread(&b,sizeof(b),1,ptr) != 0)  //read all content inside file pointer ptr
        {
            if(id == ptrb->id){
                f++;
            } else {
                fwrite(&b,sizeof(b),1,fp);
            }
        }

        (f == 1)?printf("\n\t\t\t\tRecord Deleted Successfully........."):printf("\n\t\t\t\tRecord not found.......");
        fclose(ptr);
        fclose(fp);

        remove("addBookDetails.txt");
        rename("temp.dat","addBookDetails.txt");

         usleep(2000000);

        printf("\n\n\t\t\t\tPress enter to continue.....");
        getch();

        main_menu();

}

void edit() {

      struct Book *ptrb;
      ptrb = &b;
      int id,f=0;

     puts("\n\n\t\t\t\t========================================================================");
        puts("\t\t\t\t----------------               EDIT DETAILS               ---------------");
        puts("\t\t\t\t=========================================================================");

        printf("\n\t\t\t\tEnter Book id Number: ");
        fflush(stdin);
        scanf("%d",&id);


        ptr = fopen("addBookDetails.txt","r"); //open existing file
        fp = fopen("temp.dat","w"); //open a temporary file

        if( ptr == NULL)
        {
            exit(1);
        }

        if( fp == NULL)
        {
            exit(1);
        }

        while(fread(&b,sizeof(b),1,ptr) != 0)
        {
            if ( id != ptrb->id)
            {
                fwrite(&b,sizeof(b),1,fp);
            }
            if ( id == ptrb->id) {

                fflush(stdin);
                f++;

                puts("\n\t\t\t\t========================================================================");
                puts("\t\t\t\tEditing Details");
                puts("\t\t\t\t========================================================================");


                printf("\n\t\t\t\tBook ID NO: ");
                scanf("%d",&b.id);

                while(getchar() != '\n');

                printf("\t\t\t\tBook Name: ");
                scanf("%[^\n]%*c",b.bookName);

                printf("\t\t\t\tAuthor Name: ");
                scanf("%[^\n]%*c",b.authorName);

                fflush(stdin);

                printf("\t\t\t\tIssuer Student Name: ");
                scanf("%[^\n]%*c",b.studentName);

                printf("\t\t\t\tDate of Issue: ");
                scanf("%[^\n]%*c",b.date);

                fflush(stdin);

                printf("\t\t\t\tDate of return: ");
                scanf("%[^\n]%*c",b.returnDate);


                fwrite(&b,sizeof(b),1,fp);

                fclose(ptr);
                fclose(fp);

                remove("addBookDetails.txt");
                rename("temp.dat","addBookDetails.txt");

            }
        }
        usleep(2000000);
        (f==1)?printf("\n\t\t\t\tData is Edited Successfully."):printf("\n\t\t\t\tData is not present.");

        usleep(1000000);

        printf("\n\n\n\t\t\t\tPress Enter to go to Main Menu Page........");
        getch();

        main_menu();

}

