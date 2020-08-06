#include"pch.h"
#include"mysqlDlg.h"


bool mysqlDlg::ConnectDatabase(char host[], char user[], char psw[], char table[], int port, char* error[])
{
	return 0;
}
void mysqlDlg::init()
{


}
//��ȡ�����ļ���mysql������Ϣ��
void mysqlDlg::GetMysql()
{
	//����ռ�
	HostName = new wchar_t[10];
	UserName = new wchar_t[10];
	password = new wchar_t[10];
	databases = new wchar_t[10];
	Port= new wchar_t[10];
	pws_Boot= new wchar_t[10];
	//��ȡ�����ļ�
	GetPrivateProfileString(_T("MYSQL"), _T("HostName"), _T("error"), HostName, 10, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("UserName"), _T("error"), UserName, 10, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password"), _T("error"), password, 10, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("databases"), _T("error"), databases, 10, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("Port"), _T("error"), Port, 10, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("error"), pws_Boot, 10, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));

}
//��ȡ�����ļ�����ѯ��ص���Ϣ��
void mysqlDlg::GetQuery()
{
	int a=30;
	//ʱ��
	time_table = new wchar_t[a];
	time_end = new wchar_t[a];
	time_ipid = new wchar_t[a];
	time_userid = new wchar_t[a];
	//ip��ַ
	ip_table = new wchar_t[a];
	ip_ip = new wchar_t[a];
	ip_id = new wchar_t[a];
	//�û���Ϣ
	user_table = new wchar_t[a];
	user_name = new wchar_t[a];
	user_id = new wchar_t[a];
#if 0//��ʽ
	GetPrivateProfileString(_T("TIME"), _T("time_table"), _T("error"), time_table, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_end"), _T("error"), time_end, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_ipid"), _T("error"), time_ipid, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_userid"), _T("error"), time_userid, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_table"), _T("error"), ip_table, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_ip"), _T("error"), ip_ip, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_id"), _T("error"), ip_id, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_table"), _T("error"), user_table, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_name"), _T("error"), user_name, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_id"), _T("error"), user_id, a, _T(".\\config.ini"));
#endif
	//��ȡ�����ļ�
#if 1//����
	GetPrivateProfileString(_T("TIME"), _T("time_table"), _T("error"), time_table, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_end"), _T("error"), time_end, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_ipid"), _T("error"), time_ipid, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_userid"), _T("error"), time_userid, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_table"), _T("error"), ip_table, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_ip"), _T("error"), ip_ip, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_id"), _T("error"), ip_id, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_table"), _T("error"), user_table, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_name"), _T("error"), user_name, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_id"), _T("error"), user_id, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
#endif
}
//��ȡ�����ļ����������õ���Ϣ��
void mysqlDlg::GetRoutine()
{
	int a = 30;
	//����ռ�
	day = new wchar_t[a];
	interval_time = new wchar_t[a];
	set_Boot = new wchar_t[a];
	//����

	//��ȡ�����ļ�
#if 1//����
	GetPrivateProfileString(_T("set"), _T("day"), _T("error"), day, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("set"), _T("interval_time"), _T("error"), interval_time, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	GetPrivateProfileString(_T("set"), _T("set_Boot"), _T("error"), set_Boot, a, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
#endif



}

//������Ϣ��˽������mysql������Ϣ��
void mysqlDlg::SetMysql()
{
	HostName_tmp = HostName;
	UserName_tmp = UserName;
	password_tmp = password;
	databases_tmp = databases;
	Port_tmp = Port;
	Boot_tmp = pws_Boot;
}
//������Ϣ��˽��������ѯ��Ϣ��
void mysqlDlg::SetQuery()
{
	time_table_tmp = time_table;
	time_end_tmp = time_end;
	time_ipid_tmp = time_ipid;
	time_userid_tmp = time_userid;
	ip_table_tmp = ip_table;
	ip_ip_tmp = ip_ip;
	ip_id_tmp = ip_id;
	user_table_tmp = user_table;
	user_name_tmp = user_name;
	user_id_tmp = user_id;
}
//������Ϣ��˽����������������Ϣ��
void mysqlDlg::SetRoutine()
{
	day_tmp = day;
	set_Boot_tmp = set_Boot;
	interval_time_tmp = interval_time;
}

//��˽�˱����洢�������ļ���Mysql��Ϣ��
void mysqlDlg::SaveMysql(bool falg)
{
	//����
	WritePrivateProfileString(_T("MYSQL"), _T("HostName"), HostName_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("UserName"), UserName_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("databases"), databases_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("Port"), Port_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	if(falg==1)
		WritePrivateProfileString(_T("MYSQL"), _T("password"), password_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	else
		WritePrivateProfileString(_T("MYSQL"), _T("password"), _T(" "), _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));

}
//��˽�˱����洢�������ļ�����ѯ��Ϣ��
void  mysqlDlg::SaveQuery()
{
	WritePrivateProfileString(_T("TIME"), _T("time_table"), time_table_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_end"), time_end_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_ipid"), time_ipid_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_userid"), time_userid_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	
	WritePrivateProfileString(_T("IP"), _T("ip_table"), ip_table_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("IP"), _T("ip_ip"), ip_ip_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("IP"), _T("ip_id"), ip_id_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));

	WritePrivateProfileString(_T("USERS"), _T("user_table"), user_table_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("USERS"), _T("user_name"), user_name_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("USERS"), _T("user_id"), user_id_tmp, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));

}

void  mysqlDlg::SaveRoutine()
{
#if 1//����
	WritePrivateProfileString(_T("set"), _T("day"), day, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("set"), _T("interval_time"), interval_time, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
	WritePrivateProfileString(_T("set"), _T("set_Boot"), set_Boot, _T("D:\\git\\��������\\�½��ļ���\\��������0.3\\config.ini"));
#endif
}
//�ͷ���Դ��mysql������Ϣ��
void mysqlDlg::FreeMysql()
{
	delete[] HostName;
	delete[] UserName;
	delete[] password;
	delete[] databases;
}
//�ͷ���Դ��mysql������Ϣ��
void mysqlDlg::FreeQuery()
{
	delete[] time_table;
	delete[] time_end;
	delete[] time_ipid;
	delete[] time_userid;
	delete[] ip_table;
	delete[] ip_ip;
	delete[] ip_id;
	delete[] user_table;
	delete[] user_name;
	delete[] user_id;
}
//�ͷ���Դ������������Ϣ��
void mysqlDlg::FreeRoutine()
{
	delete[] day;
	delete[] interval_time;
	delete[] set_Boot;
	
}
