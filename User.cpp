#include "headers/User.h"

//������ ����������� � ��������������
User::User() : userName(""), password(""), isOnline(false), box(Mailbox()) { }

User::User(const string &name, const string &pass) : userName(name), password(pass), isOnline(false), box(Mailbox()) { }

User::~User()
{
}
