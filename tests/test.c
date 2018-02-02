/*
** EPITECH PROJECT, 2018
** test.c
** File description:
** test.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <unistd.h>
#include <fcntl.h>

void open_file(void)
{
	int fd = -1;
	fd = open("text", O_RDONLY);
}

Test(get_next_line, first_line)
{
	int fd = open("text", O_RDONLY);
	char *expected = "titi";
	char *got = get_next_line(fd);
	cr_assert_str_eq(got, expected);
}

Test(get_next_line, entire_reading)
{
	int fd = open("text", O_RDONLY);
	int i = 0;
	char *got = get_next_line(fd);
	while (got) {
		got = get_next_line(fd);
		i = i + 1;
	}
	cr_assert_eq(i, 3);
}

Test(get_next_line, invalid)
{
	int fd = open("okokkkk", O_RDONLY);
	char *got = get_next_line(fd);
	cr_assert(got == NULL);
}

Test(get_next_line, second_line)
{
	int fd = open("text", O_RDONLY);
	char *got = get_next_line(fd);
	got = get_next_line(fd);
	cr_assert_str_eq(got, "tata");
}

Test(get_next_line, line_with_tabs)
{
	int fd = open("text2", O_RDONLY);
	char *got = get_next_line(fd);
	cr_assert_str_eq(got,  "		titi");
}

Test(get_next_line, terminator)
{
	int fd = open("text2", O_RDONLY);
	char *got = get_next_line(fd);
	got = get_next_line(fd);
	got = get_next_line(fd);
	cr_assert(got == NULL);
}

Test(get_next_line, terminator_harder)
{
	int fd = open("text3", O_RDONLY);
	char *got = get_next_line(fd);
	got = get_next_line(fd);
	got = get_next_line(fd);
	cr_assert_str_eq(got, "ok");
	got = get_next_line(fd);
	cr_assert(got == NULL);
}
