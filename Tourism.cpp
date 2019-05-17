//
// Created by 汪虎跃 on 2019-05-13.
//

#include "Tourism.h"
#include "Graph.h"
extern Graph m_Graph;
//extern int path_count=0;
extern Path pathlist[20];
void seekSinghtPoint(){
    cout<<"===== 查询景点信息 ====="<<endl;
    for(int i=0;i<m_Graph.m_nVexNum;i++){
        cout<<i<<"-"<<m_Graph.m_aVexs[i].name<<endl;
    }
    cout<<"请输入想要查询的景点编号:";
    int numofSightPoint;
    srand(time(NULL));
    cin>>numofSightPoint;
    cout<<m_Graph.m_aVexs[numofSightPoint].name<<endl;
    cout<<m_Graph.m_aVexs[numofSightPoint].desc;
    cout<<"门票价格为"<<rand()%50<<"元"<<endl;
    cout<<"----- 周边景区 -----"<<endl;
    for(int j=0;j<m_Graph.m_nVexNum;j++){
        if(m_Graph.m_aAdjMatrix[numofSightPoint][j]!=0){
            cout<<m_Graph.m_aVexs[numofSightPoint].name<<"->"<<m_Graph.m_aVexs[j].name<<" "<<m_Graph.m_aAdjMatrix[numofSightPoint][j]<<"m"<<endl;
        }
    }
}

void printM(){
    cout<<"=====创建景区景点图====="<<endl;
    cout<<"顶点个数:"<<m_Graph.m_nVexNum<<endl;
    cout<<"-------- 顶点 -------"<<endl;
    for(int i=0;i<m_Graph.m_nVexNum;i++){
        cout<<i<<"-"<<m_Graph.m_aVexs[i].name<<endl;
    }
    cout<<"--------- 边 --------"<<endl;
    for(int i=0;i<m_Graph.m_nVexNum;i++){
        for(int j=0;j<m_Graph.m_nVexNum;j++){
            if(m_Graph.m_aAdjMatrix[i][j]!=0){
                cout<<"<v"<<i<<",v"<<j<<">"<<m_Graph.m_aAdjMatrix[i][j]<<endl;
            }
        }
    }
    return;
}

void DFSTraverse() {
    int begin;
    bool choosed[20];
    int arr[20];
    for (int i = 0; i < 20; i++) {
        choosed[i] = false;
    }
    PathList pList = NULL;
    cout << "请输入起点:";
    cin >> begin;
    dfs(begin, choosed, 0,arr, pList);
    int count = 0;
    while (pList != NULL) {
        cout << "路线" << ++count << ": ";
        int len = pList->vexs.length();
        for (int i = 0; i < len; i++) {
            if (i != len - 1) {
                cout << num_to_name(pList->vexs[i]-'0') << " -> ";
            }
            else {
                cout << num_to_name(pList->vexs[i]-'0') << endl;
            }
        }
        pList = pList->next;
    }
}

void FindShortPath(){
    int begin,end;
    cout<<"===== 搜索最短路径 ====="<<endl;
    for(int i=0;i<m_Graph.m_nVexNum;i++){
        cout<<i<<"-"<<m_Graph.m_aVexs[i].name<<endl;
    }
    cout<<"请输入起点编号:";
    cout<<"请输入终点编号:";
    cin>>begin>>end;

}

int printMune(){
    cout<<"===== 景区信息管理系统 ====="<<endl;
    cout<<"1.创建景区景点图"<<endl;
    cout<<"2.查询景点信息"<<endl;
    cout<<"3.旅游景点导航"<<endl;
    cout<<"4.搜索最短路径"<<endl;
    cout<<"5.铺设电路规划"<<endl;
    cout<<"0.退出"<<endl;
    cout<<"请输入操作编号(0~5)";
    int temp;
    cin>>temp;
    return temp;
}
