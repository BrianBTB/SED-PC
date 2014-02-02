#include "sed.h"
#include "sceChnnlsv.h"
#include "MemMap.h"
#include <iostream>

//#define DEBUG

using namespace std;

void CheckAndShowError(int errCode)
{
    cout<<"\n\n";
    if(errCode >= 2) {
        return;    //No error
    } else if(errCode == FILE_IO_ERROR) {
        cout<<"File IO Error - Check the supplied paths and their permissions";
    } else if(errCode == MEMORY_ERROR) {
        cout<<"Memory Error - Something went wrong while attempting to allocate memory";
    } else if(errCode == SFO_ERROR) {
        cout<<"SFO Error - Make sure that the SFO file is correct";
    } else if(errCode == INVALID_SFO_ERROR) {
        cout<<"SFO Error - The SFO file is invalid";
    } else if(errCode == HASH_ERROR) {
        cout<<"Hash Error - Something went wrong with hashing";
    } else if(errCode <= DECRYPT_ERROR && errCode > ENCRYPT_ERROR) {
        cout<<"Decrypt Error - Something went wrong while decrypting \n Code: "<<errCode;
    } else if(errCode <= ENCRYPT_ERROR) {
        cout<<"Encrypt Error - Something went wrong while encrypting \n Code: "<<errCode;
    } else if(errCode == INVALID_ARGS) {
        cout<<"Invalid Arguments";
    } else {
        cout<<"Unknown Error - Code "<<errCode;
    }
    cout<<"\nReport any issues at https://github.com/hgoel0974/SED-PC/issues";
    cout<<"\n\n";
}

void ShowHelp()
{
    cout << "                                  /   \\        \n";
    cout << " _                        )      ((   ))     (                           \n";
    cout << "(@)                      /|\\      ))_((     /|\\ \n";
    cout << "|-|                     / | \\    (/\\|/\\)   / | \\                      (@)\n";
    cout << "| | -------------------/--|-voV---\\`|'/--Vov-|--\\---------------------|-|\n";
    cout << "|-|                         '^`   (o o)  '^`                          | |\n";
    cout << "| |                               `\\Y/'                               |-|\n";
    cout << "|-|                                                                   | |\n";
    cout << "| |              PSP Savedata Encrypter/Decrypter for PC              |-|\n";
    cout << "|-|                                                                   | |\n";
    cout << "| | Usage:                                                            |-|\n";
    cout << "|-|     sed -e [Input File] [PARAM.SFO] [Output File] [Game Key File] | |\n";
    cout << "| |     sed -d [Input File] [Output File] [Game Key File]             |-|\n";
    cout << "|_|___________________________________________________________________| |\n";
    cout << "(@)              l   /\\ /         ( (       \\ /\\   l                `\\|-|\n";
    cout << "                 l /   V           \\ \\       V   \\ l                  (@)\n";
    cout << "                 l/                _) )_          \\I\n";
    cout << "                                   `\\ /'\n";
    cout << "				     `  \n";
}

int Encrypter(char *argv[])
{
    unsigned char gameKey[0x11] = {" "};

    FILE* key = fopen(argv[5], "rb");
    if(key > 0) {
        fread((void*)gameKey, 1, 0x10, key);
        fclose(key);
    } else {
        return FILE_IO_ERROR;
    }

    //ARGV 1 = File to Encrypt
    //ARGV 2 = Path to PARAM.SFO
    //ARGV 3 = Output file name
    //ARGV 4 = Game key file
    char fname[30] = "", ext[10] = "";
    _splitpath(argv[4], NULL, NULL, fname, ext);
    strcat(fname, ext);

    return Savedata::Encrypt(argv[2], argv[4],  fname, argv[3], gameKey);
}

int Decrypter(char *argv[])
{
    unsigned char gameKey[0x11] = {" "};
    FILE* key = fopen(argv[4], "rb");
    if(key > 0) {
        fread((void*)gameKey, 1, 0x10, key);
        fclose(key);
    } else {
        return FILE_IO_ERROR;
    }

    //ARGV 1 = File to Decrypt
    //ARGV 2 = Output File name
    //ARGV 3 = Game key file
    return Savedata::Decrypt(argv[3], argv[2], gameKey);
}

int main ( int argc, char *argv[] )
{

    int ret = INVALID_ARGS;

    if(argc >=5) {
        Memory::Init();
        init_chnnlsv();

        if(strncmp(argv[1],"-e",2)==0) {
            ret = Encrypter(argv);
        } else if(strncmp(argv[1],"-d",2)==0) {
            ret = Decrypter(argv);
        } else {
            goto help;
        }

        goto error;
    }

help:
    ShowHelp();
error:
    CheckAndShowError(ret);
    Memory::Dispose();

    return 0;
}