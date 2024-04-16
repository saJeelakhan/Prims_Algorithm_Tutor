#include<iostream>
#include<fstream>
#include<graphics.h>
#include<string.h>

using namespace std;

const int numRows = 3;
const int numColumns = 11;

void psuedocode()
{
	setcolor(GREEN);
	outtextxy(200, 350, "PSEUDO CODE:");
    outtextxy(200, 370, "do key[u] = infinity");
    outtextxy(350, 370, "Pred[u] = NIL");
    outtextxy(200, 390, "Q = V[G]");
    outtextxy(350, 390, "While Q is not empty");
    outtextxy(200, 410, "do u = EXTRACT-MIN(Q)");
    outtextxy(370, 410, " For each v belongs to Adj[u]");
    outtextxy(200, 430, " do if v belongs to Q and w( u ,v ) < key[v]");
    outtextxy(200, 450, "then Pred[v] = u");
    outtextxy(350, 450, "key[v] = w(u, v)");
    setcolor(WHITE);
    return;
		
	
}

void printst(int x, int y, char* array, int index, int total_elements, int level) //MST
{
	    if (index >= total_elements)
	    return;
	
	    char str[2] = {array[index], '\0'}; // Creating a null-terminated string
	
	    setcolor(LIGHTGRAY); // Change node color to LIGHTGRAY
	
	    int left = 2 * index + 1;
	    int right = 2 * index + 2;
	
	    // Adjusting the line width for initial edges
	     setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
		 if (left < total_elements)
	    {
	        // Exclude edges from A to B, B to D, and E to J
	        if (!((index == 0 && left == 1) || (index == 1 && left == 3) || (index == 4 && left == 9)))
	        {
	            line(x, y, x - level * 20, y + 50);
	        }
	    }
		setcolor(LIGHTGRAY);
	     if (right < total_elements)
	    {
	        if (!(index == 0 && right == 2))
	        {
	            line(x, y, x + level * 20, y + 50);
	        }
	    }
		
	    if (left < 2) 
		{
	        line(x, y - 5, x + 15, y + 100); // Adjust starting Y to move the line upward
	    }
	    
	    if (left < 2) 
		{
	        line(x - 73 , y + 50, x + 80, y + 50); // Adjust starting Y to move the line upward
	    }
	
	    if (left < 3) 
		{
	        line(x-50, y + 150, x + 135, y + 110); // Adjust Y positions for a vertically shifted line
	    }
	
	    if (left < 3) 
	   {
	        line(x-180, y + 150, x -20, y + 100); // Adjust Y positions for a vertically shifted line
	    }
	
	    circle(x, y, 15);
	    floodfill(x, y, BLACK);
	    setcolor(YELLOW);
	    outtextxy(x - 5, y - 7, str);
	
	     // Change edge color to RED
	    setlinestyle(SOLID_LINE, 0, THICK_WIDTH); // Increase edge line width
		setcolor(RED);
	
	    printst(x - level * 20, y + 50,
	              array, left, total_elements, level - 1);
	
	    printst(x + level * 20, y + 50,
	              array, right, total_elements, level - 1);
	     // Change the color of the weight text to red
	        setcolor(WHITE);
	        outtextxy(650, 50, "MINIMUM SPANNING TREE");
	    return;
	}


void printTree(int x, int y, char* array, int index, int total_elements, int level)
{
    if (index >= total_elements)
    return;

    char str[2] = {array[index], '\0'}; // Creating a null-terminated string

    setcolor(LIGHTGRAY); // Change node color to LIGHTGRAY

    int left = 2 * index + 1;
    int right = 2 * index + 2;

    // Adjusting the line width for initial edges
     setlinestyle(SOLID_LINE, 0, THICK_WIDTH);

    if (left < total_elements) {
        line(x, y, x - level * 20, y + 50);
    }
    
    if (right < total_elements) {
        line(x, y, x + level * 20, y + 50);
    }

    if (left < 2) {
        line(x, y - 5, x + 15, y + 100); // Adjust starting Y to move the line upward
    }
    
    if (left < 2) {
        line(x - 73 , y + 50, x + 80, y + 50); // Adjust starting Y to move the line upward
    }

    if (left < 3) {
        line(x-50, y + 150, x + 135, y + 110); // Adjust Y positions for a vertically shifted line
    }

    if (left < 3) {
        line(x-180, y + 150, x -20, y + 100); // Adjust Y positions for a vertically shifted line
    }

    circle(x, y, 18);
    floodfill(x, y, LIGHTGRAY);

    setcolor(LIGHTGREEN); // Change text color to GREEN
    outtextxy(x - 5, y - 7, str);

    setcolor(RED); // Change edge color to RED
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH); // Increase edge line width

    printTree(x - level * 20, y + 50,
              array, left, total_elements, level - 1);

    printTree(x + level * 20, y + 50,
              array, right, total_elements, level - 1);
    setcolor(YELLOW);
     // Change the color of the weight text to red

        // Displaying edge weights at a specific position
        outtextxy(165, 155, "12");
        outtextxy(250, 100, "5");
        outtextxy(400, 220, "6");
        outtextxy(320, 130, "3");
        outtextxy(250, 160, "6");
        outtextxy(200, 205, "2");
        outtextxy(260, 225, "8");
        outtextxy(135, 209, "3");
        outtextxy(340, 100, "10");
        outtextxy(344, 185, "4");
        outtextxy(400, 151, "5");
        outtextxy(275, 128, "2");//B-C
        outtextxy(178, 205, "9");
        
        setcolor(WHITE);
        outtextxy(200, 50, "UNDIRECTED WEIGHTED GRAPH");
    return;
}

void drawTable(int x, int y, int cellWidth, int cellHeight, char tableContent[numRows][numColumns][20])
{
   // Draw the table structure
    for (int i = 0; i <= numRows; ++i)
	{
        line(x, y + i * cellHeight, x + numColumns * cellWidth, y + i * cellHeight);
    }
    for (int i = 0; i <= numColumns; ++i)
	{
        line(x + i * cellWidth, y, x + i * cellWidth, y + numRows * cellHeight);
    }

    // Add text in cells
    for (int i = 0; i < numRows; ++i) {
        for (int j = 0; j < numColumns; ++j) {
            outtextxy(x + j * cellWidth + 10, y + i * cellHeight + 10, tableContent[i][j]);
        }
    }
    return;
}

void drawTreeAndTable()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
    
    int windowHeight = 750;
    int windowWidth = 1000;
    initwindow(windowWidth, windowHeight);

    int tableWidth = windowWidth / 2;
    int tableHeight = windowHeight;

    int graphX = tableWidth;
    int graphY = 0;
    int graphWidth = windowWidth / 2;
    int graphHeight = windowHeight;

    int cellWidth = 50;
    int cellHeight = 30;

    char tableContent1[numRows][numColumns][20];
    char tableContent2[numRows][numColumns][20];
    
    char array[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', '\0'};
    printTree(300, 100,  array, 0, 10, 4);
    psuedocode();

    int tableX1 = 50;
    int tableY1 = 50;
    int tableX2 = 50;
    int tableY2 = 250;

    // Initialize the first table with initial values
			strcpy(tableContent1[0][0], "Q");
			strcpy(tableContent1[0][1], "A");
			strcpy(tableContent1[0][2], "B");
			strcpy(tableContent1[0][3], "C");
			strcpy(tableContent1[0][4], "D");
			strcpy(tableContent1[0][5], "E");
			strcpy(tableContent1[0][6], "F");
			strcpy(tableContent1[0][7], "G");
			strcpy(tableContent1[0][8], "H");
			strcpy(tableContent1[0][9], "I");
			strcpy(tableContent1[0][10], "J");
			
			strcpy(tableContent1[1][0], "KEY");
			strcpy(tableContent1[1][1], "inf");
			strcpy(tableContent1[1][2], "inf");
			strcpy(tableContent1[1][3], "inf");
			strcpy(tableContent1[1][4], "inf");
			strcpy(tableContent1[1][5], "inf");
			strcpy(tableContent1[1][6], "inf");
			strcpy(tableContent1[1][7], "inf");
			strcpy(tableContent1[1][8], "inf");
			strcpy(tableContent1[1][9], "inf");
			strcpy(tableContent1[1][10], "inf");
			
			strcpy(tableContent1[2][0], "P");
			strcpy(tableContent1[2][1], "nil");
			strcpy(tableContent1[2][2], "nil");
			strcpy(tableContent1[2][3], "nil");
			strcpy(tableContent1[2][4], "nil");
			strcpy(tableContent1[2][5], "nil");
			strcpy(tableContent1[2][6], "nil");
			strcpy(tableContent1[2][7], "nil");
			strcpy(tableContent1[2][8], "nil");
			strcpy(tableContent1[2][9], "nil");
			strcpy(tableContent1[2][10], "nil");

    // Initialize the second table with initial values

			strcpy(tableContent2[0][0], "Q");
			strcpy(tableContent2[0][1], "A");
			strcpy(tableContent2[0][2], "B");
			strcpy(tableContent2[0][3], "C");
			strcpy(tableContent2[0][4], "D");
			strcpy(tableContent2[0][5], "E");
			strcpy(tableContent2[0][6], "F");
			strcpy(tableContent2[0][7], "G");
			strcpy(tableContent2[0][8], "H");
			strcpy(tableContent2[0][9], "I");
			strcpy(tableContent2[0][10], "J");
			
			strcpy(tableContent2[1][0], "A");
			strcpy(tableContent2[1][1], "");
			strcpy(tableContent2[1][2], "");
			strcpy(tableContent2[1][3], "");
			strcpy(tableContent2[1][4], "");
			strcpy(tableContent2[1][5], "");
			strcpy(tableContent2[1][6], "");
			strcpy(tableContent2[1][7], "");
			strcpy(tableContent2[1][8], "");
			strcpy(tableContent2[1][9], "");
			strcpy(tableContent2[1][10], "");
			
			strcpy(tableContent2[2][0], "");
			strcpy(tableContent2[2][1], "");
			strcpy(tableContent2[2][2], "");
			strcpy(tableContent2[2][3], "");
			strcpy(tableContent2[2][4], "");
			strcpy(tableContent2[2][5], "");
			strcpy(tableContent2[2][6], "");
			strcpy(tableContent2[2][7], "");
			strcpy(tableContent2[2][8], "");
			strcpy(tableContent2[2][9], "");
			strcpy(tableContent2[2][10], "");

    drawTable(200, 500, cellWidth, cellHeight, tableContent1);

    // Draw the second table with initial values
    drawTable(200, 630, cellWidth, cellHeight, tableContent2);

    // Your tree drawing code here...
    
    char key;
    while (true)
	{
        if (kbhit())
		{
            key = getch();
            if (key == '1')
			{
				strcpy(tableContent1[1][1], "0");
            }
            else if (key == '2')
			{
				strcpy(tableContent1[1][2], "5");
				strcpy(tableContent1[2][2], "A");
				strcpy(tableContent1[1][3], "10");
				strcpy(tableContent1[2][3], "A");
				strcpy(tableContent1[1][6], "3");
				strcpy(tableContent1[2][6], "A");
		
				strcpy(tableContent2[1][1], "A");
				strcpy(tableContent2[0][1], "");
			}
            else if (key == '3')
            {
            	strcpy(tableContent1[1][3], "4");
				strcpy(tableContent1[2][3], "F");
				
				strcpy(tableContent2[1][2], "F");
				strcpy(tableContent2[0][6], "");
			}
			else if(key == '4')
			{
				strcpy(tableContent1[1][2], "2");
				strcpy(tableContent1[2][2], "C");
				strcpy(tableContent1[1][7], "5");
				strcpy(tableContent1[2][7], "C");
				
				strcpy(tableContent2[1][3], "C");
				strcpy(tableContent2[0][3], "");	
			}
			else if(key == '5')
			{
				strcpy(tableContent1[1][4], "12");
				strcpy(tableContent1[2][4], "B");
				strcpy(tableContent1[1][5], "6");
				strcpy(tableContent1[2][5], "B");
				
				strcpy(tableContent2[1][4], "B");
				strcpy(tableContent2[0][2], "");
			}
			else if (key == '6')
			{
				strcpy(tableContent1[1][10], "6");
				strcpy(tableContent1[2][10], "G");
				
				strcpy(tableContent2[1][5], "G");
				strcpy(tableContent2[0][7], "");
			}
			else if (key == '7')
			{
				strcpy(tableContent1[1][8], "2");
				strcpy(tableContent1[2][8], "E");
				
				strcpy(tableContent2[1][6], "E");
				strcpy(tableContent2[0][5], "");	
			}
			else if(key == '8')
			{
				strcpy(tableContent1[1][4], "3");
				strcpy(tableContent1[2][4], "H");
				
				
				strcpy(tableContent2[1][7], "H");
				strcpy(tableContent2[0][8], "");	
			}
			else if(key == '9')
			{
				strcpy(tableContent1[1][9], "9");
				strcpy(tableContent1[2][9], "D");
				
				strcpy(tableContent2[1][8], "D");
				strcpy(tableContent2[0][4], "");
			}
			else if(key == '0')
			{
				strcpy(tableContent2[1][9], "J");
				strcpy(tableContent2[0][10], "");
			}
			else if (key == 'e'|| key == 'E')
			{
				cleardevice();
	            psuedocode();
	            printTree(300, 100,  array, 0, 10, 4);
	            printst(700, 100,  array, 0, 10, 4);
	            drawTable(200, 500, cellWidth, cellHeight, tableContent1);
	    		drawTable(200, 630, cellWidth, cellHeight, tableContent2);
				break;
			}
			else
			{
				strcpy(tableContent2[1][10], "I");
				strcpy(tableContent2[0][9],"");
			}
    
            // Clear the screen and redraw both tables with updated values
            cleardevice();
            psuedocode();
            printTree(300, 100,  array, 0, 10, 4);
            drawTable(200, 500, cellWidth, cellHeight, tableContent1);
        	drawTable(200, 630, cellWidth, cellHeight, tableContent2);
        }
    }
    getch();
    closegraph();
	return;	
}

void showmenu() //main menu function
{
	string str;
    ifstream in;
    in.open("Menu.txt");                     
    while(getline(in, str))
	{ 
        cout << str << "\n"; 
    }
    in.close();
    return;
}

void q1() //Basic concepts
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("q1.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    return;
    
}

void q2()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("q2.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    char key;
    cout<<endl<<"Press C to move to psuedo code"<<endl;
    cin>>key;
    if(key == 'C'|| key == 'c')
    {
    	drawTreeAndTable();
    	return;
	}
	
}

void q3() //psuedo code and the visual representation
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("q3.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    char key;
    cout<<endl<<"Press C for visual representation"<<endl;
    cin>>key;
    if(key == 'C'|| key == 'c')
    {
    	drawTreeAndTable();
    	return;
	}
}
void q4()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("Time.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    
}
void q5()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("q4.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    
}

void q6()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("q6.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    
}

void q7()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("q7.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();
    
}

void q8()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("code.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();  
}

void q9()
{
	system("CLS");
	string str;
	ifstream in1;
    in1.open("RAM.txt");                     
    while(getline(in1, str))
	{ 
        cout << str << "\n"; 
    }
    in1.close();  
}

void runQuiz() 
{
    int score = 0;

    // Question 1
    cout << "\nQuestion 1: What does Prim's algorithm find?\n";
    cout << "a) Shortest Path\n";
    cout << "b) Minimum Spanning Tree\n";
    cout << "c) Maximum Flow\n";
    char answer1;
    cin >> answer1;
    if (answer1 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 2
    cout << "\nQuestion 2: How does Prim's algorithm select the next edge?\n";
    cout << "a) Randomly\n";
    cout << "b) Maximum Weight\n";
    cout << "c) Minimum Weight\n";
    char answer2;
    cin >> answer2;
    if (answer2 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 3
    cout << "\nQuestion 3: What type of graph does Prim's algorithm work on?\n";
    cout << "a) Directed Graph\n";
    cout << "b) Weighted Graph\n";
    cout << "c) Connected Graph\n";
    char answer3;
    cin >> answer3;
    if (answer3 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 4
    cout << "\nQuestion 4: What is the time complexity of Prim's algorithm?\n";
    cout << "a) O(V^2)\n";
    cout << "b) O(E log V)\n";
    cout << "c) O(V log V)\n";
    char answer4;
    cin >> answer4;
    if (answer4 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 5
    cout << "\nQuestion 5: In Prim's algorithm, what is updated during each iteration?\n";
    cout << "a) Node colors\n";
    cout << "b) Edge weights\n";
    cout << "c) Distance labels\n";
    char answer5;
    cin >> answer5;
    if (answer5 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 6
    cout << "\nQuestion 6: Which data structure is typically used for the priority queue in Prim's algorithm?\n";
    cout << "a) Array\n";
    cout << "b) Linked List\n";
    cout << "c) Binary Heap\n";
    char answer6;
    cin >> answer6;
    if (answer6 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 7
    cout << "\nQuestion 7: What happens if the input graph is not connected in Prim's algorithm?\n";
    cout << "a) The algorithm fails\n";
    cout << "b) It still works, but may not find a spanning tree\n";
    cout << "c) It always finds a spanning tree\n";
    char answer7;
    cin >> answer7;
    if (answer7 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 8
    cout << "\nQuestion 8: In Prim's algorithm, what is the role of the 'pred' field in the node structure?\n";
    cout << "a) Node color\n";
    cout << "b) Predecessor in the spanning tree\n";
    cout << "c) Priority in the queue\n";
    char answer8;
    cin >> answer8;
    if (answer8 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 9
    cout << "\nQuestion 9: Which of the following is a greedy strategy used by Prim's algorithm?\n";
    cout << "a) Choosing the largest edge first\n";
    cout << "b) Choosing the smallest edge first\n";
    cout << "c) Choosing a random edge\n";
    char answer9;
    cin >> answer9;
    if (answer9 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }

    // Question 10
    cout << "\nQuestion 10: What is the main application of Prim's algorithm?\n";
    cout << "a) Shortest Path\n";
    cout << "b) Minimum Spanning Tree\n";
    cout << "c) Maximum Flow\n";
    char answer10;
    cin >> answer10;
    if (answer10 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 11
    cout << "\nQuestion 11: Graphs are fundamental mathematical structures used to model relationships between what?\n";
    cout << "a) Objects\n";
    cout << "b) Numbers\n";
    cout << "c) Tables\n";
    char answer11;
    cin >> answer11;
    if (answer11 == 'a') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 12
    cout << "\nQuestion 12: A graph consist of\n";
    cout << "a) Edges\n";
    cout << "b) Nodes\n";
    cout << "c) Nodes, Edges\n";
    char answer12;
    cin >> answer12;
    if (answer12 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 13
    cout << "\nQuestion 13: An undirected graph is a graph where connections between nodes have:\n";
    cout << "a) Specific direction\n";
    cout << "b) NO specific direction\n";
    cout << "c) None\n";
    char answer13;
    cin >> answer13;
    if (answer13 == 'b') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 14
    cout << "\nQuestion 14: A Weighted graph has a value or number to each of its edges.\n";
    cout << "a) True\n";
    cout << "b) False\n";
    char answer14;
    cin >> answer14;
    if (answer14 == 'a') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 15
    cout << "\nQuestion 15: A subgraph T of a undirected graph G = ( V, E ) is a spanning tree of G if:\n";
    cout << "a) It is a tree\n";
    cout << "b) It contains every vertex of G\n";
    cout << "c) Both\n";
    char answer15;
    cin >> answer15;
    if (answer15 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 16
    cout << "\nQuestion 16: Minimum Spanning Tree (MST) in an ---------- is a spanning tree of minimum weight.\n";
    cout << "a) It is an undirected graph\n";
    cout << "b) It is an undirected weighted graph\n";
    cout << "c) It is a connected graph\n";
    char answer16;
    cin >> answer16;
    if (answer16 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    //Question 17
    cout << "\nQuestion 17: Which mathematician first developed Prim's algorithm?\n";
    cout << "a) Robert C. Prim\n";
    cout << "b) Vojtech Jarnik\n";
    cout << "c) E. W. Dijkstra\n";
    char answer17;
    cin >> answer17;
    if (answer17 == 'c') 
	{
        cout << "Correct!\n";
        score++;
    } 
	else 
	{
        cout << "Incorrect.\n";
    }
    
    // Display the final score
    cout << "\nQuiz Completed!\n";
    cout << "Your Score: " << score << " out of 10\n";
}

int main()
{
	char con_choice;
	do
	{
		showmenu();
		int choice;
		cout<<endl<<"Enter Your Choice "<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
			{
				q1(); //basic concepts
				break;
			}
			case 2:
			{
				q2(); //introduction
				break;
			}
			case 3:
			{
				q3(); //Pseudo code
				break;
			}
			case 4:
			{
				q4(); //Time complexity
				break;
			}
			case 5:
			{
				q9(); //RAM Storage
				break;
			}
			case 6:
			{
				q5(); //Advantages
				break;
			}
			case 7:
			{
				q6(); //limitation 
				break;
			}
			case 8:
			{
				q7(); //use in real life
				break;
			}
			case 9:
			{
				q8(); //Code understandibility
				break;
			}
			case 10:
			{
				cout << "\nQuiz Time!\n";
    			cout << "Now, let's test your understanding with a quiz.\n";
				runQuiz(); //Quiz
				break;		
			}
			default:
			{
				cout<<"incorrect choice!";
				break;
			}
		}
		cout<<endl<<endl<<"Do you Want to Continue (y/n)"<<endl;
		cin>>con_choice;
	} while(con_choice!='n');
	cout<<"Congrats On Completing "<<endl;
	cout<<"Thanks For Taking Our Tutorail Hope You learned Something From it"<<endl;
	return 0;
}	
