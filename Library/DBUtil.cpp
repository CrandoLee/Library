#include "DBUtil.h"


DBUtil::DBUtil()
{
}


DBUtil::~DBUtil()
{
}

//根据用户名和密码获得用户信息
User DBUtil::ReadUser(string strUserName, string strUserPWD)
{
	User user;
	// 	::CoInitialize(NULL); // 初始化OLE/COM库环境 ，为访问ADO接口做准备
	// 	_RecordsetPtr m_pRecordset("ADODB.Recordset");
	// 	_ConnectionPtr m_pConnection("ADODB.Connection");
	// 	string sql = "select * from [user]  where name='" + strUserName + "' and password='" + strUserPWD + "'";
	// 	_bstr_t bstrSQL((wchar_t *)(_bstr_t(sql.c_str()))); //查询语句 
	// 	try
	// 	{
	// 		// 创建Connection对象
	// 		m_pConnection.CreateInstance("ADODB.Connection");
	// 		// 设置连接字符串，必须是BSTR型或者_bstr_t类型
	// 		_bstr_t strConnect = "Provider=SQLOLEDB;Server=.\\SQLEXPRESS;Database=library; uid=sa; pwd=root;";
	// 		//若数据库在网络上则Server为形如(192.168.1.5,3340)
	// 		//用户sa和密码123只是针对我的库 
	// 		m_pConnection->Open(strConnect, "", "", adModeUnknown);
	// 		if (m_pConnection == NULL)
	// 			cerr << "Lind data ERROR!\n";
	// 		// 创建记录集对象
	// 		m_pRecordset.CreateInstance(__uuidof(Recordset));
	// 		// 取得表中的记录
	// 		m_pRecordset->Open(bstrSQL, m_pConnection.GetInterfacePtr(),
	// 			adOpenDynamic, adLockOptimistic, adCmdText);
	// 		int nUserID = 0;
	// 		string strName = "";
	// 		string strPassWord = "";
	// 		int nRole = 0;
	// 		while (!m_pRecordset->EndOfFile)
	// 		{
	// 			nUserID = m_pRecordset->GetCollect("id");//这儿给字段编号和字段名都可以 
	// 			strName = (const char*)_bstr_t(m_pRecordset->GetCollect("name"));
	// 			strPassWord = (const char*)_bstr_t(m_pRecordset->GetCollect("password"));
	// 			nRole = m_pRecordset->GetCollect("role");
	// 			if (strName == strUserName && strPassWord == strUserPWD)
	// 			{
	// 				user.SetUserID(nUserID);
	// 				user.SetUserName(strUserName);
	// 				user.SetUserPWD(strUserPWD);
	// 				user.SetUserRole(nRole);
	// 				return user;
	// 			}
	// 			m_pRecordset->MoveNext(); ///移到下一条记录
	// 		}
	// 
	// 		//m_pRecordset->MoveFirst(); //移动到第一条记录
	// 		//m_pRecordset->AddNew(); ///添加新记录
	// 		//m_pRecordset->PutCollect("snum", _variant_t(student.snum));
	// 		//m_pRecordset->PutCollect("sname", _variant_t(student.sname));
	// 		//m_pRecordset->PutCollect("sage", _variant_t(student.sage));
	// 		//m_pRecordset->PutCollect("ssex", _variant_t(student.ssex));
	// 		//m_pRecordset->PutCollect("smajor", _variant_t(student.smajor));
	// 		//m_pRecordset->Update();
	// 		//m_pConnection->Execute(query_cmd, NULL, 1); //用Execute执行sql语句来删除
	// 		//m_pRecordset->Close(); // 关闭记录集
	// 	}
	// 	// 捕捉异常
	// 	catch (_com_error e)
	// 	{
	// 		// 显示错误信息
	// 		cerr<<"\nERROR:"<<(char*)e.Description();//抛出异常
	// 	}
	// 	if (m_pConnection->State)
	// 		m_pConnection->Close();
	// 	::CoUninitialize();

	const char username[] = "root";         //username
	const char pswd[] = "ROOT";         //password
	const char host[] = "localhost";    //or"127.0.0.1"
	const char table[] = "library";        //database
	unsigned int port = 3306;           //server port        
	MYSQL myCont;
	MYSQL_RES *result;
	MYSQL_ROW sql_row;
	MYSQL_FIELD *fd;
	char column[32][32];
	int res;
	string sql = "";
	string strName = "";
	string strPass = "";
	mysql_init(&myCont);
	if (mysql_real_connect(&myCont, host, username, pswd, table, port, NULL, 0))
	{
		cout << "connect succeed!" << endl;
		mysql_query(&myCont, "SET NAMES GBK"); //设置编码格式,否则在cmd下无法显示中文
		sql += "select * from user where name='" + strUserName + "' and password='" + strUserPWD + "'";
		res = mysql_query(&myCont, sql.c_str());//查询
		if (!res)
		{
			result = mysql_store_result(&myCont);//保存查询到的数据到result
			if (result)
			{
				int i, j;
				//cout << "number of result: " << (unsigned long)mysql_num_rows(result) << endl;
				for (i = 0; fd = mysql_fetch_field(result); i++)//获取列名
				{
					strcpy_s(column[i], fd->name);
				}
				j = mysql_num_fields(result);
// 				for (i = 0; i < j; i++)
// 				{
// 					printf("%s\t", column[i]);
// 				}
//				printf("\n");
// 				while (sql_row = mysql_fetch_row(result))//获取具体的数据
// 				{
// 					for (i = 0; i < j; i++)
// 					{
// 						printf("%s\n", sql_row[i]);
// 					}
// 					printf("\n");
// 					
// 				}
				if (j > 0)
				{
					sql_row = mysql_fetch_row(result);
					user.SetUserID(atoi(sql_row[0]));
					user.SetUserName(sql_row[1]);
					user.SetUserRole(atoi(sql_row[3]));
				}

				//fd = mysql_fetch_field(result);
				
			}
		}
		else
		{
			cout << "query sql failed!" << endl;
		}
	}
	else
	{
		cout << "connect failed!" << endl;
	}
	if (result != NULL) mysql_free_result(result);//释放结果资源
	mysql_close(&myCont);//断开连接
	return user;
}
