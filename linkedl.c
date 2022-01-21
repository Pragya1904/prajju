#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *link;
};

struct node *head=NULL;


struct node *reverseList(struct node *head)
    {
        struct node *cur=head,*prev=NULL,*next=NULL;
        
        while(cur!=NULL){
            next=cur->link;
            cur->link=prev;
            prev=cur;
            cur=next;
        }
        head=prev;
        return head;
    }
    
    
void print(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty please insert some elements :)\n\n");
        return;
    }
    while(temp->link!=NULL){
        printf(" %d ", temp->data);
        temp=temp->link;
    }
    printf(" %d \n", temp->data);
    return;
}


int countnodes(){
    struct node *temp=head;
    int count=0;
    if(head==NULL){
        printf("List is empty please insert some elements :)\n\n");
        return 0;
    }
    while(temp!=NULL){
        count++;
        temp=temp->link;
    }
    return count;
}



void insertelebeg(int ele){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
        printf("First element inserted :)\n\n");
        return;
    }
    temp->link=head;
    head=temp;
    printf("Element inserted at beginning :)\n\n");
    return;
}

void inserteleend(int ele){
    struct node *temp,*temp1=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
        printf("First element inserted :)\n\n");
        return;
    }
    while(temp1->link!=NULL){
        temp1=temp1->link;
    }
    temp1->link=temp;
    printf("Element inserted in end :)\n\n");
    return;
}

void insertafterpos(int ele,int pos){
    struct node *temp,*temp1=head;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->link=NULL;
    if(head==NULL){
        head=temp;
        printf("First element inserted :)\n\n");
        return;
    }
    while(--pos){
        temp1=temp1->link;
    }
    temp->link=temp1->link;
    temp1->link=temp;
    printf("Inserted after %d \n\n",pos);
    return;

}

void deletebeg(){
    struct node *temp=head;
    if (head==NULL){
        printf("List is empty\n");
        return;
    }
    head=head->link;
    printf("Element deleted\n");
    free(temp);
    return;
}

void deleteend(){
    struct node *temp=head,*temp1;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    while(temp->link!=NULL){
        temp1=temp;
        temp=temp->link;
    }
    temp1->link=NULL;
    free(temp);
    return;
}

int search(int ele){
    
    int pos=1;
    struct node *temp=head;
    
    if(head==NULL)
    {
        printf("List is empty please insert some elements :)\n\n");
        return -1;
    }

    while(temp!=NULL){
        if(temp->data==ele){
            return pos;
        }
        temp=temp->link;
        pos++;
    }
    return -1;
}

void deleteafternpos(int n){
    struct node *temp=head,*temp1=NULL;
    if(head==NULL)
    {
        printf("List is empty please insert some elements :)\n\n");
        return;
    }
    while(--n){
        temp=temp->link;
    }
    temp1=temp->link;
    temp->link=temp1->link;
    free(temp1);
    return;
}

void deleteatinfo(int ele){
    struct node *temp=head;
    int pos;
    if(head==NULL)
    {
        printf("List is empty please insert some elements :)\n\n");
        return;
    }

    pos=search(ele);

    if(pos!=-1)
    {
        if(pos==1){
            deletebeg();
        }
        else{
            deleteafternpos(pos-1);
        }
    }
    return;
    
}

void swap(struct node *temp, struct node *temp1, int j){
    temp->link=temp1->link;
    temp1->link=temp;
    if(j==0){
        head=temp;
    }
}


void bubbleSort()
{
    int i, j, n=countnodes();
    struct node *temp=head,*temp1=NULL;
    for(i = 0; i < n-1; i++) 
        {
            for (j = 0; j < n-i-1; j++) 
           {
               temp1=temp->link;
               if(temp->data>temp1->data){
                   swap(temp,temp1,j);
               }
               temp=temp->link;
           }
           temp=head;
        }
}

int main(){
    int choice,ele,pos;
    
    while(1){   
        printf("Select what you want to do:\n1.Print\n2.Insert at beginning\n3.Insert in end\n4.Insert after pos\n5.Reverse the list\n6.Search\n");
        scanf("%d",&choice);
        if(choice==1){
            print();
        }
        else if(choice==2){
            printf("Enter the element you want to insert at beginning: ");
            scanf("%d",&ele);
            insertelebeg(ele);
        }
        else if(choice==3){
            printf("Enter the element you want to insert in end: ");
            scanf("%d",&ele);
            inserteleend(ele);
        }
        else if(choice==4){
            printf("Enter the position after which you want to insert: ");
            scanf("%d",&pos);
            printf("Enter the element you want to insert at position %d: ",pos);
            scanf("%d",&ele);
            insertafterpos(ele,pos);
        }
        else if(choice==5){
            head=reverseList(head);
        }
        else if(choice==6){
            printf("Enter the element to be searched= ");
            scanf("%d",&ele);
            printf("pos= %d\n",search(ele));
        }
        else if(choice==7){
            printf("sorting the list...\n");
            bubbleSort();
            print();
        }
        else if(choice==8){
            
        }
        
    }
    return 0;
}