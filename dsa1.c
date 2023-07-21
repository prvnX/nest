#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node{
int stdtid;
char name[16];
float gpa;
struct node *next;
};
struct node *temp;
int flag,count,countarray,count2;
//function to add student
void addstudent(struct node ** head,struct node * student_data){
if(*head==NULL || student_data->stdtid <= (*head)->stdtid){
    student_data->next=*head;
    *head=student_data;
}
else{
    struct node* ptr=*head;
    while(ptr->next!=NULL && ptr->next->stdtid < student_data->stdtid){
        ptr=ptr->next;
        }
        student_data->next=ptr->next;
        ptr->next=student_data;
}
}
//function to display the list
void display(struct node ** head){
temp=*head;
while(temp!=NULL){
    printf("\tID:%d , Name:%s , GPA : %.2f \n",temp->stdtid,temp->name,temp->gpa);
    temp=temp->next;
    }
}
//function to delete a data from list
int deletestudent(struct node ** head,int deleteid){
if(*head==NULL){
    printf("Can't Delete More,List is Empty\n");
}
temp=*head;
int pos=0;
while(temp!=NULL){
    pos++;
    if(deleteid==temp->stdtid){
        flag=1;
        break;
        }
    temp=temp->next;
    }
if(flag){
    if(pos==1){
        temp=(*head);
        *head=(*head)->next;
        free(temp);
    }
    else{
    temp=*head;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    struct node *delete_node=temp->next;
    temp->next=delete_node->next;
    free(delete_node);
    printf("Status : Successfully Deleted\n");

}}
else{
    printf("Status : Failure,Student Not Found\n");
    flag=0;
    return 0;}

    flag=0;
}
//function to copy list to an array
struct node *listtoarray(struct node **head){
struct node *student_array;
temp=*head;
int i=0;
student_array=malloc(count2 * sizeof(struct node));
while(temp!=NULL){
    student_array[i]=*temp;
    i++;
    temp=temp->next;
    countarray++;
    }
    return student_array;
}

int main(){
struct node *head;
head=NULL;
int choice=1,stdid,deleteid;
char name[16];
float gpa;

while(choice){
        //getting user inputs
    printf("Enter the Data of Student...\n\nEnter the student id : ");
    scanf("%d",&stdid);
    printf("\nEnter the Student name : ");
    scanf("%s",name);
    printf("\nEnter the Student's GPA : ");
    scanf("%f",&gpa);
    struct node *new_student=malloc(sizeof(struct node));
    new_student->stdtid=stdid;
    strncpy(new_student->name,name,15);
    new_student->gpa=gpa;
    new_student->next=NULL;
    addstudent(&head,new_student);
    count++;
    printf("\nDo you want to add another?(1-YES , 0-NO) ");
    scanf("%d",&choice);

}
int check;
printf("List after Adding : \n");
display(&head);
printf("\nDo you want to run delete operations ? (1- YES , 0-NO)");
scanf("%d",&choice);
while(choice && count!=0){
    printf("\nEnter the student id to delete : ");
    scanf("%d",&deleteid);
    check=deletestudent(&head,deleteid);
    if(check!=0){
        printf("List After deletion : \n");
        display(&head);
        count--;
        printf("\n");}
    printf("\nDelete Another? ? (1- YES,0 - No) ");
    scanf("%d",&choice);
}
count2=count;
if(count<=0){
    printf("CAN'T DELETE MORE , ALL THE DATA ARE ALREADY DELETED");
}
choice=0;
printf("\nDo you want to copy  the reaming list to an array ? (YES - 1 ,  NO - 0)");
scanf("%d",&choice);
//printing array
if(choice){
        if(count>0){
                printf("List to Array : \n");
struct node *array=listtoarray(&head);
int i=0;
for(i=0;i<countarray;i++){
        printf("\tArray[%d] -> ID:%d,Name:%s,GPA:%.2f\n",i,array[i].stdtid,array[i].name,array[i].gpa);
    }
}
else{
    printf("Can't copy , List is Empty");
}
}

return 0;
}
