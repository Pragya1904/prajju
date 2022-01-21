#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *link;
};

void print(struct node *head1){
    struct node *temp=head1;
    if(head1==NULL){
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

void inserteleend(int ele, struct node *head1){
    struct node *temp,*temp1=head1;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->data=ele;
    temp->link=NULL;
    if(head1==NULL){
        head1=temp;
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


void concatinate(struct node *head1,struct node *head2){
    
    struct node *temp=head1;

    if(head1==NULL){
        printf("List is empty please insert some elements :)\n\n");
        return;
    }
    
    while(temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=head2;
    return;

}

int main(){
    int choice,ele,pos;
    struct node *head1=NULL;
    struct node *head2=NULL;
    
    while(1){   
        printf("Select what you want to do:\n1.Print 1\n2.Insert in 1\n3.Print 2\n4.Insert in 2\n5.concatinate\n");
        scanf("%d",&choice);
        if(choice==1){
            print(head1);
        }
        else if(choice==2){
            printf("Enter the element you want to insert: ");
            scanf("%d",&ele);
            inserteleend(ele,head1);
        }
        else if(choice==3){
            print(head2);
        }
        else if(choice==4){
            printf("Enter the element you want to insert: ");
            scanf("%d",&ele);
            inserteleend(ele,head2);
        }
        else if(choice==5){
            concatinate(head1,head2);

        }
    }
    return 0;
}