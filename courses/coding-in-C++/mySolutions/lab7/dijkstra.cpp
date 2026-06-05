#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <limits>
#include "dijikstra.hpp"
#define NUM_OF_ARRAYPLACES_NEDDED 2
#define INFINITY std::numeric_limits<int>::max()


void AdjancencyList::printList()const{
            //std::cout<<std::setw(5)<< " "<<"0"<<std::setw(5)<<"1"<<std::setw(5)<<"2"<<std::endl;
            

            for(int i=0; i< List.size(); i++){
                for(int edges: List[i]){
                    std::cout<<edges<<"   ";
                }
                std::cout<<std::endl;
            }
            
            return;
}

void AdjancencyList::addNewVertices(int newVertice){
    this->List.push_back(std::vector<int>(NUM_OF_ARRAYPLACES_NEDDED,0));
    List[List.size()-1][0]=newVertice;
    return;
}

// wird von ausgegenagne dass edges in reihen folge wie vertices eingetragen sind
bool AdjancencyList::addEdge(int Vertice, int VerticeConnecting, int weight){
    //std::vector<std::vector<int>>::iterator it= std::find(List.begin(), List.end(), Vertice);
    int it=-1;
    for(int i=0; i<List.size(); i++){
       if( List[i][0]==Vertice){
        it=i;
       }
    }
    if(it!=-1 ){
        
        List[it][VerticeConnecting+1]= weight;
        // +1 damit nicht erste arrayplatz verändert wird
        return true;
    }else{
        return false;
    }
}

//-------- dijkstra algorithm---------//

class dijkstraAlgorithm{
    private: 
        std::vector<int> visited;
        std::vector<int> unvisited;
        std::vector<std::vector<int>> tabelle;
        AdjancencyList &List;
        int startingNode;
        int endNode;
        
    public:
        void updateTabell(int curNode);
        void updateArrays(int curNode);
        // if return ==-1 -> alle schon besucht
        int chooseNewNode();
        void doingAlgorithm();
        void printResult()const;
        dijkstraAlgorithm(AdjancencyList &List, int startingPoint, int endNode);
        
};

dijkstraAlgorithm::dijkstraAlgorithm(AdjancencyList &List, int startingPoint, int endNode)
    :List(List), startingNode(startingPoint),endNode(endNode),tabelle(List.List.size(), std::vector<int>(3,-1)), unvisited(List.List.size()), visited(1,-1){
        
        for(int i=0; i<List.List.size(); i++){
            tabelle[i][0]=List.List[i][0];
            if(i==startingPoint){
                    tabelle[i][1]=0;
                }else{
                    tabelle[i][1]= INFINITY;
                }
                 
        }

        for(int i=0; i<List.List.size(); i++){
            unvisited[i]=List.List[i][0];
        }        
}

void dijkstraAlgorithm::updateTabell(int curNode){
   //Nachbarn von curNode
    for(int i= 1; i< List.List[curNode].size(); i++){
        if(List.List[curNode][i]!=0){
            //muss i-1 nutzen da 0 stelle curnode ist und nicht edges wert
            if(tabelle[i-1][1]==INFINITY){
                tabelle[i-1][1]=List.List[curNode][i];
                tabelle[i-1][2]=curNode;
            }else{
                // schon ein wert für distanz da
                int newDistance = tabelle[curNode][1]+List.List[curNode][i];
                if(newDistance<tabelle[i-1][1]){
                    tabelle[i-1][1]=newDistance;
                    tabelle[i-1][2]=curNode;
                }else{
                    //nothing
                }
            }
            
        }
    }

    updateArrays(curNode);
    return;
}

void dijkstraAlgorithm::updateArrays(int curNode){
    auto it= std::find(unvisited.begin(), unvisited.end(), curNode);
    if(it!= unvisited.end()){
       unvisited.erase(it);
    }else{
        std::cout<<"error updating arrays";
    }

    visited.push_back(curNode);
    return;
}

int dijkstraAlgorithm::chooseNewNode(){
    
    int minDistance =INFINITY;
    int newNode=-1;
    
    for(int i=0; i< tabelle.size(); i++){
        //checks if value visited

        auto it = std::find(visited.begin(), visited.end(), tabelle[i][0]);
        if(it==visited.end()){
            //noch nicht besucht
            if(tabelle[i][1]<minDistance){
                minDistance=tabelle[i][1];
                newNode=i;
            }
        }
    }
    return newNode;
}

void dijkstraAlgorithm::doingAlgorithm(){
    updateTabell(startingNode);
    int curNode= chooseNewNode();
    while(curNode!=-1){
        updateTabell(curNode);
        curNode= chooseNewNode();
    }
}

void dijkstraAlgorithm::printResult()const{
    std::cout<<"distances between node "<<startingNode<<" and "<<endNode<<": "<<tabelle[endNode][1]<<std::endl;
    std::cout<<"Weg: ";
    int node=endNode;
    std::cout<<node<<" ";
    while(node!= startingNode){
        node=tabelle[node][2];
        std::cout<<node<<" ";
    }
    std::cout<<std::endl;
}

int main(){

    AdjancencyList myList(4);
    //A
    myList.addEdge(0,1,4);
    myList.addEdge(0,2,2);
    myList.addEdge(0,3,5);
    //B
    myList.addEdge(1,0,4);
    myList.addEdge(1,2,3);
    myList.addEdge(1,3,1);
    //C
    myList.addEdge(2,0,2);
    myList.addEdge(2,1,3);
    myList.addEdge(2,3,7);
    //D
    myList.addEdge(3,0,5);
    myList.addEdge(3,1,1);
    myList.addEdge(3,2,7);

    myList.printList();

    dijkstraAlgorithm tryOne(myList, 3,2);
    tryOne.doingAlgorithm();
    tryOne.printResult();

    return 0;
}