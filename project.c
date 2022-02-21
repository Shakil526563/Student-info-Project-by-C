#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct node
{
    char bookName[40];
    char booktype[50];
    char bookid[30];
    char bookAuthor[50];
    double  bookprice;
    struct node *next;
};
struct node *head;
void addbook()
{
    getchar();
    printf("######## Add Book Data########\n");
    struct node *temp=(struct node*) malloc (sizeof(struct node));
    printf("Book Name");
    gets(temp->bookName);
    printf("Book Type");
    gets(temp->booktype);
    printf("Book Id");
    gets(temp->bookid);
    printf("Book Author");
    gets(temp->bookAuthor);
    printf("Book Pricce");
    scanf("%lf",&temp->bookprice);
    temp->next=head;
    head=temp;

    return 0;



}
void display()
{
    struct node *temp=head;
    printf("\n######## All book ############\n");

    while(temp!=NULL)
    {
        printf("Book Name: %s\n",temp->bookName);
        printf("Book Type:%s\n",temp->booktype);
        printf("Book Id: %s\n",temp->bookid);
        printf("Book Author :%s\n",temp->bookAuthor);
        printf("Book Pricce %.2lf\n",temp->bookprice);
        temp = temp->next;


    }
    return;
}
void search()
{
    char booki[77];
    int found=0;
    struct node *temp=head;
    getchar();

    printf("Book Id ");
    gets(booki);
    while(temp!=NULL)
    {
        if(strcmp(temp->bookid,booki)==0)
        {
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==1)
    {
        printf("Book Name: %s\n",temp->bookName);
        printf("Book Type:%s\n",temp->booktype);
        printf("Book Id: %s\n",temp->bookid);
        printf("Book Author :%s\n",temp->bookAuthor);
        printf("Book Pricce %.2lf\n",temp->bookprice);


    }
    else
        printf("no data  with id %s! \n",booki);
    return ;
}
void update()
{
    char booki[77];
    int found=0;
    struct node *temp=head;
    getchar();
    printf("\n######## updare ############\n");

    printf("Book Id ");
    gets(booki);
    while(temp!=NULL)
    {
        if(strcmp(temp->bookid,booki)==0)
        {
            found=1;
            break;
        }
        temp=temp->next;
    }
    if(found==1)
    {
        printf("Old data \n");
        printf("Book Name: %s\n",temp->bookName);
        printf("Book Type:%s\n",temp->booktype);
        printf("Book Author :%s\n",temp->bookAuthor);
        printf("Book Pricce %.2lf\n",temp->bookprice);

        printf("_________________\n");
        printf("new data\n");

        printf("Book Name");
        gets(temp->bookName);
        printf("Book Type");
        gets(temp->booktype);
        printf("Book Author");
        gets(temp->bookAuthor);
        printf("Book Pricce");
        scanf("%lf",&temp->bookprice);

        printf("Data Update \n");
    }
    else
        printf("no data found with id %s! \n",booki);
    return ;
}

void removedata()
{

    char booki[77];
    int found=0;
    struct node *temp=head,*pretemp;
    getchar();
    printf("\n######## Remove a book  ############\n");

    printf("Book Id ");
    gets(booki);
    if(strcmp(temp->bookid,booki)==0)
    {

        head=temp->next;
        free(temp);
        return;
    }
    while(temp!=NULL)
    {
        if(strcmp(temp->bookid,booki)==0)
        {
            found=1;
            break;
        }
        pretemp=temp;
        temp=temp->next;
    }
    if(found==1)
    {
        pretemp->next = temp->next;
        free(temp);

        printf("Data Update \n");
    }


}
int main()
{
    int n;
    head=NULL;
    while(1)
    {

        printf("\n######## Main Menu############\n");
        printf("################################\n");
        printf("######## 1. Add Books ##########\n");
        printf("######## 2. Search a book  ######\n");
        printf("########3. Display all books ####\n");
        printf("######## 4. Remove a book #######\n");
        printf("######## 5. update a book data ##\n");
        printf("######## 6. Exit  ###############\n");
        printf("################################\n");


        printf("Reply: ");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            addbook();
            break;
        case 2:
            search();
            break;

        case 3:
            display();

            break;

        case 4:
            removedata();


            break ;

        case 5:
            update();

            break ;

        case 6:

            return 0;
            break ;

        default:
            printf("INvalid input");
            break;
        }
    }

    return 0;
}
