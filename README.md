# Corsair-Ring-0-I-O-Ports


# CorsairLLAccessLib64.dll
**16 Bit Write**
```
bool __fastcall sub_18000C040(int a1, unsigned __int16 a2)
{
  DWORD BytesReturned; // [rsp+40h] [rbp-28h] BYREF
  int InBuffer[2]; // [rsp+48h] [rbp-20h] BYREF
  __int16 v5; // [rsp+50h] [rbp-18h]

  if ( hDevice == (HANDLE)-1LL )
  {
    SetLastError(0x139Fu);
    return 0;
  }
  else
  {
    InBuffer[0] = a1;
    InBuffer[1] = a2;
    v5 = 2;
    BytesReturned = 0;
    return DeviceIoControl(hDevice, 0x229354u, InBuffer, 0xAu, 0LL, 0, &BytesReturned, 0LL);
  }
}
```

**32 Bit Write**
```
bool __fastcall sub_18000C180(int a1, int a2)
{
  DWORD BytesReturned; // [rsp+40h] [rbp-28h] BYREF
  int InBuffer[2]; // [rsp+48h] [rbp-20h] BYREF
  __int16 v5; // [rsp+50h] [rbp-18h]

  if ( hDevice == (HANDLE)-1LL )
  {
    SetLastError(0x139Fu);
    return 0;
  }
  else
  {
    InBuffer[0] = a1;
    InBuffer[1] = a2;
    v5 = 4;
    BytesReturned = 0;
    return DeviceIoControl(hDevice, 0x229354u, InBuffer, 0xAu, 0LL, 0, &BytesReturned, 0LL);
  }
}
```

**16 Bit Read**
```
bool __fastcall sub_18000C0E0(int a1, void *lpOutBuffer)
{
  DWORD BytesReturned; // [rsp+40h] [rbp-28h] BYREF
  int InBuffer[2]; // [rsp+48h] [rbp-20h] BYREF
  __int16 v5; // [rsp+50h] [rbp-18h]
  if ( hDevice == (HANDLE)-1LL )
  {
    SetLastError(0x139Fu);
    return 0;
  }
  else
  {
    InBuffer[0] = a1;
    v5 = 2;
    InBuffer[1] = 0;
    BytesReturned = 0;
    return DeviceIoControl(hDevice, 0x225358u, InBuffer, 0xAu, lpOutBuffer, 2u, &BytesReturned, 0LL);
  }
}
```

**32 Bit Read**
```
bool __fastcall sub_18000C220(int a1, void *lpOutBuffer)
{
  DWORD BytesReturned; // [rsp+40h] [rbp-28h] BYREF
  int InBuffer[2]; // [rsp+48h] [rbp-20h] BYREF
  __int16 v5; // [rsp+50h] [rbp-18h]
  if ( hDevice == (HANDLE)-1LL )
  {
    SetLastError(0x139Fu);
    return 0;
  }
  else
  {
    InBuffer[0] = a1;
    v5 = 4;
    InBuffer[1] = 0;
    BytesReturned = 0;
    return DeviceIoControl(hDevice, 0x225358u, InBuffer, 0xAu, lpOutBuffer, 4u, &BytesReturned, 0LL);
  }
}
```
