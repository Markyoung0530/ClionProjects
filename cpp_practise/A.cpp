//
// Created by 杨淦 on 2020/2/14.
//

#include "A.h"
#include <iostream>
using namespace std;
A::A() {
    cout << "A::A();i = " << i << endl;
}

A::~A() {
    cout << "A::~A();i = " << i << endl;
}

void A::set(int _i) {
    this->i = _i;
}
