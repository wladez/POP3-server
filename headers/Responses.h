#ifndef SERVER_RESPONSES_H
#define SERVER_RESPONSES_H

//512 - максимальная длина каждого элемента
const char responses[][512] = {	
	{ "-ERR no such message\n" },//0 - ошибка, нет такого сообщения
	{ "+OK " },//1 - часть ответа от сервера
	{ "+OK POP3 server ready\n" },//2 сервер готов к работе с клиентом
	{ "+OK name is a valid mailbox\n" },//3 положительный ответ на команду USER
	{ "-ERR never heard of mailbox name\n" },//4 отрицательный ответ на команду USER
	{ "+OK %s's maildrop has %d messages (%d octets)\n" },//5 доступ к почтовому серверу открыт - ответ на команду PASS
	{ "-ERR invalid password\n" },//6 неправильный пароль - ответ на команду PASS
	{ "-ERR unable to lock maildrop\n" },//7 нет доступа к почтовому ящику - ответ на команду PASS
	{ "+OK %d %d\n" },//8 ответ на команду STAT
	{ "+OK %s\n" },//9 ответ на команду LIST
	{ "+OK %d octets\n%s\n" },//10 ответ на команду RETR
	{ "+OK message %d deleted\n" },//11 ответ на команду DELE
	{ "+OK\n" },//12 ответ на команду NOOP
	{ "+OK maildrop has %d messages (%d octets)\n" },//13 ответ на команду RSET
	{ "+OK\n%s\n" },//14 ответ на команду TOP
	{ "+OK %d %s\n" },//15 ответ на команду UIDL
	{ "+OK dewey POP3 server signing off\n" }//16 ответ на команду QUIT в состоянии авторизации
};

#endif /*SERVER_RESPONSES_H*/