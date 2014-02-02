#pragma once

#include "sceChnnlsv.h"
#include <malloc.h>
#include <stdio.h>

#ifdef _WIN32
void* memalign(size_t size, size_t alignment);
#endif

class Savedata
{
public:
    /* Read, decrypt, and write a savedata file.  See main.c for example usage. */
    static int Decrypt(const char *decrypted_filename,
                       const char *encrypted_filename,
                       const unsigned char *gamekey);

    /* Encrypt the given plaintext file, and update the message
       authentication hashes in the param.sfo.  The data_filename is
       usually the final component of encrypted_filename, e.g. "DATA.BIN".
       See main.c for an example of usage. */
    static int Encrypt(const char *plaintext_filename,
                       const char *encrypted_filename,
                       const char *data_filename,
                       const char *paramsfo_filename,
                       const unsigned char *gamekey);
};