//Nguoi code:
//Pham Ngoc Son
// 1612565
#pragma once 
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include "WindowGame.h"
#include "Mouse.h"
class CpuPlayer// class engine ai chess
{
private:
	STARTUPINFO sti;
	SECURITY_ATTRIBUTES sats ;
	PROCESS_INFORMATION pi ;
	HANDLE pipin_w, pipin_r, pipout_w, pipout_r;
	BYTE buffer[2048];
	DWORD writ, excode, read, available;
	void ConnectToEngine();// ket noi engine
	void CloseConnection();// huy ket noi engine
public:
	CpuPlayer();
	std::string getNextMove(std::string position);// lay nuoc di chuyen
	~CpuPlayer();
};