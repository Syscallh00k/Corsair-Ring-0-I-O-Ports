#ifndef Corsair_STRUCTS_H
#define Corsair_STRUCTS_H
namespace Corsair {
    struct CorsairLLInterface {
        int (*GetVersion)(DWORD* outBuffer);
        DWORD(*InstallDriver)();
        DWORD(*UninstallDriver)();
        DWORD(*OpenDevice)();
        BOOL(*CloseDevice)();
        uintptr_t(*unknown_one)();
        uintptr_t(*unknown_two)();
        uintptr_t(*PhysMem)(int, int, int, int, LPVOID, int);
        uintptr_t(*unknown_three)();
        uintptr_t(*unknown_four)();
        uintptr_t(*unknown_five)();
        BOOL(*WritePortByte)(int port, unsigned __int8 value);
        BOOL(*ReadPortByte)(int port, void* outBuffer);
        BOOL(*WritePortWord)(int port, unsigned __int16 value);
        BOOL(*ReadPortWord)(int port, void* outBuffer);
        BOOL(*WritePortDword)(int port, int value);
        BOOL(*ReadPortDword)(int port, void* outBuffer);
        uintptr_t garbage[44];
    };
}
#endif // Corsair_STRUCTS_H