/*************************************************
  Function:       ins_wait
  Description:    insert a car to wait queue
  Calls:          my_strcpy
  Called By:      main
  Input:          head: the head pointer of stoping stack
                  rear: the rear pointer of stoping stack
  Output:         
  Return:         SUCCESS: insert success
*************************************************/
#include "../../include/my_typedef.h"

int ins_wait(str_wait **head, str_wait **rear, char * car_num)
{
    str_wait * temp;
    str_wait * newcar;

    newcar = (str_wait *)malloc(sizeof(str_wait));      
    newcar->next = NULL;

    if(NULL == newcar)                                
    {
        printf("malloc error!\n");
    }
    my_strcpy(newcar->num,car_num);

    if((NULL == *head)&&(NULL == *rear))             
    {
		
        *rear = newcar;
        *head = newcar;


        return SUCCESS;
    }

    temp = *rear;                                            
    temp->next = newcar;
    *rear = newcar;
}
