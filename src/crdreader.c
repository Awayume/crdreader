// SPDX-FileCopyrightText: 2024 Awayume <dev@awayume.jp>
// SPDX-License-Identifier: MIT

#include <stdio.h>

#include <windows.h>
#include <wincred.h>


int main() {
    DWORD count;
    PCREDENTIAL* credentials;

    if (!CredEnumerate(NULL, 0, &count, &credentials)) {
        char message[] = "[ERROR] Failed to enumerate credentials:";
        switch (GetLastError()) {
            case 1168:
                printf("%s ERROR_NOT_FOUND (0x490)\n", message);
            case 1312:
                printf("%s ERROR_NO_SUCH_LOGON_SESSION (0x520)\n", message);
            case 1004:
                printf("%s ERROR_INVALID_FLAGS (0x3EC)\n", message);
            default:
                printf("%sUnknown error\n", message);
        }
        return 255;
    }

    if (count == 0) {
        printf("No credentials found!\n");
        return 0;
    }

    printf("Credentials (total %d):\n", count);
    for (DWORD i = 0; i < count; i++) {
        LPSTR key = credentials[i]->TargetName;
        LPBYTE value = credentials[i]->CredentialBlob;
        printf("  %s: %s\n", key, value);
    }
}
