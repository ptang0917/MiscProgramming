#include <iostream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <stack>
#include <sstream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <unordered_map>
#include <queue>
using namespace std;


int main(){
   int testcase = 0;
   std::priority_queue<int> greenteam;
   std::priority_queue<int> blueteam;
   cin >> testcase;
   int battle = 0;
   
   int sg = 0;
   
   int sb = 0;
   
   int bluestrength = 0;
   int greenstrength = 0;
   int winner = 0;
   bool draw;
   for(int i = 0; i < testcase; i++){
      cin >> battle;
      cin >> sg;
      cin >> sb;

      for(int i = 0; i < sg; i++){
   		cin >> greenstrength;
   		greenteam.push(greenstrength);
   
      }
   
      for(int i = 0; i < sb; i++){
   		cin >> bluestrength;
   		blueteam.push(bluestrength);
      }
   
      while(!greenteam.empty() && !blueteam.empty()){
   		 for(int i = 0; i < battle; i++){
               // cout << "greenteam " << greenteam.top() << endl;
               // cout << "blueteam " << blueteam.top() << endl;
   			 if(greenteam.top() > blueteam.top()){

   			 		winner = greenteam.top() - blueteam.top();
   			 		blueteam.pop();
   			 		greenteam.pop();
   			 		greenteam.push(winner);
   			 }
   			 else if(greenteam.top() < blueteam.top()){
   			 		 winner = blueteam.top() - greenteam.top();
   			 		 blueteam.pop();
   			 		 greenteam.pop();
   			 		 blueteam.push(winner);
   			 }
             else if(greenteam.top() == blueteam.top()){
                   blueteam.pop();
                   greenteam.pop();

            }
            if(greenteam.empty() && blueteam.empty()){
               draw = true;
               break;
            }
            else if(greenteam.empty()){
               draw = false;
               break;
            }
            else if(blueteam.empty()){
               draw = false;
               break;
            }
   		}
      }


      if(greenteam.empty() && draw == false){
   		cout << "blue wins" << endl;
         for(int i = 0; i < blueteam.size(); i++){
            cout << blueteam.top() << endl;
            blueteam.pop();
         }
      }
      else if(blueteam.empty() && draw == false){
   		cout << "green wins" << endl;
          for(int i = 0; i < greenteam.size(); i++){
            cout << greenteam.top() << endl;
            greenteam.pop();
         }
      }
      else if(blueteam.empty() && greenteam.empty() && draw == true) {
   		cout << "green and blue died" << endl;
      }

  }

   return 0; 

}
