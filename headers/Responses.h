#ifndef SERVER_RESPONSES_H
#define SERVER_RESPONSES_H

//512 - ������������ ����� ������� ��������
const char responses[][512] = {	
	{ "-ERR no such message\n" },//0 - ������, ��� ������ ���������
	{ "+OK " },//1 - ����� ������ �� �������
	{ "+OK POP3 server ready\n" },//2 ������ ����� � ������ � ��������
	{ "+OK name is a valid mailbox\n" },//3 ������������� ����� �� ������� USER
	{ "-ERR never heard of mailbox name\n" },//4 ������������� ����� �� ������� USER
	{ "+OK %s's maildrop has %d messages (%d octets)\n" },//5 ������ � ��������� ������� ������ - ����� �� ������� PASS
	{ "-ERR invalid password\n" },//6 ������������ ������ - ����� �� ������� PASS
	{ "-ERR unable to lock maildrop\n" },//7 ��� ������� � ��������� ����� - ����� �� ������� PASS
	{ "+OK %d %d\n" },//8 ����� �� ������� STAT
	{ "+OK %s\n" },//9 ����� �� ������� LIST
	{ "+OK %d octets\n%s\n" },//10 ����� �� ������� RETR
	{ "+OK message %d deleted\n" },//11 ����� �� ������� DELE
	{ "+OK\n" },//12 ����� �� ������� NOOP
	{ "+OK maildrop has %d messages (%d octets)\n" },//13 ����� �� ������� RSET
	{ "+OK\n%s\n" },//14 ����� �� ������� TOP
	{ "+OK %d %s\n" },//15 ����� �� ������� UIDL
	{ "+OK dewey POP3 server signing off\n" }//16 ����� �� ������� QUIT � ��������� �����������
};

#endif /*SERVER_RESPONSES_H*/