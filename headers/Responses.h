#ifndef SERVER_RESPONSES_H
#define SERVER_RESPONSES_H

//512 - ������������ ����� ������� ��������
const char responses[][512] = {	
	{ "-ERR no such message\n" },//0 - ������, ��� ������ ���������
	{ "+OK POP3 server ready\n" },//1 ������ ����� � ������ � ��������
	{ "+OK name is a valid mailbox\n" },//2 ������������� ����� �� ������� USER
	{ "-ERR never heard of mailbox name\n" },//3 ������������� ����� �� ������� USER
	{ "+OK %s's maildrop has %d messages (%d octets)\n" },//4 ������ � ��������� ������� ������ - ����� �� ������� PASS
	{ "-ERR invalid password\n" },//5 ������������ ������ - ����� �� ������� PASS
	{ "-ERR unable to lock maildrop\n" },//6 ��� ������� � ��������� ����� - ����� �� ������� PASS
	{ "+OK %d %d\n" },//7 ����� �� ������� STAT
	{ "+OK %s\n" },//8 ����� �� ������� LIST
	{ "+OK %d octets\n%s\n" },//9 ����� �� ������� RETR
	{ "+OK message %d deleted\n" },//10 ����� �� ������� DELE
	{ "+OK\n" },//11 ����� �� ������� NOOP
	{ "+OK maildrop has %d messages (%d octets)\n" },//12 ����� �� ������� RSET
	{ "+OK\n%s\n" },//13 ����� �� ������� TOP
	{ "+OK %d %s\n" },//14 ����� �� ������� UIDL
	{ "+OK dewey POP3 server signing off\n" }//15 ����� �� ������� QUIT � ��������� �����������
};

#endif /*SERVER_RESPONSES_H*/