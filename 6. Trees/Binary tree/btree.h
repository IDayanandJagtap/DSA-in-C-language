



// Create and insert into Binary search tree

NODE * insert(NODE *root, int data){
    NODE* temp, *temp1, *newNode;

    newNode = (NODE *) malloc (sizeof(NODE));
    newNode->data = data;
    newNode->left = newNode->right = NULL;

    if(root == NULL){
        root = newNode;
    }
    else{
        temp = root;
        while(temp){
            temp1 = temp;
            if(data < temp->data)
                temp = temp->left;
            else 
                temp = temp->right;
        }

        if(data < temp1->data)
            temp1->left = newNode;
        else 
            temp1->right = newNode;
    }

    return root;
}



// Tree traversal :
// Preorder 
void preorder(NODE * root){
    if(root){
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
// Inorder
void inorder(NODE * root){
    if(root){
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
// PostOrder
void postorder(NODE * root){
    if(root){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}



// Search 
int search(NODE * root, int data){
    NODE *temp;
    temp = root; 

    while(temp){
        if(data == temp->data)
            return 1;
        if(data < temp->data)
            temp = temp->left;
        else 
            temp = temp->right;
    }

    return 0;
}

// Count total nodes :
int count_tnodes(NODE *root){
    if(root)
        return (1 + count_tnodes(root->left) + count_tnodes(root->right));
    
    return 0;
}


// Count leaf nodes : 
int count_leaf(NODE * root){
    if (!root)
        return 0;
    if(root->right == NULL && root->left == NULL)
        return 1;

    return count_leaf(root->left) + count_leaf(root->right);
}

// Count non-leaf nodes : 
int count_non_leaf(NODE *root){
    if(!root || root->right == NULL && root->left == NULL)
        return 0;
    
    return (1 + count_non_leaf(root->left) + count_non_leaf(root->right));
}


// Copy tree to new tree 
NODE * copy_tree(NODE *root){
    NODE *newNode=NULL;
    if(root){
        newNode = (NODE *) malloc(sizeof(NODE));
        newNode->data = root->data;
        newNode->left = copy_tree(root->left);
        newNode->right = copy_tree(root->right);
    }

    return newNode;
}

// Mirror tree : 
NODE * mirror_tree(NODE *root){
    NODE *temp ;
    if(root){
        temp = root->left;
        root->left = mirror_tree(root->right);
        root->right = mirror_tree(temp);
    }
    return root;
}


void level_order(NODE * root){
    if (!root)
        return ;

    queue * rear = NULL ;

    rear = enqueue(rear , root);

    while(!isQueueEmpty(rear)){

        int size = getSize(rear);
        
        for(int i=0 ; i<size ; i++){
            NODE * temp  = dequeue(rear);
            printf("%d\t", temp->data);

            if(temp->left != NULL)
                rear = enqueue(rear, temp->left);
            if(temp->right !=NULL)
                rear = enqueue(rear, temp->right);
        }
        printf("\n");
    }
}
// void level_order(NODE * root){
//     if (!root)
//         return ;

//     queue * rear = NULL ;

//     rear = enqueue(rear , root);

//     while(!isQueueEmpty(rear)){
//         NODE * temp  = dequeue(rear);
//         printf("%d\t", temp->data);
    

//         if(temp->left != NULL)
//             rear = enqueue(rear, temp->left);
//         if(temp->right !=NULL)
//             rear = enqueue(rear, temp->right);

//     }
// }


// Delete a node from BST : 
// We can either use inorder predecessor or inorder successor : 
// For that we need a function to find the inorder predecessor: (rightmost node of the left subtree of the give node)
NODE * inOrderPredecessor(NODE * root){
    if(root){
        root = root->left;
        while(root->right != NULL)
            root = root->right ;
        return root;
    }
}

NODE * deleteNode (NODE * root, int data){
    NODE * inPre;  
    if(!root) return NULL;

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if(data < root->data)
        root->left = deleteNode(root->left, data);
    else if(data > root->data)
        root->right = deleteNode(root->right, data);

    else{
        inPre = inOrderPredecessor(root);
        root->data = inPre->data;
        root->left = deleteNode(root->left, inPre->data);
    }

    return root;
    
}