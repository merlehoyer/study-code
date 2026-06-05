#ifndef DIJIKSTRA_HPP
#define DIJIKSTRA_HPP
#define NUM_OF_ARRAYPLACES_NEDDED 2

class dijkstraAlgorithm;
class AdjancencyList{
    private:
        std::vector<std::vector<int>> List;
    
    public:
        AdjancencyList(int num_of_vertices):List(num_of_vertices, std::vector<int>(num_of_vertices+1,0)){
            for(int i=0; i<num_of_vertices; i++){
                List[i][0]=i;
            }
        };
        void addNewVertices(int newVertice);
        bool addEdge(int Vertice, int VerticeConnecting, int weight); 
        void printList()const;
        int sizeList(){
            return List.size();
        }
        friend class dijkstraAlgorithm;
};



#endif