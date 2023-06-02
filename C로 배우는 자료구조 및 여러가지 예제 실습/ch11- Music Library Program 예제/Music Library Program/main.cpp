﻿#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_tools.h" // read_line(), 
#include "library.h"

#define BUFFER_LENGTH 200

void process_command();
void handle_add();

int main() 
{
	initialize(); // artist_directory 초기화
	process_command();
}

void process_command() 
{
	char command_line[BUFFER_LENGTH];
	char* command;

	while (1) { // infinite loop
		printf("$ "); // prompt

		if (read_line(stdin, command_line, BUFFER_LENGTH) <= 0) 
			continue;

		command = strtok(command_line, " ");
		if (strcmp(command, "add") == 0)
			handle_add();
		//else if (strcmp(command, "search") == 0)
		//	handle_search();
		//else if (strcmp(command, "remove") == 0)
		//	handle_remove();
		else if (strcmp(command, "status") == 0)
			status();
		//else if (strcmp(command, "play") == 0)
		//	handle_play();
		//else if (strcmp(command, "save") == 0)
		//	handle_save();
		else if (strcmp(command, "exit") == 0)
			break;
	}

}


void handle_add() 
{
	char buffer[BUFFER_LENGTH];
	char* artist = NULL, * title = NULL, * path = NULL;

	printf("	Artist: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		artist = _strdup(buffer);
	printf("	Title: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		title = _strdup(buffer);
	printf("	Path: ");
	if (read_line(stdin, buffer, BUFFER_LENGTH) > 0)
		path = _strdup(buffer);

	printf("%s %s %s\n", artist, title, path);

	/* 입력받은 내용을 music library에 add*/
	 add_song(artist, title, path);

}