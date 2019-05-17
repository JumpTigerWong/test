#pragma once
//#ifndef UNTITLED7_DATA_H
//#define UNTITLED7_DATA_H
#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
using  namespace std;
struct Vex
{
    int num;        // 景点编号
    string name;    // 景点名字
    string desc;    // 景点介绍
};

struct Graph{
    int m_aAdjMatrix[20][20]; // 邻接矩阵
    Vex m_aVexs[20]; // 顶点数组
    int m_nVexNum; // 顶点个数
} ;

//
typedef struct Path {
    string vexs;
    Path* next;
    Path(int arr[],int count){
        for (int i = 0; i < count; i++)
            vexs += arr[i] + '0';
        next = NULL;
    }
    Path() {
        vexs = "";
        next = NULL;
    }
}*PathList;

struct Edge{
    int vex1;
    int vex2;
    int weight;
};

void init();
void dfs(int nVex, bool bVisited[], int nIndex,int arr[], PathList& pList);
string num_to_name(int number);
//#endif //UNTITLED7_DATA_H
// /Users/wanghuyue/Desktop/Vex.txt
// /Users/wanghuyue/Desktop/Edge.txt
/*
 * struct Edge
{
    int vex1,vex2;   //边的两个个顶点
    int weight;          //权值
};*/