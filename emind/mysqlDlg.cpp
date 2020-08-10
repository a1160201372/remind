#include"pch.h"
#include"mysqlDlg.h"
#include"mysql.h"

#include <stdlib.h>
#include <tchar.h>
#pragma comment(lib,"libmysql.lib")
extern MYSQL mysql; //mysql连接
extern MYSQL_FIELD* fd;  //字段列数组
TCHAR nid_szInfoTitle[100][100];//存储气泡的显示内容
extern MYSQL_RES* res; //这个结构代表返回行的一个查询结果集
extern MYSQL_ROW column; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
TCHAR error_flag[200];
bool mysqlDlg::ConnectDatabase(LPWSTR host, LPWSTR user, LPWSTR psw, LPWSTR table, LPWSTR port)
{
	//初始化mysql  

	mysql_init(&mysql);  //连接mysql，数据库  
#if 0
	host = "localhost";
	user = "root";
	psw = "1234";//"maiyun";
	table = "maiyun";  //数据库的名字
	port = 3307;
#endif; 
	//转换格式
	char* host_tmp =ConvertLPWSTRToLPSTR(host);
	char* user_tmp = ConvertLPWSTRToLPSTR(user);
	char* psw_tmp = ConvertLPWSTRToLPSTR(psw);
	char* table_tmp = ConvertLPWSTRToLPSTR(table);

	int port_tmp = _ttoi(port);
	

	unsigned int timeout = 1;
	
	int ret = mysql_options(&mysql, MYSQL_OPT_CONNECT_TIMEOUT, (const char*)&timeout);
	if (ret) {
		/* Handle error */
		return false;
	}

	if (!(mysql_real_connect(&mysql, host_tmp, user_tmp, psw_tmp, table_tmp, port_tmp, NULL, 0)))
		//中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去  
	{
		
		return false;
	}
	else
	{
		//DisplayResourceNAMessageBox(_T("yes"), _T("yes1"));
		return true;
	}
}

//查询具体数值

char* mysqlDlg::QueryDatabase3(LPWSTR table_tmp, LPWSTR key_id_tmp, LPWSTR key_tmp, char* id_tmp,bool flag_ip_user)
{
	//转换格式

	char* table = ConvertLPWSTRToLPSTR(table_tmp);
	char* key_id = ConvertLPWSTRToLPSTR(key_id_tmp);
	char* key = ConvertLPWSTRToLPSTR(key_tmp);
	//char* id = ConvertLPWSTRToLPSTR(id_tmp);

	char query[150]; //查询语句
	MYSQL_RES* res1; //这个结构代表返回行的一个查询结果集
	MYSQL_ROW column1; //一个行数据的类型安全(type-safe)的表示，表示数据行的列
	char* field1[150];  //存字段名二维数组
	int flag_id = -1, flag_info = -1;
	char tableName[100];
	sprintf_s(tableName, 100, "select * from %s", table);
	strcpy_s(query, tableName);
	mysql_query(&mysql, "set names gbk");
	//返回0 查询成功，返回1查询失败  

	if (mysql_query(&mysql, tableName))        //执行SQL语句  
	{
		//printf("Query failed (%s)\n", mysql_error(&mysql));
		//TCHAR Name[100];	//定义TCHAR临时变量，
		//拼接内容
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, error_flag, 100);//转换格式
		//AfxMessageBox(Name, (MB_YESNO | MB_ICONQUESTION));
		return "error1";
	}
	else
	{
		//printf("query success\n");
	}
	res1 = mysql_store_result(&mysql);

	for (int i = 0; fd = mysql_fetch_field(res1); i++)  //获取字段名  
	{
		field1[i] = fd->name;
		if (strcmp(field1[i], key_id) == 0)//读取信息：ip、用户
			flag_id = i;
		if (strcmp(field1[i], key) == 0)//读取信息：ip、用户
			flag_info = i;
	}
	if ((flag_id == -1) || (flag_info == -1))
	{
		char tableName[100];
		if (flag_id == -1) {
			if(flag_ip_user==1)//ip
				sprintf_s(tableName, 100, "ip键名中的\tip的ID错误：%s", key_id);
			else if (flag_ip_user == 0)//user
				sprintf_s(tableName, 100, "用户键名中的\t用户的ID错误：%s", key_id);
		}
		else if (flag_info == -1)
		{
			if (flag_ip_user == 1)//ip
				sprintf_s(tableName, 100, "ip键名中的\tip地址错误：%s", key);

			else if (flag_ip_user == 0)//user
				sprintf_s(tableName, 100, "用户键名中的\t用户信息错误：%s", key);
		}
		//error_flag赋值
		MultiByteToWideChar(CP_ACP, 0, tableName, -1, error_flag, 100);//转换格式

		return "error1";
	}
	char* info_tmp = "";
	int j = mysql_num_fields(res1);  // 获取列数  
	while (column1 = mysql_fetch_row(res1))
	{
		if (strcmp(column1[flag_id], id_tmp) == 0)//id相等
		{
			info_tmp = column1[flag_info];
			return info_tmp;
		}
	}
	//MultiByteToWideChar(CP_ACP, 0, ("未找到提配"), -1, error_flag, 100);//转换格式

	return "error";
}

bool mysqlDlg::QueryDatabase2(LPWSTR table1_tmp, LPWSTR day_in_tmp,
	LPWSTR key_time_tmp, LPWSTR key_time_ipid_tmp, LPWSTR key_time_nameid_tmp,
	LPWSTR table_ip, LPWSTR key_ipid, LPWSTR key_ip,
	LPWSTR table_user, LPWSTR key_nameid, LPWSTR key_name
)
{
	user_num = 0;
	int flag_num = -1, flag_ip_id = -1, flag_name_id = -1;
	//定义变量
	int idnum;
	char* field[150];  //存字段名二维数组
	
	char tmp[100]=" ";		//定义char临时变量，最终字符串//转换临时变量
	TCHAR Name[100];	//定义TCHAR临时变量，
	//转换格式
	char* table1 = ConvertLPWSTRToLPSTR(table1_tmp);
	char* key_time = ConvertLPWSTRToLPSTR(key_time_tmp);
	char* key_time_ipid = ConvertLPWSTRToLPSTR(key_time_ipid_tmp);
	char* key_time_nameid = ConvertLPWSTRToLPSTR(key_time_nameid_tmp);
	char* day_in_tmp1 = ConvertLPWSTRToLPSTR(day_in_tmp);
	int day_in = (int)day_in_tmp1;
/*	char* table_ip = ConvertLPWSTRToLPSTR(table_ip_tmp);
	char* key_ipid = ConvertLPWSTRToLPSTR(key_ipid_tmp);
	char* key_ip = ConvertLPWSTRToLPSTR(key_ip_tmp);

	char* table_user = ConvertLPWSTRToLPSTR(table_user_tmp);
	char* key_nameid = ConvertLPWSTRToLPSTR(key_nameid_tmp);
	char* key_name = ConvertLPWSTRToLPSTR(key_name_tmp);
	*/

	//int day_in = _wtoi(day_in_tmp);
	//int day_in = 3307;


	char query[150]; //查询语句
	//const char* use_ip="local_ip";
	//const char* use_name="instance_name";
	//const char* use_time="expire_time";
#if 0
	table1 = "yundb_instance";
	use_time = "expire_time";		//#服务器到期时间键名
	use_ip = "local_ip";		//	#ip地址键名
	use_name = "instance_name";
#endif

	
	char tableName[100];
	sprintf_s(tableName, 100, "select * from %s", table1);
	strcpy_s(query, tableName);
	mysql_query(&mysql, "set names gbk");
	//返回0 查询成功，返回1查询失败  

	if (mysql_query(&mysql, tableName))        //执行SQL语句  
	{//查询失败
#if 0
		str = new char[100];
		//写入日志文件
		GetLocalTime(&st);//获取时间
		sprintf_s(str, 100, "%d-%d-%d %02d:%02d tmp: 数据库查询失败", st.wYear, st.wMonth, st.wDay, st.wHour, st.wMinute);
		WriteToLog(str, path);
		delete[] str;
#endif
		TCHAR Name[200];	//定义TCHAR临时变量，
		//拼接内容
		MultiByteToWideChar(CP_ACP, 0, mysql_error(&mysql), -1, error_flag, 200);//转换格式
		//AfxMessageBox(Name, (MB_YESNO | MB_ICONQUESTION));
		//DisplayResourceNAMessageBox(_T("连接数据库失败"), Name);
		return false;
	}
	else
	{
		//printf("query success\n");
	}
	res = mysql_store_result(&mysql);

	for (int i = 0; fd = mysql_fetch_field(res); i++)  //获取字段名  
	{
		field[i] = fd->name;
		if (strcmp(field[i], key_time) == 0)//截止日期键名
			flag_num = i;
		if (strcmp(field[i], key_time_ipid) == 0)//ipid的键名
			flag_ip_id = i;
		if (strcmp(field[i], key_time_nameid) == 0)//用户信息id键名
			flag_name_id = i;
	}
	if ((flag_name_id == -1) || (flag_ip_id == -1) || (flag_num == -1))
	{
		char tableName[100];
		if (flag_name_id == -1)
			sprintf_s(tableName, 100, "时间键名中的：\t用户ID错误：%s", key_time_nameid);
		else if (flag_ip_id == -1)
			sprintf_s(tableName, 100, "时间键名中的：\tIPID错误：%s", key_time_ipid);
		else if (flag_num == -1)
			sprintf_s(tableName, 100, "时间键名中的：\t到期时间错误：%s", key_time);
		//error_flag赋值
		MultiByteToWideChar(CP_ACP, 0, tableName, -1, error_flag, 100);//转换格式
		return false;
	}
		

	int j = mysql_num_fields(res);  // 获取列数  

	char text[] = "";
	char* customer_Name = text;
	char* customer_ip = text;
	char* customer_remind = text;
	char* ip_id = text;
	char* name_id = text;
	idnum = 0;//初始化uid

	while (column = mysql_fetch_row(res))
	{
		//for (int i = 0; i < j; i++)//第j个人的i信息,
		//{
		int time_year, time_month, time_day;	//数据库中的年月日
		char* str;
		SYSTEMTIME now_time;//当前时间
		//GetLocalTime(&now_time);//获取当前时间
		GetSystemTime(&now_time);
		//获取到期时间
		time_year = char2int(column[flag_num]);
		str = column[flag_num] + 5;//截去年份和分隔符
		time_month = char2int(str);
		str = column[flag_num] + 8;//截去月份和分隔符
		time_day = char2int(str);

		ip_id = column[flag_ip_id];
		name_id = column[flag_name_id];
		//判断今天是第几天
	//if ((flag[3] == TRUE))
	//{
		//判断表中是第几天
		int q = DaysBetween2Date(now_time.wYear, now_time.wMonth, now_time.wDay, time_year, time_month, time_day);

		if ((q < 3 + 1) && q > 0)//if ((q < day_in + 1) && q > 0)
		{
			//读取ip地址
			customer_ip = QueryDatabase3(table_ip, key_ipid, key_ip, ip_id,1);
			//读取用户地址
			customer_Name = QueryDatabase3(table_user, key_nameid, key_name, name_id,0);
			//判断是否读取正常
			if ((strcmp(customer_ip, "error1") == 0) || (strcmp(customer_Name, "error1") == 0))//截止日期键名
				return false;
			//判断是否过期
			sprintf_s(tmp, 100, "%s %d年%d月%d日 到期\n%s", customer_ip, time_year, time_month, time_day, customer_Name);//创建要显示的字符串
			MultiByteToWideChar(CP_ACP, 0, tmp, -1, nid_szInfoTitle[idnum], 100);//转换格式
			idnum++;
			continue;

		}
		else//未过期处理
		{
			continue;
		}
	}
	user_num = idnum;
	return true;
}



void mysqlDlg::init()
{


}
//读取配置文件（mysql连接信息）
void mysqlDlg::ReadMysql()
{
	//分配空间
	HostName = new wchar_t[20];
	UserName = new wchar_t[20];
	password = new wchar_t[20];
	databases = new wchar_t[20];
	Port = new wchar_t[20];
	pws_Boot = new wchar_t[20];
	//读取配置文件
#if 0//测试
	GetPrivateProfileString(_T("MYSQL"), _T("HostName"), _T("error"), HostName, 20, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("UserName"), _T("error"), UserName, 20, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password"), _T("error"), password, 20, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("databases"), _T("error"), databases, 20, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("Port"), _T("error"), Port, 20, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("error"), pws_Boot, 20, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
#endif
#if 1//正式
	GetPrivateProfileString(_T("MYSQL"), _T("HostName"), _T("error"), HostName, 20, _T(".\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("UserName"), _T("error"), UserName, 20, _T(".\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password"), _T("error"), password, 20, _T(".\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("databases"), _T("error"), databases, 20, _T(".\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("Port"), _T("error"), Port, 20, _T(".\\config.ini"));
	GetPrivateProfileString(_T("MYSQL"), _T("password_Boot"), _T("error"), pws_Boot, 20, _T(".\\config.ini"));
#endif

}
//读取配置文件（查询相关的信息）
void mysqlDlg::ReadQuery()
{
	int a=30;
	//时间
	time_table = new wchar_t[a];
	time_end = new wchar_t[a];
	time_ipid = new wchar_t[a];
	time_userid = new wchar_t[a];
	//ip地址
	ip_table = new wchar_t[a];
	ip_ip = new wchar_t[a];
	ip_id = new wchar_t[a];
	//用户信息
	user_table = new wchar_t[a];
	user_name = new wchar_t[a];
	user_id = new wchar_t[a];
#if 1//正式
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
	//读取配置文件
#if 0//测试
	GetPrivateProfileString(_T("TIME"), _T("time_table"), _T("error"), time_table, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_end"), _T("error"), time_end, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_ipid"), _T("error"), time_ipid, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("TIME"), _T("time_userid"), _T("error"), time_userid, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_table"), _T("error"), ip_table, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_ip"), _T("error"), ip_ip, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("IP"), _T("ip_id"), _T("error"), ip_id, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_table"), _T("error"), user_table, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_name"), _T("error"), user_name, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("USERS"), _T("user_id"), _T("error"), user_id, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
#endif
}
//读取配置文件（常规设置的信息）
void mysqlDlg::ReadRoutine()
{
	int a = 30;
	//分配空间
	day = new wchar_t[a];
	interval_time = new wchar_t[a];
	set_Boot = new wchar_t[a];
	//解密

	//读取配置文件
#if 0//测试
	GetPrivateProfileString(_T("set"), _T("day"), _T("error"), day, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("set"), _T("interval_time"), _T("error"), interval_time, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	GetPrivateProfileString(_T("set"), _T("set_Boot"), _T("error"), set_Boot, a, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
#endif
#if 1//测试
	GetPrivateProfileString(_T("set"), _T("day"), _T("error"), day, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("set"), _T("interval_time"), _T("error"), interval_time, a, _T(".\\config.ini"));
	GetPrivateProfileString(_T("set"), _T("set_Boot"), _T("error"), set_Boot, a, _T(".\\config.ini"));
#endif


}
//设置私人信息
//传递信息，公传私（mysql连接信息）
void mysqlDlg::SetMysql()
{
	
	
	HostName_tmp = HostName;
	UserName_tmp = UserName;
	password_tmp = password;
	databases_tmp = databases;
	Port_tmp = Port;
	Boot_tmp = pws_Boot;
}
//传递信息，公传私（查询信息）
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
//传递信息，公传私（基本设置信息）
void mysqlDlg::SetRoutine()
{
	day_tmp = day;
	set_Boot_tmp = set_Boot;
	interval_time_tmp = interval_time;
}

//获取私人信息
//传递信息，私传公（mysql连接信息）
void mysqlDlg::GetMysql()
{
	 HostName = HostName_tmp;
	 UserName = UserName_tmp;
	 password = password_tmp;
	databases= databases_tmp;
	Port = Port_tmp;
	pws_Boot = Boot_tmp;
}
//传递信息，公传私（查询信息）
void mysqlDlg::GetQuery()
{
	time_table = time_table_tmp;
	time_end = time_end_tmp;
	time_ipid = time_ipid_tmp;
	time_userid = time_userid_tmp;
	ip_table = ip_table_tmp;
	ip_ip = ip_ip_tmp;
	ip_id = ip_id_tmp;
	user_table = user_table_tmp;
	user_name = user_name_tmp;
	user_id_tmp = user_id = user_id_tmp;
}
//传递信息，公传私（基本设置信息）
void mysqlDlg::GetRoutine()
{
	day = day_tmp;
	set_Boot = set_Boot_tmp;
	interval_time = interval_time_tmp;
}

//将私人变量存储到配置文件（Mysql信息）
void mysqlDlg::SaveMysql(bool falg)
{
	//加密
#if 0//测试
	WritePrivateProfileString(_T("MYSQL"), _T("HostName"), HostName_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("UserName"), UserName_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("databases"), databases_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("Port"), Port_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	if(falg==1)
		WritePrivateProfileString(_T("MYSQL"), _T("password"), password_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	else
		WritePrivateProfileString(_T("MYSQL"), _T("password"), _T(" "), _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
#endif
#if 1//正式
	WritePrivateProfileString(_T("MYSQL"), _T("HostName"), HostName_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("UserName"), UserName_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("databases"), databases_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("MYSQL"), _T("Port"), Port_tmp, _T(".\\config.ini"));
	if (falg == 1)
		WritePrivateProfileString(_T("MYSQL"), _T("password"), password_tmp, _T(".\\config.ini"));
	else
		WritePrivateProfileString(_T("MYSQL"), _T("password"), _T(" "), _T(".\\config.ini"));
#endif

}
//将私人变量存储到配置文件（查询信息）
void  mysqlDlg::SaveQuery()
{
#if 0
	WritePrivateProfileString(_T("TIME"), _T("time_table"), time_table_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_end"), time_end_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_ipid"), time_ipid_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_userid"), time_userid_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	
	WritePrivateProfileString(_T("IP"), _T("ip_table"), ip_table_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("IP"), _T("ip_ip"), ip_ip_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("IP"), _T("ip_id"), ip_id_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));

	WritePrivateProfileString(_T("USERS"), _T("user_table"), user_table_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("USERS"), _T("user_name"), user_name_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("USERS"), _T("user_id"), user_id_tmp, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
#endif
#if 1
	WritePrivateProfileString(_T("TIME"), _T("time_table"), time_table_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_end"), time_end_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_ipid"), time_ipid_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("TIME"), _T("time_userid"), time_userid_tmp, _T(".\\config.ini"));

	WritePrivateProfileString(_T("IP"), _T("ip_table"), ip_table_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("IP"), _T("ip_ip"), ip_ip_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("IP"), _T("ip_id"), ip_id_tmp, _T(".\\config.ini"));

	WritePrivateProfileString(_T("USERS"), _T("user_table"), user_table_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("USERS"), _T("user_name"), user_name_tmp, _T(".\\config.ini"));
	WritePrivateProfileString(_T("USERS"), _T("user_id"), user_id_tmp, _T(".\\config.ini"));
#endif

}

void  mysqlDlg::SaveRoutine()
{
#if 0//测试
	WritePrivateProfileString(_T("set"), _T("day"), day, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("set"), _T("interval_time"), interval_time, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
	WritePrivateProfileString(_T("set"), _T("set_Boot"), set_Boot, _T("D:\\git\\到期提醒\\新建文件夹\\到期提醒0.3\\config.ini"));
#endif
#if 1//正式
	WritePrivateProfileString(_T("set"), _T("day"), day, _T(".\\config.ini"));
	WritePrivateProfileString(_T("set"), _T("interval_time"), interval_time, _T(".\\config.ini"));
	WritePrivateProfileString(_T("set"), _T("set_Boot"), set_Boot, _T(".\\config.ini"));
#endif
}
//释放资源（mysql连接信息）
void mysqlDlg::FreeMysql()
{
	delete[] HostName;
	delete[] UserName;
	delete[] password;
	delete[] databases;
}
//释放资源（mysql连接信息）
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
//释放资源（基本设置信息）
void mysqlDlg::FreeRoutine()
{
	delete[] day;
	delete[] interval_time;
	delete[] set_Boot;
	
}
