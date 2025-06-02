#define _DEBUG
#define UNICODE
#define _UNICODE

#include <stdio.h>
#include <winsock2.h>
#include <iphlpapi.h>
#include <icmpapi.h>
#define name2str(v) #v
#define PING_MESSAGE "1234567890"

DWORD dwError;
HANDLE hStdout;

void init() {
    hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
}

LPTSTR getFormatMessageBuffer(DWORD WinErrorCode) {
    LPTSTR buffer;
    DWORD iFMResult = FormatMessage(
        FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
        NULL,
        WinErrorCode,
        MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
        (LPTSTR)&buffer,
        NULL,
        NULL
    );
    if (iFMResult == 0) {
        dwError = GetLastError();
        if (dwError == ERROR_MORE_DATA) {
            UINT factor = 2U;
            while (dwError != ERROR_MORE_DATA) {
                buffer = (LPTSTR)LocalAlloc(LMEM_FIXED, 128U * 1024U * factor);
                if (buffer == NULL) {
                    dwError = GetLastError();
                    if (dwError == ERROR_NOT_ENOUGH_MEMORY) {
                        return NULL;
                    }
                    factor++;
                }
            }
            iFMResult = FormatMessage(
                FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS,
                NULL,
                WinErrorCode,
                MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
                (LPTSTR)&buffer,
                LocalSize(buffer) / sizeof(TCHAR),
                NULL
            );
        } else {
            return NULL;
        }
    }
    return buffer;
}

int ping(LPCTSTR str) {
    HANDLE hIcmpFile;
    ULONG32 ipaddr;
    LPVOID replyBuffer;
    DWORD replySize;
    DWORD dwRetVal;
    static LPCTSTR sendData = PING_MESSAGE;

    ipaddr = INADDR_NONE;
    replyBuffer = NULL;
    replySize = 0;

    ipaddr = inet_addr(str);
    if (ipaddr == INADDR_NONE) {
        printf("Failed to parse IP address.");
        return 1;
    }

    hIcmpFile = IcmpCreateFile();
    if (hIcmpFile == INVALID_HANDLE_VALUE) {
        printf("Unable to open handle.\nIcmpCreateFile returned error: ");
        dwError = GetLastError();
        LPTSTR errMsg = getFormatMessageBuffer(dwError);
        if (errMsg == NULL) {
            printf("0x%02X", dwError);
        } else {
            WriteConsole(hStdout, errMsg, lstrlen(errMsg), NULL, NULL);
            LocalFree(errMsg);
        }
        putchar('\n');
        return 1;
    }

    replySize = sizeof(ICMP_ECHO_REPLY) + sizeof(sendData);
    replyBuffer = (LPVOID)HeapAlloc(GetProcessHeap(), 0x00000000, replySize);
    if (replyBuffer == NULL) {
        printf("Unable to allocate memory\n");
        return 1;
    }

    FILETIME fileTime;
    // GetSystemTimeAsFileTime(lpFileTime);
    GetSystemTimePreciseAsFileTime(&fileTime);
    dwRetVal = IcmpSendEcho(hIcmpFile, ipaddr,
        sendData, sizeof(sendData), NULL,
        replyBuffer, replySize,
        1000
    );

    if (dwRetVal != 0) {
        PICMP_ECHO_REPLY pIcmpEchoReply = (PICMP_ECHO_REPLY)replyBuffer;
        IN_ADDR replyAddr;
        replyAddr.s_addr = pIcmpEchoReply->Address;
        printf("\tSent icmp message to %s at %lld\n", str,
            ((LONGLONG)fileTime.dwLowDateTime || ((LONGLONG)fileTime.dwHighDateTime << (sizeof(DWORD) * CHAR_BIT)))
        );
        printf("\tReceived %ld icmp message response", dwRetVal);
        if (dwRetVal > 1) {
            putchar('s');
        }
        printf("\nInformation fron the ");
        if (dwRetVal > 1) {
            printf("first response");
        } else {
            printf("response");
        }
        puts(":");
        printf("\t  Received from %s\n", inet_ntoa(replyAddr));
        printf("\t  Status = %ld\n", pIcmpEchoReply->Status);
        printf("\t  Roundtrip time = %ld milliseconds\n", pIcmpEchoReply->RoundTripTime);
    } else {
        dwError = GetLastError();
        LPTSTR errMsg = getFormatMessageBuffer(dwError);
        printf("\tCall IcmpSendEcho failed.\n");
        printf("\tIcmpSendEcho returned error: ");
        if (errMsg == NULL) {
            printf("0x%02X", dwError);
        } else {
            WriteConsole(hStdout, errMsg, lstrlen(errMsg), NULL, NULL);
            printf(" (0x%08X)", dwError);
            LocalFree(errMsg);
        }
        putchar('\n');
        return 1;
    }
    return 0;
}

int __cdecl main() {
    init();
    char ip[256];
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iResult != NO_ERROR) {
        dwError = GetLastError();
        printf("Failed to call WSAStartup: 0x%02X\n", dwError);
        return 1;
    }
    scanf("%s", ip);
    int ret = ping(ip);
    if (ret == 1) {
        printf("Failed to ping!");
        return 1;
    }
    WSACleanup();
    return 0;
}