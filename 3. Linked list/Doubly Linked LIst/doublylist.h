typedef struct NODE{
	int  data ; 
	struct NODE * prev;
	struct NODE * next;
}NODE;

NODE * head=NULL;


// FUNCTION TO CREATE DOUBLY LIST : 
struct NODE * createLL(int n){
	NODE * newNode , *temp;
	head = NULL;
	int i,d;
	
	for(i=0; i<n; i++){
		newNode = (struct NODE *)malloc (sizeof(struct NODE));
		printf("Enter the %d data element : ", i+1);
		scanf("%d", &d);
		newNode->data= d;
		newNode->prev = NULL;
		newNode->next = NULL;
		
		if(head == NULL){
			head = newNode;
			temp = newNode ;
		}
		else{
			newNode->prev = temp;
			temp->next = newNode;
			temp = newNode;
		}	
	}
	
	  
	return head;
}

// FUNCTION TO DISPLAY DL : 
void display(struct NODE * h){
	NODE *temp ; 
	temp = h ; 
	
	printf("Data elements : ");
	while(temp!=NULL){
	
		printf("\t%d", temp->data);
		temp = temp->next;
	}
	printf("\n");
	
}


// FUNCTION TO APPEND DATA TO DL : 
void append(struct NODE * h, int data){
	NODE *temp, *prev , *newNode; 
	temp = h ; 
	
	while(temp!=NULL){
		prev = temp;
		temp = temp->next;
	}
	newNode = (struct NODE *)malloc(sizeof(struct NODE));
	newNode->data = data;
	newNode->next = NULL;
	newNode->prev = prev;
	prev->next = newNode;
		
}

// FUNCTION TO SEARCH DATA IN DL : 
int search(struct NODE *h, int data){
	NODE *temp ; 
	temp = h;
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

// INSERTION FUNCTION IN DL: 
struct NODE * insert(struct NODE *headptr , int pos, int data){
	NODE *prev, *next, *newNode;
	next = headptr;
	newNode = (struct NODE * )malloc (sizeof(struct NODE ));
	newNode->data = data ; 
	newNode->prev = newNode->next = NULL;
	int i=1;
	
	if(pos ==1 ){
		newNode->next = next;
		newNode->prev = NULL;
		next->prev = newNode;
		head = headptr = newNode;
	}
	else{
		while(i<(pos) && next){
			prev = next;
			next = next->next;
			i++;
		}
		
		if(next){
			newNode->next = prev->next;
			newNode->prev = next->prev;
			prev->next = next->prev = newNode;
		}
	}
	
	return head;
} 


// FUNCTION TO DELETE ELEMENT BY DATA : 
int deleteByData(struct NODE *headptr, int data){
	NODE *temp;
	temp = headptr;
	int i,d, pos;
	
	pos = search(headptr,data);
	if(pos==-1){
		printf("Invalid data !");
	}
	else if(pos==1){
		head = headptr = headptr->next;
		headptr->prev = NULL;
	}
	else{
		for(i=1;i<pos;i++){
			
			temp= temp->next;
		}
		if(temp){
			(temp->prev)->next =  temp->next;
			if(temp->next != NULL){
				(temp->next)->prev = temp->prev;
			}
			d = temp->data;
		}
	}
	
	free(temp);
	return d;
}

// FUNCTION TO DELETE DATA BY POSITION :
int deleteByPos(struct NODE *headptr, int pos){
	NODE *temp, *prev;
	temp = headptr;
	int i,d; 
	if(pos==-1){
		printf("Invalid data !");
	}
	else if(pos==1){
		head = headptr = headptr->next;
		headptr->prev = NULL;
	}
	else{
		for(i=1;i<pos;i++){
			
			temp= temp->next;
		}
		if(temp){
			(temp->prev)->next =  temp->next;
			if(temp->next != NULL){
				(temp->next)->prev = temp->prev;
			}
			d = temp->data;
		}
	}
	
	free(temp);
	return d;
}

// FUNCTION TO REVERSE DL : // This is not a reverse function it just traverses the DL in reverse order.
void reverse(struct NODE * h){
	NODE *temp ; 
	temp = h ; 
	
	printf("Data elements : ");
	while(temp->next!=NULL){
		temp = temp->next;
	}
	while(temp!=NULL){
		printf("\t%d", temp->data);
		temp = temp->prev;
	}
	printf("\n");
	
}

