#include <vector>
#include <iostream>

using namespace std;

int main() {
    
    //vector<int> list = {5, 2, 4, 2, 9, 8, 0, 1, 3};
    vector<int> list;
    int list2[] = {5, 2, 4, 2, 9, 8, 0, 1, 3};
    
    for (int j = 0; j < sizeof(list2)/sizeof(int); j++) {
        list.push_back(list2[j]);
    }
    
    //for (int i = 0; i < list.size(); i++) {
    //    cout << "[" << i << "] : " << list.at(i) << endl;
    //}
    
    //int count = 0;
    //while(count <  9 /* experssion */) {
    //    cout << "[" << count << "] : " << list.at(count) << endl;
    //    count++;
        //++count;
    //}
/*
    int i = 0; // count = 1;
    do {
        //--i; // i = i - 1;
        cout << "[" << i << "] : " << list.at(i) << endl;
        //i=i+2;
        i++;
    } while (i < list.size());
    */
    
    
    /*
    int i = 0;
    for (int  element : list) {
        cout << "[" << i++ << "] : " << element << endl;
    }*/
    
    int i = 0;
    for (vector<int>::const_iterator iter = list.begin(); iter != list.end(); ++iter) {
        cout << "[" << i++ << "] : " << *iter << endl;
    }

    return 0;
}