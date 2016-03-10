#include <iostream>
#include <string>

using namespace std;

void StringRecursive(string s){
	if(s.size() == 0){
		return;
	}

    char c;
    c = s.at(0);
    s.at(0) = s.at(s.size()-1) ;
    s.at(s.size()-1) = c;
	
	cout << s.at(0) << endl;
	//cout << s.at(s.size()-1) << endl;
	s.erase(s.begin());

	cout << s << endl;

	// s.erase(s.end()-1);

	

	StringRecursive(s);
	
}

int main(){
	string s;
	cin >> s;
	StringRecursive(s);
	return 0;
}
