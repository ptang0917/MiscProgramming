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
using namespace std;


int main(){
   int testcase = 0;
   priority_queue<int> greenteam;
   priority_queue<int> blueteam;
   int battle = 0;
   cin >> battle;
   int sg = 0;
   cin >> sg;
   int sb = 0;
   cin >> sb;
   int bluestrength = 0;
   int greenstrength = 0;
   int winner = 0;
   
   for(int i = 0; i < sg; i++){
   		cin >> greenstrength;
   		greenteam.push(greenstrength)
   
   }
   
   for(int i = 0; i < sb; i++){
   		cin >> bluestrength;
   		blueteam.push(bluestrength)
   }
   
   while(!greenteam.empty() || !blueteam.empty()){
   		for(int i = 0; i < battle; i++){
   			 if(greenteam.top() < blueteam.top()){
   			 		winner = greenteam.top() - blueteam.top();
   			 		blueteam.pop();
   			 		greenteam.pop();
   			 		greenteam.push(winner);
   			 }
   			 else if(greenteam.top() > blueteam.top()){
   			 		
   			 }
   		}
   }
   



}
