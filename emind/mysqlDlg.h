#pragma once
//mysql��
class mysqlDlg 
{
	public://����
		//��ȡ�����ļ�����������
		void GetMysql();

		//��������˽��
		void SetMysql();

		//�洢˽������
		void SaveMysql(bool flag);


		//�ͷ���Դ
		void freeMysql();
	
		/*void GetQueryTime();
		void GetQueryIp();
		void GetQueryUser();*/

		void init();
		//�������ݿ�
		bool ConnectDatabase(char host[], char user[], char psw[], char table[], int port,char* error[]);
		//
		//
		//����
		LPWSTR	HostName;	//
		LPWSTR	Port, pws_Boot;		//
		LPWSTR	UserName;	//
		LPWSTR	password;	//
		LPWSTR	databases;	//
		//

	protected://˽��

	//����
	
		LPWSTR	HostName_tmp;//
		LPWSTR		Port_tmp, Boot_tmp;	//
		LPWSTR	UserName_tmp;//
		LPWSTR	password_tmp;//
		LPWSTR   databases_tmp;//

};


