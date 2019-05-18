#include "Graph.h"
#include "Tourism.h"
Graph m_Graph;

int path_count=0;
Path pathlist[20];
int main() {
    init();
    int choose=1;
    while (choose) {
        choose=printMune();
        switch (choose) {
            case 1:
                printM();
                break;
            case 2:
                seekSinghtPoint();
                break;
            case 3:
                DFSTraverse();
                break;
            case 4:
                FindShortPath();
                break;
            case 5:
                DesignPath();
                break;
            default:
                break;
        }
    }
    return 0;
}
