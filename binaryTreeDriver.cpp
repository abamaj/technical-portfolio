#include <string>
#include <math.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "BinaryTree.cpp"
using namespace std;

int main(int argc, char* argv[]){
    
    int dataArray[40000];
    int i = 0;
    
    ifstream myFile;
    
    myFile.open(argv[1]);
    
    if(myFile.is_open()){
        
        string line = "";
        
        while(getline(myFile, line, ',')){ 
            
            if(line == ""){
                
                continue;
            }
            
            else{
                
                int data = stoi(line);
                dataArray[i] = data;
            }
        }
        i++;
        
    }
    
    else{
        
        cout << "file not opened correctly" << endl;
    }
    
    
}

