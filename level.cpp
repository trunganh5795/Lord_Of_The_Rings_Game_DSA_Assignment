#include <iostream>>
using namespace std;
int main(){
    int b,levelOf;
    for(int i=1;i<20;i++){
        b = i % 10;
		levelOf = i > 6 ? (b > 5 ? b : 5) : b;
        cout<<levelOf<<" ";
    }
}