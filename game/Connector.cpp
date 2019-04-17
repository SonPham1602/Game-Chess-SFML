#include "Connector.h"
CpuPlayer::CpuPlayer()
{
	ConnectToEngine();
}
CpuPlayer::~CpuPlayer()
{
	CloseConnection();
}
void CpuPlayer::ConnectToEngine()
{
		STARTUPINFO sti_temp = {0};
		SECURITY_ATTRIBUTES sats_temp = {0};
		PROCESS_INFORMATION pi_temp = {0};
		sti=sti_temp;
		sats=sats_temp;
		pi=pi_temp;
		char text[] = "stockfish.exe";
		wchar_t wtext[20];
		mbstowcs(wtext, text, strlen(text)+1);//Plus null
		LPWSTR ptr = wtext;
		pipin_w = pipin_r = pipout_w = pipout_r = NULL;
		sats.nLength = sizeof(sats);
		sats.bInheritHandle = TRUE;
		sats.lpSecurityDescriptor = NULL;

		CreatePipe(&pipout_r, &pipout_w, &sats, 0);
		CreatePipe(&pipin_r, &pipin_w, &sats, 0);

		sti.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
		sti.wShowWindow = SW_HIDE;
		sti.hStdInput = pipin_r;
		sti.hStdOutput = pipout_w;
		sti.hStdError = pipout_w;
		CreateProcess(NULL, ptr, NULL, NULL, TRUE,0, NULL, NULL, &sti, &pi);
}
std::string CpuPlayer::getNextMove(std::string position)
{
		std::string str;
		position = "position startpos moves "+position+"\ngo\n";	
		WriteFile(pipin_w, position.c_str(), position.length(),&writ, NULL);
		Sleep(75);
		PeekNamedPipe(pipout_r, buffer,sizeof(buffer), &read, &available, NULL);   
		do
		{   
			ZeroMemory(buffer, sizeof(buffer));
			if(!ReadFile(pipout_r, buffer, sizeof(buffer), &read, NULL) || !read) break; 
			buffer[read] = 0;	
			str+=(char*)buffer;
		}
		while(read >= sizeof(buffer));

		int n = str.find("bestmove");  
		if (n!=-1) return str.substr(n+9,4);
		return "error";
}
void CpuPlayer::CloseConnection()
{
	WriteFile(pipin_w, "quit\n", 5,&writ, NULL);
	if(pipin_w != NULL) CloseHandle(pipin_w);
	if(pipin_r != NULL) CloseHandle(pipin_r);
	if(pipout_w != NULL) CloseHandle(pipout_w);
	if(pipout_r != NULL) CloseHandle(pipout_r);
	if(pi.hProcess != NULL) CloseHandle(pi.hProcess);
	if(pi.hThread != NULL) CloseHandle(pi.hThread);
}