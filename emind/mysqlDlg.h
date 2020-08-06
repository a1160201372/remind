#pragma once
//mysql类
class mysqlDlg 
{
	public://公共
		//读取配置文件，读到公共
		void GetMysql();
		void GetQuery();
		void GetRoutine();

		//公共传到私人
		void SetMysql();
		void SetQuery();
		void SetRoutine();
		//存储私人数据
		void SaveMysql(bool flag);
		void SaveQuery();
		void SaveRoutine();
		//释放资源
		void FreeMysql();
		void FreeQuery();
		void FreeRoutine();
		/*void GetQueryTime();
		void GetQueryIp();
		void GetQueryUser();*/

		void init();
		//连接数据库
		bool ConnectDatabase(char host[], char user[], char psw[], char table[], int port,char* error[]);
		//
		//
		//公开
		//Mysql
		LPWSTR	HostName;	//
		LPWSTR	Port, pws_Boot;		//
		LPWSTR	UserName;	//
		LPWSTR	password;	//
		LPWSTR	databases;	//
		//查询
		LPWSTR	time_table;	//
		LPWSTR	time_end;	//
		LPWSTR	time_ipid;	//
		LPWSTR	time_userid;	//

		LPWSTR	ip_table;	//
		LPWSTR	ip_ip;	//
		LPWSTR	ip_id;	//

		LPWSTR	user_table;	//
		LPWSTR	user_name;	//
		LPWSTR	user_id;	//

		LPWSTR	day;	//
		LPWSTR	interval_time;	//
		LPWSTR	set_Boot;	//


		//

	protected://私人

	//连接
	
		LPWSTR	HostName_tmp;//
		LPWSTR	Port_tmp, Boot_tmp;	//
		LPWSTR	UserName_tmp;//
		LPWSTR	password_tmp;//
		LPWSTR  databases_tmp;//

		//查询
		LPWSTR	time_table_tmp;	//
		LPWSTR	time_end_tmp;	//
		LPWSTR	time_ipid_tmp;	//
		LPWSTR	time_userid_tmp;	//

		LPWSTR	ip_table_tmp;	//
		LPWSTR	ip_ip_tmp;	//
		LPWSTR	ip_id_tmp;	//

		LPWSTR	user_table_tmp;	//
		LPWSTR	user_name_tmp;	//
		LPWSTR	user_id_tmp;	//

		LPWSTR	day_tmp;	//
		LPWSTR	interval_time_tmp;	//
		LPWSTR	set_Boot_tmp;	//

};


