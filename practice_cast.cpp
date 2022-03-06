#include <iostream>
#include <vector>
#include <string>

void aFunction(uint32_t* a)
{
    std::cout << *a << std::endl;
}

struct mystruct {
    int x;
    int y;
    char c;
    bool b;
};

int main()
{
    uint32_t value[] = {100,101,102,103,104};
    uint32_t* p = (uint32_t*)&value[0];
    
    std::cout << "pointer size: " << sizeof(p) << std::endl;
    
    std::cout << p << " -> " << *p << std::endl;
    
    p = p + 1; 
    
    std::cout << p << " -> " << *p << std::endl;
    
    //uint64_t address = p; // <-  error: invalid conversion from ‘uint32_t*’ 
    //  {aka ‘unsigned int*’} to ‘uint64_t’ {aka ‘long unsigned int’} [-fpermissive]
  
    //==========================================================================
  
    std::cout << "=======region 1=====================" << std::endl;
  
    uint32_t* p2 = std::addressof(value[0]);
    
    std::cout << p2 << " -> " << *p2 << std::endl;
    
    p2 = p2 + 1; 
    
    std::cout << p2 << " -> " << *p2 << std::endl;
    
    //==========================================================================

    unsigned long address = (unsigned long)&value[0]; //64-bit compiler
    
    std::cout << "0x" <<std::hex << address << " -> " << *(int*)address << std::endl;
    
    //but for 32 or 64 compiler
    
    uintptr_t ptr = (uintptr_t)&value[0];
    
    std::cout << "0x" <<std::hex << ptr << " -> " << *(int*)ptr << std::endl;
    
   //==========================================================================
   //static_cast operator can also convert between related pointer types.
    
    std::cout << "=======region 2=====================" << std::endl;
    
    uint32_t value2 = 10;
    float fl = static_cast<float>(value2);
    
    std::cout << std::to_string(fl) << std::endl;
    
    uint32_t* pValue2 = &value2;
    float* pFl = &fl;
    
    //float* resultFloat = static_cast<float*>(pValue2);
    
    std::cout << "sizeof float* -> " << sizeof(pFl) << std::endl;
    std::cout << "sizeof unsigned int* -> " << sizeof(pValue2) << std::endl;
    
    std::cout << "sizeof float  -> " << sizeof(float) << std::endl;
    std::cout << "sizeof unsigned int  -> " << sizeof(uint32_t) << std::endl;
    
    std::cout << std::to_string(*pFl) << std::endl;
    
    //==========================================================================
    
    uint32_t a = 10;
    const uint32_t* var = &a;
    
    //aFunction(var); // <- error: invalid conversion from ‘const uint32_t*’ 
    // {aka ‘const unsigned int*’} to ‘uint32_t*’ {aka ‘unsigned int*’} [-fpermissive]
    
    aFunction( const_cast<uint32_t*>(var)); 
    
    //==========================================================================
    
    uint32_t* testVal = new uint32_t(10);
    
    float* fTest = reinterpret_cast<float*>(testVal);
    
    std::cout << std::to_string(*testVal) << " " <<"reinterpret_cast -> " 
    << std::to_string(*fTest) << std::endl;
    
    delete testVal;
    
    //========================================================================== 
    
    mystruct testStruct;
    
    testStruct.x = 0x41; //'A'
    testStruct.y = 10;
    testStruct.c = 'a';
    testStruct.b = true;
    
    uint8_t* p33 = reinterpret_cast<uint8_t*>(&testStruct);
 
    std::cout << *p33 << std::endl;
    
    uint8_t testArr[4] = {0x7e,0xe4,0x40,0x46}; // float 12345.12345 0x4640e47e
    
    float* p44 = reinterpret_cast<float*>(&testArr);
    
    std::cout << std::to_string(*p44) << std::endl;
    
    
    return 0;
}




























