#include"pch.h"
#include"mysqlDlg.h"
#include"mysql.h"

#include <stdlib.h>
#include <tchar.h>
#pragma comment(lib,"libmysql.lib")
extern MYSQL mysql; //mysql����
extern MYSQL_FIELD* fd;  //�ֶ�������
TCHAR nid_szInfoTitle[100][100];//�洢���ݵ���ʾ����
extern MYSQL_RES* res; //����ṹ�������е�һ����ѯ�����
extern MYSQL_ROW column; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���

bool mysqlDlg::ConnectDatabase(LPWSTR host, LPWSTR user, LPWSTR psw, LPWSTR table, LPWSTR port)
{
	//��ʼ��mysql  

	mysql_init(&mysql);  //����mysql�����ݿ�  
#if 0
	host = "localhost";
	user = "root";
	psw = "1234";//"maiyun";
	table = "maiyun";  //���ݿ������
	port = 3307;
#endif; 
	//ת����ʽ
	char* host_tmp =ConvertLPWSTRToLPSTR(host);
	char* user_tmp = ConvertLPWSTRToLPSTR(user);
	char* psw_tmp = ConvertLPWSTRToLPSTR(psw);
	char* table_tmp = ConvertLPWSTRToLPSTR(table);

	int port_tmp = _ttoi(port);
	
	if (!(mysql_real_connect(&mysql, host_tmp, user_tmp, psw_tmp, table_tmp, port_tmp, NULL, 0)))
		//�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ  
	{
		TCHAR Name[100];	//����TCHAR��ʱ������
		//ƴ������
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, Name, 100);//ת����ʽ
		DisplayResourceNAMessageBox(_T("�������ݿ�ʧ��"), Name);
		return false;
	}
	else
	{
		DisplayResourceNAMessageBox(_T("yes"), _T("yes1"));
		return true;
	}
}

//��ѯ������ֵ

char* mysqlDlg::QueryDatabase3(LPWSTR table_tmp, LPWSTR key_id_tmp, LPWSTR key_tmp, char* id_tmp)
{
	//ת����ʽ

	char* table = ConvertLPWSTRToLPSTR(table_tmp);
	char* key_id = ConvertLPWSTRToLPSTR(key_id_tmp);
	char* key = ConvertLPWSTRToLPSTR(key_tmp);
	//char* id = ConvertLPWSTRToLPSTR(id_tmp);

	char query[150]; //��ѯ���
	MYSQL_RES* res1; //����ṹ�������е�һ����ѯ�����
	MYSQL_ROW column1; //һ�������ݵ����Ͱ�ȫ(type-safe)�ı�ʾ����ʾ�����е���
	char* field1[150];  //���ֶ�����ά����
	int flag_id = -1, flag_info = -1;
	char tableName[100];
	sprintf_s(tableName, 100, "select * from %s", table);
	strcpy_s(query, tableName);
	mysql_query(&mysql, "set names gbk");
	//����0 ��ѯ�ɹ�������1��ѯʧ��  

	if (mysql_query(&mysql, tableName))        //ִ��SQL���  
	{
		//printf("Query failed (%s)\n", mysql_error(&mysql));
		TCHAR Name[100];	//����TCHAR��ʱ������
		//ƴ������
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, Name, 100);//ת����ʽ
		DisplayResourceNAMessageBox(_T("�������ݿ�ʧ��"), Name);
		return "error";
	}
	else
	{
		//printf("query success\n");
	}
	res1 = mysql_store_result(&mysql);

	for (int i = 0; fd = mysql_fetch_field(res1); i++)  //��ȡ�ֶ���  
	{
		field1[i] = fd->name;
		if (strcmp(field1[i], key_id) == 0)//��ȡ��Ϣ��ip���û�
			flag_id = i;
		if (strcmp(field1[i], key) == 0)//��ȡ��Ϣ��ip���û�
			flag_info = i;
	}
	if ((flag_id == -1) || (flag_info == -1))
		return "error";
	char* info_tmp = "";
	int j = mysql_num_fields(res1);  // ��ȡ����  
	while (column1 = mysql_fetch_row(res1))
	{
		if (strcmp(column1[flag_id], id_tmp) == 0)//id���
		{
			info_tmp = column1[flag_info];
			return info_tmp;
		}
	}
	return "error";
}

bool mysqlDlg::QueryDatabase2(LPWSTR table1_tmp, LPWSTR day_in_tmp,
	LPWSTR key_time_tmp, LPWSTR key_time_ipid_tmp, LPWSTR key_time_nameid_tmp,
	LPWSTR table_ip, LPWSTR key_ipid, LPWSTR key_ip,
	LPWSTR table_user, LPWSTR key_nameid, LPWSTR key_name
)
{
	int flag_num = -1, flag_ip_id = -1, flag_name_id = -1;
	//�������
	int idnum;
	char* field[150];  //���ֶ�����ά����
	
	char tmp[100]=" ";		//����char��ʱ�����������ַ���//ת����ʱ����
	TCHAR Name[100];	//����TCHAR��ʱ������
	//ת����ʽ
	char* table1 = ConvertLPWSTRToLPSTR(table1_tmp);
	char* key_time = ConvertLPWSTRToLPSTR(key_time_tmp);
	char* key_time_ipid = ConvertLPWSTRToLPSTR(key_time_ipid_tmp);
	char* key_time_nameid = ConvertLPWSTRToLPSTR(key_time_nameid_tmp);

/*	char* table_ip = ConvertLPWSTRToLPSTR(table_ip_tmp);
	char* key_ipid = ConvertLPWSTRToLPSTR(key_ipid_tmp);
	char* key_ip = ConvertLPWSTRToLPSTR(key_ip_tmp);

	char* table_user = ConvertLPWSTRToLPSTR(table_user_tmp);
	char* key_nameid = ConvertLPWSTRToLPSTR(key_nameid_tmp);
	char* key_name = ConvertLPWSTRToLPSTR(key_name_tmp);
	*/

	int day_in = _ttoi(day_in_tmp);


	char query[150]; //��ѯ���
	//const char* use_ip="local_ip";
	//const char* use_name="instance_name";
	//const char* use_time="expire_time";
#if 0
	table1 = "yundb_instance";
	use_time = "expire_time";		//#����������ʱ�����
	use_ip = "local_ip";		//	#ip��ַ����
	use_name = "instance_name";
#endif

	
	char tableName[100];
	sprintf_s(tableName, 100, "select * from %s", table1);
	strcpy_s(query, tableName);
	mysql_query(&mysql, "set names gbk");
	//����0 ��ѯ�ɹ�������1��ѯʧ��  

	if (mysql_query(&mysql, tableName))        //ִ��SQL���  
	{//��ѯʧ��
#if 0
		str = new char[100];
		//д����־�ļ�
		GetLocalTime(&st);//��ȡʱ��
		sprintf_s(str, 100, "%d-%d-%d %02d:%02d tmp: ���ݿ��ѯʧ��", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
		WriteToLog(str, path);
		delete[] str;
#endif
		TCHAR Name[200];	//����TCHAR��ʱ������
		//ƴ������
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, Name, 200);//ת����ʽ
		DisplayResourceNAMessageBox(_T("�������ݿ�ʧ��"), Name);
		return false;
	}
	else
	{
		//printf("query success\n");
	}
	res = mysql_store_result(&mysql);

	for (int i = 0; fd = mysql_fetch_field(res); i++)  //��ȡ�ֶ���  
	{
		field[i] = fd->name;
		if (strcmp(field[i], key_time) == 0)//��ֹ���ڼ���
			flag_num = i;
		if (strcmp(field[i], key_time_ipid) == 0)//ipid�ļ���
			flag_ip_id = i;
		if (strcmp(field[i], key_time_nameid) == 0)//�û���Ϣid����
			flag_name_id = i;
	}
	if ((flag_name_id == -1) || (flag_ip_id == -1) || (flag_num == -1))
		return false;

	int j = mysql_num_fields(res);  // ��ȡ����  

	char text[] = "";
	char* customer_Name = text;
	char* customer_ip = text;
	char* customer_remind = text;
	char* ip_id = text;
	char* name_id = text;
	idnum = 0;//��ʼ��uid

	while (column = mysql_fetch_row(res))
	{
		//for (int i = 0; i < j; i++)//��j���˵�i��Ϣ,
		//{
		int time_year, time_month, time_day;	//���ݿ��е�������
		char* str;
		SYSTEMTIME now_time;//��ǰʱ��
		//GetLocalTime(&now_time);//��ȡ��ǰʱ��
		GetSystemTime(&now_time);
		//��ȡ����ʱ��
		time_year = char2int(column[flag_num]);
		str = column[flag_num] + 5;//��ȥ��ݺͷָ���
		time_month = char2int(str);
		str = column[flag_num] + 8;//��ȥ�·ݺͷָ���
		time_day = char2int(str);

		ip_id = column[flag_ip_id];
		name_id = column[flag_name_id];
		//�жϽ����ǵڼ���
	//if ((flag[3] == TRUE))
	//{
		//�жϱ����ǵڼ���
		int q = DaysBetween2Date(now_time.wYear, now_time.wMonth, now_time.wDay, time_year, time_month, time_day);

		if ((q < 3 + 1) && q > 0)//if ((q < day_in + 1) && q > 0)
		{
			//��ȡip��ַ
			customer_ip = QueryDatabase3(table_ip, key_ipid, key_ip, ip_id);
			//��ȡ�û���ַ
			customer_Name = QueryDatabase3(table_user, key_nameid, key_name, name_id);
			//�ж��Ƿ��ȡ����
			if ((strcmp(customer_ip, "error") == 0) || (strcmp(customer_Name, "error") == 0))//��ֹ���ڼ���
				return false;
			//�ж��Ƿ����
			sprintf_s(tmp, 100, "%s %d��%d��%d�� ����\n%s", customer_ip, time_year, time_month, time_day, customer_Name);//����Ҫ��ʾ���ַ���
			MultiByteToWideChar(CP_ACP, 0, tmp, -1, nid_szInfoTitle[idnum], 100);//ת����ʽ
			idnum++;

			if (idnum > 31)
				break;
			else
				continue;
		}
		else//δ���ڴ���
		{
			continue;
		}
	}
	return true;
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
