#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
using namespace v8;
struct StructureArray02
{
    unsigned int ulong_CMAlive;
    unsigned int ulong_Mode;
    unsigned int ulong_State;
    unsigned int ulong_CMStatus;
    unsigned int ulong_OupputState[40];
};

StructureArray02 getArray02() {

    StructureArray02 dataArray02;

    dataArray02.ulong_CMAlive = 500;
    dataArray02.ulong_Mode = 1;
    dataArray02.ulong_State = 2;
    dataArray02.ulong_CMStatus = 3;
    
    unsigned int temp_ulong_OupputState[40] = {
        50, 48, 50, 49, 45, 48, 56, 45,
        50, 51, 84, 48, 50, 58, 49, 56,
        58, 50, 51, 46, 54, 54, 48, 90,
        50, 51, 84, 48, 50, 58, 49, 56,
        50, 51, 84, 48, 50, 58, 49, 56
    };
    memcpy(dataArray02.ulong_OupputState, temp_ulong_OupputState, sizeof(unsigned int) * 40);
    
    return dataArray02;
}
ostream& operator<<(ostream& os, const StructureArray02 da) {
    os << "{" << endl;
    os << " ulong_CMAlive: " << da.ulong_CMAlive << endl;
    os << " ulong_Mode: " << da.ulong_Mode << endl;
    os << " ulong_State: " << da.ulong_State << endl;
    os << " ulong_CMStatus: " << da.ulong_CMStatus << endl;

    os << " ulong_OupputState: ";
    for (int i = 0; i < 40; i++)
        printf("%d ", da.ulong_OupputState[i]);
    os << endl;

    os << "}" << endl;
    return os;
}
Local<Object> getObjectFromStructureArray02(Isolate* isolate,Local<Context> context,StructureArray02 array02){
    
    Local<Object> obj = Object::New(isolate);
    obj->Set(context,String::NewFromUtf8(isolate,"ulong_CMAlive").ToLocalChecked(),Number::New(isolate, array02.ulong_CMAlive));
    obj->Set(context,String::NewFromUtf8(isolate,"ulong_Mode").ToLocalChecked(),Number::New(isolate, array02.ulong_Mode));
    obj->Set(context,String::NewFromUtf8(isolate,"ulong_State").ToLocalChecked(),Number::New(isolate, array02.ulong_State));
    obj->Set(context,String::NewFromUtf8(isolate,"ulong_CMStatus").ToLocalChecked(),Number::New(isolate, array02.ulong_CMStatus));    

    Local<Array> ulong_OupputState=Array::New(isolate,40);for(int i=0;i<40;i++){ulong_OupputState->Set(context,i, Integer::New(isolate,array02.ulong_OupputState[i]));}obj->Set(context,String::NewFromUtf8(isolate,"ulong_OupputState").ToLocalChecked(),ulong_OupputState);
    
    return obj;
}

// {
//   ulong_CMAlive: 500,
//   ulong_Mode: 1,
//   ulong_State: 2,
//   ulong_CMStatus: 3,
//   ulong_OutputState: [
//     50, 48, 50, 49, 45, 48, 56, 45, 50, 51,
//     84, 48, 50, 58, 49, 56, 58, 50, 51, 46,
//     54, 54, 48, 90, 50, 51, 84, 48, 50, 58,
//     49, 56, 50, 51, 84, 48, 50, 58, 49, 56
//   ]
// }