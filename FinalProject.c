#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define GST 0.18

struct node
{
   char name[50];
   char email[50];
   char address[50];
   char feedback[100];
   int contactNumber;
   int NoOfItems;
   int rating;
   float amountToBePaid;
   struct node *next;
} *head = NULL;

struct queueNode
{
   int orderNumber;
   char personName[50];
   struct queueNode *NEXT;
};

struct orderQueue
{
   struct queueNode *front;
   struct queueNode *back;
};
struct orderQueue q;
int ordernumber = 1001;

struct queueNode *createQueueNode(int ordern, char nam[])
{
   struct queueNode *nNode = (struct queueNode *)malloc(sizeof(struct queueNode));
   nNode->orderNumber = ordern;
   strcpy(nNode->personName, nam);
   nNode->NEXT = NULL;
   return nNode;
}

void initiaLiseOrderQueue(struct orderQueue *ptr)
{
   ptr->back = NULL;
   ptr->front = NULL;
}

void pushInOrderQueue(struct orderQueue *ptr, int ordern, char nam[])
{
   struct queueNode *n = createQueueNode(ordern, nam);
   if (ptr->front == NULL && ptr->back == NULL)
   {
      ptr->front = n;
      ptr->back = n;
      return;
   }
   ptr->back->NEXT = n;
   ptr->back = n;
}

int popFromOrderQueue(struct orderQueue *ptr)
{
   if (ptr->front == NULL)
   {
      return 0;
   }
   int x = 0;
   struct queueNode *temp = ptr->front;
   x = temp->orderNumber;
   ptr->front = (ptr->front)->NEXT;
   free(temp);
   return x;
}

void displayOrdersInQueue(struct orderQueue *ptr)
{
   struct queueNode *temp = ptr->front;
   printf("-------------------------------------------\n");
   printf("------------\t       -------------\t\n");
   printf("Order-Number\t       Customer-Name\t\n");
   printf("------------\t       -------------\t\n");
   while (temp != NULL)
   {
   printf("   %d       \t        %s\t\n", temp->orderNumber, temp->personName);
   temp = temp->NEXT;
   }
    printf("-------------------------------------------\n");
}

void menuAndPrices()
{
   printf("------------------------------------------------\n");
   printf("                 ----                       \n");
   printf("                 MENU                       \n");
   printf("                 ----                       \n");
   printf("Item:           \t          Price: \t\n");
   printf("Burger          \t          Rs.50  \t\n");
   printf("Tea             \t          Rs.10  \t\n");
   printf("Noodles         \t          Rs.60  \t\n");
   printf("Coffee          \t          Rs.20  \t\n");
   printf("Soup            \t          Rs.90  \t\n");
   printf("SoftDrink       \t          Rs.50  \t\n");
   printf("Sandwich        \t          Rs.60  \t\n");
   printf("Pastry          \t          Rs.30  \t\n");
   printf("cold coffee     \t          Rs.90  \t\n");
   printf("Pizza           \t          Rs.78  \t\n");
   printf("Latte           \t          Rs.95  \t\n");
   printf("French Fries    \t          Rs.100 \t\n");
   printf("\n");
   printf("------------------------------------------------\n");
}

struct node *returnNameForfeedbackForm(struct node *head, char nameInput[])
{
   struct node *temp = head;
   while (temp != NULL && (strcmp(nameInput, temp->name) != 0))
   {
      temp = temp->next;
   }

   if (!temp)
   {
      return NULL;
   }

   return temp;
}

void feedback()
{
   char feedbackName[30];
   printf("Enter your Name:");
   getchar();
   gets(feedbackName);
   struct node *temp = returnNameForfeedbackForm(head, feedbackName);
   if (temp == NULL)
   {
      printf("Name does not exist in record!\n");
      return;
   }
   int ratings = 0;
feedbackform:
   printf("Press 1 to give one-star rating\n");
   printf("Press 2 to give two-star rating\n");
   printf("Press 3 to give three-star rating\n");
   printf("Press 4 to give four-star rating\n");
   printf("Press 5 to give five-star rating\n");
   printf("Input here->");
   scanf("%d", &ratings);
   if (ratings == 1)
   {
      printf("-------------------------\n");
      printf(" *     ->Very Poor\n");
      temp->rating = 1;
      printf("-------------------------\n");
   }
   else if (ratings == 2)
   {
      printf("-------------------------\n");
      printf(" * *    ->Poor\n");
      temp->rating = 2;
      printf("-------------------------\n");
   }
   else if (ratings == 3)
   {
      printf("-------------------------\n");
      printf(" * * *    ->Average\n");
      temp->rating = 3;
      printf("-------------------------\n");
   }
   else if (ratings == 4)
   {
      printf("-------------------------\n");
      printf(" * * * *    ->Good\n");
      temp->rating = 4;
      printf("-------------------------\n");
   }
   else if (ratings == 5)
   {
      printf("-------------------------\n");
      printf(" * * * * *    ->Awesome\n");
      temp->rating = 5;
      printf("-------------------------\n");
   }
   else
   {
      int key;
      printf("Invalid Input\n");
      printf("1 to give rating again\n");
      printf("Press any other number to return\n");
      printf("Input here->");
      scanf("%d", &key);
      if (key == 1)
      {
         goto feedbackform;
      }
      else
      {
         printf("Thankyou!\n");
         return;
      }
   }
   int wfeedback = 0;
   printf("Press 1 if you want to write feedback.\n");
   printf("Press any other number to return.\n");
   printf("Input here->");
   scanf("%d", &wfeedback);
   if (wfeedback == 1)
   {
      printf("-------------------------------------------------\n");
      printf("Write Here:\n");
      getchar();
      gets(temp->feedback);
      printf("\n");
       printf("-------------------------------------------------\n");
      printf("Thankyou! Your feedback was taken successfully!\n");
      printf("We will work on your complains and improve ourselves for your better experience on your next visit.\n");
      printf("And will maintain our good services  :)\n");
      return;
   }
   else
   {
      return;
   }
}

void viewfeedback(struct node *temp)
{
    printf("-------------------------------------------------\n");
   printf("Rating:");
   if (temp->rating == 1)
   {
      printf(" *     ->Very Poor\n");
   }
   else if (temp->rating == 2)
   {
      printf(" * *    ->Poor\n");
   }
   else if (temp->rating == 3)
   {
      printf(" * * *    ->Average\n");
   }
   else if (temp->rating == 4)
   {
      printf(" * * * *    ->Good\n");
   }
   else if (temp->rating == 5)
   {
      printf(" * * * * *    ->Awesome\n");
   }
   printf("Your Feedback:\n");
   printf("%s\n", temp->feedback);
   printf("-------------------------------------------------\n");
   int k = 0;
   printf("Press 1 to edit feedback\n");
   printf("Press any other number to return\n");
   printf("Input here->");
   scanf("%d", &k);
   if (k == 1)
   {
      feedback();
   }
   else
   {
      return;
   }
}

struct node *CreateNode()
{
    printf("-------------------------------------------------\n");
   char foodName[20];
   struct node *newnode = (struct node *)malloc(sizeof(struct node));
   strcpy(newnode->feedback, "");
   newnode->rating = 0;
   newnode->NoOfItems = 0;
   newnode->amountToBePaid = 0;
   newnode->next = NULL;
   printf("Enter Name:");
   getchar();
   gets(newnode->name);

   pushInOrderQueue(&q, ordernumber, newnode->name);
   ordernumber++;

   printf("Enter Email ID:");
   scanf("%s", newnode->email);
   printf("Enter Contact Number:");
   scanf("%d", &(newnode->contactNumber));
   printf("Enter Address:");
   getchar();
   gets(newnode->address);

here:
   printf("Enter Number of Food items to be purchased:");
   scanf("%d", &(newnode->NoOfItems));

   int x = 0;
   for (int i = 0; i < (newnode->NoOfItems); i++)
   {
      printf("Enter name of food item No. %d :", i + 1);
      scanf("%s", foodName);
      if (!strcmp(foodName, "burger"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 50 + 50 * GST;
      }
      else if (!strcmp(foodName, "tea"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 10 + 10 * GST;
      }
      else if (!strcmp(foodName, "noodles"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 60 + 60 * GST;
      }
      else if (!strcmp(foodName, "coffee"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 20 + 20 * GST;
      }
      else if (!strcmp(foodName, "soup"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 90 + 90 * GST;
      }
      else if (!strcmp(foodName, "softdrink"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 50 + 50 * GST;
      }
      else if (!strcmp(foodName, "sandwich"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 60 + 60 * GST;
      }
      else if (!strcmp(foodName, "pastry"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 30 + 30 * GST;
      }
      else if (!strcmp(foodName, "salads"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 20 + 20 * GST;
      }
      else if (!strcmp(foodName, "coldcoffee"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 90 + 90 * GST;
      }
      else if (!strcmp(foodName, "pizza"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 120 + 120 * GST;
      }
      else if (!strcmp(foodName, "cupcakes"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 78 + 78 * GST;
      }
      else if (!strcmp(foodName, "frenchfries"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 100 + 100 * GST;
      }
      else if (!strcmp(foodName, "latte"))
      {
         newnode->amountToBePaid = newnode->amountToBePaid + 95 + 95 * GST;
      }
      else
      {
         printf("Food Item Not Availaible\n");
         printf("Press any number key to continue Ordering OR Press '0' to EXIT:\n");

         scanf("%d", &x);

         if (x == 0)
         { 
            popFromOrderQueue(&q);
            free(newnode);
            return NULL;
         }
         else
         {
            goto here;
         }
      }
   }
    printf("-------------------------------------------------\n");
   return newnode;
}

void displayNode(struct node *temp)
{
   if (temp == NULL)
   {
      printf("No Details exits\n");
      return;
   }
   printf("--------------------------------------------------\n");
   printf("                    -------                       \n");
   printf("                    Receipt                       \n");
   printf("                    -------                       \n");
   struct tm *ptr;
   time_t t;
   t = time(NULL);
   ptr = localtime(&t);
   printf("Date and Time:%s", asctime(ptr));
   printf("Name of Customer:%s\n", temp->name);
   printf("Email ID:%s\n", temp->email);
   printf("Contact Number:%d\n", temp->contactNumber);
   printf("Address:%s\n", temp->address);
   printf("Number of Food Items purchased:%d\n", temp->NoOfItems);
   printf("Amount to be Paid: Rs.%f\n", temp->amountToBePaid);
   printf("GST-Rate: 18 percent \n");
   printf("--------------------------------------------------\n");
}

void displayList(struct node *head)
{
   if (head == NULL)
   {
      printf("No Details Added yet for today\n");
      return;
   }
   struct node *temp = head;
   while (temp != NULL)
   {
      printf("--------------------------------------------------\n");
      printf("                    -------                       \n");
      printf("                    Receipt                       \n");
      printf("                    -------                       \n");
      struct tm *ptr;
      time_t t;
      t = time(NULL);
      ptr = localtime(&t);
      printf("Date and Time:%s\n", asctime(ptr));
      printf("Name of Customer:%s\n", temp->name);
      printf("Email ID:%s\n", temp->email);
      printf("Contact Number:%d\n", temp->contactNumber);
      printf("Address:%s\n", temp->address);
      printf("Number of Food Items purchased:%d\n", temp->NoOfItems);
      printf("Amount to be Paid: Rs.%f\n", temp->amountToBePaid);
      printf("GST-Rate: 18 percent\n");
      printf("--------------------------------------------------\n");
      temp = temp->next;
   }
}

void searchByName(struct node *head, char nameInput[])
{
   if(head==NULL)
   {
   printf("Record does not exist\n");
   return;
   }

   struct node *temp = head;
   while (temp != NULL && (strcmp(nameInput, temp->name) != 0))
   {
      temp = temp->next;
   }

   if (temp == NULL)
   {
      printf("No Record\n");
   }
   else
   {
      displayNode(temp);
   }
}

void insertNodeAtTail(struct node **head)
{
   struct node *newNode = CreateNode();

   if (*head == NULL)
   {
      *head = newNode;
      return;
   }

   struct node *temp = *head;
   while (temp->next != NULL)
   {
      temp = temp->next;
   }
   temp->next = newNode;
}

void deleteNodeAtHead(struct node **head)
{
   if (*head == NULL)
   {
      return;
   }
   struct node *temp = *head;
   *head = temp->next;
   free(temp);
}

void searchAnddeleteNodeByName(struct node **head, char deleName[])
{
  if(*head==NULL)
   {
   printf("Record does not exist\n");
   return;
   }

   struct node *temp = *head;
   struct node *previous = NULL;

   if (!(strcmp(temp->name, deleName)))
   {
      deleteNodeAtHead(head);
      printf("Deleted Successfully!\n");
      return;
   }

   while (temp != NULL && (strcmp(temp->name, deleName) != 0))
   {
      previous = temp;
      temp = temp->next;
   }

   if (temp == NULL)
   {
      printf("Name-Record doest Not Exist: Try Again\n");
   }
   else
   {
      previous->next = temp->next;
      free(temp);
      printf("Deleted Successfully!\n");
   }
}





int main()
{
   char searchName[20];

   initiaLiseOrderQueue(&q);

   int x = 0, y = 0, n = 0, z = 0;
   printf("--------------------------------------------------------\n");
   printf("|       WELCOME TO RESTAURANT MANAGEMENT SYSTEM!       |\n");
   printf("--------------------------------------------------------\n");
main_menu:
   printf("                    ---------                       \n");
   printf("                    Main-Menu                       \n");
   printf("                    ---------                       \n");
   printf("Press 1 to access Admin Section\n");
   printf("Press 2 to access Customer Section\n");
   printf("Press 3 to display Menu and Prices\n");
   printf("Press 4 to Exit System\n");
   printf("Input Here->");
   scanf("%d", &x);

   if (x == 1)
   {
   admin_menu:
      printf("                    -------------                       \n");
      printf("                    Admin-Section                       \n");
      printf("                    -------------                       \n");
      printf("Press 1 to Add Customer-Order Details\n");
      printf("Press 2 to Search and display Customer-Order Details/Receipt\n");
      printf("Press 3 to Delete Customer-Order Details\n");
      printf("Press 4 to display all Customer-Order Details/Receipts\n");
      printf("Press 5 to display Order-Queue\n");
      printf("Press 6 to remove order from Order-Queue\n");
      printf("Press 7 to go Back to Main-Menu\n");
      printf("Input Here->");
      scanf("%d", &y);
      if (y == 1)
      {
         printf("Enter Number of Customer-Orders to Add:");
         scanf("%d", &n);
         printf("Enter Customer Details:\n");
         int j = 1;
         while (n--)
         {
            printf("-----------------------------\n");
            printf("Enter Details of Customer %d:\n", j);
            printf("-----------------------------\n");
            insertNodeAtTail(&head);
            j++;
         }
         goto admin_menu;
      }
      else if (y == 2)
      {

         printf("Enter Customer Name to Search and display: ");
         getchar();
         gets(searchName);
         searchByName(head, searchName);
         goto admin_menu;
      }
      else if (y == 3)
      {
         printf("Enter Customer Name to Search and delete:");
         getchar();
         gets(searchName);
         searchAnddeleteNodeByName(&head, searchName);
         goto admin_menu;
      }
      else if (y == 4)
      {
         printf("Total-Orders:\n");
         displayList(head);
         goto admin_menu;
      }
      else if (y == 5)
      {
         displayOrdersInQueue(&q);
         goto admin_menu;
      }
      else if (y == 6)
      {
         printf("Order-Number:%d removed successfully from Order-Queue\n", popFromOrderQueue(&q));
         goto admin_menu;
      }
      else if (y == 7)
      {
         goto main_menu;
      }
      else
      {
         printf("Invalid Input: Try again.\n");
         goto admin_menu;
      }
   }
   else if (x == 2)
   {
   customer_menu:
      printf("                    ----------------                       \n");
      printf("                    Customer-Section                       \n");
      printf("                    ----------------                       \n");
      printf("Press 1 to display Menu and Prices\n");
      printf("Press 2 to Order and get your order-receipt\n");
      printf("Press 3 to search your order by Name\n");
      printf("Press 4 to give Feedback\n");
      printf("Press 5 to view or edit your Feedback\n");
      printf("Press 6 to go back to Main-Menu\n");
      printf("Input Here->");
      scanf("%d", &z);
      if (z == 1)
      {
         menuAndPrices();
         goto customer_menu;
      }
      else if (z == 2)
      {
         menuAndPrices();
         printf("Enter Your Details:\n");
         insertNodeAtTail(&head);
         printf("Type Your Name Again:");
         getchar();
         gets(searchName);
         searchByName(head, searchName);
         goto customer_menu;
      }
      else if (z == 3)
      {
         printf("Enter your Name:");
         getchar();
         gets(searchName);
         printf("Details:\n");
         searchByName(head, searchName);
         goto customer_menu;
      }
      else if (z == 4)
      {
         feedback();
         goto customer_menu;
      }
      else if (z == 5)
      {
         printf("Enter your Name:");
         getchar();
         gets(searchName);
         struct node *temp = returnNameForfeedbackForm(head, searchName);
         if (temp == NULL)
         {
            printf("Record doest not exist! Try Again! \n");
            goto customer_menu;
         }
         viewfeedback(temp);
         goto customer_menu;
      }
      else if (z == 6)
      {
         goto main_menu;
      }
      else
      {
         printf("Invalid Input:Try Again.\n");
         goto customer_menu;
      }
   }
   else if (x == 3)
   {
      menuAndPrices();
      goto main_menu;
   }
   else if (x == 4)
   {
      exit;
   }
   else
   {
      printf("Invalid Input:Try again.\n");
      goto main_menu;
   }
   return 0;
}