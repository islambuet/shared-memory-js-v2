#pragma once
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
using namespace std;
using namespace v8;
struct StructureArray01
{
    unsigned int ulong_msCounter;
    unsigned int ulong_Encoder;
    unsigned int ulong_Encoder2;
    unsigned int ulong_Encoder3;
    unsigned int ulong_PLCStatus;
    unsigned int ulong_Data[40];
    unsigned int ulong_DeviceConnected[2];

};

StructureArray01 getArray01() {

    StructureArray01 dataArray01;

    dataArray01.ulong_msCounter = 34320540;
    dataArray01.ulong_Encoder = 1;
    dataArray01.ulong_Encoder2 = 2;
    dataArray01.ulong_Encoder3 = 3;
    dataArray01.ulong_PLCStatus = 4;
    
    unsigned int temp_ulong_Data[40] = {
        5, 6, 7, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 8, 9, 10
    };
    memcpy(dataArray01.ulong_Data, temp_ulong_Data, sizeof(unsigned int) * 40);
    
    unsigned int temp_ulong_DeviceConnected[2] = {
        11, 12
    };
    memcpy(dataArray01.ulong_DeviceConnected, temp_ulong_DeviceConnected, sizeof(unsigned int) * 2);
    return dataArray01;


}
ostream& operator<<(ostream& os, const StructureArray01 da) {
    os << "{" << endl;
    os << " ulong_msCounter: " << da.ulong_msCounter << endl;
    os << " ulong_Encoder: " << da.ulong_Encoder << endl;
    os << " ulong_Encoder2: " << da.ulong_Encoder2 << endl;
    os << " ulong_Encoder3: " << da.ulong_Encoder3 << endl;
    os << " ulong_PLCStatus: " << da.ulong_PLCStatus << endl;
    os  <<  "ulong_Data: ";
    for (int i = 0; i < 40; i++)
        printf("%d ", da.ulong_Data[i]);
    os << endl;
    os  <<  "ulong_DeviceConnected: ";
    for (int i = 0; i < 2; i++)
        printf("%d ", da.ulong_DeviceConnected[i]);
    os << endl;    
    os << "}" << endl;
    return os;
}
StructureArray01 getStructureArray01FromObject(Isolate* isolate,Local<Context> context,Local<Object> obj){
    StructureArray01 array_01;
    array_01.ulong_msCounter=obj->Get(context, String::NewFromUtf8(isolate,"ulong_msCounter").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_Encoder=obj->Get(context, String::NewFromUtf8(isolate,"ulong_Encoder").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_Encoder2=obj->Get(context, String::NewFromUtf8(isolate,"ulong_Encoder2").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_Encoder3=obj->Get(context, String::NewFromUtf8(isolate,"ulong_Encoder3").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    array_01.ulong_PLCStatus=obj->Get(context, String::NewFromUtf8(isolate,"ulong_PLCStatus").ToLocalChecked()).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();

    Local<Array> ulong_Data=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"ulong_Data").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<40;i++){
        array_01.ulong_Data[i]=ulong_Data->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }
    Local<Array> ulong_DeviceConnected=Local<Array>::Cast(obj->Get(context, String::NewFromUtf8(isolate,"ulong_DeviceConnected").ToLocalChecked()).ToLocalChecked());
    for(int i=0;i<2;i++){
        array_01.ulong_DeviceConnected[i]=ulong_DeviceConnected->Get(context, i).ToLocalChecked()->ToNumber(context).ToLocalChecked()->Value();
    }
    
    return array_01;

}
//
// {
//   ulong_msCounter: 34320540,
//   ulong_Encoder: 0,
//   ulong_Encoder2: 0,
//   ulong_Encoder3: 0,
//   ulong_PLCStatus: 0,
//   ulong_Data: [
//     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//     0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
//     0, 0, 0, 0, 0, 0, 0, 0, 0, 0
//   ],
//   ulong_DeviceConnected: [ 0, 0 ]
// }
