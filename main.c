#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char line[] = "+---------------------------------------------------------------------------------------+"; 
struct Motorbikes {
    char name[25];
    char manufacture[25];
    int release_year;
    float price;
};
struct Motorbikes_List {
    int length;
    struct Motorbikes * mb_list;
};
int printMenuHead();
int processChoice();
void Menu(struct Motorbikes_List * );
struct Motorbikes_List * input_Fn(struct Motorbikes_List * );
void printList(struct Motorbikes_List *);
void appendList(struct Motorbikes_List *, struct Motorbikes_List);
void sortList(struct Motorbikes_List *);
void analyzeList(struct Motorbikes_List *);


//MAIN FUNCTION 
int main() {
    struct Motorbikes_List * mb_og = (struct Motorbikes_List *) malloc(1 * sizeof(struct Motorbikes_List *));
    mb_og->length = 0;
    Menu(mb_og);
    // printf("%d", mb_og->length);
    // for (int i = 0; i < mb_og->length; i++)
    // {
    //     printf("%s", mb_og->mb_list[i].name);
    //     printf("\t");
    // }
    free(mb_og);
    return 0;
}


int printMenuHead(){
    int choice;
    printf(line ,"\n");
    printf("\n|                           MOTORBIKE STORE MANAGEMENT PROGRAM                          |\n");
    printf(line ,"\n");
    printf("\n|           1. Input |2. Sort |3. Analyze |4. Find |5. Save |6. Open |7. Exit           |\n");
    printf(line ,"\n"); 
    printf("\nEnter your choice: ");
    scanf("%d", &choice);
    return choice;
}
int processChoice() {
    int cont = 0;
    char input;
    printf("\nDo you want to continue?\n");
    printf("- Yes, I do. (press 'y' or 'Y')\n");
    printf("- No, I don't. (press 'n' or 'N')\n");
    printf("Please clear the screen. (press 'c' or 'C')\n");

    while (input != 'y' || 'Y' || 'n' || 'N' || 'c' || 'C'){
        scanf("%s", &input);
        if (input == 'y' || input == 'Y') {
            cont = 1;
            return cont;
        } else {
            if (input == 'n' || input == 'N')
            {
                return cont;
            }
            if (input == 'c' || input == 'C')
            {
                system("cls");
                return cont;
            }
            
        }
        printf("Please re-enter input: ");
    }

}
void Menu(struct Motorbikes_List * mb_list) {
    int choice = printMenuHead();
    int running = 1;
    while (running == 1){
        switch (choice)
        {
            case 1:
                printf("You choose 1. Input");
                if (processChoice() == 1) {
                    input_Fn(mb_list);
                };
                choice = printMenuHead();
                break;

            case 2:
                printf("You choose 2. Sort");
                if (processChoice() == 1) {
                    sortList(mb_list);
                };
                choice = printMenuHead();
                
                break;

            case 3:
                printf("You choose 3. Analyze");
                if (processChoice() == 1) {
                    analyzeList(mb_list);

                };
                choice = printMenuHead();
                
                break;

            case 4:
                printf("You choose 4. Find");
                if (processChoice() == 1) {

                };
                choice = printMenuHead();
                
                break;

            case 5:
                printf("You choose 5. Save");
                if (processChoice() == 1) {

                };
                choice = printMenuHead();
                
                break;

            case 6:
                printf("You choose 6. Open");
                if (processChoice() == 1) {

                };
                choice = printMenuHead();
                
                break;

            case 7:
                printf("You choose 7. Exit");
                running = 0;
                break;
            
            default:
                break;
        }

    }



}
struct Motorbikes_List * input_Fn(struct Motorbikes_List * mb_para) {
    int n;
    printf("Enter total number of motorbikes: ");
    scanf("%d", &n);
    struct Motorbikes mb_arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the name of motorbike: ");
        scanf("%s", &mb_arr[i].name);

        printf("Enter the manufacture of motorbike: ");
        scanf("%s", &mb_arr[i].manufacture);

        printf("Enter release year of motorbike: ");
        scanf("%d", &mb_arr[i].release_year);
        while (mb_arr[i].release_year < 1990)
        {
            printf("Motorbike release year must be greater than or equal to 1990.\n");
            printf("Enter release year of motorbike: ");
            scanf("%d", &mb_arr[i].release_year);

        }
        
        printf("Enter the price of motorbike: ");
        scanf("%f", &mb_arr[i].price);
        while (mb_arr[i].price < 500 || mb_arr[i].price > 5000)
        {
            printf("Motorbike price must be between 500($) and 5000($).\n");
            printf("Enter release price of motorbike: ");
            scanf("%f", &mb_arr[i].price);
        }
    }
    // CONCAT NEW LIST TO ORIGIN LIST 
    struct Motorbikes_List mb = {n, mb_arr};
    int new_length = n + mb_para->length;
    struct Motorbikes * mb_arr_res = (struct Motorbikes *) malloc(new_length * sizeof(struct Motorbikes));
    for (int i = 0; i < mb_para->length; i++)
    {
        mb_arr_res[i] = mb_para->mb_list[i];
    }
    for (int i = 0; i < n; i++)
    {
        mb_arr_res[i + mb_para->length] = mb_arr[i];
        
    }
    // struct Motorbikes_List mb_res = {new_length, mb_arr_res};
    
    mb_para->mb_list = mb_arr_res; 
    mb_para->length = new_length;
    return mb_para;
}
void printList(struct Motorbikes_List* mb_para) {
    printf("\n");
    printf("List after sorted is \n");
    for (int i = 0; i < mb_para->length; i++)
    {
        printf("%s", mb_para->mb_list[i].name);
    }
    
}
void sortList(struct Motorbikes_List *mb_para) {
    char s[25];
    for(int i=0;i< mb_para->length;i++){
      for(int j=i+1;j< mb_para->length;j++){
         if(strcmp(mb_para->mb_list[i].name,mb_para->mb_list[j].name)>0){
            strcpy(s,mb_para->mb_list[i].name);
            strcpy(mb_para->mb_list[i].name,mb_para->mb_list[j].name);
            strcpy(mb_para->mb_list[j].name,s);
         }
      }
    }
    printf("%s", line);
    printf("\n|Motorbike Name               |Manufacturer         |Release Year      |Price($)        |\n");
    printf("%s", line);
    printf("\n");
    if (mb_para->length == 0)
    {
        printf("There is no saved motorbike\n");
    } else {
        for (int i = 0; i < mb_para->length; i++)
        {
            printf("|%-29s|%-21s|%-18d|%-16f|\n", mb_para->mb_list[i].name, mb_para->mb_list[i].manufacture,
             mb_para->mb_list[i].release_year, mb_para->mb_list[i].price);
            printf("%s", line);
            printf("\n");

        }
        
    }
    Phong                       |
}
void analyzeList(struct Motorbikes_List * mb_para) {
    //SORT LIST
    char s[25];
    for(int i=0;i< mb_para->length;i++){
      for(int j=i+1;j< mb_para->length;j++){
         if(strcmp(mb_para->mb_list[i].name,mb_para->mb_list[j].name)>0){
            strcpy(s,mb_para->mb_list[i].name);
            strcpy(mb_para->mb_list[i].name,mb_para->mb_list[j].name);
            strcpy(mb_para->mb_list[j].name,s);
         }
      }
    }
    //CREATE ARRAY TO SAVE COUNT
    int res_arr[mb_para->length];
    for (int i = 0; i < mb_para->length; i++)
    {
        res_arr[i] = 0;
    }
    //SAVE COUNT TO ARRAY
    int count = 1;
    for (int i = 0; i < mb_para->length; i++)
    {
        if (strcmp(mb_para->mb_list[i].name, mb_para->mb_list[i + 1].name) == 0)
        {
            count++;
        } else {
            res_arr[i] = count;
            count = 1;
        }
    }
    
    printf("\nStatistic Result");
    for (int i = 0; i < mb_para->length; i++)
    {
        if (res_arr[i] != 0)
        {
            printf("\n+ There are %d motorbike(s) from '%s.'", res_arr[i], mb_para->mb_list[i].name);
        }
        
    }
    printf("\n");
}








