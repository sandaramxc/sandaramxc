#include "../../include/my_typedef.h"

int main()
{
    int temp;
    int len;
    char car_num[20];
    char order[10];
    str_park * park;                           //停车栈指针
    str_park * giveway;                        //让位栈指针
    str_wait * head = NULL;                    //等候头指针
    str_wait * rear = NULL;                    //等候尾指针
    str_wait * temp_wait = NULL;

    park = (str_park *)malloc(sizeof(str_park));
    if(NULL == park)
    {
	    printf("malloc error!");
	    exit(FULL);
    }

    giveway = (str_park *)malloc(sizeof(str_park));
    if(NULL == giveway)
    {
	    printf("malloc error!");
	    exit(FULL);
    }

    init_park(park);                       //初始化停车栈
    init_park(giveway);                    //初始化让位栈

    while(1)
    {
        system("reset");                   
        surface();                         //前往主菜单

        scanf("%s",order);

        if(0 != my_strcmp(order, "PARK"))   //实现停车
        {
            system("reset");
            printf("Please input your car num:\n");
            scanf("%s", car_num);

            temp = car_park(park, car_num);

            if(PARK_FULL != temp)           //如果停满
            {
                printf("\nparking success!\n");
           }
            else
            {
                len = my_strlen(head,rear);
                printf("\nWaiting queue have % d car, whether to wait?(Y/N)\n",len);
                scanf("%s",order);
                if(0 != my_strcmp(order,"Y"))
                {
                    ins_wait(&head, &rear, car_num);  //insert to wait queue
                    printf("\nentered a waiting queue success!\n");
                }
                else
                {
                    continue;
                }
            }
			
            printf("\n\nPlease input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
        else if(0 != my_strcmp(order, "DISPLAY"))      //display function
        {
            system("reset");

            len = my_strlen(head,rear);
            print(park,len);

            printf("\n\nPlease input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
        else if(0 != my_strcmp(order, "GETCAR"))       //leave function
        {
            system("reset");

            len = my_strlen(head,rear);
            print(park,len);              //input the information of park

            temp = leave(park, giveway);

	    if(FAIL == temp)
	    {
	        printf("\ncan't find appoint car!please check your input\n");
                printf("\n\nPlease input anything to return homepage\n");
                scanf("%s",order);
		continue;
	    }

            if(0 != len)                  
            {
                temp_wait = head;

                my_strcpy(car_num, temp_wait->num);
                head = head->next;
                free(temp_wait);

                car_park(park,car_num);
				
                if(1 == len)
                {
                    init_wait(&head, &rear);
                }
            }

            printf("\n\nPlease input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
        else if(0 != my_strcmp(order, "QUIT"))             //quit function
        {
            system("reset");
            exit(1);
        }
        else
        {
            system("reset");
            printf("input error!Please input anything to return homepage\n");
            scanf("%s",order);
            continue;
        }
    }

    return 0;
}
