#include <iostream>
#include <memory>
using namespace std;
#define _CRT  DBG_MAP_ALLOC
#include <stdlib.h>
// #include <crtdbg.h>

template<typename T>
class smart_ptr
{
public:
    smart_ptr(T* ptr = nullptr) : _ptr{ ptr }  {}
    smart_ptr(const smart_ptr&) = delete;
    smart_ptr& operator = (const smart_ptr&) = delete;

    ~smart_ptr() { if (_ptr) delete _ptr;  }

    T& operator * () { return *_ptr; }
    T* operator & () { return  _ptr; }
    T* operator -> () { return  _ptr; }

    T* get() { return _ptr; }

private:
    T* _ptr{};
};

int main() {
    int a[] = { 1,2,3,4,5 };

    int* p = a;

    p++;
    p++;
    p--;
    p = p + 10;

    int* ptHeap = new int;
    cout << ptHeap << endl;
    cout << *ptHeap << endl;

    delete ptHeap;

    {
        smart_ptr<int> sp(new int { 5 });
        // smart_ptr<int> spc(sp); // err: value deleted
        unique_ptr<int> up(new int { 10 });
    }
    // _CrtDumpMemoryLeaks();
}