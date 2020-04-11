#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};


class A
{
    public:
        node* insert(node* root, int val)
        {
            if(root == NULL)
            {
                root = new node();
                root->data = val;
                root->left = NULL;
                root->right = NULL;
            }

            else if(val <= root->data)
                root->left = insert(root->left,val);
            else
                root->right = insert(root->right,val);
            return root;
        }


        int searching(node* root, int val)
        {
            if(root==NULL)
                return 0;
            else if(val == root->data)
                return 1;
            else if(val < root->data)
                return searching(root->left,val);
            else if(val > root->data)
                return searching(root->right,val);
        }


        node* largest_node(node* root)
        {
            if(root == NULL || root->right == NULL)
                return root;
            else
                return largest_node(root->right);
        }

        node* delete_node(node* root,int val)
        {
            node* temp = new node();
            if(root == NULL)
            {
                cout<<"Value not Found!"<<endl;
                return root;
            }
            else if(val < root->data)
                root->left = delete_node(root->left,val);
            else if(val > root->data)
                root->right = delete_node(root->right,val);

            else if(root->left && root->right)                  //case in which node has two child
            {
                temp = largest_node(root->left);
                root->data = temp->data;
                delete_node(root->left,temp->data);
            }

            else                                                //case in which node has one or no child
            {
                if(root->left == NULL && root->right == NULL)   //no child
                    root = NULL;
                else if(root->left != NULL)                     //either left child
                    root->left = NULL;
                else                                            //or right child only
                    root->right = NULL;

                delete temp;
            }
            return root;
        }

        void Preorder(node* root)
        {
            if(root == NULL)
                return;
            cout<<root->data<<endl;
            Preorder(root->left);
            Preorder(root->right);
        }

        void Inorder(node* root)
        {
            if(root == NULL)
                return;
            Inorder(root->left);
            cout<<root->data<<endl;
            Inorder(root->right);
        }

        void Postorder(node* root)
        {
            if(root == NULL)
                return;
            Postorder(root->left);
            Postorder(root->right);
            cout<<root->data<<endl;
        }

        int getHeight(node* node)
        {
            if (node == NULL)
                return 0;
            else
            {
                /* compute the depth of each subtree */
                int lDepth = getHeight(node->left);
                int rDepth = getHeight(node->right);

                /* use the larger one */
                if (lDepth > rDepth)
                    return(lDepth + 1);
                else
                    return(rDepth + 1);
            }
        }

};


int main()
{
    A obj;
    int val;
    node* root = NULL;
    cout<<endl<<"----------------# Tree  Menu #------------------"<<endl;
    cout<<endl<<"1. Insert"<<endl<<"2. Search"<<endl<<"3. Delete"<<endl<<"4. Display"<<endl<<"5. Height"<<endl<<"6. Exit"<<endl<<endl;
    int ch;
    cin>>ch;
    do{
    switch(ch)
    {
        case 1:
        {
            cout<<"Enter Data:"<<endl;
            cin>>val;
            root = obj.insert(root,val);
            break;
        }

        case 2:
        {
            int search_val;
            cout<<endl<<"Enter Value to Serach in Tree: "<<endl;
            cin>>search_val;

            int search_flag = obj.searching(root,search_val);
            if(search_flag == 1)
                cout<<endl<<search_val<<" is present in Tree!"<<endl;
            else
                cout<<endl<<search_val<<" is not present in Tree!"<<endl;
            break;
        }
        case 3:
        {
            cout<<endl<<"Enter Value to be Deleted: "<<endl;
            int del_val;
            cin>>del_val;
            root = obj.delete_node(root,del_val);
            break;
        }
        case 4:
        {
            cout<<endl<<"Content of Tree: "<<endl;
            cout<<endl<<"--------------# Pre-Order #--------------"<<endl;
            obj.Preorder(root);
            cout<<endl<<"--------------# In-Order #--------------"<<endl;
            obj.Inorder(root);
            cout<<endl<<"--------------# Post-Order #--------------"<<endl;
            obj.Postorder(root);
            /*int ch_disp;
            cout<<endl<<"1. Preorder"<<endl<<"2. Inorder"<<endl<<"3. Postorder"<<endl;
            cin>>ch_disp;
            if(ch_disp == 1)
            {
                cout<<endl<<"--------------# Pre-Order #--------------"<<endl;
                obj.Preorder(root);
            }

            else if(ch_disp == 2)
            {
                cout<<endl<<"--------------# In-Order #--------------"<<endl;
                obj.Inorder(root);
            }
            else if(ch_disp == 3)
            {
                cout<<endl<<"--------------# Post-Order #--------------"<<endl;
                obj.Postorder(root);
            }
            else
                cout<<endl<<"Invalid Option!"<<endl;
            break;*/
        }

        case 5:
        {
            cout << "Height of tree is " << obj.getHeight(root);
        }


    }
    cout<<endl<<"1. Insert"<<endl<<"2. Search"<<endl<<"3. Delete"<<endl<<"4. Display"<<endl<<"5. Height"<<endl<<"6. Exit"<<endl;
    cin>>ch;


}while(ch!=6);
}