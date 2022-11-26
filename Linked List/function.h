
struct nodeFB *addFB = NULL;
struct nodeGS *addGS = NULL;
struct nodeFB *FB = NULL;
struct nodeGS *GS = NULL;
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

void insertFB(struct nodeFB **startFB, int id, int age)
{
    addFB = (struct nodeFB *)malloc(sizeof(struct nodeFB));
    addFB->id = id;
    addFB->age = age;
    addFB->next = NULL;
    struct nodeFB *current;
    int change, i;
    struct nodeFB *ptr1;
    struct nodeFB *lptr = NULL;
    if (*startFB == NULL)
    {
        addFB->next = *startFB;
        *startFB = addFB;
    }
    else
    {
        current = *startFB;
        while (current->next != NULL && current->next->id < addFB->id)
        {
            current = current->next;
        }
        addFB->next = current->next;
        current->next = addFB;
    }
    if (startFB == NULL)
    {
        return;
    }
    else
    {
        do
        {
            change = 0;
            ptr1 = *startFB;
            while (ptr1->next != lptr)
            {
                if (ptr1->id > ptr1->next->id)
                {
                    int memo = ptr1->id;
                    int agge = ptr1->age;
                    ptr1->id = ptr1->next->id;
                    ptr1->age = ptr1->next->age;
                    ptr1->next->id = memo;
                    ptr1->next->age = agge;
                    change = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (change);
    }
}
void printFB(struct nodeFB *startFB)
{
    addFB = startFB;
    while (addFB->next != NULL)
    {
        printf("%d %d ", addFB->id, addFB->age);
        addFB = addFB->next;
        printf("\n");
    }
    printf("%d %d ", addFB->id, addFB->age);
    printf("\n");
}

void insertGS(struct nodeGS **startGS, int id)
{
    addGS = (struct nodeGS *)malloc(sizeof(struct nodeGS));
    addGS->id = id;
    addGS->next = NULL;
    struct nodeGS *current;
    int change, i;
    struct nodeGS *ptr1;
    struct nodeGS *lptr = NULL;
    if (*startGS == NULL)
    {
        addGS->next = *startGS;
        *startGS = addGS;
    }
    else
    {
        current = *startGS;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = addGS;
    }
    if (startGS == NULL)
    {
        return;
    }
    else
    {
        do
        {
            change = 0;
            ptr1 = *startGS;
            while (ptr1->next != lptr)
            {
                if (ptr1->id < ptr1->next->id)
                {
                    int memo = ptr1->id;
                    ptr1->id = ptr1->next->id;
                    ptr1->next->id = memo;
                    change = 1;
                }
                ptr1 = ptr1->next;
            }
            lptr = ptr1;
        } while (change);
    }
}
void printGS(struct nodeGS *startGS)
{
    addGS = startGS;

    while (addGS->next != NULL)
    {
        printf("\n%d", addGS->id);
        addGS = addGS->next;
    }
    printf("\n%d", addGS->id);
    printf("\n");
}

void createFinalList(struct newNodeFB **startNewFB, struct nodeFB *startFB, struct nodeGS *startGS)
{
    int x = 0;
    struct newNodeGS *final;
    while (startGS != NULL)
    {
        struct newNodeFB *newFB;
        struct newNodeGS *newGS;
        newFB = (struct newNodeFB *)malloc(sizeof(struct newNodeFB));
        newGS = (struct newNodeGS *)malloc(sizeof(struct newNodeGS));
        if (x == 0)
        {

                *startNewFB = newFB;
        }
        newFB->age = startFB->age;
        newFB->id = startFB->id;
        newGS->id = startGS->id;
        newFB->next = newGS;
        newGS->next = NULL;
        if (x != 0)
        {
            final->next = newFB;
        }
        final = newGS;
        startFB = startFB->next;
        startGS = startGS->next;
        x++;
    }
};
void printAll(struct newNodeFB *startNewFB)
{
    printf("\n");
    struct newNodeGS *Gs = NULL;
    int i = 0;
    while (startNewFB != NULL)
    {
        if (i % 2 == 0)
        {
            printf("%d %d\n", startNewFB->id, startNewFB->age);
            Gs = startNewFB->next;
        }
        else
        {
            printf("%d\n", Gs->id);
            startNewFB = Gs->next;
        }
        i++;
    }
};
