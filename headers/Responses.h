#ifndef SERVER_RESPONSES_H
#define SERVER_RESPONSES_H

//512 - ������������ ����� ������� ��������
const char responses[][512] = {
	{ "-ERR no such message\r\n" },//0 - ������, ��� ������ ���������
	{ "+OK " },//1 - ����� ������ �� �������
	{ "+OK POP3 server ready\r\n" },//2 ������ ����� � ������ � ��������
	{ "+OK name is a valid mailbox\r\n" },//3 ������������� ����� �� ������� USER
	{ "-ERR never heard of mailbox name\r\n" },//4 ������������� ����� �� ������� USER
	{ "+OK %s's maildrop has %d messages (%d octets)\n" },//5 ������ � ��������� ������� ������ - ����� �� ������� PASS
	{ "-ERR invalid password\r\n" },//6 ������������ ������ - ����� �� ������� PASS
	{ "-ERR unable to lock maildrop\n" },//7 ��� ������� � ��������� ����� - ����� �� ������� PASS
	{ "+OK %d %d\n" },//8 ����� �� ������� STAT
	{ "+OK %s\n" },//9 ����� �� ������� LIST
	{ "+OK %d octets\n%s\n" },//10 ����� �� ������� RETR
	{ "+OK message " },//11 ����� �� ������� DELE
	{ "+OK\n" },//12 ����� �� ������� NOOP
	{ "+OK maildrop has " },//13 ����� �� ������� RSET
	{ "+OK\n%s\n" },//14 ����� �� ������� TOP
	{ "+OK %d %s\n" },//15 ����� �� ������� UIDL
	{ "+OK dewey POP3 server signing off\n" },//16 ����� �� ������� QUIT � ��������� �����������
	{ "'s maildrop has " },//17
	{ " messages (" },//18
	{ "+OK dewey POP3 server signing off (" },//19 ����� �� ������� QUIT ��� ������������ ������������
	{ "+OK dewey POP3 server signing off (maildrop empty)" },//20 ����� �� ������� QUIT ��� ������������ ������������ ��� ������ �����
	{ "+OK Capability list follows\r\n" }//21 CAPA - ���������� ��� POP3
};

#endif /*SERVER_RESPONSES_H*/