#pragma once
//mysql��
class mysqlDlg 
{
	public://����
		//
		/*void GetMysql();
		void GetQueryTime();
		void GetQueryIp();
		void GetQueryUser();*/
		void init();
		//�������ݿ�
		bool ConnectDatabase(char host[], char user[], char psw[], char table[], int port,char* error[]);
		//
		//
		//����
		char*	HostName_tmp;//
		int		Port_tmp;	//
		char*	UserName_tmp;//
		char*	password_tmp;//
		char*	databases_tmp;//
		//

	protected://˽��

	//����
		char*	HostName;	//
		int		Port;		//
		char*	UserName;	//
		char*	password;	//
		char*	databases;	//

};


