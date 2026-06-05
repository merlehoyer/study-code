#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#define NUM_OF_ARRAYPLACES_NEDDED 2

class AdjacencyMatrix{
    private:
    std::vector<std::vector<int>> matrix;
    //int matrix[3][3];
    public:
        void setConnectionToNull(int firstNode, int secondNode){
            matrix[firstNode][secondNode]=0;
            return;
        }

        void setConnectionToOne(int firstNode, int secondNode){
            matrix[firstNode][secondNode]=1;
            return;
        }

        void printMatrix()const{
            std::cout<<std::setw(5)<< " "<<"0"<<std::setw(5)<<"1"<<std::setw(5)<<"2"<<std::endl;
            

            for(int i=0; i<3; i++){
                std::cout<<std::setw(5)<<i;
                for (int j =0;j<3;j++){
                    std::cout<<std::setw(5)<<matrix[j][i];
                }
                std::cout<<std::endl;
            }
            return;
        }
        /*
        AdjacencyMatrix(int numOfNodes){

            matrix.resize(numOfNodes);

            for(std::vector<int> nodes: matrix){
               
                nodes.resize(numOfNodes,0);
            }
        }*/

        AdjacencyMatrix(int numOfNodes):matrix(numOfNodes, std::vector<int>(numOfNodes,0)){}
        
};

class AdjancencyList{
    private:
        std::vector<std::vector<int>> List;
    
    public:
        AdjancencyList(int num_of_vertices):List(num_of_vertices, std::vector<int>(NUM_OF_ARRAYPLACES_NEDDED,0)){
            for(int i=0; i<num_of_vertices; i++){
                List[i][0]=i;
            }
        };
        void addNewVertices(int newVertice);
        bool addEdge(int Vertice, int VerticeConnecting); 
        void printList()const;
        void check(){
            std::cout<<List.size()<<std::endl;
        }
        
};

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

bool AdjancencyList::addEdge(int Vertice, int VerticeConnecting){
    //std::vector<std::vector<int>>::iterator it= std::find(List.begin(), List.end(), Vertice);
    int it=-1;
    for(int i=0; i<List.size(); i++){
       if( List[i][0]==Vertice){
        it=i;
       }
    }
    if(it!=-1 ){
        
        List[it].push_back(VerticeConnecting);
        
        return true;
    }else{
        return false;
    }
}

int main(){
    AdjacencyMatrix myMatrix(4);

    myMatrix.printMatrix();
    myMatrix.setConnectionToOne(0,1);
    myMatrix.setConnectionToOne(1,2);
    myMatrix.printMatrix();

    AdjancencyList myList(3);
    myList.printList();

    myList.addNewVertices(3);
    myList.printList();
    myList.check();

    bool check= myList.addEdge(2,3);
    if(check==false){
        std::cout<<"error"<<std::endl;
        return 23;
    }
    check= myList.addEdge(2,1);
    if(check==false){
        std::cout<<"error"<<std::endl;
        return 23;
    }
    myList.printList();

    return 0;
}