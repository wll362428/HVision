#pragma once
#include "lock.h"

//#define EMULATOR_TEST

#define DEBUG_LOG_FILE         _T("log.txt")

#define LOG_BUFFER_SIZE    4096

class CDebugLog
{
public:
	CDebugLog(void);
	CDebugLog(TCHAR *lpPath);

	 ~CDebugLog(void);
	//void WriteLog(const wchar_t* wstr, ...);		// д��־(���ֽڰ汾)
	void WriteLog(const char* str, ...);			// д��־(���ֽڰ汾)
	void WriteLogHex(const char * buf, int len);
	void OpenLog(LPCTSTR szPath =_T("COM_OUTPUT"));
	void CloseLog();
	void SetLogFilePath(TCHAR* szPath);
private:
	bool m_bLogWriteFile;
// 	CRITICAL_SECTION m_criticalSection_log;
	CLock m_csLogLock;
	HANDLE m_hCom1;
	
};
