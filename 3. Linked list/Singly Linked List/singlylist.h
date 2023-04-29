// Creating structure : 

typedef struct NODE {
	int data; 
	struct NODE* next;
}NODE;

NODE *head;



// FUNCTION TO DISPLAY LL :
void display(struct NODE * head){
	NODE *temp ; 
	temp = head ; 
	
	printf("Data elements : ");
	while(temp!=NULL){
	
		printf("\t%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
}


// FUNCTION TO CREATE LINKED LIST: 
struct NODE * createLL(int n){
	NODE * newNode , *head, *temp;
	head = NULL;
	int i,d;
	
	for(i=0; i<n; i++){
		newNode = (struct NODE *)malloc (sizeof(struct NODE));
		printf("Enter the %d data element : ", i+1);
		scanf("%d", &d);
		newNode->data= d;
		newNode->next = NULL;
		
		if(head == NULL){
			head = newNode;
			temp = newNode ;
		}
		else{
			temp->next = newNode;
			temp = newNode;
		}	
	}
	
	  
	return head;
}



// FUNCTION APPEND ELEMENT IN LL : 
void append(struct NODE * head, int data){
	NODE *temp, *prev , *newNode; 
	temp = head ; 
	
	while(temp!=NULL){
		prev = temp;
		temp = temp->next;
	}
	newNode = (struct NODE *)malloc(sizeof(struct NODE));
	newNode->data = data;
	newNode->next = NULL;
	prev->next = newNode;
		
}


// FUNCTION TO INSERT IN LL :
void insert(struct NODE *headptr , int pos, int data){
	NODE *temp, *newNode;
	temp = headptr;
	int i=1;
	
	newNode = (struct NODE *)malloc(sizeof(struct NODE ));
	newNode->data = data;
	
	if(pos==1){
		newNode->next = head;
		headptr=head = newNode;
	}else{
		while(i<(pos-1) && temp!=NULL ){
			temp = temp->next;
			i++;
		}
		
		if(temp){
			newNode->next = temp->next;
			temp->next = newNode;
		}
	
	}
	
}

// FUNCTION TO SEARCH ELEMENT : 
int search(struct NODE *head, int data){
	NODE *temp ; 
	temp = head;
	int i=1;
	
	while(temp && (temp->data!=data)){
		temp = temp->next;
		i++;
	}
	if(temp = NULL){
		
		return -1;
	}
	else{
		return i;
	}
	
}

// FUNCTION TO DELETE ELEMENT BY DATA : 
int deleteByData(struct NODE *headptr, int data){
	NODE *temp, *prev;
	temp = headptr;
	int i,d, pos;
	
	pos = search(head,data);
	if(pos==-1){
		printf("Invalid data !");
	}
	else if(pos==1){
		head = headptr = headptr->next;
	}
	else{
		for(i=1;i<pos;i++){
			prev = temp;
			temp= temp->next;
		}
		prev->next = temp->next;
		d = temp->data;
	}
	
	free(temp);
	return d;
}


// FUNCTION TO DELETE DATA BY POSITION :
int deleteByPos(struct NODE *headptr, int pos){
	NODE *temp, *prev;
	temp = headptr;
	int i,d; 
	if(pos==1){
		d = headptr->data;
		head = headptr = headptr->next;
	}
	else{
		for(i=1;i<pos;i++){
			prev = temp;
			temp= temp->next;
		}
		prev->next = temp->next;
		d = temp->data;
	}
	
	free(temp);
	return d;
}


// Function to reverse LL 

NODE * reverseLL(){
    NODE *prev , *curr ; 
    if(head!=NULL){
        //assign first two node as prev and curr
        prev = head ;              
        head = head->next ;
        curr = head;

        // Make 1st element the last element
        prev->next = NULL;

        while(head!=NULL){          // Traverse till end
            head = head->next;     // Increment head pointer to next NODE 
            curr->next = prev;

            prev = curr;            // Move pointers to next Node
            curr= head;
        }
        
        head = prev;                    // Make last node as head
    }
        return head;
}

