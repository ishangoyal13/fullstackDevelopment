#include <list>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <windows.h>
#define INFINITY 9999999
#define FOREGROUND_WHITE (FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE)

using namespace std;


class TextAttr {
    friend std::ostream& operator<<(std::ostream& out, TextAttr attr)
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), attr.value);
        return out;
    }
public:
    explicit TextAttr(WORD attributes) : value(attributes) {}
private:
    WORD value;
};

class Point {
public:
    int x, y;
    Point()
    {}
    Point(int i, int j)
    {
        x = i; y = j;
    }
    void setp(int i, int j)
    {
        x = i, y = j;
    }
};

class Node {
public:
    Point point;
    bool visited = false;
    bool blocked = false;
    bool inPath = false;
    vector<Node*> neighbours;
    Node* parent;
    float gValue, hValue;
    
    bool operator == (const Node& o) { return point.x == o.point.x && point.y == o.point.y; }
    bool operator == (const Point& o) { return point.x == o.x && point.y == o.y;
    }
    //bool operator < (const Node& o) { return hValue < o.hValue; }
    
}; 


class map {
public:

    Node* start; Node* end;
    Node** mat;
    int w, h;
    map(int height , int width) {
        h = height; w = width;
        mat = new Node * [w];
            for (int r = 0; r < w; r++) {
                mat[r] = new Node[h];
                for (int s = 0; s < h; s++)
                {
                    mat[r][s].point.setp(r, s);
                    mat[r][s].blocked = false;
                    mat[r][s].parent = nullptr;
                    mat[r][s].visited = false;
                    mat[r][s].gValue = INFINITY;
                    mat[r][s].hValue = INFINITY;
                }
            }
            //add neighbours
            for (int i = 0; i < w; i++) {
                
                for (int j = 0; j < h; j++)
                {
                    if (j > 0)
                        mat[i][j].neighbours.push_back(&mat[i][j - 1]);
                    if (j < h-1)
                        mat[i][j].neighbours.push_back(&mat[i][j + 1]);
                    if (i > 0)
                        mat[i][j].neighbours.push_back(&mat[i-1][j ]);
                    if (i < w - 1)
                        mat[i][j].neighbours.push_back(&mat[i+1][j ]);
                    if (i > 0 && j > 0)
                        mat[i][j].neighbours.push_back(&mat[i - 1 ][j - 1]);
                    if (i < w-1 && j < h-1)
                        mat[i][j].neighbours.push_back(&mat[i + 1][j + 1]);
                    if (i > 0 && j < h-1)
                        mat[i][j].neighbours.push_back(&mat[i - 1][j + 1]);
                    if (i < w-1 && j > 0)
                        mat[i][j].neighbours.push_back(&mat[i + 1][j - 1]);
                }
            }
    }

    void addBlocks(int val)
    {
        srand((unsigned)time(0));
        float temp = float(val) / 100;
        float num = (h * w) * temp;
        while (num > 0)
        {
            int x = rand() % w;
            int y = rand() % h;
            while (1) {
                if (!mat[x][y].blocked) {
                    mat[x][y].blocked = true;
                    break;
                }
                x = rand() % w;
                y = rand() % h;
            }
            num--;
        }
    }

    bool setStart(int x, int y)
    {
        Point p(x, y);
        if (isValid(p)) {
            start = &mat[x][y];
            start->gValue = 0;
            return true;
        }
        return false;
    }
    bool setend(int x, int y)
    {
        Point p(x, y);
        if (isValid(p)) {
            end = &mat[x][y];
            return true;
        }
        return false;
    }
    bool isValid(Point& p) {
        return (p.x > -1 && p.y > -1 && p.x < w && p.y < h);
    }

    void print(){
        for (int i = 0; i < w; i++) 
        {
            cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_BLUE);
            cout << '|';
            cout << TextAttr(FOREGROUND_WHITE);
            for (int j = 0; j < h; j++)
            {
                //cout << '|';
                if (mat[i][j].blocked) {
                    cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_RED);
                    cout << 'x';
                    cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                    cout << '|';
                    cout << TextAttr(FOREGROUND_WHITE);
                }
                else if (mat[i][j].inPath) {
                    if (&mat[i][j] == start)
                      cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                    else if (&mat[i][j] == end)
                        cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_RED);
                    else 
                        cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                    cout << char(219);
                    cout << char(219);

                    cout << TextAttr(FOREGROUND_WHITE);
                }
                else { 
                    if (&mat[i][j] == start)
                    {
                        cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_GREEN);
                        cout << char(219);
                        cout << char(219);
                        cout << TextAttr(FOREGROUND_WHITE);
                    }
                    else if (&mat[i][j] == end)
                    {
                        cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_RED);
                        cout << char(219);
                        cout << char(219);
                        cout << TextAttr(FOREGROUND_WHITE);
                    }
                    else
                    {
                        //cout << TextAttr(FOREGROUND_WHITE);
                        cout << TextAttr(FOREGROUND_INTENSITY | FOREGROUND_BLUE);
                        cout << '_'; 
                        
                        cout << '|';
                        cout << TextAttr(FOREGROUND_WHITE);

                    }
                }
            }
            //cout << '|';
            cout << endl; 
        }
     }

    ~map()
    {
        for (int i = 0; i < w; i++)
            delete[] mat[i];
        delete[] mat;
    }
};

class aStar {
public:

    map* m; 
    list<Node*> listNotTested;
    aStar(map* map) {
        m = map;
        m->start->hValue = calHeuristic(*(m->start));
        listNotTested.push_back(m->start);
    }

    float calHeuristic(Node p) {
        
        float x = m->end->point.x - p.point.x; float y = m->end->point.y - p.point.y;
        return sqrtf(x * x + y * y);
    }

    bool isValid(Point& p) {
        return (p.x > -1 && p.y > -1 && p.x < m->w&& p.y < m->h);
    }

    
    float distance(Node* a, Node* b) // For convenience
    {
        return sqrtf((a->point.x - b->point.x) * (a->point.x - b->point.x) + (a->point.y - b->point.y) * (a->point.y - b->point.y));
    };

    bool search() 
    {
        if (m->start->blocked)
        {
            cout << "\nStart location blocked\n";
            return 0;
        }
        if (m->end->blocked)
        {
            cout << "\End location blocked\n";
            return 0;
        }
        Node* current = m->start;
        m->start->hValue = calHeuristic(*m->start);
        while (!listNotTested.empty() && current != m->end)
        {
            listNotTested.sort([](const Node* l, const Node* r) {return l->hValue < r->hValue; });

            while(!listNotTested.empty() && listNotTested.front()->visited)
                listNotTested.pop_front();
            
            if (listNotTested.empty())
                break;

            current = listNotTested.front();
            current->visited = true;
            for (auto n : current->neighbours)
            {
                if (!n->blocked && !n->visited)
                    listNotTested.push_back(n);
                float newG = current->gValue + distance(current, n);
                //float newG = current->gValue + 1;

                if (newG < n->gValue)
                {
                    n->parent = current;
                    n->gValue = newG;
                    n->hValue = n->gValue + calHeuristic(*n);
                }
            }
        }
        current = m->end->parent; int count = 0;
        if (current == nullptr)
            return false;
        cout << "Path:\n";
        while (current != nullptr)
        {
            current->inPath = true;
            cout << " ( " << current->point.x << "," << current->point.y << " ) \n";
            current = current->parent;
            count++;
        }
        cout << "\nCost: " << count << endl;
        return true;
    }

    

};

int main() {
    while (1) {
        int rows, cols, blocks;
        cout << "Enter rows: ";
        cin >> rows;
        cout << "Enter columns: ";
        cin >> cols;
        map* m = new map(rows, cols);
    
        cout << "Enter Start row: ";
        cin >> rows;
        cout << "Enter Start column: ";
        cin >> cols;
        m->setStart(rows, cols);
        cout << "Enter End row: ";
        cin >> rows;
        cout << "Enter End column: ";
        cin >> cols;
        m->setend(rows, cols);
        cout << "What percentage of obstacles are there: ";
        cin >> blocks;
        m->addBlocks(blocks);
        cout << "\nMAP\n\n";
        m->print();
        cout << "\n ---A* Algo--- \n" << endl;
        aStar a(m);
        cout << "\n\n";
        if (a.search())
            m->print();
        
        char temp;
        cout << "\nPress n to end||Any letter to continue\n";
        cin >> temp;
        if (toupper(temp) == 'N')
            break;
        system("CLS");
        cout << "CONTINUED!\n";

    }
    return 0;
}