#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace std;
template <class t>
class bunch{
private:
    t data[36];
    int top = 0;
    int number_of_items = 0;
public:
    bunch()= default;    // default constructor
    bunch(const bunch& that){       // copy constructor
        t data[36];
        for(int i= 0; i< 36; i++) {
            data[i] = that.data[i];
        }
    }
    bunch & operator = (const bunch& that){   // copy assignment
        if(that == this){
            return *this;
        }
        t data[36];
        for(int i=0; i<36;i++){
            data[i] = that.data[i];
        }
        return *this;
    }
    bunch(const bunch&& that)noexcept{       // move constructor
        for(int i= 0; i< 36; i++) {
            data[i] = move(that.data[i]);
        }
    }
    bunch & operator = (bunch && that) noexcept{  // move assignment
        for(int i= 0; i< 36; i++) {
            data[i] = move(that.data[i]);
        }
        that.data = nullptr;
        return *this;
    }
  ~bunch()= default;                           // destructor
    void insert_bunch(t item);
    void print_info();
    void paint_all();
    void paint(int index);
    int is_empty();
    void delete_data();
    int check_size();
    void store_data(char name[]);

};
template <class t>
void bunch<t>::insert_bunch(t item){
    data[top] = item;
    top++;
    number_of_items++;
}
template <class t>
int bunch<t>::is_empty(){
    if(top == 0){
        return 1;
    }
    else{
        return 0;
    }
}
template <class t>
void bunch<t>::delete_data() {
    if (!is_empty()){
        data[top] = nullptr;
        top--;
        number_of_items--;
    }
}
template <class t>
void bunch<t>::print_info() {
    for(int i = 0; i < top; i++) {
        data[i].info();
    }
}

template <class t>
void bunch<t>::paint_all(){
    for(int i = 0; i <= top; i++){
        data[i].draw();
    }
}

template <class t>
int bunch<t>::check_size() {
    return number_of_items;
}

template <class t>
void bunch<t>::paint(int index){
    data[index].draw();
}

template <class t>
void bunch<t>::store_data(char name[]){
    char location[100];
    sprintf(location,"%s%s%s","C:\\Users\\omsus\\CLionProjects\\Graphics_project\\",name,".txt");
    ofstream store_file;
    store_file.open(location,ios::app);
    for(int i = 0; i < top; i++) {
      store_file << data[i].get_xyz()<<endl;
    }
    store_file.close();
}