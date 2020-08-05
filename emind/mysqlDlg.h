#pragma once
//mysql类
class mysqlDlg 
{
	public://公共
		//读取配置文件，读到公共
		void GetMysql();

		//公共传到私人
		void SetMysql();

		//存储私人数据
		void SaveMysql(bool flag);


		//释放资源
		void freeMysql();
	
		/*void GetQueryTime();
		void GetQueryIp();
		void GetQueryUser();*/

		void init();
		//连接数据库
		bool ConnectDatabase(char host[], char user[], char psw[], char table[], int port,char* error[]);
		//
		//
		//公开
		LPWSTR	HostName;	//
		LPWSTR	Port, pws_Boot;		//
		LPWSTR	UserName;	//
		LPWSTR	password;	//
		LPWSTR	databases;	//
		//

	protected://私人

	//连接
	
		LPWSTR	HostName_tmp;//
		LPWSTR		Port_tmp, Boot_tmp;	//
		LPWSTR	UserName_tmp;//
		LPWSTR	password_tmp;//
		LPWSTR   databases_tmp;//

};


