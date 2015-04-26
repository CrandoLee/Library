#include "Book.h"

Book::Book()
{

}

Book::Book(int nBookID, string strBookName, string strAuthor, string strISBN, string strPub, time_t inDate, int nTotalNum, int nLeftNum)
{
	m_nBookID = nBookID;
	m_strBookName = strBookName;
	m_strAuthor = strAuthor;
	m_strISBN = strISBN;
	m_strPub = strPub;
	m_inDate = inDate;
	m_nTotalNum = nTotalNum;
	m_nLeftNum = nLeftNum;
}


Book::~Book()
{
}

int Book::GetBookID()
{
	return m_nBookID;
}

void Book::SetBookID(int nID)
{
	m_nBookID = nID;
}

string Book::GetBookName()
{
	return m_strBookName;
}

void Book::SetBookName(string strName)
{
	m_strBookName = strName;
}

string Book::GetAuthor()
{
	return m_strAuthor;
}

void Book::SetAuthor(string strAuthor)
{
	m_strAuthor = strAuthor;
}

string Book::GetISBN()
{
	return m_strISBN;
}

void Book::SetISBN(string strISBN)
{
	m_strISBN = strISBN;
}

string Book::GetPub()
{
	return m_strPub;
}

void Book::SetPub(string strPub)
{
	m_strPub = strPub;
}

time_t Book::GetInDate()
{
	return m_inDate;
}

void Book::SetInDate(time_t inDate)
{
	m_inDate = inDate;
}

int Book::GetTotalNum()
{
	return m_nTotalNum;
}

void Book::SetTotalNum(int nTotalNum)
{
	m_nTotalNum = nTotalNum;
}

int Book::GetLeftNum()
{
	return m_nLeftNum;
}

void Book::SetLeftNum(int nLeftNum)
{
	m_nLeftNum = nLeftNum;
}
