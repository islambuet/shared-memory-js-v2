#include <node.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <tchar.h>
#include <iostream>
#include "Array01.h"
#include "Array02.h"
using namespace std;
using namespace v8;

  #define BUF_SIZE 256
  TCHAR memory1_key[] = TEXT("MEMORY1");
  TCHAR memory2_key[] = TEXT("MEMORY2");

  HANDLE handle1;
  LPCTSTR pMemory1;

  HANDLE handle2;
  LPCTSTR pMemory2;

  struct MyStruct
    {
        int a, b, c;

    };


  HANDLE CreateHandle(TCHAR key[]) {
    HANDLE hMapFile = CreateFileMapping(
        INVALID_HANDLE_VALUE,    // use paging file
        NULL,                    // default security
        PAGE_READWRITE,          // read/write access
        0,                       // maximum object size (high-order DWORD)
        BUF_SIZE,                // maximum object size (low-order DWORD)
        key);                 // name of mapping object

    return hMapFile;
  }
  LPCTSTR getHandleMemory(HANDLE handle) {    
    LPCTSTR pMemory = (LPTSTR)MapViewOfFile(handle,   // handle to map object
        FILE_MAP_ALL_ACCESS, // read/write permission
        0,
        0,
        BUF_SIZE);
    if (pMemory == NULL)
    {
        CloseHandle(handle);        
    }
    return pMemory;
  }
  void InitiateMemory(const FunctionCallbackInfo<Value>& args) { 
    handle1 = CreateHandle(memory1_key);
    pMemory1 = getHandleMemory(handle1);

    handle2 = CreateHandle(memory2_key);
    pMemory2 = getHandleMemory(handle2);    
  }
  // void writeArray01(LPCTSTR pMemory, DataArray01 dataArray01) {
  //   CopyMemory((PVOID)pMemory, &dataArray01, sizeof(dataArray01));
  // }
  // DataArray01 readArray01(LPCTSTR pMemory) {
  //     DataArray01 dataArray01;
  //     memcpy(&dataArray01, pMemory, sizeof(dataArray01));    
  //     return dataArray01;
  // }

  // void writeArray02(LPCTSTR pMemory, DataArray02 dataArray02) {
  //     CopyMemory((PVOID)pMemory, &dataArray02, sizeof(dataArray02));
  // }
  // DataArray02 readArray02(LPCTSTR pMemory) {
  //     DataArray02 dataArray02;
  //     memcpy(&dataArray02, pMemory, sizeof(dataArray02));
  //     return dataArray02;
  // }

  void WriteArray01(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    Local<Object> array01Obj= Local<Object>::Cast(args[0]);
    StructureArray01 array01=getStructureArray01FromObject(isolate,context,array01Obj);   
    CopyMemory((PVOID)pMemory1, &array01, sizeof(array01)); 
    args.GetReturnValue().Set(1);
  }
  void ReadArray02(const FunctionCallbackInfo<Value>& args) {

    Isolate* isolate = args.GetIsolate();
    Local<Context> context = isolate->GetCurrentContext();
    StructureArray02 array02;
    memcpy(&array02, pMemory2, sizeof(array02));
    //array02=getArray02();
    Local<Object> array02Obj=getObjectFromStructureArray02(isolate,context,array02); 
    args.GetReturnValue().Set(array02Obj);    
  }
  void Getch(const FunctionCallbackInfo<Value>& args) {
    cout<<"Press key..";
    _getch();
  }
  void Init(Local<Object> exports) {
    NODE_SET_METHOD(exports, "initiateMemory", InitiateMemory);
    NODE_SET_METHOD(exports, "writeArray01", WriteArray01);
    NODE_SET_METHOD(exports, "readArray02", ReadArray02);    
    NODE_SET_METHOD(exports, "getch", Getch);    
  }
NODE_MODULE(NODE_GYP_MODULE_NAME, Init)