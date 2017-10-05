/**************************************************************
 *
 * userprog/ksyscall.h
 *
 * Kernel interface for systemcalls 
 *
 * by Marcus Voelp  (c) Universitaet Karlsruhe
 *
 **************************************************************/

#ifndef __USERPROG_KSYSCALL_H__ 
#define __USERPROG_KSYSCALL_H__ 

#include "kernel.h"

#include "synchconsole.h"

typedef int OpenFileID;


void SysHalt()
{
  kernel->interrupt->Halt();
}

int SysAdd(int op1, int op2)
{
  return op1 + op2;
}

OpenFileID SysOpen(char *fileName)
{
	return kernel->interrupt->OpenFile(fileName);
}

int SysClose(OpenFileID fid)
{
	return kernel->interrupt->CloseFile(fid);
}

int SysWrite(char* buffer, int bufferLen, OpenFileID fid)
{
	return kernel->interrupt->WriteFile(buffer, bufferLen, fid);
}

int SysRead(char* buffer, int size, OpenFileID fid)
{
	return kernel->interrupt->ReadFile(buffer, size, fid);
}

int SysCreate(char *filename)
{
	// return value
	// 1: success
	// 0: failed
	return kernel->interrupt->CreateFile(filename);
}

void SysPrintInt(int number)
{
	kernel->interrupt->PrintInt(number);
}


#endif /* ! __USERPROG_KSYSCALL_H__ */
