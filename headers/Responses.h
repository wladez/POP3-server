#ifndef SERVER_RESPONSES_H
#define SERVER_RESPONSES_H

//512 - максимальная длина каждого элемента
const char responses[][512] = {	
	{ "-ERR no such message\n" },//0 - ошибка, нет такого сообщения
	{ "+OK POP3 server ready\n" },//1 сервер готов к работе с клиентом
	{ "+OK name is a valid mailbox\n" },//2 положительный ответ на команду USER
	{ "-ERR never heard of mailbox name\n" },//3 отрицательный ответ на команду USER
	{ "+OK %s's maildrop has %d messages (%d octets)\n" },//4 доступ к почтовому серверу открыт - ответ на команду PASS
	{ "-ERR invalid password\n" },//5 неправильный пароль - ответ на команду PASS
	{ "-ERR unable to lock maildrop\n" },//6 нет доступа к почтовому ящику - ответ на команду PASS
	{ "+OK %d %d\n" },//7 ответ на команду STAT
	{ "+OK %s\n" },//8 ответ на команду LIST
	{ "+OK %d octets\n%s\n" },//9 ответ на команду RETR
	{ "+OK message %d deleted\n" },//10 ответ на команду DELE
	{ "+OK\n" },//11 ответ на команду NOOP
	{ "+OK maildrop has %d messages (%d octets)\n" },//12 ответ на команду RSET
	{ "+OK\n%s\n" },//13 ответ на команду TOP
	{ "+OK %d %s\n" },//14 ответ на команду UIDL
	{ "+OK dewey POP3 server signing off\n" }//15 ответ на команду QUIT в состоянии авторизации
};

#endif /*SERVER_RESPONSES_H*/