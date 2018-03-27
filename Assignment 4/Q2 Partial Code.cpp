#include <iostream>

using namespace std;

class Man
{
public:
    Man(int v = 0) : Value(v) { cout << "Constructor: " << Value << endl; }
    ~Man() { cout << "Destructor: " << Value << endl; }
    void setMan(double v) { Value = v; }
private:
    int Value;
};

int mai()
{
    auto_ptr<Man> ptr(new Man(10));
    (*ptr).setMan(15);
    return 0;
}
