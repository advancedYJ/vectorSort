#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class K {
public:
    static double Tt;
};

class Foo{
public:
    double x, y;
    static double x_abs_value;
    Foo(double x, double y){
        this->x = x;
        this->y = y;
    }

    bool operator<(const Foo &bar){
        if (this->x < bar.x)
            return 1;
        else if (this->x == bar.x && this->y <= bar.y)
            return 1;
        return 0;
    }

    bool static decrease(const Foo &foo1, const Foo &foo2){
        if (foo1.x > foo2.x)
            return 1;
        else if (foo1.x == foo2.x)
            return foo1.y >= foo2.y;
        return 0;
    }

    bool static dist_abs(const Foo &foo1, const Foo &foo2){
        double f1 = abs(foo1.x - K::Tt), f2 = abs(foo2.x - K::Tt);
        if (f1 > f2)
            return 1;
        else if (f1 == f2)
            return f1 >= f2;
        return 0;
    }

    friend inline ostream &operator<<(ostream &out, Foo & foo){
        out << foo.x << " " << foo.y << endl;
        return out;
    }
};

double K::Tt = 0;

int main() {
    vector<Foo> myVec;
    for (int i = 0; i < 5; i++){
        Foo f(0, 0);
        cin >> f.x >> f.y;
        myVec.push_back(f);
    }
    printf("increase : \n");
    sort(myVec.begin(), myVec.end());
    for (Foo &foo : myVec)
        cout << foo;

    printf("\n decrease : \n");
    sort(myVec.begin(), myVec.end(), Foo::decrease);
    for (Foo &foo : myVec)
        cout << foo;

    printf("\n abs : \n");
    K::Tt = 3;
    sort(myVec.begin(), myVec.end(), Foo::dist_abs);
    for (Foo &foo : myVec)
        cout << foo;
    return 0;
}