#include<iostream>
using namespace std;
typedef struct node Node;
struct node{
    int data;
    struct node* next;
};
struct List{
    Node* head;
    Node* tail;
};


void CreatList(List&ls){
    ls.head=ls.tail=NULL;
}



Node* CreatNode(int value){
    Node* p=new Node;
    if(p==NULL){
        cout<<"Khong du bo nho cap phap"<<endl;
        return NULL;
    }
    p->data=value;
    p->next=NULL;
    return p;
}



void AddHead(List&ls,int value){
    Node*p=CreatNode(value);
    if(ls.head==NULL){
        ls.head=ls.tail=p;
    }
    else{
        p->next=ls.head;
        ls.head=p;
    }
}




void AddTail(List&ls,int value){
    Node*p=CreatNode(value);
    if(ls.head==NULL){
        ls.head=ls.tail=p;
    }
    else{
        ls.tail->next=p;
        ls.tail=p;
    }
}




void AddAt(List&ls,int pos,int value){
    if(pos==0||ls.head==NULL) AddHead(ls,value);
    else{
        int k=1;
        Node*temp=ls.head;
        while(temp!=NULL&&k!=pos){
            k++;
            temp=temp->next;
        }
        if(k!=pos){
            cout<<"The added position is invalid"<<endl;
        }
        else{
            Node*p=CreatNode(value);
            p->next=temp->next;
            temp->next=p;
        }
    }
}



void DeleteHead(List&ls){
    if(!ls.head){
        cout<<"Empty list!"<<endl;
    }
    else{
        ls.head=ls.head->next;
    }
}



void DeleteTail(List&ls){
     if(ls.head==NULL||ls.head->next==NULL){
        DeleteHead(ls);
    }
    else{
        Node*temp=ls.head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next=temp->next->next;
    }
}


void DeleteAt(List&ls,int pos){
    if(pos==0||ls.head==NULL||ls.head->next==NULL){
        DeleteHead(ls);
    }
    else{
        int k=1;
        Node*p=ls.head;
        while(p->next->next!=NULL&&k!=pos){
            p=p->next;
            k++;
        }
        if(k!=pos){
            cout<<"The added position is invalid"<<endl;
        }
        else{
            p->next=p->next->next;
        }
    }
}

int Length(List&ls){
    int size=0;
    for(Node*k=ls.head;k!=NULL;k=k->next){
        ++size;
    }
    return size;
}

void GetAt(List&ls,int index){
    if(index<0||index>Length(ls)-1) {
        cout<<"index error"<<endl;
        return;
    }
    int k=0;
    Node*p=ls.head;
    while(p->next!=NULL&&k!=index){
        k++;
        p=p->next;
    }
    cout<<"Value at location "<<index<<":"<<p->data<<endl;
}



void PrintList(List ls){
    for(Node*k=ls.head;k!=NULL;k=k->next){
        cout<<k->data<<" ";
    }
    cout<<endl;
}
int main(){
    List ls;
    CreatList(ls);
    AddHead(ls,1);
    AddHead(ls,2);
    AddHead(ls,3);
    AddTail(ls,4);
    AddTail(ls,5);
    AddTail(ls,6);
    PrintList(ls);
    DeleteHead(ls);
    DeleteTail(ls);
    PrintList(ls);
    AddAt(ls,0,5);
    PrintList(ls);
    GetAt(ls,3);
    DeleteAt(ls,3);
    PrintList(ls);

}
