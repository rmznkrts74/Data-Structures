struct nodeFB
{
	int id;
	int age;
	struct nodeFB *next;
};

struct nodeGS
{
	int id;
	struct nodeGS *next;
};

struct newNodeFB
{
	int id;
	int age;
	struct newNodeGS *next;
};

struct newNodeGS
{
	int id;
	struct newNodeFB *next;
};
void insertFB(struct nodeFB **FBs,int order,int data){
	struct nodeFB *onHand,*temp,*last;
	onHand = (struct nodeFB *)malloc(sizeof(struct nodeFB));
	onHand->id = order;
	onHand->age = data;
	onHand->next = NULL;
	if(*FBs != NULL){
		int i = 0;
		temp = *FBs;
		while (1)
		{
			if(onHand->id > temp->id){
				last = temp;
				if(temp->next == NULL){
					temp->next = onHand;
					break;
				}
				else{
					temp = temp->next;
				}
			}
			else{
				if(i == 0){
					*FBs = onHand;
					onHand->next = temp;
					break;
				}
				else{
					onHand->next = last->next;
					last->next = onHand;
					break;
				}
			}
			i++;
		}
	}
	else if(*FBs == NULL){
		*FBs = onHand;
		last = onHand;
	}
};
void insertGS(struct nodeGS **GS,int order){	
	struct nodeGS *onHand,*temp,*last;
	onHand = (struct nodeGS *)malloc(sizeof(struct nodeGS));
	onHand->id = order;
	onHand->next = NULL;
	if(*GS != NULL){
		int i = 0;
		temp = *GS;
		while (1)
		{
			if(onHand->id < temp->id){
				last = temp;
				if(temp->next == NULL){
					temp->next = onHand;
					break;
				}
				else{
					temp = temp->next;
				}
				
			}
			else{
				if(i == 0){
					*GS = onHand;
					onHand->next = temp;
					break;
				}
				else{
					onHand->next = last->next;
					last->next = onHand;
					break;
				}
			}
			i++;
		}
	}
	else if(*GS == NULL){
		*GS = onHand;
		last = onHand;
	}
};
void printFB(struct nodeFB *FBs){
	while(FBs != NULL){
		printf("Id:%d Age:%d\n",FBs->id,FBs->age);
		FBs = FBs->next;
	}
	printf("\n");
};
void printGS(struct nodeGS *GS){
	while(GS != NULL){
		printf("Id:%d\n",GS->id);
		GS = GS->next;
	}
	printf("\n");
};
void createFinalList(struct newNodeFB **newFB,struct nodeFB *FB,struct nodeGS *GS){
	int i = 0;
	struct newNodeGS *last;
	while(GS != NULL){
		struct newNodeFB *onHandFB;
		struct newNodeGS *onHandGS;
		onHandFB = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
		onHandGS = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
		if(i == 0){
			*newFB = onHandFB;
		}
		onHandFB->age = FB->age;
		onHandFB->id = FB->id;
		onHandGS->id = GS->id;
		onHandFB->next = onHandGS;
		onHandGS->next = NULL;
		if(i != 0){
			last->next = onHandFB;
		}
		last = onHandGS;
		FB = FB->next;
		GS = GS->next;
		i++;
	}
};
void printAll(struct newNodeFB *newFB){
	struct newNodeGS *GS = NULL;
	int i = 0;
	while(i<20){
		if(i%2 == 0){
			printf("Id:%d Age:%d\n",newFB->id,newFB->age);
			GS = newFB->next;
		}
		else{
			printf("Id:%d\n",GS->id);
			newFB = GS->next;
		}
		i++;
	}
};
// You must write all the function definitions to be used in this lab into this file. 
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



