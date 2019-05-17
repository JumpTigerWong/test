#include "Graph.h"
extern Graph m_Graph;
//extern int path_count=0;//用力记录路径的数量
//extern Path pathlist[20];

void init(){
    ifstream in1("/Users/wanghuyue/Desktop/Vex.txt");
    //freopen("/Users/wanghuyue/Desktop/Vex.txt","r",stdin);
    in1>>m_Graph.m_nVexNum;
    for(int i=0;i<m_Graph.m_nVexNum;i++){
        in1>>m_Graph.m_aVexs[i].num;
        in1>>m_Graph.m_aVexs[i].name;
        in1>>m_Graph.m_aVexs[i].desc;
    }
    in1.close();
    ifstream in2("/Users/wanghuyue/Desktop/Edge.txt");
    //freopen("/Users/wanghuyue/Desktop/Edge.txt","r",stdin);
    int m,n;
    for(int i=0;i<10;i++){
        in2>>m>>n;
        in2>>m_Graph.m_aAdjMatrix[m][n];
        m_Graph.m_aAdjMatrix[n][m]=m_Graph.m_aAdjMatrix[m][n];
    }
    in2.close();
}

string num_to_name(int number) {
    return m_Graph.m_aVexs[number].name;
}

void dfs(int nVex, bool bVisited[], int nIndex,int arr[], PathList& pList) {
    bVisited[nVex] = true;
    arr[nIndex++] = nVex;
    if (nIndex == m_Graph.m_nVexNum) {
        PathList now = pList;
        PathList next = new Path(arr, m_Graph.m_nVexNum);
        if (pList == NULL) {
            pList = next;
        }
        else {
            while (now->next != NULL) {
                now = now->next;
            }
            now->next = next;
        }
    }
    for (int i = 0; i < m_Graph.m_nVexNum; i++) {
        if (m_Graph.m_aAdjMatrix[nVex][i] != 0&&!bVisited[i]) {
            dfs(i, bVisited, nIndex,arr, pList);
        }
    }
    bVisited[nVex] = false;
}
