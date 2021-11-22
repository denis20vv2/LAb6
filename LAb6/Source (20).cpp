#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <cmath>
#include <vector>
#include <queue> // очередь
#define SIZE 40





void BFS1(int** graph);

using namespace std;
int main1(int ** graphM, int size);
int main2(int** graphM, int size);





void BFS1(int **mas, int DIST[7], int start, int max_size)
{
    queue<int> Queue;
    int* nodes;
    nodes = (int*)malloc(max_size * sizeof(int));
    for (int i = 0; i < max_size; i++)
    {
        nodes[i] = (int)malloc(max_size * sizeof(int));
    }
    //int nodes[max_size]; // вершины графа
    //for (int i = 0; i < 7; i++)
    
    Queue.push(start); // помещаем в очередь первую вершину
    DIST[start] = 0; // исходно все вершины равны -1
    while (!Queue.empty())
    { // пока очередь не пуста
        start = Queue.front(); // извлекаем вершину
        Queue.pop();
        cout << start  << endl; // выводим номер вершины
        for (int j = 0; j < max_size; j++)
        { // проверяем для нее все смежные вершины
            if (mas[start][j] == 1  && DIST[j]==-1)
            { // если вершина смежная и не обнаружена
                Queue.push(j); // добавляем ее в очередь
                //nodes[j] = 1; // отмечаем вершину как обнаруженную
                DIST[j] = DIST[start] +1;
            }
        }
        
    }
}


int main() {
    setlocale(LC_ALL, "Rus");
    printf("Через BFS\n");
    
    int** graph, max_size;
    printf("Ведите размер графа");
    scanf_s("%d", &max_size);
    graph = (int**)malloc(max_size * sizeof(int));
    for (int i = 0; i < max_size; i++)
    {
        graph[i] = (int*)malloc(max_size * sizeof(int));
    }





    for (int i = 0; i < max_size; i++)
    {
        for (int j = i + 1; j < max_size; j++)
        {
            graph[i][j] = rand() % 2;
            graph[j][i] = graph[i][j];
        }
    }

    for (int i = 0; i < max_size; i++)
    {
        
        for (int j = 0; j < max_size; j++)
        {
            if (i == j)
                graph[i][j] = 0;
            printf("%2d", graph[i][j]);
        }
        printf("\n");
    }






    int start;
    cout << "Введите начальную вершину \n";
    cin >> start;


    int DIST[7];

    for (int i = 0; i < 7; i++) {

        DIST[i] = -1;
    }
    cout << "обход в ширину\n";
    
    BFS1(graph, DIST, start, max_size);

    for (int i = 0; i < 7; i++) {

        printf("рассояние от %d до %d = %d\n", start, i ,DIST[i]);
    }
    
   main1(graph, max_size);
   main2(graph, max_size);
    return 0;
}


int DSFD_Recr(int st, int** b, int num_of_elem, int* visited) {
    int i;
    printf("%d ", st + 1);
    for (i = 0; i < num_of_elem; i++)
    {
        if (b[st][i] == 1 && visited[i] == -1)
        {
            visited[i] = visited[st] + 1;
            DSFD_Recr(i, b, num_of_elem, visited);
        }
    }
    return 0;
}




int main1(int** a, int max_size) {
    printf("\nЧерез DFS\n");
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    //int** a, max_size;
    
   





    
    int DIST[10];
    for (int i = 0; i < max_size; i++)
    {
        DIST[i] = -1;
        for (int j = 0; j < max_size; j++)
        {
            if (i == j)
                a[i][j] = 0;
            printf("%2d", a[i][j]);
        }
        printf("\n");
    }
    printf("\nПоиск расстояний обходомм в глубину \ncтартовая вершина - ");
    int start;
    scanf_s("%d", &start);
    DIST[start - 1] = 0;
    DSFD_Recr(start - 1, a, max_size, DIST);
   // printf("\nРасстояние из первой:\n");
    for (int i = 0; i < max_size; i++) {
       
        printf("рассояние от %d до %d = %d\n", start, i, DIST[i]);
        DIST[i] = -1;
    }
    return 0;
}




struct node
{
    int vertex;
    struct node* next;
};

struct node* createNode(int v);

struct Graph
{
    int numVertices;
    int* visited;
    struct node** adjLists; // we need int** to store a two dimensional array. Similary, we need struct node** to store an array of Linked lists
};
struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
void printGraph(struct Graph*);

void bfs(struct Graph* graph, int startVertex, int DIST[5]);

int main2(int ** graphM, int size)
{
    setlocale(LC_ALL, "Rus");
    struct Graph* graph = createGraph(size);
    

    int versh, i, ver, conect;
    int start, j;

    int  n;

    srand(time(NULL));
    
    bool* visited = new bool[size];

    


    cout << "Матрица смежности графа для конверта: " << endl;
    for (i = 0; i < size; i++)
    {
        visited[i] = false;
        for (j = 0; j < size; j++)
            cout << " " << graphM[i][j];
        cout << endl;
    }



        int  tmp;

        for (i = 0; i < size; i++)
        {
            for ( j = 0; j < size; j++)
            {
                if (graphM[i][j] == 1)
                {
                    addEdge(graph, i, j);
                }
            }
        }


    int  end1;
    cout << "\nСтартовая вершина "; cin >> start;



    cout << "\n поиск на основе списокв, в в ширину ";
    int DIST[5];

    for (int i = 0; i < 5; i++) {

        DIST[i] = -1;
    }

    bfs(graph, start, DIST);

    for (int i = 0; i < 5; i++) {
        printf("\nрассояние от %d до %d = %d\n", start, i, DIST[i]);
        //printf("Посетил %d\n", DIST[i]);
    }
    printGraph(graph);





    return 0;
}
void bfs(struct Graph* graph, int startVertex, int DIST[5]) {
    queue<int> Queue;
    int ii = 0;
    int search[100];
    graph->visited[startVertex] = 1;
    Queue.push(startVertex); // помещаем в очередь первую вершину
    DIST[startVertex] = 0;
    while (!Queue.empty()) {
        int currentVertex = Queue.front(); // извлекаем вершину
        Queue.pop();

        //printf("Посетил %d\n", currentVertex);
        struct node* temp = graph->adjLists[currentVertex];

        while (temp) {
            int adjVertex = temp->vertex;
            if (graph->visited[adjVertex] == 0 && DIST[adjVertex] == -1) {

                Queue.push(adjVertex);
                DIST[adjVertex] = DIST[startVertex] + 1;

            }
            temp = temp->next;
        }
    }
}





struct node* createNode(int v)
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices)
{
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct node**)malloc(vertices * sizeof(struct node*));
    graph->visited = (int*)malloc(vertices * sizeof(int));


    int i;
    for (i = 0; i < vertices; i++) {
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}


void addEdge(struct Graph* graph, int src, int dest)
{
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // Add edge from dest to src
    newNode = createNode(src);
    newNode->next = graph->adjLists[dest];
    graph->adjLists[dest] = newNode;
}










void printGraph(struct Graph* graph)
{
    int v;
    for (v = 0; v < graph->numVertices; v++)
    {
        struct node* temp = graph->adjLists[v];
        printf("\n Список смежности вершины  %d\n ", v);
        while (temp)
        {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}