#pragma once

//Uncomment for Dogenation!
//#define DOGE

#define INVALID_ARGS 1
#define FILE_IO_ERROR -1
#define MEMORY_ERROR -2
#define CHNNLSV_ERROR -3
#define SFO_ERROR -4
#define INVALID_SFO_ERROR -5
#define HASH_ERROR -2000
#define DECRYPT_ERROR -100
#define ENCRYPT_ERROR -1000

#ifdef DOGE
#define FILE_IO_MSG "Much file not found"
#define MEMORY_MSG "Such memory error"
#define SFO_MSG "Much SFO bad"
#define INVALID_SFO_MSG "Much SFO invalid"
#define HASH_MSG "Update hash. Much fail"
#define DECRYPT_MSG "Such decrypt error "<<errCode
#define ENCRYPT_MSG "Such encrypt error "<<errCode
#define INVALID_MSG "Wow. Much invalid. Such arguments"
#define UNKN_MSG "Much unknown. Very message "<<errCode
#else
#define FILE_IO_MSG "File IO Error - Check the supplied paths and their permissions"
#define MEMORY_MSG "Memory Error - Something went wrong while attempting to allocate memory"
#define SFO_MSG "SFO Error - Make sure that the SFO file is correct"
#define INVALID_SFO_MSG "SFO Error - The SFO file is invalid"
#define HASH_MSG "Hash Error - Something went wrong with hashing"
#define DECRYPT_MSG "Decrypt Error - Something went wrong while decrypting \n Code: "<<errCode
#define ENCRYPT_MSG "Encrypt Error - Something went wrong while encrypting \n Code: "<<errCode
#define INVALID_MSG "Invalid Arguments"
#define UNKN_MSG "Unknown Error - Code: "<<errCode
#endif