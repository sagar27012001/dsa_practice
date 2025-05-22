#include <bits/stdc++.h>
using namespace std;

class Vector {
  private:
    int *arr;
    int curr, limit;

  public:
    Vector() {
        arr = new int[1];
        curr = 0;
        limit = 1;
    }

    void push(int ele) {
        if (curr == limit) {
            limit = 2 * curr + 1;
            int *copy = new int[limit];
            for (int i=0; i<curr; i++) {
                *(copy + i) = *(arr + i);
            }
            delete[] arr;
            arr = copy;
        }
        *(arr + curr) = ele;
        curr++;
    }

    void print() {
        for (int i=0; i<curr; i++) {
            cout << *(arr + i) << " ";
        }
        cout << endl;
    }

    void pop() {
        curr--;
    }

    int size() {
        return curr;
    }

    int back() {
        return *(arr + curr - 1);
    }

    ~Vector() {
        delete[] arr;
        cout << "memory freed\n";
    }
};


int main() {
    Vector vec;

    vec.push(10);
    vec.push(20);
    vec.push(30);
    vec.print();
    cout << "size " << vec.size() << endl;
    cout << "Back element " << vec.back() << endl;
    vec.pop();
    vec.print();
    cout << "size " << vec.size() << endl;
    cout << "Back element " << vec.back() << endl;
    return 0;
}