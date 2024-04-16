#include<iostream>
#include<string.h>
#include<graphics.h>
using namespace std;

struct edge
{
    char dest;
    char w;
    struct edge *link;
};

struct co_ord
{
	int x;
	int y;
};

struct node
{
    struct node *next;
    char name;
    struct edge *adj;
    struct co_ord *loc;
    
};
node *start = NULL;

void insert_node(char node_name) // Node insertion
{
    struct node *tmp, *ptr;
    tmp = new (struct node);
    tmp->name = node_name;
    tmp->adj = NULL;
    tmp->next = NULL;

    if (start == NULL)
    {
        start = tmp;
        return;
    }
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = tmp;
}

struct node *find(char item) // Find nodes for creating edges
{
    struct node *ptr, *loc;
    ptr = start;
    while (ptr != NULL)
    {
        if (item == ptr->name)
        {
            loc = ptr;
            return loc;
        }
        else
        {
            ptr = ptr->next;
        }
    }
    loc = NULL;
    return loc;
}

void insert_edge(char u, char v, char weight) // Edge Insertion
{
    struct node *locu, *locv;
    struct edge *ptr, *tmp;

    locu = find(u);
    locv = find(v);

    if (locu == NULL)
    {
        cout << "SOURCE NODE NOT PRESENT.";
        return;
    }
    if (locv == NULL)
    {
        cout << "DESTINATION NODE NOT PRESENT.";
        return;
    }
    tmp = new edge;
    tmp->dest = v;
    tmp->link = NULL;
    tmp->w = weight;

    if (locu->adj == NULL)
    {
        locu->adj = tmp;
        return;
    }

    ptr = locu->adj;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = tmp;
}

void Display()
{
    struct node *ptr;
    struct edge *q;

    ptr = start;
    while (ptr != NULL)
    {
        cout << ptr->name << " --> ";
        q = ptr->adj;
        while (q != NULL)
        {
            cout << q->dest << "-->";
            q = q->link;
        }
        cout << endl;
        ptr = ptr->next;
    }
}

int getXPosition(char nodeName)
{
	struct node *tmp = new node();
	tmp = find(nodeName);
	struct co_ord *c = tmp->loc;
	return c->x;
}

int getYPosition(char nodeName)
{
	struct node *tmp = new node();
	tmp = find(nodeName);
	struct co_ord *c = tmp->loc;
	return c->y;
}

void displayMenu()
{
    cout << "\nMenu:\n";
    cout << "1. Insert Node\n";
    cout << "2. Insert Edge\n";
    cout << "3. Display\n";
    cout << "4. Display Graph\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}
void drawNodesAndEdges() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    struct node* ptr = start;
    int x = 100, y = 100; // Initial coordinates for nodes

    // Draw nodes and labels
    while (ptr != NULL) {
        circle(x, y, 20);
        ptr->loc->x = x;
        ptr->loc->y = y;
        outtextxy(x - 5, y - 7, &ptr->name);

        // Update coordinates for the next node
        x += 150;
        if (x >= getmaxx()) {
            x = 100;
            y += 150;
        }
        ptr = ptr->next;
    }

    // Drawing edges
    ptr = start;
    while (ptr != NULL) {
        struct edge* q = ptr->adj;
        while (q != NULL) {
            int x1 = getXPosition(ptr->name);
            int y1 = getYPosition(ptr->name);
            int x2 = getXPosition(q->dest);
            int y2 = getYPosition(q->dest);
            line(x1, y1, x2, y2);
            outtextxy((x1 + x2) / 2, (y1 + y2) / 2, &q->w);
            q = q->link; // Move to the next edge
        }
        ptr = ptr->next;
    }

    getch();
    delay(10000);
    closegraph();
    return;
}




int main()
{
    int choice;
    char node_name, u, v, w;

    do {
        displayMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter node name to insert: ";
                cin >> node_name;
                insert_node(node_name);
                break;
            case 2:
                cout << "Enter source and destination nodes for the edge: ";
                cin >> u >> v;
                cout<<"Enter edge weight:";
                cin>>w;
                insert_edge(u, v, w);
                break;
            case 3:
                Display();
                break;
            case 4:
                drawNodesAndEdges();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}

