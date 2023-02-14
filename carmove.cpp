#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

void input();


   



int main(){
    vector<int> position(0,0);
    int x, y;




    while(true){
    if(GetKeyState(VK_UP) & 0x8000) 
    {

        position[1] += y;
    
    }
    if(GetKeyState(VK_DOWN) & 0x8000) 
    {

        position[1] -= y;
      
    }
    if(GetKeyState(VK_LEFT) & 0x8000) 
    {

        position[0] -= x;
      
    
    }
    if(GetKeyState(VK_RIGHT) & 0x8000) 
    {

        position[0] += x;
      
    
    }

    
    
    
    
    cout <<"Velor de X: "<< position[0] <<"Velor de y: " << position[1] << endl;
    }
    return 0;

}

void input(){

   


}