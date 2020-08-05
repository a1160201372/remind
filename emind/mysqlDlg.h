#pragma once
//mysql类
class mysqlDlg 
{
	public://公共
		//
		/*void GetMysql();
		void GetQueryTime();
		void GetQueryIp();
		void GetQueryUser();*/
		void init();
		//连接数据库
		bool ConnectDatabase(char host[], char user[], char psw[], char table[], int port,char* error[]);
		//
		//
		//公开
		char*	HostName_tmp;//
		int		Port_tmp;	//
		char*	UserName_tmp;//
		char*	password_tmp;//
		char*	databases_tmp;//
		//

	protected://私人

	//连接
		char*	HostName;	//
		int		Port;		//
		char*	UserName;	//
		char*	password;	//
		char*	databases;	//

};


