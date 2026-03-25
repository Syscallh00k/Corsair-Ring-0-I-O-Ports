# Corsair-Ring-0-I-O-Ports

# CorsairLLAccess64.sys
**IO Port Function**
```
__int64 __fastcall sub_140001FFC(__int64 a1, char a2, unsigned int a3, unsigned int a4, _QWORD *a5)
{
  unsigned int v5; // r8d
  unsigned int v6; // r8d
  unsigned int v7; // r8d
  unsigned int v8; // r8d
  unsigned int v9; // r8d
  unsigned __int32 v11; // eax
  unsigned __int16 v12; // ax
  unsigned __int8 v13; // al

  if ( a3 >= 0xA )
  {
    v5 = *(unsigned __int16 *)(a1 + 8);
    if ( a2 )
    {
      v6 = v5 - 1;
      if ( !v6 )
      {
        __outbyte(*(_DWORD *)a1, *(_BYTE *)(a1 + 4));
        goto LABEL_17;
      }
      v7 = v6 - 1;
      if ( !v7 )
      {
        __outword(*(_DWORD *)a1, *(_WORD *)(a1 + 4));
        goto LABEL_17;
      }
      if ( v7 == 2 )
      {
        __outdword(*(_DWORD *)a1, *(_DWORD *)(a1 + 4));
LABEL_17:
        *a5 = *(unsigned __int16 *)(a1 + 8);
        return 0LL;
      }
      return 3221225485LL;
    }
    if ( a4 >= v5 )
    {
      v8 = v5 - 1;
      if ( !v8 )
      {
        v13 = __inbyte(*(_DWORD *)a1);
        *(_BYTE *)a1 = v13;
        goto LABEL_17;
      }
      v9 = v8 - 1;
      if ( !v9 )
      {
        v12 = __inword(*(_DWORD *)a1);
        *(_WORD *)a1 = v12;
        goto LABEL_17;
      }
      if ( v9 == 2 )
      {
        v11 = __indword(*(_DWORD *)a1);
        *(_DWORD *)a1 = v11;
        goto LABEL_17;
      }
      return 3221225485LL;
    }
  }
  return 3221225507LL;
}
```

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
