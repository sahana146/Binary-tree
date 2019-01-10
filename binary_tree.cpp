/*implementation of binary tree */

#include<iostream>
#include<cstdlib>
#include<queue>

using namespace std;

//structure of a node
struct node
{
     int data;
     struct node *left;
     struct node *right;
};


typedef struct node* Node;
queue<Node>  q;                            // declaring a queue

//Insertion
Node insert(Node *root,int value)
{

Node curr=*root;
                 //creating new node and initializing it

Node newnode=(Node)malloc(sizeof(struct node));                         
newnode->data=value;
newnode->left=NULL;
newnode->right=NULL;             
    if(q.empty() && curr==NULL)          // if the tree is empty
    {
                       curr=newnode;
                       q.push(newnode);
                       return curr;
    }
   
    while(!q.empty())      //searching for first empty position in level order traversal
    {
             struct node *front=q.front();

                   if(front->left==NULL)
                   {       
                       front->left=newnode;
                       q.push(front->left);
                       break;
                   }
                   else if(front->right==NULL)
                   {
                        front->right=newnode;
                        q.push(front->right);
                        break;
                   }
         q.pop();               

     }

return curr;
}



//Deletion
void del(Node root,Node end)
{

q.push(root);

 while(!q.empty())                                       //find the last node and delete it
 {

     struct node *front=q.front();
                   

                   if(front->left!=NULL)
                   {       
                       if(front->left==end)
                         { front->left=NULL;free(end); return; }
                       else
                        q.push(front->left);                      
                   }
                   if(front->right!=NULL)
                   {
                        
                       if(front->right==end)
                       {front->right=NULL;free(end);return;}
                       else
                        q.push(front->right); 
                        
                   }
                   
                   
         q.pop();      

 }

}


void deletenode(Node root,int value)
{
    int val;
    Node key=NULL;
    Node rightmost;
    Node front;

    if(q.empty())
    {cout<<"-----The tree is empty-----\n"; return;}
 
    q.push(root);
    
    while(!q.empty())                                    //find the key node(the node to delete)
    {
           front=q.front();
                   
                   if(front->data==value)
                        {key=front;}
                   if(front->left!=NULL)
                        {
                              q.push(front->left);

                        }
                   if(front->right!=NULL)
                        {
                               q.push(front->right);
                        }
                                
         q.pop();               

    }

   if(key==NULL)                                                  //if the key node is not found
   { 
       cout<<"No such element exists\n";
       return;
   }

  rightmost=front; //the last front value is the last node
//if the key node is found swap the data with the last node
   
   val=rightmost->data;
   key->data=val;
   del(root,rightmost);
   
}



//Display ---- inorder traversal
void inorder(struct node *root)
{
       if(root!=NULL)
      {
               inorder(root->left);
               cout<<root->data<<" ";
               inorder(root->right);  

      }
   
   cout<<"\n";
}



int main()                                  //main function
{


int option,value;
struct node *root=NULL;
while(1)
{
  cout<<"Choose one of the options(Enter the corresponding number):\n";
  cout<<"1. Insert\n2. Delete\n3. Display\n4. Exit\n";
  cin>>option;
  if(option==1)
  {    
         cout<<"Enter the value to be inserted\n"; 
         cin>>value; 
         root=insert(&root,value);
  }
  else if(option==2)
  {    
         cout<<"Enter the value to be deleted\n";  
         cin>>value;
         deletenode(root,value);
  }
  else if(option==3)
  {
          cout<<"Inorder traversal:\n";
          if(root==NULL)
           cout<<"-----The tree is empty-----\n";
          else
          inorder(root);

  }
  else
       break;
  
 }


return 0;

}
