#pragma once
//mysql类
class mysqlDlg 
{
	public://公共
		//读取配置文件，读到公共
		void ReadMysql();
		void ReadQuery();
		void ReadRoutine();

		//私人传到公共
		void SetMysql();
		void SetQuery();
		void SetRoutine();
		//公共传到私人
		void GetMysql();
		void GetQuery();
		void GetRoutine();
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
		bool ConnectDatabase(LPWSTR host, LPWSTR user, LPWSTR psw, LPWSTR table, LPWSTR port);
		//查询数据
		bool QueryDatabase2(LPWSTR table1_tmp, LPWSTR day_in_tmp,
			LPWSTR key_time_tmp, LPWSTR key_time_ipid_tmp, LPWSTR key_time_nameid_tmp,
			LPWSTR table_ip_tmp, LPWSTR key_ipid_tmp, LPWSTR key_ip_tmp,
			LPWSTR table_user_tmp, LPWSTR key_nameid_tmp, LPWSTR key_name_tmp
		);
		char* mysqlDlg::QueryDatabase3(LPWSTR table_tmp, LPWSTR key_id_tmp, LPWSTR key_tmp, char* id_tmp,bool flag_ip_user);

			//
		//公开
		//Mysql
		wchar_t* HostName;	//
		wchar_t* Port;
		wchar_t*	pws_Boot;		//
		wchar_t* UserName;	//
		wchar_t* password;	//
		wchar_t* databases;	//
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

private://私人

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


