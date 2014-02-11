#pragma once

#include "sceChnnlsv.h"
#include "ErrorCodes.h"
#include <stdio.h>
#include <stdlib.h>
 
#if defined(_WIN32)
    #define aligned_alloc _aligned_malloc
    #define aligned_free _aligned_free
    #define strcasecmp _stricmp
    #define strncasecmp _strnicmp
#elif defined(__APPLE__)
    // http://stackoverflow.com/questions/196329/osx-lacks-memalign
    #define aligned_alloc(a,size) malloc(size)
    #define aligned_free free
#else
    #define aligned_free free
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