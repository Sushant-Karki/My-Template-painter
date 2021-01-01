#include "screen.h"
#include "template_class.h"
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string>
#include <cstring>
#include <cctype>
screen ss;

class point{
public:
    point():x{0},y{0},s{'\n'}{};    //default constructor
    point(point const & that):x{that.x}, y{that.y}, s{that.s}{};  //copy constructor
    point(point && that)noexcept: x{move(that.x)},y{move(that.y)},s{move(that.s)}{};   //move constructor
    point & operator = (point const & that);    //copy assignment
    point & operator = (point && that) noexcept;     //move assignment
    void set_xys(int x_value, int y_value, char s_value){
        x = x_value;
        y = y_value;
        s = s_value;
    }
    string get_xyz() {
        string value_xyz = "point x y s  =  point "+ to_string(x) +" "+ to_string(y) +" "+ s;
        return value_xyz; //
    }
    void draw() ;
    void info() ;
private:
    int x, y;
    char s;
};

point  & point::operator = (point const & that){
    this->x = that.x;
    this->y = that.y;
    this->s = that.s;
    return *this;
}

point & point::operator = (point && that) noexcept{
    x = move(that.x);
    y = move(that.y);
    s = move(that.s);
    return *this;
}

void point::draw(){
    ss.point(x,y,s);
}

void point::info(){
    cout<<"point x y s  =  point "<<x<<" "<<y<<" "<<s<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class line{
public:
    line():x{0},y{0},xp{0},yp{0},s{'\n'}{};    //default constructor
    line(line const & that):x{that.x},y{that.y},xp{that.xp},yp{that.yp},s{that.s}{};  //copy constructor
    line(line && that) noexcept: x{move(that.x)},y{move(that.y)},xp{move(that.xp)},yp{move(that.yp)},s{move(that.s)}{};   //move constructor
    line & operator = (line const & that);    //copy assignment
    line & operator = (line && that) noexcept;     //move assignment
    void set_xys(int x_value, int y_value,int xp_value, int yp_value, char s_value){
        x = x_value;
        y = y_value;
        xp = xp_value;
        yp = yp_value;
        s = s_value;
    }
    string get_xyz() {
        string value_xyz = "line x y xp yp s  =  line "+ to_string(x) +" "+ to_string(y) +" "+ to_string(xp) +" "+ to_string(yp) +" "+ s;
        return value_xyz;
    }
    void draw();
    void info();
private:
    int x, y, xp, yp;
    char s;
};

line  & line::operator = (line const & that){
    this->x = that.x;
    this->y = that.y;
    this->xp = that.xp;
    this->yp = that.yp;
    this->s = that.s;
    return *this;
}

line & line::operator = (line && that) noexcept{
    x = move(that.x);
    y = move(that.y);
    xp = move(that.xp);
    yp = move(that.yp);
    s = move(that.s);
    return *this;
}

void line::draw(){
    ss.line(x,y,xp,yp,s);
}

void line::info(){
    cout<<"line x y xp yp s  =  line "<<x<<" "<<y<<" "<<xp<<" "<<yp<<" "<<s<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class ellipse{
public:
    ellipse():xc{0},yc{0},rx{0},ry{0},s{'\n'}{};    //default constructor
    ellipse(ellipse const & that):xc{that.xc},yc{that.yc},rx{that.rx},ry{that.ry},s{that.s}{};  //copy constructor
    ellipse(ellipse && that) noexcept: xc{move(that.xc)},yc{move(that.yc)},rx{move(that.rx)},ry{move(that.ry)},s{move(that.s)}{};   //move constructor
    ellipse & operator = (ellipse const & that);    //copy assignment
    ellipse & operator = (ellipse && that) noexcept;     //move assignment
    void set_xys(int xc_value, int yc_value,int rx_value, int ry_value, char s_value){
        xc = xc_value;
        yc = yc_value;
        rx = rx_value;
        ry = ry_value;
        s = s_value;
    }
    string get_xyz() {
        string value_xyz = "ellipse xc yc rx ry s  =  ellipse "+ to_string(xc) +" "+ to_string(yc) +" "+ to_string(rx) +" "+ to_string(ry) +" "+ s;
        return value_xyz;
    }
    void draw();
    void info();
private:
    int xc, yc, rx, ry;
    char s;
};

ellipse  & ellipse::operator = (ellipse const & that){
    this->xc = that.xc;
    this->yc = that.yc;
    this->rx = that.rx;
    this->ry = that.ry;
    this->s = that.s;
    return *this;
}

ellipse & ellipse::operator = (ellipse && that) noexcept{
    xc = move(that.xc);
    yc = move(that.yc);
    rx = move(that.rx);
    ry = move(that.ry);
    s = move(that.s);
    return *this;
}

void ellipse::draw(){
    ss.ellipse(xc,yc,rx,ry,s);
}

void ellipse::info(){
    cout<<"ellipse xc yc rx ry s  =  ellipse "<<xc<<" "<<yc<<" "<<rx<<" "<<ry<<" "<<s<<endl;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class polygon{
public:
    polygon():x{0},y{0},n{0},l{0},s{'\n'}{};    //default constructor
    polygon(polygon const & that):x{that.x},y{that.y},n{that.n},l{that.l},s{that.s}{};  //copy constructor
    polygon(polygon && that) noexcept: x{move(that.x)},y{move(that.y)},n{move(that.n)},l{move(that.l)},s{move(that.s)}{};   //move constructor
    polygon & operator = (polygon const & that);    //copy assignment
    polygon & operator = (polygon && that) noexcept;     //move assignment
    void set_xys(int x_value, int y_value,int n_value, int l_value, char s_value){
        x = x_value;
        y = y_value;
        n = n_value;
        l = l_value;
        s = s_value;
    }
    string get_xyz() {
        string value_xyz = "polygon x y n l s  =  polygon "+ to_string(x) + " " + to_string(y) +" "+ to_string(n) +" "+ to_string(l) +" "+ s;
        return value_xyz;
    }
    void draw();
    void info();
private:
    int x, y, n, l;
    char s;
};

polygon  & polygon::operator = (polygon const & that){
    this->x = that.x;
    this->y = that.y;
    this->n = that.n;
    this->l = that.l;
    this->s = that.s;
    return *this;
}

polygon & polygon::operator = (polygon && that) noexcept{
    x = move(that.x);
    y = move(that.y);
    n = move(that.n);
    l = move(that.l);
    s = move(that.s);
    return *this;
}

void polygon::draw(){
    ss.polygon(x,y,n,l,s);
}

void polygon::info(){
    cout<<"polygon x y n l s  =  polygon "<<x<<" "<<y<<" "<<n<<" "<<l<<" "<<s<<endl;
}

int main(){
    bunch<point> point_stack;
    bunch<line> line_stack;
    bunch<ellipse> ellipse_stack;
    bunch<polygon> polygon_stack;

    int response, repeat=1;
    cout<<"!--- welcome to the program ---!"<<endl<<endl;

    int x,xp,xc,rx,y,yp,yc,ry,n,l;
    char s;

    while(repeat) {
        cout<<"Please choose one of the following shapes to draw"<<endl;
        cout<<"1. point, 2. line, 3. ellipse, 4. polygon ... , 5. to load the shapes from files"<<endl;
        cin>>response;
        switch (response) {
            case 1: {
                cout << "For a point, please input the x, y co-ordinates and a symbol" << endl;
                cin >> x >> y >> s;
                point p;
                p.set_xys(x,y,s);
                point_stack.insert_bunch(p);
                break;
            }
            case 2: {
                cout << "For a line, please input the x, y, xp, yp co-ordinates and a symbol" << endl;
                cin >> x >> y >> xp >> yp >> s;
                line li;
                li.set_xys(x, y, xp, yp, s);
                line_stack.insert_bunch(li);
                break;
            }
            case 3: {
                cout << "For a ellipse, please input the xc, yc, rx, ry co-ordinates and a symbol" << endl;
                cin >> xc >> yc >> rx >> ry >> s;
                ellipse el;
                el.set_xys(xc, yc, rx, ry, s);
                ellipse_stack.insert_bunch(el);
                break;
            }
            case 4: {
                cout << "For a polygon, please input the x, y, n ,l co-ordinates and a symbol" << endl;
                cin >> x >> y >> n >> l >> s;
                polygon po;
                po.set_xys(x, y, n, l, s);
                polygon_stack.insert_bunch(po);
                break;
            }
            case 5: {
                char read_file_name[10];
                char package[100];
                cout << "Which file do you want to read from ?" << endl;
                cin >> read_file_name;
                char location[100];
                sprintf(location, "%s%s%s", "C:\\Users\\omsus\\CLionProjects\\Graphics_project\\", read_file_name,
                        ".txt");
                FILE *read_file = fopen(location,"r");
                fgets(package,60,read_file);
                cout<<package<<endl;
                while (strcmp(package, "\n") != 0) {
                    switch (package[3]) {
                        case 'n': {
                            point p_read;
                            for (int i = 0; i <= 21; i++) {
                                package[i] = ' ';
                            }

                            int x_read = stoi(strtok(package, " "));
                            int y_read = stoi(strtok(NULL, " "));
                            char *s_read = strtok(NULL, " ");
                            p_read.set_xys(x_read, y_read, *s_read);

                            point_stack.insert_bunch(p_read);
                            break;
                        }
                        case 'e': {
                            line l_read;
                            for (int i = 0; i <= 25; i++) {
                                package[i] = ' ';
                            }

                            int x_read = stoi(strtok(package, " "));
                            int y_read = stoi(strtok(NULL, " "));
                            int xp_read = stoi(strtok(NULL, " "));
                            int yp_read = stoi(strtok(NULL, " "));
                            char *s_read = strtok(NULL, " ");
                            l_read.set_xys(x_read, y_read, xp_read, yp_read, *s_read);

                            line_stack.insert_bunch(l_read);
                            break;
                        }
                        case 'i': {
                            ellipse e_read;
                            for (int i = 0; i <= 33; i++) {
                                package[i] = ' ';
                            }

                            int xc_read = stoi(strtok(package, " "));
                            int yc_read = stoi(strtok(NULL, " "));
                            int rx_read = stoi(strtok(NULL, " "));
                            int ry_read = stoi(strtok(NULL, " "));
                            char *s_read = strtok(NULL, " ");
                            e_read.set_xys(xc_read, yc_read, rx_read, ry_read, *s_read);

                            ellipse_stack.insert_bunch(e_read);
                            break;
                        }
                        case 'y': {
                            polygon po_read;
                            for (int i = 0; i <= 29; i++) {
                                package[i] = ' ';
                            }

                            int x_read = stoi(strtok(package, " "));
                            int y_read = stoi(strtok(NULL, " "));
                            int n_read = stoi(strtok(NULL, " "));
                            int l_read = stoi(strtok(NULL, " "));
                            char *s_read = strtok(NULL, " ");
                            po_read.set_xys(x_read, y_read, n_read, l_read, *s_read);

                            polygon_stack.insert_bunch(po_read);
                            break;
                        }
                    }
                    fgets(package,60,read_file);
                }
                break;
            }
            default: {
                cout << "invalid input" << endl;
            }
        }
        cout<<"List of shapes: "<<endl;
        point_stack.print_info();
        line_stack.print_info();
        ellipse_stack.print_info();
        polygon_stack.print_info();
        cout<<"Would you like to add another shape?  0. No, 1. Yes"<<endl;
        cin>>repeat;
    }
    response = 0;
    int response_index = 0;
    cout<<"You have Successfully added your shapes, select one of the following options to draw the shapes."<<endl;
    cout<<"TO paint the shape of a certain type select: 1. point, 2. line, 3. ellipse, 4. polygon .. else select 5 for paint shapes of all types"<<endl;
    cin>>response;

    switch(response){
        case 1:{
            cout<<"you have selected to paint point, please provide an index to paint the point. To print all of the points, enter the number of points"<<endl;
            cin>>response_index;
            if(response_index == point_stack.check_size()){
                point_stack.paint_all();
            }
            else{
                point_stack.paint(response);
            }
            break;
        }
        case 2:{
            cout<<"you have selected to paint line, please provide an index to paint the line. To print all of the lines, enter the number of lines"<<endl;
            cin>>response_index;
            if(response_index == line_stack.check_size()){
                line_stack.paint_all();
            }
            else{
                line_stack.paint(response);
            }
            break;
        }
        case 3:{
            cout<<"you have selected to paint ellipse, please provide an index to paint the ellipse. To print all of the ellipses, enter the number of ellipses"<<endl;
            cin>>response_index;
            if(response_index == ellipse_stack.check_size()){
                ellipse_stack.paint_all();
            }
            else{
                ellipse_stack.paint(response);
            }
            break;
        }
        case 4:{
            cout<<"you have selected to paint polygon, please provide an index to paint the polygon. To print all of the polygons, enter the number of polygons"<<endl;
            cin>>response_index;
            if(response_index == polygon_stack.check_size()){
                polygon_stack.paint_all();
            }
            else{
                polygon_stack.paint(response);
            }
            break;
        }
        case 5:{
            point_stack.paint_all();
            line_stack.paint_all();
            ellipse_stack.paint_all();
            polygon_stack.paint_all();
        }
            break;
    }
    ss.display();

    cout<<"Would you like to save this painting in a file ? 0. No 1. Yes"<<endl;
    cin>>response;

    if(response){
        cout<<"Name your painting"<<endl;
        char name[10];
        cin>>name;
        point_stack.store_data(name);
        line_stack.store_data(name);
        ellipse_stack.store_data(name);
        polygon_stack.store_data(name);
    }
}