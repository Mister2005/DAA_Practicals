#include <stdio.h>
#include <conio.h>
#define MAX 20

// Array of color names for visualization
const char* COLOR_NAMES[] = {
    "None", "Red", "Green", "Blue", "Yellow", 
    "Purple", "Orange", "Brown", "Pink", "Cyan"
};

// Function to print the graph's adjacency matrix
void printGraph(int V, int graph[MAX][MAX]) {
    printf("\nAdjacency Matrix of the Graph:\n");
    printf("   ");
    for(int i = 0; i < V; i++)
        printf("%3d", i);
    printf("\n   ");
    for(int i = 0; i < V; i++)
        printf("---");
    printf("\n");
    
    for(int i = 0; i < V; i++) {
        printf("%2d |", i);
        for(int j = 0; j < V; j++) {
            printf("%3d", graph[i][j]);
        }
        printf("\n");
    }
}

// Function to print the color assignment for each vertex
void printColorAssignment(int V, int color[], int graph[MAX][MAX]) {
    printf("\nColor Assignment:\n");
    printf("---------------\n");
    for(int i = 0; i < V; i++) {
        printf("Node %d -> %s", i, COLOR_NAMES[color[i]]);
        // Print adjacent nodes
        printf(" (Adjacent to: ");
        int printed = 0;
        for(int j = 0; j < V; j++) {
            if(graph[i][j]) {
                if(printed) printf(", ");
                printf("%d", j);
                printed = 1;
            }
        }
        printf(")\n");
    }
}

// Function to check if it's safe to color vertex v with color c
int isSafe(int v, int V, int graph[MAX][MAX], int color[], int c) {
    for(int i = 0; i < V; i++)
        if(graph[v][i] && c == color[i])
            return 0;
    return 1;
}

// Recursive function to solve graph coloring
int graphColoringUtil(int V, int graph[MAX][MAX], int m, int color[], int v) {
    // Base case: all vertices colored
    if(v == V)
        return 1;
    
    // Try different colors for vertex v
    for(int c = 1; c <= m; c++) {
        // Check if color c can be assigned to vertex v
        if(isSafe(v, V, graph, color, c)) {
            color[v] = c;
            // Recur for next vertex
            if(graphColoringUtil(V, graph, m, color, v + 1))
                return 1;
            // If color c didn't lead to solution, remove it
            color[v] = 0;
        }
    }
    return 0;
}

void main() {
    //clrscr();  // Clear screen for Turbo C
    int V, m;
    int graph[MAX][MAX];
    int color[MAX] = {0};  // Initialize all colors to 0 (no color)
    
    printf("Graph Coloring Problem Solver\n");
    printf("--------------------------\n\n");
    
    // Get number of vertices
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &V);
    
    if(V <= 0 || V > MAX) {
        printf("Invalid number of vertices!\n");
        //getch();
        return;
    }
    
    // Get adjacency matrix
    printf("\nEnter the adjacency matrix (1 if connected, 0 if not):\n");
    printf("Example for 3 vertices:\n");
    printf("0 1 1\n1 0 1\n1 1 0\n\n");
    
    for(int i = 0; i < V; i++) {
        printf("Enter row %d: ", i);
        for(int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] != 0 && graph[i][j] != 1) {
                printf("Invalid input! Please use only 0 or 1.\n");
                //getch();
                return;
            }
        }
    }
    
    // Print the graph structure
    printGraph(V, graph);
    
    // Get number of colors
    printf("\nEnter the number of colors to use (max 10): ");
    scanf("%d", &m);
    
    if(m <= 0 || m > 10) {
        printf("Invalid number of colors!\n");
        //getch();
        return;
    }
    
    printf("\nTrying to color the graph with %d colors...\n", m);
    
    // Try to color the graph
    if(graphColoringUtil(V, graph, m, color, 0)) {
        printf("\nSolution exists!\n");
        printColorAssignment(V, color, graph);
        
        // Print color summary
        printf("\nColor Summary:\n");
        printf("-------------\n");
        int colorCount[11] = {0};  // Count of each color used
        for(int i = 0; i < V; i++)
            colorCount[color[i]]++;
        for(int i = 1; i <= m; i++)
            if(colorCount[i] > 0)
                printf("%s: Used for %d node(s)\n", COLOR_NAMES[i], colorCount[i]);
    }
    else {
        printf("\nNo solution exists with %d colors!\n", m);
        printf("Try increasing the number of colors.\n");
    }
    
    printf("\nPress any key to exit...");
    //getch();  // Wait for key press in Turbo C
}
