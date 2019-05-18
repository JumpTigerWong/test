#include "Graph.h"
extern Graph m_Graph;
//extern int path_count=0;//用力记录路径的数量
//extern Path pathlist[20];

void init(){
    int INF=0xffff;
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
    for(int i=0;i<m_Graph.m_nVexNum;i++){
        for(int j=0;j<m_Graph.m_nVexNum;j++){
            if(m_Graph.m_aAdjMatrix[i][j]==0){
                m_Graph.m_aAdjMatrix[i][j]=INF;
            }
        }
    }
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

Edge edge[20];
Edge ans[20];
int ecount;
int minlength=0x7ffff;
bool visited[20];
void getMinPath(int begin,int end,int curpoint,int total_lenghth){
    if(begin==end){
        if(total_lenghth<minlength){
            for(int i=0;i<curpoint;i++){
                ans[i]=edge[i];
            }
            minlength=total_lenghth;
            ecount=curpoint;
        }
    }
    visited[begin]=true;
    for(int j=0;j<m_Graph.m_nVexNum;j++){
        if(m_Graph.m_aAdjMatrix[begin][j]!=0&&!visited[j]){
            visited[j]=true;
            edge[curpoint].vex1=begin;
            edge[curpoint].vex2=j;
            edge[curpoint].weight=m_Graph.m_aAdjMatrix[begin][j];
            getMinPath(j,end,curpoint+1,total_lenghth+edge[curpoint].weight);
            visited[j]=false;
        }
    }
}

void printMinPath(){
    cout<<"最短路线为:"<<m_Graph.m_aVexs[ans[0].vex1].name<<"->";
    for(int i=0;i<ecount;i++){
        if(i!=ecount-1){
            cout<<m_Graph.m_aVexs[ans[i].vex2].name<<"->";
        }else{
            cout<<m_Graph.m_aVexs[ans[i].vex2].name<<endl;
        }
    }
    cout<<"最短距离为:"<<minlength<<endl;
}

void FindMinTree(){
    int min,i,j,k,weight=0;
    int lowcost[20];
    int adjvex[20];
    lowcost[0]=0;
    adjvex[0]=0;
    for(i=1;i<m_Graph.m_nVexNum;i++){
        lowcost[i]=m_Graph.m_aAdjMatrix[0][i];
        adjvex[i]=0;
    }
    for(i=1;i<m_Graph.m_nVexNum;i++){
        min=0xffff;
        j=1,k=0;
        while(j<m_Graph.m_nVexNum){
            if(lowcost[j]!=0&&lowcost[j]<min){
                min=lowcost[j];
                k=j;
            }
            j++;
        }
        lowcost[k]=0;
        cout<<m_Graph.m_aVexs[adjvex[k]].name<<"->"<<m_Graph.m_aVexs[k].name<<" "<<m_Graph.m_aAdjMatrix[adjvex[k]][k]<<endl;
        //cout<<adjvex[k]<<k;
        weight+=m_Graph.m_aAdjMatrix[adjvex[k]][k];
        for(j=1;j<m_Graph.m_nVexNum;j++){
            if(lowcost[j]!=0&&m_Graph.m_aAdjMatrix[k][j]<lowcost[j]){
                lowcost[j]=m_Graph.m_aAdjMatrix[k][j];
                adjvex[j]=k;
            }
        }
    }
    cout<<"铺设线路总长度为:"<<weight<<endl;
}