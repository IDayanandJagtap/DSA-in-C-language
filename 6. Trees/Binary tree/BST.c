#include<stdio.h>
#include<stdlib.h>
//Because we are using this following structure in que.h
typedef struct node {
    int data;
    struct node * left;
    struct node * right;
}NODE;


#include"que.h"
#include"btree.h"

void main() {
    NODE * root = NULL;
    NODE* root1 = NULL; 
    int i,n,op, data;


    while(1){
        printf("\n\t1. Create \n\t2. Insert\n\t3. Search\n\t4. Display pre\n\t5. Display inorder\n\t6. Display post\n\t");
        printf("7. Count total nodes \n\t8. Count leaf nodes\n\t9. Count Non leaf nodes\n\t10. Copy tree\n\t11. Mirror tree\n\t");
        printf("12. Level order traversal\n\t13. Delete a node\n\t");
        printf("14. Exit\n\n\t");
        scanf("%d", &op);

        switch(op){
            case 1: 
                printf("\nEnter no of nodes : ");
                scanf("%d", &n);
                for(i=0 ; i<n; i++){
                    printf("Enter %d node data : ", i+1);
                    scanf("%d", &data);
                    root = insert(root, data);
                }
                break;

            case 2 :
                printf("\nEnter the data : ");
                scanf("%d", &data);
                root = insert(root, data);
                break; 

            case 3:
                printf("Enter the data : ");
                scanf("%d", &data);
                if(search(root, data))
                    printf("Data found !\n");
                else 
                    printf("Data not found !\n");
                break;

            case 4: 
                printf("\n");
                preorder(root);
                break;
            case 5 : 
                printf("\n");
                inorder(root);
                break;
            case 6: 
                printf("\n");
                postorder(root);
                break;

            case 7: 
                n = count_tnodes(root);
                printf("Total nodes are : %d\n", n);
                break;
            
            case 8: 
                n = count_leaf(root);
                printf("No of leaf nodes are : %d\n", n);
                break;
            
            case 9 : 
                n = count_non_leaf(root);
                printf("No of non leaf nodes are : %d\n", n);
                break;

            case 10: 
                root1 = copy_tree(root);
                inorder(root1);
                break;

            case 11: 
                mirror_tree(root);
                inorder(root);
                break;

            case 12: 
                if(root){
                    level_order(root);
                }    

            case 13: 
                if(root){
                    printf("Enter the node data to be deleted : ");
                    scanf("%d", &data);
                    deleteNode(root, data);
                    inorder(root);
                }
                break;

            case 14: 
                exit(0);

        }
    }
}